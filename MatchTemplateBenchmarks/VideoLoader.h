#ifndef VideoLoader_H
#define VideoLoader_H

#include <opencv2/opencv.hpp>
#include <QThread>

using namespace cv;


class VideoLoader : public QThread
{
    Q_OBJECT

public:

    /** Metodos */
    VideoLoader();
    bool startCaptureFromCamera();
    bool startCaptureFromVideo();

private:

    /** Atributos */
    VideoCapture mVideoCap;

    /** Metodos */
    void run();
    void notifyWithFrame();

signals:
    void onNewImageCaptured(Mat&);
};

#endif // VideoLoader_H
