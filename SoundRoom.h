#ifndef SoundRoom_H
#define SoundRoom_H

#include <QWidget>
#include <QtCore/QList>
#include <QFrame>
#include <QGraphicsView>

#include "speaker.h"

QT_FORWARD_DECLARE_CLASS(QGraphicsView)
QT_FORWARD_DECLARE_CLASS(QLabel)
QT_FORWARD_DECLARE_CLASS(QSlider)
QT_FORWARD_DECLARE_CLASS(QToolButton)
 

class SoundRoom : public QFrame
{
Q_OBJECT
public:
	SoundRoom(QWidget *parent = 0);
	virtual ~SoundRoom();
	
	QGraphicsView *view() const;
	virtual void paintEvent(QPaintEvent* );
	
	QList<Speaker> m_speakerlist;
	QPoint m_origin;

private slots:
	void setupMatrix();
	void setResetButtonEnabled();
	void zoomOut();
	void zoomIn();
	
private:
	void drawSpeaker(Speaker* speaker);
	void shadePoint(QPoint* point);
	QGraphicsView *m_graphicsView;
	QSlider *zoomSlider;
	QToolButton *resetButton;
	
};

#endif // SoundRoom_H
