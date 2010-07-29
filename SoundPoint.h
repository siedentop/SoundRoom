/*
(c) 2010 Christoph Siedentop, <christophsiedentop@gmail.com
*/

#ifndef SOUNDPOINT_H
#define SOUNDPOINT_H

#include <QObject>
#include <QPoint>


class SoundPoint : public QObject, public QPoint
{
Q_OBJECT
public: 
	SoundPoint(int x, int y);
	~SoundPoint();
	
	double loudness;
};

#endif // SOUNDPOINT_H
