#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <QObject>
#include <QElapsedTimer>
#include <QString>
#include <opencv2/opencv.hpp>
#include <QFile>
#include <QList>

using namespace cv;

class Benchmark : public QObject
{
    Q_OBJECT
public:

    /** Singleton */
    static Benchmark& getInstance();

    /** General */
    void saveAndRestart();

    /** Para el tiempo */
    void startTimer();
    void markLapTimer();
    void stopTimer();

   /** Para los ticks */
    void startTickCPU();
    void markLapTickCPU();
    void stopTickCPU();

    /** Para imagenes recibidas / procesadas */
    void addProccesedImage();
    void stopProcessedImages();

    void addSkippedImage();
    void stopSkippedImages();

    /** Ruta donde se van a guardar los archivos*/
    void setPath(QString pPath);

private:
    explicit Benchmark(QObject *parent = 0);

    QElapsedTimer timer;
    QString path;
    int skippedImages;
    int proccesedImages;
    double startTicks;
    QList<double> totalTicks;
    QList<double> totalElapsedTimes;

};

#endif // BENCHMARK_H
