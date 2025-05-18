#include "kshapefactory.h"

KShapeFactory::KShapeFactory(QObject *parent)
	: QObject(parent)
{
}

KShapeFactory::~KShapeFactory()
{
}

KShape *KShapeFactory::createShape(KCanvas::KDrawFlag drawFlag)
{
	switch (drawFlag)
	{
	case KCanvas::KDrawFlag::LineDrawFlag:
		return new KLine;
	case KCanvas::KDrawFlag::CircleDrawFlag:
		return new KCircle;
	case KCanvas::KDrawFlag::RectDrawFlag:
		return new KRect;
	case KCanvas::KDrawFlag::PentagonDrawFlag:
		return new KPentagon;
	case KCanvas::KDrawFlag::HexagonDrawFlag:
		return new KHexagon;
	case KCanvas::KDrawFlag::PentagramDrawFlag:
		return new KPentagram;
	case KCanvas::KDrawFlag::EllipseDrawFlag:   
		return new KEllipse;  // –¬‘ˆÕ÷‘≤
	default:
		break;
	}
	return Q_NULLPTR;
}

KShape* KShapeFactory::createShape(KShapeType type)
{
	switch (type) {
	case KShapeType::LineShapeType:      return new KLine();
	case KShapeType::CircleShapeType:    return new KCircle();
	case KShapeType::RectShapeType:      return new KRect();
	case KShapeType::PentagonShapeType:  return new KPentagon();
	case KShapeType::HexagonShapeType:   return new KHexagon();
	case KShapeType::PentagramShapeType: return new KPentagram();
	default: return nullptr;
	}
 }
