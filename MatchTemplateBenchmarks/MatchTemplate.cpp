#include "MatchTemplate.h"
#include "QDebug"
#include <QList>
#include <Helpers.h>

MatchTemplate::MatchTemplate()
{
    mTemplateImg = cvLoadImage("resources/template.jpg");
}

/**
  * Este metodo corre cuando se llama this->start().
  */
void MatchTemplate::run()
{
    if(mMetodo == MATCH_NORMAL) //NORMAL
    {
        this->normal();
    }else if(mMetodo == MATCH_TBB) //TBB
    {
        this->tbb();
    }
}

/**
  * Inicia el proceso de match_template normal en un hilo aparte
  * Cuando termina el matchTemplate invoca la signal onMatchTemplateFinished(Mat)
  * Por lo que debe hacerse un connect() antes de llamarse
  **/
void MatchTemplate::normal( Mat original )
{
    /// Guarda la imagen por modificar
    mOriginalImage = original;

    /// Llama al metodo en un hilo aparte
    mMetodo = MATCH_NORMAL;
    this->start();
}

/**
  * Logica que realiza el match_template normal.
  * Se llama dentro de normal(Mat)
  **/
void MatchTemplate::normal()
{
    /// Create the result matrix
    Mat result;
    int result_cols =  mOriginalImage.cols - mTemplateImg.cols + 1;
    int result_rows = mOriginalImage.rows - mTemplateImg.rows + 1;
    result.create( result_rows, result_cols, CV_32FC1 );

    /// @LuisAlonso, el tiempo del match template empieza aqui

    /// Realiza el match template
    matchTemplate( mOriginalImage, mTemplateImg, result, MATCH_METHOD );


    /// @LuisAlonso, y termina aqui

    normalize( result, result, 0, 1, NORM_MINMAX, -1, Mat() );

    /// Localizing the best match with minMaxLoc
    double minVal; double maxVal; Point minLoc; Point maxLoc; Point matchLoc;
    minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );

    /// For SQDIFF and SQDIFF_NORMED, the best matches are lower values. For all the other methods, the higher the better
    if( MATCH_METHOD  == CV_TM_SQDIFF || MATCH_METHOD == CV_TM_SQDIFF_NORMED )
    { matchLoc = minLoc; }
    else
    { matchLoc = maxLoc; }

    /// Show me what you got
    rectangle( result, matchLoc, Point( matchLoc.x + mTemplateImg.cols , matchLoc.y + mTemplateImg.rows ), Scalar::all(0), 2, 8, 0 );

    /// Notifica a quien este conectado
    emit onMatchTemplateFinished(result);
}

/**
  * Inicia el proceso de match_template usando tbb en un hilo aparte
  * Cuando termina el matchTemplate invoca la signal onMatchTemplateFinished(Mat)
  * Por lo que debe hacerse un connect() antes de llamarse
  **/
void MatchTemplate::tbb( Mat original)
{
    /// Guarda la imagen por modificar
    mOriginalImage = original;

    /// Llama al metodo en un hilo aparte
    mMetodo = MATCH_TBB;
    this->start();
}

/**
  * Logica que realiza el match_template con tbb.
  * Se llama dentro de normal(Mat)
  **/
void MatchTemplate::tbb()
{
    /**
    * Se crea una imagen resultado del tamano necesario para que solo se tenga que dividir por 4 en
    * TBB.
    * IMPORTANTE: Cuando se divide las imagenes se dividen por cantidad de filas
    *   --------------------
    *   |                  |
    *   --------------------
    *   |                  |
    *   --------------------
    *   |                  |
    *   --------------------
    **/

    Mat result;
    int result_cols =  mOriginalImage.cols - mTemplateImg.cols + 1;
    int result_rows = mOriginalImage.rows - mTemplateImg.rows*FRAMES_PER_IMAGE_TBB + FRAMES_PER_IMAGE_TBB;
    result.create( result_rows, result_cols, CV_32FC1 );

     /// @LuisAlonso, el tiempo del match template empieza aqui

    /// create 8 threads and use TBB
    cv::parallel_for_(cv::Range(0, FRAMES_PER_IMAGE_TBB), MatchTemplateTBB(mOriginalImage, result, mTemplateImg, FRAMES_PER_IMAGE_TBB));

    /// @LuisAlonso, y termina aqui

    /// For SQDIFF and SQDIFF_NORMED, the best matches are lower values. For all the other methods, the higher the better
    normalize( result, result, 0, 1, NORM_MINMAX, -1, cv::Mat() );
    double minVal; double maxVal; Point minLoc; Point maxLoc, matchLoc;
    minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );

    if( MATCH_METHOD  == CV_TM_SQDIFF || MATCH_METHOD == CV_TM_SQDIFF_NORMED )
    {    matchLoc = minLoc;}
    else
    {  matchLoc = maxLoc;}

    /// Show me what you got
    rectangle( result, matchLoc, Point( matchLoc.x + mTemplateImg.cols , matchLoc.y + mTemplateImg.rows ), Scalar::all(0), 2, 8, 0 );

    /// Notifica a quien este conectado
    emit onMatchTemplateFinished(result);
}

void MatchTemplate::gpu( Mat image )
{

}

void MatchTemplate::gpu()
{

}
