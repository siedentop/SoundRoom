/*
(c) 2010 Christoph Siedentop, <christophsiedentop@gmail.com
*/

#include "speaker.h"

Speaker::Speaker(QPoint pos) : m_pos(pos)
{
}


Speaker::~Speaker()
{
}


void Speaker::setFrequency(double freq)
{
	m_frequency = freq;
}


