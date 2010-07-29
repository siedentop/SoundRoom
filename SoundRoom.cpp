#include <stdio.h>

#include <QtGui>

#include "SoundRoom.h"
#include "complex.h"
#include "SoundPoint.h"

SoundRoom::SoundRoom(QWidget *parent)
 : QFrame(parent)
{	//TODO: largely taken from Example under GPL. This should be replaced at some time.
	setFrameStyle(Sunken | StyledPanel);
	m_graphicsView = new QGraphicsView;
	m_graphicsView->setRenderHint(QPainter::Antialiasing, false);
	m_graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
	m_graphicsView->setOptimizationFlags(QGraphicsView::DontSavePainterState);
	m_graphicsView->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
	
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

	QGridLayout *topLayout = new QGridLayout;
	topLayout->addWidget(m_graphicsView, 0, 0);
	topLayout->addLayout(zoomSliderLayout, 0, 1);
	topLayout->addWidget(resetButton, 1, 0);
	setLayout(topLayout);

	connect(resetButton, SIGNAL(clicked()), this, SLOT(resetView()));
	connect(zoomSlider, SIGNAL(valueChanged(int)), this, SLOT(setupMatrix()));
	connect(m_graphicsView->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(setResetButtonEnabled()));
	connect(m_graphicsView->horizontalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(setResetButtonEnabled()));
	connect(zoomInIcon, SIGNAL(clicked()), this, SLOT(zoomIn()));
	connect(zoomOutIcon, SIGNAL(clicked()), this, SLOT(zoomOut()));

	setupMatrix();

	
	m_origin = QPoint(width()/2, height()/2); //! Origin is on lefthand side in the middle
	//! @note: All points are to be relative to m_origin!
	
	for (int i= 0; i< 20; ++i)
	{
		m_speakerlist << Speaker(QPoint(10,(int)(i*19.5)) + m_origin, 440, 255, i*M_PI/6);
	}
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
	zoomSlider.setValue(zoomSlider->value() + zoomSlider->singleStep());
}

//! Zooms out a single step.
void SoundRoom::zoomOut()
{
	zoomSlider.setValue(zoomSlider->value() - zoomSlider->singleStep());
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

void SoundRoom::paintEvent(QPaintEvent* )
{
	int x, y;
	int dx = 1;
	int x_max = width();
	int y_max = height();
	for(x=0; x<x_max; x +=dx)
	{
		for(y=0; y<y_max; y +=dx)
		{
			shadePoint(new QPoint(x, y)); 
		}
	}
	
	foreach(Speaker speaker, m_speakerlist)
	{
		drawSpeaker(&speaker);
	}
}

//! Shades a point. @param point Point to be shaded.
void SoundRoom::shadePoint(QPoint* point)
{
	QPainter painter(this);
	
	Complex local_volume;
	int num_speakers = m_speakerlist.count();
	foreach(Speaker speaker, m_speakerlist)
	{
		local_volume += speaker.getSound(*point);
	}
	
// 	QColor intensity(0, 0, 255, abs(local_volume.real())/num_speakers); <--- Calculation costly but looks more pretty.
	QColor intensity(Qt::blue);
	painter.setPen(intensity.darker(local_volume.real()/num_speakers + 100));

	painter.drawPoint(*point);
}

//! Draws a speaker. @param speaker Speaker to be drawn.
void SoundRoom::drawSpeaker(Speaker* speaker)
{
	QPainter painter(this);

	painter.setBrush(Qt::red);
	
	painter.translate(speaker->getPosition());
	painter.drawRect(-4, -4, 8, 8);
}


QGraphicsView *SoundRoom::view() const
{
	return m_graphicsView;
}
#include "SoundRoom.moc"
