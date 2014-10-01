#include "VideoLoader.h"
#include "stdio.h"
#include "QElapsedTimer"
#include "QDebug"
#include "Constantes.h"
#include "Helpers.h"

VideoLoader::VideoLoader()
{
}

bool VideoLoader::startCaptureFromCamera()
{
    if(mVideoCap.isOpened()) {

        Helpers h;
        h.showAlertMessage("Error", "Camara ya iniciada...");
        return false;
    }

    /** Intenta cargar el video */
    mVideoCap.open(-1);
    if(!mVideoCap.isOpened())
    {
        Helpers h;
        h.showAlertMessage("Error", "Camara no se pudo iniciar...");
        return false;
    }

    /** Como ya se cargo inicia un timer para que envie las imagenes al listener */
    mRunning = true;
    this->start();
    return true;
}

bool VideoLoader::startCaptureFromVideo()
{
    if(mVideoCap.isOpened()) {
        Helpers h;
        h.showAlertMessage("Error", "Video ya iniciado...");
        return false;
    }

    /** Intenta cargar el video */
    mVideoCap.open("resources/video3.mp4");
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
    if(mRunning)
    {
        mRunning = false;

        if(mVideoCap.isOpened()) {
            mVideoCap.release();
        }
    }
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
    }else
    {
        mRunning = false;
        mVideoCap.release();
    }
}
