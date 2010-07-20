#include <stdio.h>
#include <QtGui/QPainter>

#include "SoundRoom.h"

SoundRoom::SoundRoom()
{
	this->resize(300, 300);
	m_speakerlist << Speaker(QPoint(10,0));
}


SoundRoom::~SoundRoom()
{}

//Show speaker
void SoundRoom::paintEvent(QPaintEvent* )
{
	QPainter painter(this);

	painter.translate(QPoint(0, height()/2)); //! Origin is on lefthand side in the middle
		
	painter.setBrush(Qt::red);
	
	painter.translate(m_speakerlist.first().m_pos);
	painter.drawRect(-4, -4, 8, 8);
}
#include "SoundRoom.moc"
