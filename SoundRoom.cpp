#include <stdio.h>

#include "SoundRoom.h"

SoundRoom::SoundRoom()
{
	this->resize(300, 300);
	m_speakerlist << QPoint(0,0);
}

SoundRoom::~SoundRoom()
{}

#include "SoundRoom.moc"
