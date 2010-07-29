/*
(c) 2010 Christoph Siedentop, <christophsiedentop@gmail.com
*/

#ifndef SOUNDPOINT_H
#define SOUNDPOINT_H

#include <QObject>
#include <QPoint>
#include <QtGui/QGraphicsItem>

#include "speaker.h"


class SoundPoint : public QGraphicsItem
{
public: 
	SoundPoint(int x, int y, QList<Speaker> speakerlist);
	~SoundPoint();     
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget);
	
	double loudness;
private:
	QPoint* m_position;
	QColor *m_colour;
	void calculateColour(QList<Speaker> speakerlist);
};

#endif // SOUNDPOINT_H
