#include "VideoLoader.h"
#include "stdio.h"


#define CAMERA_NUM -1
#define FRAMES_PER_SECOND 25

VideoLoader::VideoLoader()
{

}

bool VideoLoader::startCaptureFromCamera(VideoLoaderListener* listener, QObject* sender)
{
    if(listener == NULL)
        return false;

    return false;
}

bool VideoLoader::startCaptureFromVideo(VideoLoaderListener* listener, Mainwi* sender)
{
    qDebug() << "1";
    if(listener == NULL) {
        printf( "\nListener no encontrado... startCaptureFromVideo\n\n" );
        return false;
    }

    qDebug() << "2";
    if(mVideoCap.isOpened()) {
        printf( "\nVideo ya iniciado... startCaptureFromVideo\n\n" );
        return false;
    }

    /** Intenta cargar el video */
    mVideoCap.open("resources/video3.mp4");
    if(!mVideoCap.isOpened())
    {
        printf( "\nVideo no encontrado... startCaptureFromVideo\n\n" );
        return false;
    }

    /** Como ya se cargo inicia un timer para que envie las imagenes al listener */
    mListener = listener;
    mNotifyTimer = new QTimer(sender);
    connect(mNotifyTimer, SIGNAL(timeout()), sender, SLOT(notifyWithFrame()));
    mNotifyTimer->start(FRAMES_PER_SECOND);
    return true;
}

void VideoLoader::notifyWithFrame()
{
    qDebug() << "A";
    if(mListener != NULL)
    {
        qDebug() << "B";
        Mat frame;
        if(mVideoCap.grab())
        {
            mVideoCap >> frame;
            mListener->onNewImageCaptured(frame);
            return;
        }
    }
}
