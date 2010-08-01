/*
(c) 2010 Christoph Siedentop, <christophsiedentop@gmail.com
*/

#ifndef SOUNDROOM_H
#define SOUNDROOM_H

#include <QObject>
#include <qgraphicsscene.h>
#include "speaker.h"

// #ifdef TEST
#include "tests/SoundRoomTest.h"
// #endif


class SoundRoom : public QGraphicsScene
{
public: 
	SoundRoom(QSize size = QSize(10, 10));
	QPixmap *getPixmap();
	QRgb calculateColour(QPoint *position);
	
protected:
	QImage m_image;
	QList<Speaker> m_speakers;
	QSize m_size;
	QPixmap m_pixmap;
	
// #ifdef TEST //TODO: make sure this really works. (also see above!)
private: 
	friend class SoundRoomTest;
// #endif 
};

#endif // SOUNDROOM_H
