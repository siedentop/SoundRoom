#ifndef View_H
#define View_H

#include <QWidget>
#include <QtCore/QList>
#include <QFrame>
#include <QGraphicsView>

#include "speaker.h"

QT_FORWARD_DECLARE_CLASS(QGraphicsView)
QT_FORWARD_DECLARE_CLASS(QLabel)
QT_FORWARD_DECLARE_CLASS(QSlider)
QT_FORWARD_DECLARE_CLASS(QToolButton)
 

class View : public QFrame
{
Q_OBJECT
public:
	View(QWidget *parent = 0);
	virtual ~View();
	
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

#endif // View_H
