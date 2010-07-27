/*
(c) 2010 Christoph Siedentop, <christophsiedentop@gmail.com
*/

#include "ComplexTest.h"
#include <QtTest/QTest>
#include <math.h>


#include "../complex.h"

void ComplexTest::initTestCase()
{
}

void ComplexTest::init()
{
}

void ComplexTest::cleanup()
{
}


void ComplexTest::cleanupTestCase()
{
}

void ComplexTest::createPhasor_data()
{
	QTest::addColumn<double>("absolute");
	QTest::addColumn<double>("argument");
	QTest::addColumn<double>("real");
	QTest::addColumn<double>("imag");
	
	QTest::newRow("very simple") << 0.0 << 0.0 << 0.0 << 0.0;
	QTest::newRow("simple") << 1.0 << 0.0 << 1.0 << 0.0;
	QTest::newRow("+90 deg") << 1.0 << M_PI/2 << 0.0 << 1.0;
	QTest::newRow("-90 deg") << 1.0 << -M_PI/2 << 0.0 << -1.0;
	QTest::newRow("30 deg") << 5.0 << M_PI/6 << 4.0 << 3.0;
}

//! Make sure that a phasor can be created. 
void ComplexTest::createPhasor()
{
	QFETCH(double, absolute);
	QFETCH(double, argument);
	QFETCH(double, real);
	QFETCH(double, imag);
	
	Complex c;
	c = c.createPhasor(absolute, argument);
// 	c.createPhasor(absolute, argument);
	

	QCOMPARE(c.real(), real);
	QCOMPARE(c.imag(), imag);
}

//! Assert that an empty Complex can be created and is instantiated to (0, 0i)
void ComplexTest::createEmpty()
{
	Complex c;
	QCOMPARE(c.real(), 0.0);
	QCOMPARE(c.imag(), 0.0);
	
}

QTEST_MAIN(ComplexTest)
#include "ComplexTest.moc"