#ifndef VIDEOLOADER_LISTENER_H
#define VIDEOLOADER_LISTENER_H

#include <opencv/cv.h>
#include <opencv2/opencv.hpp>

using namespace cv;

class VideoLoaderListener
{

public:
    virtual void onNewImageCaptured(Mat& capturedImage) = 0;

};

#endif // VIDEOLOADER_LISTENER_H
