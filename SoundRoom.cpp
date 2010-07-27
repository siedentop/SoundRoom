#include <stdio.h>
// #include <math.h>
// #include <complex.h>

#include <QtGui/QPainter>
#include <QtGui/QColormap>

#include <Eigen/Core>

#include "SoundRoom.h"
#include "complex.h"

SoundRoom::SoundRoom()
{
	this->resize(300, 300); //TODO: Make non-resizable
	m_origin = QPoint(0, height()/2); //! Origin is on lefthand side in the middle
	//! @note: All points are to be relative to m_origin!
	
	m_speakerlist << Speaker(QPoint(10,0) + m_origin, 440, 255);
}


SoundRoom::~SoundRoom()
{}

void SoundRoom::paintEvent(QPaintEvent* )
{
	
	
	int x, y;
	int x_max = width();
	int y_max = height();
	for(x=0; x<x_max; x +=3)
	{
		for(y=0; y<y_max; y +=3)
		{
			shadePoint(new QPoint(x, y)); 
		}
	}
	
	drawSpeaker(&m_speakerlist.first());
}

//! Shades a point. @param point Point to be shaded.
void SoundRoom::shadePoint(QPoint* point)
{
	QPainter painter(this);
	
	QColor colour(Qt::blue);
	
// 	painter.translate(m_origin); 
	
	Complex local_volume;
	foreach(Speaker speaker, m_speakerlist)
	{
		local_volume += speaker.getSound(*point);
	}
	
	QColor intensity(0, 0, 160, abs(local_volume.real()));
	painter.setPen(intensity);
	
	painter.drawPoint(*point);
}

//! Draws a speaker. @param speaker Speaker to be drawn.
void SoundRoom::drawSpeaker(Speaker* speaker)
{
	QPainter painter(this);

	painter.setBrush(Qt::red);
	
	painter.translate(speaker->getPosition());
	painter.drawRect(-4, -4, 8, 8); // Not really centred!
}
#include "SoundRoom.moc"
