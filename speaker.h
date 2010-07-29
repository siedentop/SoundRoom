/*
(c) 2010 Christoph Siedentop, <christophsiedentop@gmail.com
*/

#ifndef SPEAKER_H
#define SPEAKER_H

#include <QObject>
#include <QtCore/QPoint>
#include <Eigen/Core>

#include "complex.h"

class Speaker // : public QObject TODO: Doesn't like QObject, what a pity.
{
// Q_OBJECT
public:
	Speaker(QPoint pos, double frequency = 430, double volume = 255, double phase_shift = 0.0);
	virtual ~Speaker();
	
	void setFrequency(double freq);
	Complex getSound(QPoint *point);
	QPoint getPosition();
	double getFrequency();

protected:
	QPoint m_pos;
	double m_frequency;
	double m_volume;
	double m_phase;
};

#endif // SPEAKER_H
