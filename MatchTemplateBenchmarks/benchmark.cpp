#include "benchmark.h"
#include <QDebug>

Benchmark::Benchmark(QObject *parent) :
    QObject(parent)
{
    skip = 0;
    taked = 0;

    QFile file_time("files/file_time.csv");
    if (file_time.open(QFile::WriteOnly|QFile::Truncate))
    {
      QTextStream stream(&file_time);
      stream << "Metodo" << "\t" << "Tiempo" << "\n";
      file_time.close();
    }


    QFile file_CPU("files/file_CPU.csv");
    if (file_CPU.open(QFile::WriteOnly|QFile::Truncate))
    {
      QTextStream stream(&file_CPU);
      stream << "Metodo" << "\t" << "CPU" << "\n";
      file_CPU.close();
    }

    QFile file_images("files/file_images.csv");
    if (file_images.open(QFile::WriteOnly|QFile::Truncate))
    {
      QTextStream stream(&file_images);
      stream << "Metodo" << "\t" << "skip"<< "\t" << "procesado" << "\n";
      file_images.close();
    }
}

Benchmark& Benchmark::getInstance()
{
    static Benchmark instance;
    return instance;
}

void Benchmark::startTime()
{
    this->timer.start();
}

void Benchmark::startTickCPU()
{
    this->duration = static_cast<double>(cv::getCPUTickCount());
}

void Benchmark::stopTime(QString pMethod)
{
    QFile file_time("files/file_time.csv");
    if (file_time.open(QFile::WriteOnly|QFile::Append))
    {
      QTextStream stream(&file_time);
      stream << pMethod << "\t" << timer.nsecsElapsed() << "\n";
      file_time.close();
    }

    //qDebug() << "El timepo que duro el proceso " << pMethod << ": " << timer.nsecsElapsed();
}

void Benchmark::stopTickCPU(QString pMethod)
{
    duration = static_cast<double>(cv::getCPUTickCount()) - duration;

    QFile file_CPU("files/file_CPU.csv");
    if (file_CPU.open(QFile::WriteOnly|QFile::Append))
    {
      QTextStream stream(&file_CPU);
      stream << pMethod << "\t" << timer.nsecsElapsed() << "\n";
      file_CPU.close();
    }

    //qDebug() << "El tick CPU de " << pMethod << ": " << duration;
}

void Benchmark::setSkipImage(QString pMethod)
{
    skip++;

    QFile file_images("files/file_images.csv");
    if (file_images.open(QFile::WriteOnly|QFile::Truncate))
    {
      QTextStream stream(&file_images);
      stream << "Metodo" << "\t" << "skip"<< "\t" << "procesado" << "\n";
      stream << pMethod << "\t" << skip << "\t"<< taked << "\n";
      file_images.close();
    }
}

void Benchmark::setGetImage(QString pMethod)
{
    taked++;

    QFile file_images("files/file_images.csv");
    if (file_images.open(QFile::WriteOnly|QFile::Truncate))
    {
      QTextStream stream(&file_images);
      stream << "Metodo" << "\t" << "skip"<< "\t" << "procesado" << "\n";
      stream << pMethod << "\t" << skip << "\t"<< taked << "\n";
      file_images.close();
    }
}
