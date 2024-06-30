#include "kcanvas.h"
#include "kshapefactory.h"
#include "kshapeparameter.h"

KCanvas::KCanvas(QWidget *parent)
	: QWidget(parent)
	, m_pShapeList(new QList<KShape*>)
	, m_isLPress(false)
	, m_isDrawing(false)
	, m_isSelected(false)
	, m_transType(KMoveType::None)
	, m_scaleFactor(1.0)
	, m_canvasWidth(600)
	, m_canvasHeight(600)
	, m_currentDrawFlag(KDrawFlag::NoneDrawFlag)
	, m_enableSelect(false)
	, m_isCleanCanvas(false)
{
	setAttribute(Qt::WA_StyledBackground, true);
	//�������׷��
	setMouseTracking(true);
	//������ȡ����
	setFocusPolicy(Qt::ClickFocus);
	// ���������ͣ
	this->setAttribute(Qt::WA_Hover, true);
	// ��װ�¼�������
	this->installEventFilter(this);
}

KCanvas::~KCanvas()
{
	qDeleteAll(*m_pShapeList);
	delete m_pShapeList;
}

bool KCanvas::eventFilter(QObject *watched, QEvent *event)
{
	if (watched == this)
	{
		if (event->type() == QEvent::HoverMove)
		{
			if (!m_pCurrentShape)
				return QWidget::eventFilter(watched, event);
			// �ų���ǰͼ��Ϊ����ǵ����
			if (m_pCurrentShape->getShapeType() == KShapeType::PentagramShapeType)
				return QWidget::eventFilter(watched, event);
			if (m_currentDrawFlag == KDrawFlag::MouseDrawFlag)
			{
				QHoverEvent *e = static_cast<QHoverEvent*>(event);
				// �������λ�ø��������ʽ
				int controlPos = m_pCurrentShape->getControlRectIndex(e->pos());
				switch (controlPos)
				{
				case 0:	// ���Ͻ�
					setCursor(Qt::SizeFDiagCursor);
					break;
				case 1:	// �����м�
					setCursor(Qt::SizeVerCursor);
					break;
				case 2:	// ���Ͻ�
					setCursor(Qt::SizeBDiagCursor);
					break;
				case 3:	// �ұ��м�
					setCursor(Qt::SizeHorCursor);
					break;
				case 4:	// ���½�
					setCursor(Qt::SizeFDiagCursor);
					break;
				case 5:	// �ײ��м�
					setCursor(Qt::SizeVerCursor);
					break;
				case 6:	// ���½�
					setCursor(Qt::SizeBDiagCursor);
					break;
				case 7:	// ����м�
					setCursor(Qt::SizeHorCursor);
					break;
				default:	// ����λ��
					setCursor(Qt::ArrowCursor);
					break;
				}
			}
		}
	}
	return QWidget::eventFilter(watched, event);
}

// ��д�滭�¼�
void KCanvas::paintEvent(QPaintEvent *event)
{
	// ��ͼ
	if (!m_pShapeList->isEmpty())
	{
		for (QList<KShape*>::iterator it = m_pShapeList->begin();
			it != m_pShapeList->end(); ++it)
			(*it)->drawShape(this);
	}
	else if(m_isCleanCanvas)	// ���û�л��Ƶ�ͼ�Σ����ҵ������ջ�������return
	{
		return;
	}
	// �����ǰ�ڻ���ͼ�λ���ѡ����ͼ��
	if (m_pCurrentShape)
	{
		// ����Ǵ����ƶ�״̬��ֻ���Ƹ�������
		if (m_currentDrawFlag == KDrawFlag::MouseDrawFlag)
		{
			// �����������򲻽��п��Ƶ�Ļ���
			if (m_pCurrentShape->getShapeType() == KShapeType::PentagramShapeType)
				m_pCurrentShape->drawSelectedHighlight(this, false);
			else
				m_pCurrentShape->drawSelectedHighlight(this, true);
		}
		else
		{
			// ������ڻ��ƾ��������ͼ�Σ�����˻��ƾ��α߽��⻹Ҫ����ͼ��
			if (m_currentDrawFlag != KDrawFlag::RectDrawFlag)
				m_pCurrentShape->drawShape(this);
			m_pCurrentShape->drawOutline(this);
		}
	}
}

// ��д��갴���¼�
void KCanvas::mousePressEvent(QMouseEvent *event)
{
	// ��鵱ǰ�����ű���
	qreal scale = KShapeParameter::getInstance()->getShapeScale();
	if (scale != 1.0)
	{
		QMessageBox::warning(this, QStringLiteral("����"), QStringLiteral("���Ȼָ����ű���Ϊ1.0�ٽ��в���"));
		return;
	}
	// ��ȡ��ǰ�Ļ��Ʊ�־�������������ĸ���ť��
	m_currentDrawFlag = KShapeParameter::getInstance()->getDrawFlag();
	// ���û�е�����İ�ť�������������ʱ����ʲô������
	if (m_currentDrawFlag == KDrawFlag::NoneDrawFlag)
		return;
	m_lastPos = event->pos();	// ��ȡ���µ�λ��
	m_isCleanCanvas = false;	// ����ջ���״̬
	// ������ƶ�����
	if (m_currentDrawFlag == KDrawFlag::MouseDrawFlag)
	{
		// ������
		if (event->buttons() == Qt::LeftButton)
		{
			m_isLPress = true;	// ����������±�־
			// ��ȡ���λ�õ�ͼ��
			KShape *shape = getCurrentShape(m_lastPos);
			if (shape)
			{
				m_pCurrentShape = shape;
				int controlPos = m_pCurrentShape->getControlRectIndex(event->pos());
				switch (controlPos)
				{
				case 0:	// ���Ͻ�
					m_transType = KMoveType::TopLeft;
					break;
				case 1:	// �����м�
					m_transType = KMoveType::Top;
					break;
				case 2:	// ���Ͻ�
					m_transType = KMoveType::TopRight;
					break;
				case 3:	// �ұ��м�
					m_transType = KMoveType::Right;
					break;
				case 4:	// ���½�
					m_transType = KMoveType::BottomRight;
					break;
				case 5:	// �ײ��м�
					m_transType = KMoveType::Bottom;
					break;
				case 6:	// ���½�
					m_transType = KMoveType::BottomLeft;
					break;
				case 7:	// ����м�
					m_transType = KMoveType::Left;
					break;
				default:	// ����λ��
					m_transType = KMoveType::Move;
					break;
				}
				m_enableSelect = true;
				// ���õ�ǰѡ���ͼ��
				KShapeParameter::getInstance()->setCurrentShape(m_pCurrentShape);
				// �Ѿ�ѡ����ͼ��
				emit shapeSelected(true);
				// ��ȡ�߿���
				int width = m_pCurrentShape->getBorderWidth();
				emit currentShapeBorderWidth(width);
				// ��ȡ�߿���ʽ
				Qt::PenStyle style = m_pCurrentShape->getBorderStyle();
				emit currentShapeBorderStyle(style);
				// ��ȡ�߿���ɫ
				QRgb rgb = m_pCurrentShape->getBorderColor();
				emit currntShapeBorderColor(rgb);
				// ��ȡͼ�������ɫ
				rgb = m_pCurrentShape->getShapeColor();
				emit currntShapeColor(rgb);
				update();
			}
		}
	}
	else
	{
		if (event->buttons() == Qt::LeftButton)
		{
			m_isLPress = true;	// ����������±�־
			// ����һ��ͼ��
			m_pCurrentShape = KShapeFactory::createShape(m_currentDrawFlag);
			// ������ʼ�������
			m_pCurrentShape->setStartPoint(m_lastPos);
			// ���ý����������
			m_pCurrentShape->setEndPoint(m_lastPos);
			m_isDrawing = true;	// ���û�ͼ��־
		}
	}
}

// ��д����ƶ��¼�
void KCanvas::mouseMoveEvent(QMouseEvent *event)
{
	if (m_currentDrawFlag == KDrawFlag::NoneDrawFlag)
		return;
	// ��ȡ���λ��
	QPoint nowPos = event->pos();
	if (m_currentDrawFlag == KDrawFlag::MouseDrawFlag)
	{
		if(m_enableSelect)
		{
			QPointF offset = nowPos - m_lastPos;
			switch (m_transType)
			{
			case KMoveType::Move:
				m_pCurrentShape->move(offset);
				break;
			case KMoveType::Top:
				m_pCurrentShape->moveTop(nowPos);
				break;
			case KMoveType::Bottom:
				m_pCurrentShape->moveBottom(nowPos);
				break;
			case KMoveType::Left:
				m_pCurrentShape->moveLeft(nowPos);
				break;
			case KMoveType::Right:
				m_pCurrentShape->moveRight(nowPos);
				break;
			case KMoveType::TopLeft:
				m_pCurrentShape->moveTopLeft(nowPos);
				break;
			case KMoveType::TopRight:
				m_pCurrentShape->moveTopRight(nowPos);
				break;
			case KMoveType::BottomRight:
				m_pCurrentShape->moveBottomRight(nowPos);
				break;
			case KMoveType::BottomLeft:
				m_pCurrentShape->moveBottomLeft(nowPos);
				break;
			default:
				break;
			}
			update();
			m_lastPos = nowPos;
		}
	}
	// ����ǻ�ͼ״̬
	else
	{
		if (m_isLPress)
		{
			if (m_isDrawing && m_pCurrentShape)
			{
				m_pCurrentShape->setEndPoint(nowPos);
				update();
			}
		}
	}
}

// ��д����ͷ��¼�
void KCanvas::mouseReleaseEvent(QMouseEvent *event)
{
	if (m_currentDrawFlag == KDrawFlag::NoneDrawFlag)
		return;
	if (m_currentDrawFlag == KDrawFlag::MouseDrawFlag)
	{
		if (event->button() == Qt::LeftButton)
		{
			m_isLPress = false;
			m_enableSelect = false;
		}
			
	}
	else
	{
		if (event->button() == Qt::LeftButton)
		{
			m_isLPress = false;
			if (m_isDrawing && m_pCurrentShape)
			{
				m_pCurrentShape->setEndPoint(event->pos());
				if (m_pCurrentShape->isShapeVaild())
					m_pShapeList->append(m_pCurrentShape);
				else
					delete m_pCurrentShape;
				m_pCurrentShape = nullptr;
				m_isDrawing = false;
				update();
			}
		}
	}
}

// ��ȡ��ǰ���λ�õ�ͼ��
KShape *KCanvas::getCurrentShape(QPointF pos)
{
	for (KShape *shape : *m_pShapeList)
	{
		if (shape->getShapeRect().contains(pos))
		{
			return shape;
		}
	}
	// û��ͼ�η��ؿ�
	return Q_NULLPTR;
}

QList<KShape*> *KCanvas::getShapeList()
{
	return m_pShapeList;
}

// ���û������
void KCanvas::setCanvasWidth(int width)
{
	m_canvasWidth = width;
	resize(m_canvasWidth, m_canvasHeight);
}

// ���û����߶�
void KCanvas::setCanvasHeight(int height)
{
	m_canvasHeight = height;
	resize(m_canvasWidth, m_canvasHeight);
}

// ���Ż���
void KCanvas::zoomCanvas(qreal scale)
{
	// ���Ż���
	resize(m_canvasWidth * scale, m_canvasHeight * scale);
	qreal shapeScale = KShapeParameter::getInstance()->getShapeScale();
	// ���Ż��������ͼ��
	for (auto shape : *m_pShapeList)
	{
		shape->setShapeScale(shapeScale);
	}
	update();
}

// ��ȡ�������
int KCanvas::getCanvasWidth()
{
	return m_canvasWidth;
}

// ��ȡ�����߶�
int KCanvas::getCanvasHeight()
{
	return m_canvasHeight;
}

// ��ջ���
void KCanvas::cleanCanvas()
{
	m_pShapeList->clear();
	m_isCleanCanvas = true;
	update();
}
