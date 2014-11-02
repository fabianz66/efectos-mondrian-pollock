#include "VideoLoader.h"
#include "stdio.h"
#include "QElapsedTimer"
#include "QDebug"
#include "Constantes.h"
#include "Helpers.h"
#include "Paths.h"

VideoLoader::VideoLoader()
{
}

bool VideoLoader::startCaptureFromVideo()
{
    if(mVideoCap.isOpened()) {
        Helpers h;
        h.showAlertMessage("Error", "Video ya iniciado...");
        return false;
    }

    /** Intenta cargar el video */
    qDebug() <<" PATH: " << Paths::getInstance().getVideoPath();
    mVideoCap.open(Paths::getInstance().getVideoPath());
    if(!mVideoCap.isOpened())
    {
        Helpers h;
        h.showAlertMessage("Error", "Video no encontrado...");
        return false;
    }

    /** Como ya se cargo inicia un timer para que envie las imagenes al listener */
    mRunning = true;
    this->start();
    return true;
}

void VideoLoader::stop()
{
    mRunningMutex.lock();
    if(mRunning)
    {
        mRunning = false;
        if(mVideoCap.isOpened()) {
            mVideoCap.release();
        }
    }
    mRunningMutex.unlock();
}

/**
  * Este metodo corre cuando se llama this->start().
  * Llama notifyWithFrame() cada  DELAY_BETWEEN_FRAMES_MS
  */
void VideoLoader::run()
{
    QElapsedTimer timer;
    timer.start();

    while(mRunning)
    {
        if(timer.elapsed() >= DELAY_BETWEEN_FRAMES_MS)
        {
            mRunningMutex.lock();
            notifyWithFrame();
            mRunningMutex.unlock();
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
        if(frame.cols != 0 && frame.rows != 0)
        {
            //Notifica a quien este conectado
            emit onNewImageCaptured(frame);
            return;
        }
    }

    qDebug() << "FIN DE VIDEO";
    mRunning = false;
    if(mVideoCap.isOpened()) {
        mVideoCap.release();
    }
}
