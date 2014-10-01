#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <QObject>
#include <QElapsedTimer>
#include <QString>
#include <opencv2/opencv.hpp>
#include <QFile>

using namespace cv;

class Benchmark : public QObject
{
    Q_OBJECT
public:
    /** Singleton */
    static Benchmark& getInstance();

    void startTime();
    void stopTime(QString pMethod);
    void startTickCPU();
    void stopTickCPU(QString pMethod);
    void setSkipImage(QString pMethod);
    void setGetImage(QString pMethod);

private:
    explicit Benchmark(QObject *parent = 0);

    QElapsedTimer timer;
    int skip;
    int taked;
    double duration;

signals:

public slots:

};

#endif // BENCHMARK_H
