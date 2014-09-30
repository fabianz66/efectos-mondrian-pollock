#ifndef MATCHTEMPLATETBB_H
#define MATCHTEMPLATETBB_H

#endif // MATCHTEMPLATETBB_H

#include "Constantes.h"
#include <opencv2/opencv.hpp>
#include "QDebug"

using namespace cv;

/**
 *
 * Clase para el manejo del match_template utilizando TBB.
 *
 **/
class MatchTemplateTBB : public cv::ParallelLoopBody
{

private:
    cv::Mat mOriginal;
    cv::Mat mTemplate;
    cv::Mat& mResult;
    int mSubFrames;
    int mOriginalSubFrameHeight;
    int mResultSubFrameHeight;

public:
    MatchTemplateTBB(cv::Mat inputImage, cv::Mat& outImage , cv::Mat templ, int subFrames)
        : mOriginal(inputImage), mTemplate(templ), mResult(outImage), mSubFrames(subFrames) {

        mOriginalSubFrameHeight = inputImage.rows / (subFrames);
        mResultSubFrameHeight = outImage.rows / (subFrames);

    }

    virtual void operator()(const cv::Range& range) const
    {
        for(int i = range.start; i < range.end; i++)
        {
            /// divide image in 'diff' number of parts and process simultaneously
            cv::Mat in(mOriginal, cv::Rect(0, mOriginalSubFrameHeight*i, mOriginal.cols, mOriginalSubFrameHeight));
            cv::Mat out(mResult, Rect(0, mResultSubFrameHeight * i, mResult.cols, mResultSubFrameHeight));

            /// Realiza el match template
            matchTemplate( in, mTemplate, out, MATCH_METHOD );
            normalize( out, out, 0, 1, NORM_MINMAX, -1, cv::Mat() );
        }
    }
};
