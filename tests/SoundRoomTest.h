/*
(c) 2010 Christoph Siedentop, <christophsiedentop@gmail.com
*/

#ifndef SOUNDROOMTEST_H
#define SOUNDROOMTEST_H

#include <SoundRoom.h>
#include <QtCore/QObject>

class SoundRoomTest : public SoundRoom
{
Q_OBJECT
private slots:
	void initTestCase();
	void init();
	void cleanup();
	void cleanupTestCase();

	void testSuperClass();

};

#endif // SOUNDROOMTEST_H

