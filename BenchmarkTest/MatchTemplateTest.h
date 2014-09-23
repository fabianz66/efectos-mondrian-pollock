#ifndef MATCHTEMPLATETEST_H
#define MATCHTEMPLATETEST_H

#include <QtCore/QString>
#include <QtTest/QtTest>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/gpu/gpu.hpp"

using namespace std;
using namespace cv;

class MatchTemplateTest : public QObject
{
    Q_OBJECT

public:
    MatchTemplateTest();

private:
    //gpu::GpuMat imgGPU;
    //gpu::GpuMat templGPU;
    //gpu::GpuMat resultGPU;

    Mat img;
    Mat templ;
    Mat result;
    int match_method;

private Q_SLOTS:
    void BasicMatchTemplate();
    void ParallelMatchTemplate();
    void GPUMatchTemplate();
};

#endif // MATCHTEMPLATETEST_H
