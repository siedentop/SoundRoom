#include "SoundRoomTest.h"
#include <QtTest/QTest>



void SoundRoomTest::initTestCase()
{}

void SoundRoomTest::init()
{
	m_uut = new SoundRoom();
}

void SoundRoomTest::cleanup()
{}

void SoundRoomTest::cleanupTestCase()
{}

void SoundRoomTest::someTest()
{
    QCOMPARE(1,2);
}


QTEST_MAIN(SoundRoomTest)
#include "SoundRoomTest.moc"
