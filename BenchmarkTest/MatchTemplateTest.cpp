#include "MatchTemplateTest.h"
#include "Parallel_process.h"
#include <iostream>
#include <stdio.h>

//Constructor
MatchTemplateTest::MatchTemplateTest()
{
    //Se cargan las imagenes
    img = imread( "imagen.png", 1 );
    templ = imread( "template.png", 1 );

    //GPU
    //imgGPU.upload(img);
    //templGPU.upload(templ);

    match_method = CV_TM_SQDIFF;
}

void MatchTemplateTest::BasicMatchTemplate()
{
    int result_cols =  img.cols - templ.cols + 1;
    int result_rows = img.rows - templ.rows + 1;

    result.create( result_cols, result_rows, CV_32FC1 );

    QBENCHMARK{
        matchTemplate( img, templ, result, match_method );
        normalize( result, result, 0, 1, NORM_MINMAX, -1, Mat() );
    }
}

void MatchTemplateTest::ParallelMatchTemplate()
{
    result.create(img.size(), img.type());

    QBENCHMARK{
        // create 8 threads and use TBB
        cv::parallel_for_(cv::Range(0, 8), Parallel_process(img, result, 5, 8));
    }
}

void MatchTemplateTest::GPUMatchTemplate()
{
    //Colocar aqui la implementacion del modulo GPU del matchTemplate()
}
