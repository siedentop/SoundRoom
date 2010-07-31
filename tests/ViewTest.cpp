#include "ViewTest.h"
#include <QtTest/QTest>

#include <stdio.h>

#include "../speaker.h"

void ViewTest::initTestCase()
{
	m_uut = new View();
}

void ViewTest::init()
{
}

void ViewTest::cleanup()
{
}

void ViewTest::cleanupTestCase()
{
	delete m_uut;
}

//! Test that SoundRoom inherits from QWidget
void ViewTest::testSuperClass()
{
	QVERIFY(m_uut->isWidgetType());
}

//! Assert that size of window is 300px times 300px.
void ViewTest::testWindowSize()
{
	QCOMPARE(m_uut->size(), QSize(640, 480));
}

//! Test that one speaker exists at position (10, 0)
void ViewTest::testSpeaker()
{
	Speaker s(QPoint(160, 150));
	QCOMPARE(s.getPosition(), QPoint(160, 150));
}

//! Give speaker a frequency of 440Hz
void ViewTest::testSpeakerfrequency()
{
	Speaker speaker(QPoint(160, 150), 430.0, 100);
	speaker.setFrequency(440.0);
	QCOMPARE(speaker.getFrequency(), 440.0);
}

void ViewTest::bench_shadepoint()
{
	m_uut->show();
	
	QBENCHMARK
	{
		m_uut->repaint(); //TODO: Check that this test still makes sense?!
	}
	m_uut->close();
}


QTEST_MAIN(ViewTest)
#include "ViewTest.moc"
