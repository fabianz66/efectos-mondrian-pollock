#ifndef MATCHTEMPLATE_H
#define MATCHTEMPLATE_H

#include <opencv2/opencv.hpp>
#include <QThread>
#include "Benchmark.h"

using namespace cv;

/**
 *
 * Aqui esta el codigo fuente: https://github.com/Itseez/opencv/blob/master/modules/imgproc/src/templmatch.cpp
 * INTEL IPP : https://software.intel.com/en-us/articles/intel-integrated-performance-primitives-intel-ipp-open-source-computer-vision-library-opencv-faq
 * Intel IPP: https://software.intel.com/en-us/intel-ipp
 * Fast match template: http://opencv-code.com/tutorials/fast-template-matching-with-image-pyramid/
 * OpenCV con CUDA: http://on-demand.gputechconf.com/gtc/2013/webinar/opencv-gtc-express-shalini-gupta.pdf
 *
 **/

class MatchTemplate : public QThread
{

    Q_OBJECT
private:
    /// Atributos
    Benchmark *mBenchmark;
    Mat mOriginalImage;
    Mat mTemplateImg;
    int mMetodo;

    /// Metodos
    void normal();
    void tbb();
    void gpu();
    void run();

public:
    MatchTemplate();
    void normal( Mat original );
    void tbb( Mat original );
    void gpu( Mat original );

signals:
    void onMatchTemplateFinished(Mat);
};

#endif // MATCHTEMPLATE_H
