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

private slots:
	void setupMatrix();
	void setResetButtonEnabled();
	void zoomOut();
	void zoomIn();
	void resetView();
	
private:
	QGraphicsView *m_graphicsView;
	QSlider *zoomSlider;
	QToolButton *resetButton;
	
};

#endif // SoundRoom_H
