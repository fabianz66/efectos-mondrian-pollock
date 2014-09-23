#ifndef PARALLEL_PROCESS_H
#define PARALLEL_PROCESS_H

#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <opencv/cxcore.h>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

class Parallel_process : public cv::ParallelLoopBody
{

private:
    cv::Mat img;
    cv::Mat& retVal;
    int size;
    int diff;

public:
    Parallel_process(cv::Mat inputImgage, cv::Mat& outImage,
                     int sizeVal, int diffVal)
        : img(inputImgage), retVal(outImage),
          size(sizeVal), diff(diffVal){}

    virtual void operator()(const cv::Range& range) const
    {
        for(int i = range.start; i < range.end; i++)
        {
            /* divide image in 'diff' number
                    of parts and process simultaneously */

            cv::Mat in(img, cv::Rect(0, (img.rows/diff)*i,
                                     img.cols, img.rows/diff));
            cv::Mat out(retVal, cv::Rect(0, (retVal.rows/diff)*i,
                                         retVal.cols, retVal.rows/diff));

//            cv::Canny(in,out,1,2);
            cv::threshold(in,out,66,255,1);
//            cv::GaussianBlur(in, out, cv::Size(size, size), 0);
        }
    }
};

#endif // PARALLEL_PROCESS_H
