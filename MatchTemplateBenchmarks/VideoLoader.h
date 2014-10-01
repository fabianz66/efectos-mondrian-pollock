#ifndef VideoLoader_H
#define VideoLoader_H

/**
 * Sirve para manejar la toma de imagenes ya sea de camara o de video.
 * Las imagenes se reciben por medio de signals.
 * REF: http://www.qtcentre.org/wiki/index.php?title=MyThread.h
 *
 * Ejemplo de uso:
 *
 * #include "opencv2/opencv.hpp"
 * #include "VideoLoader.h"
 *
 * using namespace cv;
 *
 * VideoLoader* vl = new VideoLoader();
 * qRegisterMetaType< cv::Mat >("Mat");
 * connect(vl, SIGNAL(onNewImageCaptured(Mat)), this, SLOT(imgReceived(Mat)));
 * vl->startCaptureFromVideo();
 *
 * Donde imgReceived es un slot de la clase que llama.
 *
 **/

#include <opencv2/opencv.hpp>
#include <QThread>
#include <QTimer>

using namespace cv;

class VideoLoader : public QThread
{

    Q_OBJECT
public:

    /** Metodos */
    VideoLoader();
    bool startCaptureFromCamera();
    bool startCaptureFromVideo();
    void stop();

signals:
    void onNewImageCaptured(Mat);

private:

    /** Atributos */
    VideoCapture mVideoCap;
    bool mRunning;

    /** Metodos */
    void run();

private slots:
    void notifyWithFrame();
};

#endif // VideoLoader_H
