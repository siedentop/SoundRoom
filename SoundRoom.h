#ifndef SoundRoom_H
#define SoundRoom_H

#include <QtCore/QObject>

class SoundRoom : public QObject
{
Q_OBJECT
public:
    SoundRoom();
    virtual ~SoundRoom();
};

#endif // SoundRoom_H
