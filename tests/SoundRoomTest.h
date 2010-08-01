/*
(c) 2010 Christoph Siedentop, <christophsiedentop@gmail.com
*/

#ifndef SOUNDROOMTEST_H
#define SOUNDROOMTEST_H

#include <SoundRoom.h>
#include <QtCore/QObject>

class SoundRoomTest : public QObject
{
Q_OBJECT
private slots:
	void initTestCase();
	void init();
	void cleanup();
	void cleanupTestCase();

	void testSuperClass();
	void testSize(); //! Assert that passing of size to soundroom has correct effect.
	void testPixel(); //! Assert that pixels have the correct colour
	void testPixel_data();
	void testSpeakerlist(); //! Test that there is at least one speaker
};

#endif // SOUNDROOMTEST_H

