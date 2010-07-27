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
	QTest::newRow("30 deg") << 5.0 << asin(0.6) << 4.0 << 3.0;
}

//! Make sure that a phasor can be created. 
void ComplexTest::createPhasor()
{
	QFETCH(double, absolute);
	QFETCH(double, argument);
	QFETCH(double, real);
	QFETCH(double, imag);
	
	Complex c = *Complex::createPhasor(absolute, argument);

	// Fuzzy compare for doubles is not fuzzy enough. So 1e-^^7 != 0 --> tests would not pass. Now they do.
	if (real == 0)
		QVERIFY(abs(c.real()) < 0.0000001);
	else
		QCOMPARE(c.real(), real);
	if (imag == 0)
		QVERIFY(abs(c.imag()) < 0.0000001);
	else
		QCOMPARE(c.imag(), imag);
}

//! Assert that an empty Complex can be created and is instantiated to (0, 0i)
void ComplexTest::createEmpty()
{
	Complex c;
	QCOMPARE(c.real(), 0.0);
	QCOMPARE(c.imag(), 0.0);
}

//! Assert that standard complex can be created. 
void ComplexTest::createStandard()
{
	Complex c(12.0, 13.0);
	QCOMPARE(c.real(), 12.0);
	QCOMPARE(c.imag(), 13.0);
}

QTEST_MAIN(ComplexTest)
#include "ComplexTest.moc"