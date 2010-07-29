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
	SoundPoint(int x, int y, int dx, int dy);
	~SoundPoint();     
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget);
	void calculateColour(QList<Speaker> *speakerlist);

private:
	QPoint* m_position;
	QColor *m_colour;
	const QRectF *m_rect;
};

#endif // SOUNDPOINT_H
