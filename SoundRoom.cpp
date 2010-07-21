#include <stdio.h>
#include <QtGui/QPainter>

#include "SoundRoom.h"

SoundRoom::SoundRoom()
{
	this->resize(300, 300);
	//TODO make non-resizable!
	m_origin = QPoint(0, height()/2); //! Origin is on lefthand side in the middle
	
	m_speakerlist << Speaker(QPoint(10,0));
}


SoundRoom::~SoundRoom()
{}

void SoundRoom::paintEvent(QPaintEvent* )
{
	drawSpeaker(&m_speakerlist.first());
	
	
	QPoint point(QPoint(60, -30));
	shadePoint(&point);
}

//! Shades a point. @param point Point to be shaded.
void SoundRoom::shadePoint(QPoint* point)
{
	QPainter painter(this);
	
	painter.translate(m_origin); 
		
	painter.setBrush(Qt::black);
	
	painter.translate(*point);
	painter.drawRect(-4, -4, 8, 8);
}

//! Draws a speaker. @param speaker Speaker to be drawn.
void SoundRoom::drawSpeaker(Speaker* speaker)
{
	QPainter painter(this);
	
	painter.translate(m_origin);
		
	painter.setBrush(Qt::red);
	
	painter.translate(speaker->m_pos);
	painter.drawRect(-4, -4, 8, 8);
}
#include "SoundRoom.moc"
