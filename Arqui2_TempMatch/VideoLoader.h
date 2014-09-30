#ifndef VideoLoader_H
#define VideoLoader_H

#include <VideoLoaderListener.h>
#include <opencv2/opencv.hpp>
#include <QTimer>

using namespace cv;

class VideoLoader : QObject
{
private:
    VideoCapture mVideoCap;
    QTimer *mNotifyTimer;
    VideoLoaderListener *mListener;

public:
    VideoLoader();
    bool startCaptureFromCamera(VideoLoaderListener* listener, QObject* sender);
    bool startCaptureFromVideo(VideoLoaderListener* listener, QObject *sender);

private slots:
    void notifyWithFrame();
};

#endif // VideoLoader_H
