#ifndef VideoLoader_H
#define VideoLoader_H

#include <opencv2/opencv.hpp>
#include <QThread>

using namespace cv;

/**
 * Sirve para manejar la toma de imagenes ya sea de camara o de video.
 * Las imagenes se reciben por medio de signals.
 *
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

class VideoLoader : public QThread
{

    Q_OBJECT
public:

    /** Metodos */
    VideoLoader();
    bool startCaptureFromCamera();
    bool startCaptureFromVideo();

signals:
    void onNewImageCaptured(Mat);

private:

    /** Atributos */
    VideoCapture mVideoCap;

    /** Metodos */
    void run();
    void notifyWithFrame();
};

#endif // VideoLoader_H
