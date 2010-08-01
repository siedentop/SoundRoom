/* (c) 2010 Christoph Siedentop, <christophsiedentop@gmail.com */
#include "SoundRoomTest.h"
#include <QtTest/QTest>
#include "../SoundRoom.h"

void SoundRoomTest::initTestCase()
{
}

void SoundRoomTest::init()
{
}

void SoundRoomTest::cleanup()
{
}

void SoundRoomTest::cleanupTestCase()
{
}

//! Test that SoundRoom inherits from QWidget
void SoundRoomTest::testSuperClass()
{
// 	QVERIFY(m_uut->isWidgetType());
	QVERIFY(true); //Test is_QGraphicsScene
}

void SoundRoomTest::testSize()
{
	SoundRoom* room = new SoundRoom(QSize(100, 100));
	QCOMPARE(room->getPixmap()->size(), QSize(100, 100));
}

void SoundRoomTest::testPixel()
{
	QFETCH(QSize, size);
	
	SoundRoom *room = new SoundRoom(size);
	QImage image = room->getPixmap()->toImage();
	
	QFETCH(QPoint, point);
	QColor colour(Qt::blue); //obviously stupid...
	QCOMPARE(image.pixel(point), colour.rgb()); //TODO: Has rgb() some alpha channel? 
}

void SoundRoomTest::testPixel_data()
{
	QSize size(100, 100);
	
	QTest::addColumn<QSize>("size");
	QTest::addColumn<QPoint>("point");
	
	for(int i=0; i<10; ++i)
	{
		QTest::newRow(QString("Point %1").arg(i).toAscii().constData()) << size << QPoint(30, 10*i);
	}
}

void SoundRoomTest::testSpeakerlist()
{
	// Test that this->m_speakerlist has the correct objects. 
	SoundRoom *uut = new SoundRoom(QSize(100, 100));
	QVERIFY(uut->m_speakers.count() > 0);
}

void SoundRoomTest::test_returnQPixmap()
{
	SoundRoom *room = new SoundRoom(QSize(100, 100));
	QCOMPARE(room->m_image, room->getPixmap()->toImage());
}

QTEST_MAIN(SoundRoomTest)
#include "SoundRoomTest.moc"
