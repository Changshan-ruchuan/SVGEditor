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
	setMouseTracking(true);
	setFocusPolicy(Qt::ClickFocus);
	this->setAttribute(Qt::WA_Hover, true);
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
			if (m_pCurrentShape->getShapeType() == KShapeType::PentagramShapeType)
				return QWidget::eventFilter(watched, event);
			if (m_currentDrawFlag == KDrawFlag::MouseDrawFlag)
			{
				QHoverEvent *e = static_cast<QHoverEvent*>(event);
				int controlPos = m_pCurrentShape->getControlRectIndex(e->pos());
				switch (controlPos)
				{
				case 0:	
					setCursor(Qt::SizeFDiagCursor);
					break;
				case 1:	
					setCursor(Qt::SizeVerCursor);
					break;
				case 2:	
					setCursor(Qt::SizeBDiagCursor);
					break;
				case 3:	
					setCursor(Qt::SizeHorCursor);
					break;
				case 4:	
					setCursor(Qt::SizeFDiagCursor);
					break;
				case 5:	
					setCursor(Qt::SizeVerCursor);
					break;
				case 6:	
					setCursor(Qt::SizeBDiagCursor);
					break;
				case 7:	
					setCursor(Qt::SizeHorCursor);
					break;
				default:
					setCursor(Qt::ArrowCursor);
					break;
				}
			}
		}
	}
	return QWidget::eventFilter(watched, event);
}


void KCanvas::paintEvent(QPaintEvent *event)
{
	if (!m_pShapeList->isEmpty())
	{
		for (QList<KShape*>::iterator it = m_pShapeList->begin();
			it != m_pShapeList->end(); ++it)
			(*it)->drawShape(this);
	}
	else if(m_isCleanCanvas)	
	{
		return;
	}
	if (m_pCurrentShape)
	{
		if (m_currentDrawFlag == KDrawFlag::MouseDrawFlag)
		{
			if (m_pCurrentShape->getShapeType() == KShapeType::PentagramShapeType)
				m_pCurrentShape->drawSelectedHighlight(this, false);
			else
				m_pCurrentShape->drawSelectedHighlight(this, true);
		}
		else
		{
			if (m_currentDrawFlag != KDrawFlag::RectDrawFlag)
				m_pCurrentShape->drawShape(this);
			m_pCurrentShape->drawOutline(this);
		}
	}
}


void KCanvas::mousePressEvent(QMouseEvent *event)
{
	qreal scale = KShapeParameter::getInstance()->getShapeScale();
	if (scale != 1.0)
	{
		QMessageBox::warning(this, QStringLiteral("警告"), QStringLiteral("请先恢复缩放比例为1.0再进行操作"));
		return;
	}
	m_currentDrawFlag = KShapeParameter::getInstance()->getDrawFlag();
	if (m_currentDrawFlag == KDrawFlag::NoneDrawFlag)
		return;
	m_lastPos = event->pos();	
	m_isCleanCanvas = false;	
	if (m_currentDrawFlag == KDrawFlag::MouseDrawFlag)
	{
		
		if (event->buttons() == Qt::LeftButton)
		{
			m_isLPress = true;	
			KShape *shape = getCurrentShape(m_lastPos);
			if (shape)
			{
				m_pCurrentShape = shape;
				int controlPos = m_pCurrentShape->getControlRectIndex(event->pos());
				switch (controlPos)
				{
				case 0:	
					m_transType = KMoveType::TopLeft;
					break;
				case 1:	
					m_transType = KMoveType::Top;
					break;
				case 2:	
					m_transType = KMoveType::TopRight;
					break;
				case 3:	
					m_transType = KMoveType::Right;
					break;
				case 4:	
					m_transType = KMoveType::BottomRight;
					break;
				case 5:	
					m_transType = KMoveType::Bottom;
					break;
				case 6:	
					m_transType = KMoveType::BottomLeft;
					break;
				case 7:	
					m_transType = KMoveType::Left;
					break;
				default:	
					m_transType = KMoveType::Move;
					break;
				}
				m_enableSelect = true;
				KShapeParameter::getInstance()->setCurrentShape(m_pCurrentShape);
				emit shapeSelected(true);
				int width = m_pCurrentShape->getBorderWidth();
				emit currentShapeBorderWidth(width);
				Qt::PenStyle style = m_pCurrentShape->getBorderStyle();
				emit currentShapeBorderStyle(style);
				QRgb rgb = m_pCurrentShape->getBorderColor();
				emit currntShapeBorderColor(rgb);
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
			m_isLPress = true;	
			m_pCurrentShape = KShapeFactory::createShape(m_currentDrawFlag);
			m_pCurrentShape->setStartPoint(m_lastPos);
			m_pCurrentShape->setEndPoint(m_lastPos);
			m_isDrawing = true;	
		}
	}
}


void KCanvas::mouseMoveEvent(QMouseEvent *event)
{
	if (m_currentDrawFlag == KDrawFlag::NoneDrawFlag)
		return;
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


KShape *KCanvas::getCurrentShape(QPointF pos)
{
	for (KShape *shape : *m_pShapeList)
	{
		if (shape->getShapeRect().contains(pos))
		{
			return shape;
		}
	}
	return Q_NULLPTR;
}

QList<KShape*> *KCanvas::getShapeList()
{
	return m_pShapeList;
}


void KCanvas::setCanvasWidth(int width)
{
	m_canvasWidth = width;
	resize(m_canvasWidth, m_canvasHeight);
}


void KCanvas::setCanvasHeight(int height)
{
	m_canvasHeight = height;
	resize(m_canvasWidth, m_canvasHeight);
}


void KCanvas::zoomCanvas(qreal scale)
{
	resize(m_canvasWidth * scale, m_canvasHeight * scale);
	qreal shapeScale = KShapeParameter::getInstance()->getShapeScale();
	for (auto shape : *m_pShapeList)
	{
		shape->setShapeScale(shapeScale);
	}
	update();
}


int KCanvas::getCanvasWidth()
{
	return m_canvasWidth;
}


int KCanvas::getCanvasHeight()
{
	return m_canvasHeight;
}


void KCanvas::cleanCanvas()
{
	m_pShapeList->clear();
	m_isCleanCanvas = true;
	update();
}
