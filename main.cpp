#include <QApplication>
#include "framelessmovewindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    FramelessMoveWindow framelessMoveWindow;
    framelessMoveWindow.show();

    return a.exec();
}
