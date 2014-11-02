#include <QtGui/QApplication>
#include "MainWindow.h"
#include "Paths.h"

int main(int argc, char *argv[])
{
    //Toma el video del input del usuario
    if(argc > 0) {
        Paths::getInstance().setVideoPath(argv[1]);
    }

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
