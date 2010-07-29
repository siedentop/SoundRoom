/*
(c) 2010 Christoph Siedentop, <christophsiedentop@gmail.com
*/
#include "SoundPointTest.h"
#include <QtTest/QTest>

#include "../SoundPoint.h"

#include <stdio.h>

void SoundPointTest::initTestCase()
{
}

void SoundPointTest::init()
{
}

void SoundPointTest::cleanup()
{
}

void SoundPointTest::cleanupTestCase()
{
}

void SoundPointTest::test_constructor_data()
{
	
}

void SoundPointTest::test_constructor()
{
	SoundPoint uut(12, 11);

// 	printf("X: %d, Y: %d\n", uut.x(), uut.y());
	QCOMPARE(uut.x(), 12);
	QCOMPARE(uut.y(), 11);
}

void SoundPointTest::test_setLoudness()
{
	QSKIP("Not Implemented.", SkipAll);
}
	
void SoundPointTest::test_getLoudness()
{
	QSKIP("Not Implemented.", SkipAll);
}



QTEST_MAIN(SoundPointTest)
#include "SoundPointTest.moc"