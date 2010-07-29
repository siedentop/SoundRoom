/*
(c) 2010 Christoph Siedentop, <christophsiedentop@gmail.com
*/

#ifndef SOUNDPOINTTEST_H
#define SOUNDPOINTTEST_H

#include <QObject>
#include <SoundPoint.h>


class SoundPointTest : public QObject
{
Q_OBJECT
private slots:
	void initTestCase();
	void init();
	void cleanup();
	void cleanupTestCase();
	
	//! Make sure it can be created like a QPoint. 
	void test_position(); 
	void test_position_data();
	
	//! Assert that loudness can be set. 
	void test_setLoudness();
	
	//! Assert that loudness can be read.
	void test_getLoudness();
};

#endif // SOUNDPOINTTEST_H
