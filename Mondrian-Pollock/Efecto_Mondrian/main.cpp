#include <QtGui/QApplication>
#include "VentanaInicio.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VentanaInicio w;
    w.show();

    return a.exec();
}
