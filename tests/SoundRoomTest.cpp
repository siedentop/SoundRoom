#include "SoundRoomTest.h"
#include <QtTest/QTest>

#include <stdio.h>

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

QTEST_MAIN(SoundRoomTest)
#include "SoundRoomTest.moc"
