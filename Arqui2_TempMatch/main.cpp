
#include <stdio.h>
#include "videoloader.h"

int main( int argc, const char* argv[] )
{
    videoLoader* loader = new videoLoader();
    loader->startVideoCapture();
}
