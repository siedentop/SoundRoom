/*
(c) 2010 Christoph Siedentop, <christophsiedentop@gmail.com
*/

#include "MainWindow.h"
#include "SoundRoom.h"

#include <QtGui>

MainWindow::MainWindow(QWidget *parent)
 : QWidget(parent)
{
//      populateScene();

	m_scene = new QGraphicsScene;

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

#include "MainWindow.moc"