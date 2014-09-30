#include "VideoLoader.h"
#include "stdio.h"
#include "QElapsedTimer"
#include "QDebug"
#include "Constantes.h"

VideoLoader::VideoLoader()
{
}

bool VideoLoader::startCaptureFromCamera()
{
    mCamCapture = cvCreateCameraCapture(-1);
    if(!mCamCapture)
    {
        printf( "\nCamara no iniciada... startCaptureFromCamera\n\n" );
        return false;
    }

    /** Como ya se cargo inicia un timer para que envie las imagenes al listener */
    this->start();
    return true;
}

bool VideoLoader::startCaptureFromVideo()
{
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
    this->start();
    return true;
}

/**
  * Este metodo corre cuando se llama this->start().
  * Llama notifyWithFrame() cada  DELAY_BETWEEN_FRAMES_MS
  */
void VideoLoader::run()
{
    QElapsedTimer timer;
    timer.start();
    while(true)
    {
        if(timer.elapsed() >= DELAY_BETWEEN_FRAMES_MS)
        {
            notifyWithFrame();
            timer.restart();
        }
    }
}

/**
  * Se llama dentro de run().
  * Carga una nueva imagen del video / camara y notifica al listener
  */
void VideoLoader::notifyWithFrame()
{
    Mat frame;
    if(mVideoCap.grab())
    {
        mVideoCap >> frame;

        //Notifica a quien este conectado
        emit onNewImageCaptured(frame);
        return;
    }

    if(mCamCapture)
    {
        frame = cvQueryFrame(mCamCapture);

        //Notifica a quien este conectado
        emit onNewImageCaptured(frame);
        return;
    }
}
