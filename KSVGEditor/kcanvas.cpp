#include "kcanvas.h"
#include "kshapefactory.h"
#include "kshapeparameter.h"
#include <QWheelEvent>
#include <QContextMenuEvent> 

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
	setFocusPolicy(Qt::StrongFocus); 
	this->setAttribute(Qt::WA_Hover, true);
	this->installEventFilter(this);
}

KCanvas::~KCanvas()
{
	if (m_copiedShape) delete m_copiedShape;
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

void KCanvas::contextMenuEvent(QContextMenuEvent* event) {
	if (m_currentDrawFlag == KDrawFlag::MouseDrawFlag) {
		QPoint pos = event->pos();
		KShape* shape = getCurrentShape(pos);
		if (shape) {
			m_pCurrentShape = shape;
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
			int index = m_pShapeList->indexOf(m_pCurrentShape);
			bool isTop = (index == m_pShapeList->size() - 1);   
			bool isBottom = (index == 0);                       
			QMenu menu(this);
			QAction* moveTopAction = menu.addAction("moveToTopLayer");
			moveTopAction->setEnabled(!isTop); 
			QAction* moveBottomAction = menu.addAction("moveToBottomLayer");
			moveBottomAction->setEnabled(!isBottom); 
			QAction* moveUpAction = menu.addAction("moveUpOneLayer");
			moveUpAction->setEnabled(index > 0); 
			QAction* moveDownAction = menu.addAction("moveDownOneLayer");
			moveDownAction->setEnabled(index < m_pShapeList->size() - 1); 
			connect(moveTopAction, &QAction::triggered, this, &KCanvas::moveToTopLayer);
			connect(moveBottomAction, &QAction::triggered, this, &KCanvas::moveToBottomLayer);
			connect(moveUpAction, &QAction::triggered, this, &KCanvas::moveUpOneLayer);
			connect(moveDownAction, &QAction::triggered, this, &KCanvas::moveDownOneLayer);
			menu.exec(event->globalPos());
		}
	}
	event->accept();
}


void KCanvas::moveToTopLayer() {
	if (!m_pCurrentShape || m_pShapeList->isEmpty()) return;
	int index = m_pShapeList->indexOf(m_pCurrentShape);
	if (index != -1 && index != m_pShapeList->size() - 1) {
		m_pShapeList->removeAt(index);
		m_pShapeList->append(m_pCurrentShape);
		update(); 
	}
}


void KCanvas::moveToBottomLayer() {
	if (!m_pCurrentShape || m_pShapeList->isEmpty()) return;
	int index = m_pShapeList->indexOf(m_pCurrentShape);
	if (index != -1 && index != 0) {
		m_pShapeList->removeAt(index);
		m_pShapeList->prepend(m_pCurrentShape);
		update(); 
	}
}


void KCanvas::moveUpOneLayer() {
	if (!m_pCurrentShape || m_pShapeList->isEmpty()) return;
	int index = m_pShapeList->indexOf(m_pCurrentShape);
	if (index > 0) {
		m_pShapeList->swap(index, index - 1);
		update();
	}
}


void KCanvas::moveDownOneLayer() {
	if (!m_pCurrentShape || m_pShapeList->isEmpty()) return;
	int index = m_pShapeList->indexOf(m_pCurrentShape);
	if (index < m_pShapeList->size() - 1) {
		m_pShapeList->swap(index, index + 1);
		update(); 
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
		if (m_enableSelect && m_isLPress)
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
			m_transType = KMoveType::None; 
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

void KCanvas::wheelEvent(QWheelEvent* event)
{
	qint16 delta = event->angleDelta().y();
	if (delta == 0) {
		event->ignore();
		return;
	}
	qreal currentScale = KShapeParameter::getInstance()->getCanvasScale();
	qreal scaleFactor = (delta > 0) ? 1.1 : 0.9;
	qreal newScale = currentScale * scaleFactor;
	newScale = qBound(0.1, newScale, 5.0);
	emit canvasZoomRequested(newScale);
	event->accept();
}

void KCanvas::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Delete)
	{
		if (m_pCurrentShape
			&& m_currentDrawFlag == KDrawFlag::MouseDrawFlag
			&& m_enableSelect)
		{
			if (m_pShapeList->contains(m_pCurrentShape))
			{
				m_pShapeList->removeOne(m_pCurrentShape);
			}
			delete m_pCurrentShape;
			m_pCurrentShape = nullptr;
			KShapeParameter::getInstance()->setCurrentShape(nullptr);
			m_isSelected = false;
			m_enableSelect = false;  
			emit shapeSelected(false);
			update();
		}
	}
	else if (event->modifiers() == Qt::ControlModifier)
	{
		if (event->key() == Qt::Key_C) {        
			copySelectedShape();
		}
		else if (event->key() == Qt::Key_V) { 
			pasteCopiedShape();
		}
	}
	QWidget::keyPressEvent(event);
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


void KCanvas::copySelectedShape() {
	if (!m_pCurrentShape || m_currentDrawFlag != KDrawFlag::MouseDrawFlag) return;
	if (m_copiedShape) delete m_copiedShape;
	KShapeType type = m_pCurrentShape->getShapeType();
	m_copiedShape = KShapeFactory::createShape(type);
	if (!m_copiedShape) return;
	m_copiedShape->setStartPoint(m_pCurrentShape->getStartPoint());
	m_copiedShape->setEndPoint(m_pCurrentShape->getEndPoint());
	m_copiedShape->setBorderWidth(m_pCurrentShape->getBorderWidth());
	m_copiedShape->setBorderStyle(m_pCurrentShape->getBorderStyle());
	m_copiedShape->setBorderColor(m_pCurrentShape->getBorderColor());
	m_copiedShape->setShapeColor(m_pCurrentShape->getShapeColor());
	m_copiedShape->setShapeScale(m_pCurrentShape->getShapeScale());
}


void KCanvas::pasteCopiedShape() {
	if (!m_copiedShape) return;
	KShape* pastedShape = KShapeFactory::createShape(m_copiedShape->getShapeType());
	if (!pastedShape) return;
	pastedShape->setStartPoint(m_copiedShape->getStartPoint());
	pastedShape->setEndPoint(m_copiedShape->getEndPoint());
	pastedShape->setBorderWidth(m_copiedShape->getBorderWidth());
	pastedShape->setBorderStyle(m_copiedShape->getBorderStyle());
	pastedShape->setBorderColor(m_copiedShape->getBorderColor());
	pastedShape->setShapeColor(m_copiedShape->getShapeColor());
	pastedShape->setShapeScale(m_copiedShape->getShapeScale());
	QPointF offset(10, 10); 
	pastedShape->move(offset);
	m_pShapeList->append(pastedShape);
	update();
}