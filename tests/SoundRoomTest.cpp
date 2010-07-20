#include "SoundRoomTest.h"
#include <QtTest/QTest>

#include <stdio.h>

void SoundRoomTest::initTestCase()
{}

void SoundRoomTest::init()
{
	m_uut = new SoundRoom();
}

void SoundRoomTest::cleanup()
{
	delete m_uut;
}

void SoundRoomTest::cleanupTestCase()
{}

//! Test that SoundRoom inherits from QWidget
void SoundRoomTest::testSuperClass()
{
	QString name = m_uut->metaObject()->superClass()->className();
	QCOMPARE(name, QString("QWidget"));
}


QTEST_MAIN(SoundRoomTest)
#include "SoundRoomTest.moc"
