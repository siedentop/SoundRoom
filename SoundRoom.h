#ifndef SoundRoom_H
#define SoundRoom_H

#include <QWidget>
#include <QtCore/QList>

#include "speaker.h"

class SoundRoom : public QWidget
{
Q_OBJECT
public:
	SoundRoom();
	virtual ~SoundRoom();
	virtual void paintEvent(QPaintEvent* );
	
	QList<Speaker> m_speakerlist;
};

#endif // SoundRoom_H
