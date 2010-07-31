/*
(c) 2010 Christoph Siedentop, <christophsiedentop@gmail.com
*/
#include "SoundRoomTest.h"
#include <QtTest/QTest>

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

QTEST_MAIN(SoundRoomTest)
#include "SoundRoomTest.moc"
