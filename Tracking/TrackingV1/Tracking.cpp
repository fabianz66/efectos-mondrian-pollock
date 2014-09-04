#include "Tracking.h"
#include <QDebug>

Tracking::Tracking()
{
}

//Funcion estatica que retorna la unica instancia de la clase
Tracking& Tracking::getInstance()
{
    static Tracking instance;
    return instance;
}

bool Tracking::iniciarCamara()
{
    mCamCapture = cvCreateCameraCapture(NUM_CAM);
    if(mCamCapture) iniciarImagenes();
    return mCamCapture;
}

void Tracking::iniciarImagenes()
{
    //Tamano de las imagenes tomadas por la camara
    CvSize size = cvGetSize(cvQueryFrame(mCamCapture));

    //Se guardan las dimensiones q se utilizaran para la cuadricula
    //Largo de cada cuadro de la cuadricula
    tamano_cuadro[0] = size.width/TAMANO_CUADRICULA;

    //Alto de cada cuadro de la cuadricula
    tamano_cuadro[1] = size.height/TAMANO_CUADRICULA;

    //Imagenes necesarias para convertir a rgb
    mBayerImage = cvCreateImage( size, IPL_DEPTH_8U, 1);
    mRgbCameraFrame = cvCreateImage( size, IPL_DEPTH_8U, 3);
}

IplImage* Tracking::getTrackingFrame()
{
    /** Primero se lee la imagen de la firewire camera en RGB*/
    getRgbCameraFrame(FIREWIRE);

    if(mTemplateImage)
    {
        /// Source image to display
        Mat original(mRgbCameraFrame);
        Mat templ (mTemplateImage);
        Mat result;

        /// Source image to display
        Mat img_display;
        original.copyTo( img_display );

        /// Create the result matrix
        int result_cols =  original.cols - templ.cols + 1;
        int result_rows = original.rows - templ.rows + 1;

        result.create( result_cols, result_rows, CV_32FC1 );

        /// Do the Matching and Normalize
        int match_method = 0;
        matchTemplate( original, templ, result, match_method );
        normalize( result, result, 0, 1, NORM_MINMAX, -1, Mat() );

        /// Localizing the best match with minMaxLoc
        double minVal; double maxVal; Point minLoc; Point maxLoc;
        Point matchLoc;

        minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );

        /// For SQDIFF and SQDIFF_NORMED, the best matches are lower values. For all the other methods, the higher the better
        if( match_method  == CV_TM_SQDIFF || match_method == CV_TM_SQDIFF_NORMED )
        { matchLoc = minLoc; }
        else
        { matchLoc = maxLoc; }

        /// Show me what you got
        rectangle( img_display, matchLoc, Point( matchLoc.x + templ.cols , matchLoc.y + templ.rows ), Scalar::all(0), 2, 8, 0 );
        rectangle( result, matchLoc, Point( matchLoc.x + templ.cols , matchLoc.y + templ.rows ), Scalar::all(0), 2, 8, 0 );

        imshow( "image_window", img_display );
        imshow( "result_window", result );
    }

    //Se le dibuja la cuadricula
    dibujarCuadricula(mRgbCameraFrame);

    return mRgbCameraFrame;
}

void Tracking::getRgbCameraFrame(bool pFirewire)
{
    IplImage* camera_frame = cvQueryFrame(mCamCapture);

    if(pFirewire)
    {
        // set channel of interest to 1
        cvSetImageCOI(camera_frame,1);

        //Se copia a bayer
        cvCopy(camera_frame,mBayerImage,NULL);

        //Se pasa a color
        cvCvtColor(mBayerImage,mRgbCameraFrame,CV_BayerGB2RGB);
    }else
    {
        cvCopy(camera_frame, mRgbCameraFrame);
    }
}


void Tracking::dibujarCuadricula(IplImage* src)
{
    int largo_imagen = tamano_cuadro[0]*TAMANO_CUADRICULA;
    int alto_imagen = tamano_cuadro[1]*TAMANO_CUADRICULA;
    CvPoint inicio = cvPoint(0,0);
    CvPoint final = cvPoint(largo_imagen, 0);
    for(int linea=0; linea<TAMANO_CUADRICULA; linea++)
    {
        cvLine( src, inicio, final, cvScalar(255,255,255,0));
        inicio.y += tamano_cuadro[1];
        final.y += tamano_cuadro[1];
    }
    inicio = cvPoint(0,0);
    final = cvPoint(0,alto_imagen);
    for(int linea=0; linea<TAMANO_CUADRICULA; linea++)
    {
        cvLine( src, inicio, final, cvScalar(255,255,255,0));
        inicio.x += tamano_cuadro[0];
        final.x += tamano_cuadro[0];
    }
}

void Tracking::comenzarRastreo(QRect pRectTemp)
{
    qDebug() << "AAAAAAAA";
    CvRect box = cvRect(pRectTemp.x(), pRectTemp.y(), pRectTemp.width(), pRectTemp.height());
    qDebug() << "BBBBBBBB";
    crearTemplate(box);
}

void Tracking::crearTemplate(CvRect box)
{
    //Se lee la imagen de la camara, esto para que no quede con la cuadricula
    getRgbCameraFrame(FIREWIRE);

    qDebug() << "CCCCCCCC";
    //Se crea una imagen para guardar el template
    IplImage* dst = cvCreateImage(cvSize(box.width, box.height),8, 3);

    qDebug() << "DDDDDDDDD";
    //Se toma el area del rectangulo
    CvMat* template_img_area = cvGetSubRect( (CvMat*)mRgbCameraFrame, (CvMat*)dst, box);

    if(mTemplateImage)
        cvReleaseImage(&mTemplateImage);

    qDebug() << "EEEEEEEEEE";
    //Se guarda la imagen
    mTemplateImage = cvCreateImage(cvGetSize(template_img_area), 8, 3);
    cvCopy(template_img_area, mTemplateImage);

    qDebug() << "FFFFFFFFF";
    //    cvReleaseImage(&dst);
    //    cvReleaseMat(&template_img_area);
    cvShowImage("Template", mTemplateImage);

}

void Tracking::liberarMemoria()
{
    cvReleaseImage(&mBayerImage);
    cvReleaseImage(&mRgbCameraFrame);
    cvReleaseCapture(&mCamCapture);
    cvReleaseImage(&mTemplateImage);
}
