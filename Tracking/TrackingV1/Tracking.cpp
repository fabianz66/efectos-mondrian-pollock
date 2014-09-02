#include "Tracking.h"

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
    CvRect box = cvRect(pRectTemp.x(), pRectTemp.y(), pRectTemp.width(), pRectTemp.height());
    crearTemplate(box);
}

void Tracking::crearTemplate(CvRect box)
{
    //Se lee la imagen de la camara, esto para que no quede con la cuadricula
    getRgbCameraFrame(FIREWIRE);

    //Se crea una imagen para guardar el template
    IplImage* dst = cvCreateImage(cvSize(box.width, box.height),8, 3);

    //Se toma el area del rectangulo
    CvMat* template_img_area = cvGetSubRect( (CvMat*)mRgbCameraFrame, (CvMat*)dst, box);

    if(mTemplateImage)
        cvReleaseImage(&mTemplateImage);

    //Se guarda la imagen
    mTemplateImage = cvCreateImage(cvGetSize(template_img_area), 8, 3);
    cvCopy(template_img_area, mTemplateImage);

    cvReleaseImage(&dst);
    cvReleaseMat(&template_img_area);
    cvShowImage("Template", mTemplateImage);

}

void Tracking::liberarMemoria()
{
    cvReleaseImage(&mBayerImage);
    cvReleaseImage(&mRgbCameraFrame);
    cvReleaseCapture(&mCamCapture);
    cvReleaseImage(&mTemplateImage);
}
