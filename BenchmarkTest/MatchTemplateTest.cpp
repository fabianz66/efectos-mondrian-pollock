#include "MatchTemplateTest.h"
#include <iostream>
#include <stdio.h>

//Constructor
MatchTemplateTest::MatchTemplateTest()
{
    //Se cargan las imagenes
    img = imread( "imagen.png", 1 );
    templ = imread( "template.png", 1 );

    //GPU
    imgGPU.upload(img);
    templGPU.upload(templ);

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
}

void MatchTemplateTest::GPUMatchTemplate()
{
    //Colocar aqui la implementacion del modulo GPU del matchTemplate()
}
