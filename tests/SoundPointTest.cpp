/*
(c) 2010 Christoph Siedentop, <christophsiedentop@gmail.com
*/
#include "SoundPointTest.h"
#include <QtTest/QTest>

#include "../SoundPoint.h"
#include "../speaker.h"

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

void SoundPointTest::test_position_data()
{
	//TODO
}

void SoundPointTest::test_position()
{
	QList<Speaker> speakerlist;
	SoundPoint uut(12, 11, speakerlist);

// 	printf("X: %d, Y: %d\n", uut.x(), uut.y());
	QCOMPARE(uut.x(), 12.0); //TODO: Test that uut.x() really returns a position not something else!
	QCOMPARE(uut.y(), 11.0);
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