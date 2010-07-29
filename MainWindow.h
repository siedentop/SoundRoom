/*
(c) 2010 Christoph Siedentop, <christophsiedentop@gmail.com
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/qwidget.h>
#include "speaker.h"

QT_FORWARD_DECLARE_CLASS(QGraphicsScene)
QT_FORWARD_DECLARE_CLASS(QGraphicsView)
QT_FORWARD_DECLARE_CLASS(QLabel)
QT_FORWARD_DECLARE_CLASS(QSlider)
QT_FORWARD_DECLARE_CLASS(QSplitter)

class MainWindow : public QWidget
{
Q_OBJECT
public: 
	MainWindow(QWidget* parent = 0);
	~MainWindow();
private:
	QGraphicsScene *m_scene;
	void populateScene();
	QList<Speaker> m_speakerlist;
};

#endif // MAINWINDOW_H

