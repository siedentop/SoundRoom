#include "SoundRoomTest.h"
#include <QtTest/QTest>

#include <stdio.h>

#include "../speaker.h"

void SoundRoomTest::initTestCase()
{
	m_uut = new SoundRoom();
}

void SoundRoomTest::init()
{
}

void SoundRoomTest::cleanup()
{
}

void SoundRoomTest::cleanupTestCase()
{
	delete m_uut;
}

//! Test that SoundRoom inherits from QWidget
void SoundRoomTest::testSuperClass()
{
	QString name = m_uut->metaObject()->superClass()->className();
	QCOMPARE(name, QString("QWidget"));
}

//! Assert that size of window is 300px times 300px.
void SoundRoomTest::testWindowSize()
{
	QCOMPARE(m_uut->size(), QSize(300, 300));
}

//! Test that one speaker exists at position (10, 0)
void SoundRoomTest::testSpeaker()
{
	Speaker s(QPoint(160, 150));
	QCOMPARE(s.getPosition(), QPoint(160, 150));
}

//! Give speaker a frequency of 440Hz
void SoundRoomTest::testSpeakerfrequency()
{
	Speaker speaker(QPoint(160, 150), 430.0, 100);
	speaker.setFrequency(440.0);
	QCOMPARE(speaker.getFrequency(), 440.0);
}

void SoundRoomTest::bench_shadepoint()
{
	m_uut->show();
	
	QBENCHMARK
	{
		m_uut->repaint();
	}
	m_uut->close();
}


QTEST_MAIN(SoundRoomTest)
#include "SoundRoomTest.moc"
