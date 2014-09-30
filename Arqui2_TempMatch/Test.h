#ifndef TEST_H
#define TEST_H

#include "VideoLoaderListener.h"
#include <opencv2/opencv.hpp>

using namespace cv;

class Test : public VideoLoaderListener
{
public:
    Test();
    void onNewImageCaptured(Mat &capturedImage);
};

#endif // TEST_H
