#include <stdio.h>

#include <QtGui> 
#ifndef QT_NO_OPENGL
#include <QtOpenGL>
#endif

#include "SoundRoom.h"
#include "complex.h"
#include "SoundPoint.h"

SoundRoom::SoundRoom(QWidget *parent)
 : QFrame(parent)
{	//TODO: largely taken from Example under GPL. This should be replaced at some time.
	setFrameStyle(Sunken | StyledPanel);
	m_graphicsView = new QGraphicsView;

	int size = style()->pixelMetric(QStyle::PM_ToolBarIconSize);
	QSize iconSize(size, size);
	
	QToolButton *zoomInIcon = new QToolButton;
	zoomInIcon->setAutoRepeat(true);
	zoomInIcon->setAutoRepeatInterval(33);
	zoomInIcon->setAutoRepeatDelay(0);
	zoomInIcon->setIcon(QPixmap(":/zoomin.png")); //TODO: this should be done somehow...
	zoomInIcon->setIconSize(iconSize);
	QToolButton *zoomOutIcon = new QToolButton;
	zoomOutIcon->setAutoRepeat(true);
	zoomOutIcon->setAutoRepeatInterval(33);
	zoomOutIcon->setAutoRepeatDelay(0);
	zoomOutIcon->setIcon(QPixmap(":/zoomout.png"));
	zoomOutIcon->setIconSize(iconSize);
	zoomSlider = new QSlider;
	zoomSlider->setMinimum(0);
	zoomSlider->setMaximum(500);
	zoomSlider->setValue(250);
	zoomSlider->setTickPosition(QSlider::TicksRight);
	zoomSlider->setSingleStep(1);

	// Zoom slider layout
	QVBoxLayout *zoomSliderLayout = new QVBoxLayout;
	zoomSliderLayout->addWidget(zoomInIcon);
	zoomSliderLayout->addWidget(zoomSlider);
	zoomSliderLayout->addWidget(zoomOutIcon);

	resetButton = new QToolButton;
	resetButton->setText(tr("0"));
	resetButton->setEnabled(false);
	resetButton->setIconSize(iconSize);

	QGridLayout *topLayout = new QGridLayout;
	topLayout->addWidget(m_graphicsView, 0, 0);
	topLayout->addLayout(zoomSliderLayout, 0, 1);
	topLayout->addWidget(resetButton, 1, 0);
	setLayout(topLayout);
	
	// Enable OpenGl 
	#ifndef QT_NO_OPENGL
	qDebug() << "Opengl: " << QGLFormat::hasOpenGL() << "Version None: " << (QGLFormat::OpenGLVersionFlags() == QGLFormat::OpenGL_Version_None);
	QGLFormat fmt;
	fmt.setAlpha(true);
	m_graphicsView->setViewport(new QGLWidget(fmt)); 
	m_graphicsView->setCacheMode(QGraphicsView::CacheBackground);
/** @todo 
TODO: 
OpenGL doesn't seem to make a difference in speed (at least on my machine which is known to have OpenGL problems). 
However, when included it returns the following after closing the programm: 
do_wait: drmWaitVBlank returned -1, IRQs don't seem to be working correctly.
Try adjusting the vblank_mode configuration parameter.
*/
	#endif

	connect(resetButton, SIGNAL(clicked()), this, SLOT(resetView()));
	connect(zoomSlider, SIGNAL(valueChanged(int)), this, SLOT(setupMatrix()));
	connect(m_graphicsView->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(setResetButtonEnabled()));
	connect(m_graphicsView->horizontalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(setResetButtonEnabled()));
	connect(zoomInIcon, SIGNAL(clicked()), this, SLOT(zoomIn()));
	connect(zoomOutIcon, SIGNAL(clicked()), this, SLOT(zoomOut()));

	setupMatrix();
}

SoundRoom::~SoundRoom()
{}

//! Set ups view according to set scale.
void SoundRoom::setupMatrix()
{
	qreal scale = qPow(qreal(2), (zoomSlider->value() - 250) / qreal(50));

	QMatrix matrix;
	matrix.scale(scale, scale);

	m_graphicsView->setMatrix(matrix);
	setResetButtonEnabled();
}

//! Zooms in a single step.
void SoundRoom::zoomIn()
{
	zoomSlider->setValue(zoomSlider->value() + zoomSlider->singleStep());
}

//! Zooms out a single step.
void SoundRoom::zoomOut()
{
	zoomSlider->setValue(zoomSlider->value() - zoomSlider->singleStep());
}

//! Resets view.
void SoundRoom::resetView()
{
	zoomSlider->setValue(250);
	resetButton->setEnabled(false);
	setupMatrix();
	
	//TODO: Ensure we haven't moved to the wrong place (centre must be visible)
}


//! Enables the Reset Button. TODO: Taken from Example.
void SoundRoom::setResetButtonEnabled()
{
	resetButton->setEnabled(true);
}

QGraphicsView *SoundRoom::view() const
{
	return m_graphicsView;
}

#include "SoundRoom.moc"
