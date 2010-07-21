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
	Speaker(QPoint pos, double frequency = 430, double volume = 11);
	virtual ~Speaker();
	
	void setFrequency(double freq);
	Complex getSound(); //make complex<double>
	QPoint getPosition();
	double getFrequency();

protected:
	QPoint m_pos;
	double m_frequency;
	double m_volume;
};

#endif // SPEAKER_H
