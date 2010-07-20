#include <QtGui/QApplication>
#include "SoundRoom.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    SoundRoom widget;
    widget.show();
    return app.exec();
}
