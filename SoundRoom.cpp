/*
(c) 2010 Christoph Siedentop, <christophsiedentop@gmail.com
*/

#include "SoundRoom.h"


SoundRoom::SoundRoom (QSize size ) : m_size(size)
{	
	QPoint origin(0, 300); //! Origin is in the middle
	//! @note: All points are to be relative to origin!
	
	for (int i= 0; i< 30; ++i)
	{
		m_speakers << Speaker(QPoint(10,(int)(i*19.5)) + origin, 440, 255, i*M_PI/6);
	}
	
	m_image = QImage(size, QImage::Format_ARGB32);
	
// 	m_image.setColor(1, Qt::blue);
	
	int x_max = size.width();
	int y_max = size.height();
	for(int x=0; x<x_max; ++x)
	{
		for(int y=0; y<y_max; ++y)
		{
			QPoint point(x, y);
			m_image.setPixel(point, QColor(Qt::blue).rgb());
// 			m_image.setPixel(point, calculateColour(&point));
		}
	}
	foreach(Speaker speaker, m_speakers)
	{
// 		m_scene->addItem (drawSpeaker(&speaker)); //TODO
	}
	
	m_pixmap = QPixmap::fromImage(m_image); // = QPixmap::fromImage(m_image);
	this->addPixmap(m_pixmap);
}

QPixmap* SoundRoom::getPixmap()
{
	return &m_pixmap;
}

QRgb SoundRoom::calculateColour(QPoint *position)
{
	Complex local_volume;
	int num_speakers = m_speakers.count();
	foreach(Speaker speaker, m_speakers)
	{
		local_volume += speaker.getSound(position);
	}
	
	return QColor(0, 0, 255, abs(local_volume.real())/num_speakers).rgb(); //TODO <--- Calculation costly but looks nice.
}
