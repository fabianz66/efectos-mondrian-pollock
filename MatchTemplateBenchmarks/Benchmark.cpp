#include "Benchmark.h"
#include <QDebug>

Benchmark::Benchmark(QObject *parent) :
    QObject(parent)
{
    this->proccesedImages = 0;
    this->skippedImages = 0;
    path = "files";
}

/** Singleton */

Benchmark& Benchmark::getInstance()
{
    static Benchmark instance;
    return instance;
}

/** General */

void Benchmark::saveAndRestart()
{
    this->stopTickCPU();
    this->stopTimer();
    this->stopProcessedImages();
    this->stopSkippedImages();
}

/** Para TIMER */

void Benchmark::startTimer()
{
    this->timer.start();
}

void Benchmark::markLapTimer()
{
    double elapsedMillis = timer.elapsed();
    this->totalElapsedTimes.append(elapsedMillis);
}

void Benchmark::stopTimer()
{
    QFile file_time(path + "_file_timer.csv");
    if (file_time.open(QFile::WriteOnly|QFile::Truncate))
    {
        QTextStream stream(&file_time);

        //Guarda todos los valores almacenados
        foreach(double time, this->totalElapsedTimes)
            stream << time << "\n";
        file_time.close();
    }
    this->totalElapsedTimes.clear();
}

/** TICKS  */

void Benchmark::startTickCPU()
{
    this->startTicks = static_cast<double>(cv::getCPUTickCount());
}

void Benchmark::markLapTickCPU()
{
    double elapsedTicks = static_cast<double>(cv::getCPUTickCount()) - this->startTicks;
    this->totalTicks.append(elapsedTicks);
}

void Benchmark::stopTickCPU()
{
    QFile file_CPU(path + "_file_CPU_ticks.csv");
    if (file_CPU.open(QFile::WriteOnly|QFile::Truncate))
    {
        QTextStream stream(&file_CPU);

        //Guarda todos los valores almacenados
        foreach(double ticks, this->totalTicks)
            stream << ticks << "\n";

        file_CPU.close();
    }
    this->totalTicks.clear();
}

/** Imagenes procesadas */

void Benchmark::addProccesedImage()
{
    this->proccesedImages++;
}

void Benchmark::stopProcessedImages()
{
    QFile file_images(path + "_file_imagenes_procesadas.csv");
    if (file_images.open(QFile::WriteOnly|QFile::Truncate))
    {
        QTextStream stream(&file_images);
        stream << this->proccesedImages << "\n";
        file_images.close();
    }
    this->proccesedImages = 0;
}

/** Imagenes recibidas */

void Benchmark::addSkippedImage()
{
    this->skippedImages++;
}

void Benchmark::stopSkippedImages()
{
    QFile file_images(path + "_file_imagenes_brincadas.csv");
    if (file_images.open(QFile::WriteOnly|QFile::Truncate))
    {
        QTextStream stream(&file_images);
        stream << this->skippedImages << "\n";
        file_images.close();
    }
    this->skippedImages = 0;
}

/** Path para guardar las imagenes */

void Benchmark::setPath(QString pPath)
{
    this->path = pPath;
}
