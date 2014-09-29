#include "videoloader.h"
#include "stdio.h"
#include <opencv2/opencv.hpp>

using namespace cv;

videoLoader::videoLoader()
{

}

bool videoLoader::startVideoCapture()
{
    VideoCapture cap;
    cap.open("resources/video3.mp4");
    if(cap.isOpened())
    {
        Mat videoFrame;
        namedWindow("Video",1);
        while(1)
        {
            if(cap.grab())
            {
                printf("HOLA");
                cap >> videoFrame;
                imshow("Video", videoFrame);

                waitKey(100);
            }
        }
    }else {
        printf( "\nVideo no encontrado!!\n\n" );
    }

    return cap.isOpened();
}
