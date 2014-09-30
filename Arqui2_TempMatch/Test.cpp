#include "Test.h"

Test::Test()
{
}

void Test::onNewImageCaptured(Mat &capturedImage)
{
    namedWindow("video", 1);
    imshow("video", capturedImage);
}
