/*
(c) 2010 Christoph Siedentop, <christophsiedentop@gmail.com
*/

#include "speaker.h"

#define SOUNDSPEED 34300 //343m/s --> 34300cm/s

Speaker::Speaker(QPoint pos, double frequency, double volume, double phase_shift)
 : m_pos(pos), m_frequency(frequency), m_volume(volume), m_phase(phase_shift)
{
}


Speaker::~Speaker()
{
}


void Speaker::setFrequency(double frequency)
{
	m_frequency = frequency;
}

//! Returns position of speaker
QPoint Speaker::getPosition()
{
	return m_pos;
}

//! Returns frequency of speaker
double Speaker::getFrequency()
{
	return m_frequency;
}


//! Returns Phasor of Sound at a given point.
Complex Speaker::getSound(QPoint* point)
{
	QPoint p = m_pos - *point;
	double distance = sqrt(pow(p.x(), 2) + pow(p.y(), 2));
	double phase = 2 * M_PI * m_frequency * distance / SOUNDSPEED + m_phase;
	return *Complex::createPhasor(m_volume, phase);
}

//! Draws a speaker. @param speaker Speaker to be drawn.
/*void Speaker::paint(Speaker* speaker)
{
	QPainter painter(this);

	painter.setBrush(Qt::red);
	
	painter.translate(speaker->getPosition());
	painter.drawRect(-4, -4, 8, 8);
 }  */

#include "speaker.moc"
