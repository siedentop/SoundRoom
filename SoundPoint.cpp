/*
(c) 2010 Christoph Siedentop, <christophsiedentop@gmail.com
*/

#include "SoundPoint.h"
#include "speaker.h"
#include <qpainter.h>

#include <QDebug>


SoundPoint::SoundPoint(int x, int y, int dx, int dy)
{
// 	this->setPosition(x, y);
	m_position = new QPoint(x, y);
	m_rect = new QRectF(0, 0, dx, dy);
}

QRectF SoundPoint::boundingRect() const
{
	return *m_rect;
}


SoundPoint::~SoundPoint()
{
}

void SoundPoint::calculateColour(QList< Speaker >* speakerlist)
{
	Complex local_volume;
	int num_speakers = speakerlist->count();
	foreach(Speaker speaker, *speakerlist)
	{
		local_volume += speaker.getSound(m_position);
	}
	
// 	qDebug() << "Loudness: " << local_volume.real() << "Nums: " << num_speakers;
	m_colour = new QColor(0, 0, 255, abs(local_volume.real())/num_speakers); //TODO <--- Calculation costly but looks nice.

// 	m_colour = new QColor(Qt::blue);
// // 	m_colour->darker(local_volume.real()/num_speakers + 100);
// 	m_colour->darker(80);
}

void SoundPoint::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->fillRect(*m_rect, *m_colour);
}

#include "SoundPoint.moc"