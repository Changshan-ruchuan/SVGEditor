#include "kshape.h"
#include "kshapeparameter.h"

KShape::KShape(QObject *parent)
	: QObject(parent)
	, m_borderWidth(KShapeParameter::getInstance()->getBorderWidth())
	, m_borderStyle(KShapeParameter::getInstance()->getBorderStyle())
	, m_borderColor(KShapeParameter::getInstance()->getBorderColor())
	, m_shapeColor(KShapeParameter::getInstance()->getShapeColor())
	, m_scaleFactor(KShapeParameter::getInstance()->getCanvasScale())
{
}

KShape::~KShape()
{
}

// ��ȡ��ʼ�����
QPointF KShape::getStartPoint() const
{
	return m_startPoint;
}

// ��ȡ�滭���������
QPointF KShape::getEndPoint() const
{
	return m_endPoint;
}

// ���û滭��ʼ�����
void KShape::setStartPoint(const QPointF &point)
{
	m_startPoint = point;
}

// ���û滭���������
void KShape::setEndPoint(const QPointF &point)
{
	m_endPoint = point;
}

// �жϻ滭�Ƿ�Ϸ�
bool KShape::isShapeVaild() const
{
	return (m_startPoint.x() != m_endPoint.x() || m_startPoint.y() != m_endPoint.y());
}

KShapeType KShape::getShapeType()
{
	return KShapeType::None;
}

QRectF KShape::getShapeRect()
{
	return QRectF(m_startPoint, m_endPoint);
}


void KShape::drawOutline(QPaintDevice *parent)
{
	QPainter painter(parent);
	// ���������
	painter.setRenderHint(QPainter::Antialiasing);
	// Ӧ�����ű任
	QTransform transform;
	transform.scale(m_scaleFactor, m_scaleFactor);
	painter.setTransform(transform);
	painter.setPen(QPen(Qt::black, 1.0, Qt::DashLine));	// ����
	painter.drawRect(getShapeRect());
}

// ѡ��ͼ�θ�����ʾ�߿��Լ��˸����Ƶ�
void KShape::drawSelectedHighlight(QPaintDevice *parent, bool drawControl)
{
	QPainter painter(parent);
	// ���������
	painter.setRenderHint(QPainter::Antialiasing);
	// Ӧ�����ű任
	QTransform transform;
	transform.scale(m_scaleFactor, m_scaleFactor);
	painter.setTransform(transform);
	painter.setPen(QPen(QColor(128, 0, 128), 2.0, Qt::SolidLine));
	// ��ȡ���ο�Ŀ�͸�
	int shapeWidth = m_endPoint.x() - m_startPoint.x();
	int shapeHeight = m_endPoint.y() - m_startPoint.y();
	// ����߽���εĿ�Ȼ�߶�С�ڵ���0���򷵻ز����л���
	if (shapeWidth <= 0 || shapeHeight <= 0)
		return;
	// ���Ʊ߽����
	painter.drawRect(getShapeRect());
	// ����Ƿ���Ҫ���ƿ��Ƶ�
	if (!drawControl)
		return;
	// ��ȡ�߽���ε����Ͻ�����
	QPointF shapeLeftTopXY = m_startPoint;
	// ��ȡ���ű���
	qreal scale = KShapeParameter::getInstance()->getShapeScale();
	// ���ÿ��Ƶ��һ�볤�ȵ�ֵ
	qreal halfLength = 4.0 * scale;
	// ����8�����Ƶ㣬���������ǵ�λ�úʹ�С
	for (int i = 0; i < 8; i++)
	{
		switch (i)
		{
		case 0:	// �������ϽǵĿ��Ƶ�����Ͻ�����
			m_controlRect[i].setX(shapeLeftTopXY.x() - halfLength);
			m_controlRect[i].setY(shapeLeftTopXY.y() - halfLength);
			break;
		case 1:	// �����ϱ��е�Ŀ��Ƶ�����Ͻ�����
			m_controlRect[i].setX(shapeLeftTopXY.x() + shapeWidth / 2.0 - halfLength);
			m_controlRect[i].setY(shapeLeftTopXY.y() - halfLength);
			break;
		case 2:	// �������ϽǵĿ��Ƶ�����Ͻ�����
			m_controlRect[i].setX(shapeLeftTopXY.x() + shapeWidth - halfLength);
			m_controlRect[i].setY(shapeLeftTopXY.y() - halfLength);
			break;
		case 3:	// �����ұ��е�Ŀ��Ƶ�����Ͻ�����
			m_controlRect[i].setX(shapeLeftTopXY.x() + shapeWidth - halfLength);
			m_controlRect[i].setY(shapeLeftTopXY.y() + shapeHeight / 2.0 - halfLength);
			break;
		case 4:	// �������½ǵĿ��Ƶ�����Ͻ�����
			m_controlRect[i].setX(shapeLeftTopXY.x() + shapeWidth - halfLength);
			m_controlRect[i].setY(shapeLeftTopXY.y() + shapeHeight - halfLength);
			break;
		case 5:	// �����±��е�Ŀ��Ƶ�����Ͻ�����
			m_controlRect[i].setX(shapeLeftTopXY.x() + shapeWidth / 2.0 - halfLength);
			m_controlRect[i].setY(shapeLeftTopXY.y() + shapeHeight - halfLength);
			break;
		case 6:	// �������½ǵĿ��Ƶ�����Ͻ�����
			m_controlRect[i].setX(shapeLeftTopXY.x() - halfLength);
			m_controlRect[i].setY(shapeLeftTopXY.y() + shapeHeight - halfLength);
			break;
		case 7:	// ��������е�Ŀ��Ƶ�����Ͻ�����
			m_controlRect[i].setX(shapeLeftTopXY.x() - halfLength);
			m_controlRect[i].setY(shapeLeftTopXY.y() + shapeHeight / 2.0 - halfLength);
			break;
		default:
			break;
		}

		// ���ÿ��Ƶ�Ĵ�С
		m_controlRect[i].setWidth(2.0 * halfLength);
		m_controlRect[i].setHeight(2.0 * halfLength);

		// ���ƿ��Ƶ����
		painter.drawRect(m_controlRect[i]);
		// �����Ƶ����Ϊ��ɫ
		painter.fillRect(m_controlRect[i], QColor(128, 0, 128));
	}
}

void KShape::move(const QPointF &offset)
{
	// ƽ�ƾ��α߽磨��Ҫ�ٻ���ͼ�β��ܽ�ͼ��ƽ�ƣ�
	m_startPoint += offset;
	m_endPoint += offset;
}

void KShape::moveTop(QPointF pos)
{
	if (pos.y() - m_endPoint.y() <= -25)
		m_startPoint.setY(pos.y());
}

void KShape::moveBottom(QPointF pos)
{
	if (pos.y() - m_startPoint.y() >= 25)
		m_endPoint.setY(pos.y());
}

void KShape::moveLeft(QPointF pos)
{
	if (pos.x() - m_endPoint.x() <= -25)
		m_startPoint.setX(pos.x());
}

void KShape::moveRight(QPointF pos)
{
	if (pos.x() - m_startPoint.x() >= 25)
		m_endPoint.setX(pos.x());
}

void KShape::moveTopLeft(QPointF pos)
{
	if (pos.y() - m_endPoint.y() <= -25 && pos.x() - m_endPoint.x() <= -25)
		m_startPoint = pos;
	else if (pos.y() - m_endPoint.y() > -25 && pos.x() - m_endPoint.x() <= -25)
		m_startPoint.setX(pos.x());
	else if (pos.y() - m_endPoint.y() <= -25 && pos.x() - m_endPoint.x() > -25)
		m_startPoint.setY(pos.y());
}

void KShape::moveTopRight(QPointF pos)
{
	if (pos.y() - m_endPoint.y() <= -25 && pos.x() - m_startPoint.x() >= 25)
	{
		m_startPoint.setY(pos.y());
		m_endPoint.setX(pos.x());
	}
	else if (pos.y() - m_endPoint.y() > -25 && pos.x() - m_startPoint.x() >= 25)
	{
		m_endPoint.setX(pos.x());
	}
	else if (pos.y() - m_endPoint.y() <= -25 && pos.x() - m_startPoint.x() < 25)
	{
		m_startPoint.setY(pos.y());
	}
}

void KShape::moveBottomLeft(QPointF pos)
{
	if (pos.y() - m_startPoint.y() >= 25 && pos.x() - m_endPoint.x() <= -25)
	{
		m_startPoint.setX(pos.x());
		m_endPoint.setY(pos.y());
	}
	else if (pos.x() - m_endPoint.x() > -25 && pos.y() - m_startPoint.y() >= 25)
	{
		m_endPoint.setY(pos.y());
	}
	else if (pos.x() - m_endPoint.x() <= -25 && pos.y() - m_startPoint.y() < 25)
	{
		m_startPoint.setX(pos.x());
	}
}

void KShape::moveBottomRight(QPointF pos)
{
	if (pos.y() - m_startPoint.y() >= 25 && pos.x() - m_startPoint.x() >= 25)
		m_endPoint = pos;
	else if (pos.y() - m_startPoint.y() < 25 && pos.x() - m_startPoint.x() >= 25)
		m_endPoint.setX(pos.x());
	else if (pos.y() - m_startPoint.y() >= 25 && pos.x() - m_startPoint.x() < 25)
		m_endPoint.setY(pos.y());
}

void KShape::setShapeScale(qreal scale)
{
	m_scaleFactor = scale;
}

qreal KShape::getShapeScale()
{
	return m_scaleFactor;
}

void KShape::setBorderWidth(int width)
{
	m_borderWidth = width;
}

void KShape::setBorderStyle(Qt::PenStyle style)
{
	m_borderStyle = style;
}

void KShape::setBorderColor(QRgb color)
{
	m_borderColor = color;
}

void KShape::setShapeColor(QRgb color)
{
	m_shapeColor = color;
}

QRgb KShape::getBorderColor()
{
	return m_borderColor;
}

Qt::PenStyle KShape::getBorderStyle()
{
	return m_borderStyle;
}

QRgb KShape::getShapeColor()
{
	return m_shapeColor;
}

int KShape::getBorderWidth()
{
	return m_borderWidth;
}

const int KShape::getControlRectIndex(QPoint pos)
{
	for (int i = 0; i < 8; i++)
	{
		if (m_controlRect[i].contains(pos))
			return i;
	}
	return -1;
}
