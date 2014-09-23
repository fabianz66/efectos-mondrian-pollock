#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include "parallel_process.h"
#include "QElapsedTimer"
#include "QDebug"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));



    cv::Mat img, img2, out, out2;
    img = cvLoadImage("Imagenes/city_night.jpeg");
    img2 = cvLoadImage("Imagenes/city_night.jpeg");
    out.create(img.size(), img.type());
    out2.create(img2.size(), img2.type());

    QElapsedTimer timer;
    qint64 nanoSec, nanoSec2;
    timer.start();

    //Lo hace todo en un solo hilo
    cv::threshold(img2,out2,66,255,1);
    nanoSec = timer.nsecsElapsed();
    qDebug() << nanoSec;

    timer.restart();

    // create 8 threads and use TBB
    cv::parallel_for_(cv::Range(0, 8), Parallel_process(img, out, 5, 8));

    nanoSec2 = timer.nsecsElapsed();
    qDebug() << nanoSec - nanoSec2;

    cv::imshow("image", out2);
    cv::imshow("blur", out);

    return app->exec();
}
