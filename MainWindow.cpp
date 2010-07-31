/*
(c) 2010 Christoph Siedentop, <christophsiedentop@gmail.com
*/

#include "MainWindow.h"
#include "SoundRoom.h"

#include <QtGui>

MainWindow::MainWindow(QWidget *parent)
 : QWidget(parent)
{
	populateScene();

	SoundRoom *view = new SoundRoom();
	view->view()->setScene(m_scene);

	QHBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(view);
	setLayout(layout);

	setWindowTitle(tr("Sound Room"));
}


MainWindow::~MainWindow()
{
}

void MainWindow::populateScene()
{
	m_scene = new QGraphicsScene;
	
	QPoint origin(0, 300); //! Origin is in the middle
	//! @note: All points are to be relative to origin!
	
	for (int i= 0; i< 30; ++i)
	{
		m_speakerlist << Speaker(QPoint(10,(int)(i*19.5)) + origin, 440, 255, i*M_PI/6);
	}
	
	int x, y;
	int dx = 2;
	int dy = 5;
	int x_max = 400;
	int y_max = 600;
	for(x=0; x<x_max; x +=dx)
	{
		for(y=0; y<y_max; y +=dy)
		{
		}
	}
	foreach(Speaker speaker, m_speakerlist)
	{
// 		m_scene->addItem (drawSpeaker(&speaker)); //TODO
	}
}

#include "MainWindow.moc"