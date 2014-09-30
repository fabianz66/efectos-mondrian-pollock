
#include <stdio.h>
#include "VideoLoader.h"
#include "Test.h"

int main( int argc, const char* argv[] )
{

    Test* t = new Test();
    VideoLoader* vl = new VideoLoader();
    vl->startCaptureFromVideo(t);

    while(1)
    {}

    return 0;
}
