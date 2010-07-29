/*
(c) 2010 Christoph Siedentop, <christophsiedentop@gmail.com
*/

#include "SoundPoint.h"
#include "speaker.h"


SoundPoint::SoundPoint(int x, int y, QList<Speaker> speakerlist)
{
// 	this->setPosition(x, y);
}

QRectF SoundPoint::boundingRect() const
{
	return QRectF(0, 0, 1, 1);
}


SoundPoint::~SoundPoint()
{
}


void SoundPoint::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(widget);

	QColor colour = Qt::blue; //TODO

//TODO paint some. 


}

#include "SoundPoint.moc"