/*
(c) 2010 Christoph Siedentop, <christophsiedentop@gmail.com
*/

#include "MainWindow.h"
#include "SoundRoom.h"
#include "SoundPoint.h"

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
	
	for (int i= 0; i< 20; ++i)
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
			SoundPoint *item = new SoundPoint(x, y, dx, dy);
			item->setPos(QPointF(x, y)); //? TODO ???
			item->calculateColour(&m_speakerlist);
			m_scene->addItem(item);
		}
	}
}

// void SoundRoom::paintEvent(QPaintEvent* )
// {
// 	int x, y;
// 	int dx = 1;
// 	int x_max = width();
// 	int y_max = height();
// 	for(x=0; x<x_max; x +=dx)
// 	{
// 		for(y=0; y<y_max; y +=dx)
// 		{
// 			shadePoint(new QPoint(x, y)); 
// 		}
// 	}
// 	
// 	foreach(Speaker speaker, m_speakerlist)
// 	{
// 		drawSpeaker(&speaker);
// 	}
// }

//! Shades a point. @param point Point to be shaded.
// void MainWindow::shadePoint(QPoint* point)
// {
// 	QPainter painter(this);
// 	
// 	Complex local_volume;
// 	int num_speakers = m_speakerlist.count();
// 	foreach(Speaker speaker, m_speakerlist)
// 	{
// 		local_volume += speaker.getSound(*point);
// 	}
// 	
// // 	QColor intensity(0, 0, 255, abs(local_volume.real())/num_speakers); <--- Calculation costly but looks more pretty.
// 	QColor intensity(Qt::blue);
// 	painter.setPen(intensity.darker(local_volume.real()/num_speakers + 100));
// 
// 	painter.drawPoint(*point);
// }



#include "MainWindow.moc"