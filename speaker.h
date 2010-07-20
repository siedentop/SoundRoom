/*
(c) 2010 Christoph Siedentop, <christophsiedentop@gmail.com
*/

#ifndef SPEAKER_H
#define SPEAKER_H

#include <QObject>
#include <QtCore/QPoint>


class Speaker // : public QObject TODO: Doesn't like QObject, what a pity.
{
// Q_OBJECT
public:
	Speaker(QPoint pos);
	virtual ~Speaker();
	
	void setFrequency(double freq);
	
	QPoint m_pos;
	double m_frequency;
};

#endif // SPEAKER_H
