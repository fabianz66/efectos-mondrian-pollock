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
    int size;
    int diff;

public:
    MatchTemplateTBB(cv::Mat inputImage, cv::Mat templ, cv::Mat& outImage, int sizeVal, int diffVal)
        : mOriginal(inputImage), mTemplate(templ), mResult(outImage), size(sizeVal), diff(diffVal) {

        //        namedWindow("template",1);
        //        imshow("template", mTemplate);

    }

    virtual void operator()(const cv::Range& range) const
    {
        for(int i = range.start; i < range.end; i++)
        {
            /// divide image in 'diff' number of parts and process simultaneously

            cv::Mat in(mOriginal, cv::Rect(0, (mOriginal.rows/diff)*i, mOriginal.cols, mOriginal.rows/diff));
            cv::Mat out(mResult, cv::Rect(0, (mResult.rows/diff)*i, mResult.cols, mResult.rows/diff));

            /// ========== LOGICA MATCH_TEMPLATE NORMAL =============== ///

            /// Realiza el match template
            matchTemplate( in, mTemplate, out, MATCH_METHOD );
            normalize( out, out, 0, 1, NORM_MINMAX, -1, cv::Mat() );

            /// Una vez realizado el match template por la imagen se busca el mejor match en la imagen completa
            /// Localizing the best match with minMaxLoc
            double minVal; double maxVal; Point minLoc; Point maxLoc; Point matchLoc;
            minMaxLoc( out, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );

            /// For SQDIFF and SQDIFF_NORMED, the best matches are lower values. For all the other methods, the higher the better
            if( MATCH_METHOD  == CV_TM_SQDIFF || MATCH_METHOD == CV_TM_SQDIFF_NORMED )
            { matchLoc = minLoc; }
            else
            { matchLoc = maxLoc; }

            /// Show me what you got
            rectangle( out, matchLoc, Point( matchLoc.x + mTemplate.cols , matchLoc.y + mTemplate.rows ), Scalar::all(0), 2, 8, 0 );

            /// ========== LOGICA MATCH_TEMPLATE NORMAL =============== ///
            //            cv::threshold(in,out,66,255,1);
        }


        qDebug() << "PARALLEL";
        //        /// Una vez realizado el match template por la imagen se busca el mejor match en la imagen completa
        //        /// Localizing the best match with minMaxLoc
        //        double minVal; double maxVal; Point minLoc; Point maxLoc; Point matchLoc;
        //        minMaxLoc( mResult, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );

        //        /// For SQDIFF and SQDIFF_NORMED, the best matches are lower values. For all the other methods, the higher the better
        //        if( MATCH_METHOD  == CV_TM_SQDIFF || MATCH_METHOD == CV_TM_SQDIFF_NORMED )
        //        { matchLoc = minLoc; }
        //        else
        //        { matchLoc = maxLoc; }

        //        /// Show me what you got
        //        rectangle( mResult, matchLoc, Point( matchLoc.x + mTemplate.cols , matchLoc.y + mTemplate.rows ), Scalar::all(0), 2, 8, 0 );
    }
};
