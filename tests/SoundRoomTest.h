#ifndef SoundRoomTEST_H
#define SoundRoomTEST_H

#include <QtCore/QObject>
#include "../SoundRoom.h"

class SoundRoomTest : public QObject
{
Q_OBJECT
private slots:
    void initTestCase();
    void init();
    void cleanup();
    void cleanupTestCase();

    void testSuperClass();
    
protected:
	SoundRoom *m_uut;
};

#endif // SoundRoomTEST_H
