/*
(c) 2010 Christoph Siedentop, <christophsiedentop@gmail.com
*/

#include "SoundPoint.h"
#include "speaker.h"
#include <qpainter.h>


SoundPoint::SoundPoint(int x, int y, QList<Speaker> speakerlist)
{
// 	this->setPosition(x, y);
	m_position = new QPoint(x, y);
	calculateColour(speakerlist);
}

QRectF SoundPoint::boundingRect() const
{
	return QRectF(0, 0, 1, 1);
}


SoundPoint::~SoundPoint()
{
}

void SoundPoint::calculateColour(QList<Speaker> speakerlist)
{
	Complex local_volume;
	int num_speakers = speakerlist.count();
	foreach(Speaker speaker, speakerlist)
	{
		local_volume += speaker.getSound(m_position);
	}
	
	// m_colour = QColor(0, 0, 255, abs(local_volume.real())/num_speakers); <--- Calculation costly but looks nice.

	m_colour = new QColor(Qt::blue);
	m_colour->darker(local_volume.real()/num_speakers + 100);
}

void SoundPoint::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->fillRect(QRectF(0, 0, 1, 1), *m_colour);
}

#include "SoundPoint.moc"