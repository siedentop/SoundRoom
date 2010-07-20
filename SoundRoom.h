#ifndef SoundRoom_H
#define SoundRoom_H

#include <QWidget>

class SoundRoom : public QWidget
{
Q_OBJECT
public:
	SoundRoom();
	virtual ~SoundRoom();
	
	QList<QPoint> m_speakerlist;
};

#endif // SoundRoom_H
