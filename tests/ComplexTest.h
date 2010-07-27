/*
(c) 2010 Christoph Siedentop, <christophsiedentop@gmail.com
*/

#ifndef COMPLEXTEST_H
#define COMPLEXTEST_H

#include <QtCore/QObject>


class ComplexTest : public QObject
{
Q_OBJECT
private slots:
	void initTestCase();
	void init();
	void cleanup();
	void cleanupTestCase();
	
	void createPhasor_data();
	void createPhasor();
	void createEmpty();
	void createStandard();
	void test_operator_plus_equal();
};

#endif // COMPLEXTEST_H
