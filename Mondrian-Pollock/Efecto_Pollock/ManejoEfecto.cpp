#include "ManejoEfecto.h"

ManejoEfecto::ManejoEfecto(IplImage* rImagenModelo)
{	
    //
    mAnteriorGuardado = false;

    //
    CrearImagenes(rImagenModelo);
}


/*
Se crean inician las imagenes que se van a utilizar en el programa, 
se recibe como parametro una imagen modelo para tomar las medidas y la profundidad default de la camara
*/
void ManejoEfecto::CrearImagenes(IplImage* rModeloImagen)
{
    //
    CvSize size = cvGetSize(rModeloImagen);

    //
    mImagenRecorrido = cvCreateImage(size, rModeloImagen->depth, 3);

    //
    mDataImagenRecorrido = (uchar*)mImagenRecorrido->imageData;

    //
    mImagenDeteccion = cvCreateImage(size, rModeloImagen->depth, 1);
}

/*

*/
IplImage* ManejoEfecto::GetImagenFiltrada(IplImage* mImagenHsvCamara)
{
    //
    cvInRangeS(mImagenHsvCamara,mValorMinColor,mValorMaxColor, mImagenDeteccion);

    //
    cvSmooth( mImagenDeteccion, mImagenDeteccion, CV_GAUSSIAN, 9, 9 );

    //
    cvThreshold(mImagenDeteccion, mImagenDeteccion,0, 255, CV_THRESH_BINARY);

    //
    cvErode(mImagenDeteccion, mImagenDeteccion,0,mCiclosErosion);

    return mImagenDeteccion;
}

/*

*/
IplImage* ManejoEfecto::GetImagenRecorrido()
{
    //Recorre de arriba a abajo de izquierda a derecha
    for( int pos_x = 0 ; pos_x < mImagenDeteccion->width ; pos_x++ )
    {
        for( int pos_y = 0 ; pos_y < mImagenDeteccion->height ; pos_y++ )
        {
            CvScalar pixel = cvGet2D(mImagenDeteccion,pos_y,pos_x);
            int num_color = pixel.val[0];
            if( num_color > 250) //Se comprueba que el color sea blanco
            {
                if(!mAnteriorGuardado)
                {
                    mAnterior = cvPoint(pos_x, pos_y);
                    mAnteriorGuardado = true;
                }else
                {
                    cvLine(mImagenRecorrido, mAnterior, cvPoint(pos_x, pos_y), mColorLineaUno,3);
                    cvLine(mImagenRecorrido, cvPoint(mAnterior.x, mAnterior.y-10), cvPoint(pos_x, pos_y-10), mColorLineaDos, 3);
                    cvLine(mImagenRecorrido, cvPoint(mAnterior.x, mAnterior.y-20), cvPoint(pos_x, pos_y-20), mColorLineaTres,3);
                    mAnterior = cvPoint(pos_x, pos_y);
                }
                DibujarGota();
                return mImagenRecorrido;
            }
        }
    }
    return mImagenRecorrido;
}

void ManejoEfecto::ResetRecorrido()
{
    cvZero(mImagenRecorrido);
}

void ManejoEfecto::SetColoresLineas(CvScalar rUno,CvScalar rDos,CvScalar rTres)
{
    mColorLineaUno = rUno;
    mColorLineaDos = rDos;
    mColorLineaTres = rTres;
}

void ManejoEfecto::SetValoresColorDeteccion(CvScalar rMin, CvScalar rMax)
{
    mValorMinColor = rMin;
    mValorMaxColor = rMax;
}

void ManejoEfecto::SetValorErosion(int rErosion)
{
    mCiclosErosion = rErosion;
}

int num_color = 0;
bool gota_dibujada = false;
void ManejoEfecto::DibujarGota()
{
    CvScalar color = mColorLineaUno;
    int segundo = QTime::currentTime().second();
    if(segundo % 3 == 0 && !gota_dibujada)
    {
        if(num_color == 1)
        {
            color = mColorLineaDos;
        }else if(num_color == 2)
        {
            color = mColorLineaTres;
            num_color = -1;
        }
        cvCircle(mImagenRecorrido,cvPoint(mAnterior.x, mAnterior.y-10), 5,color,30);
        cvCircle(mImagenRecorrido,cvPoint(mAnterior.x+10, mAnterior.y+10), 5,color,20);
        cvCircle(mImagenRecorrido,cvPoint(mAnterior.x-15, mAnterior.y+10),5,color,30);

        //Se cambia el color y se indica que ya se dibujo 1 gota
        num_color++;
        gota_dibujada = true;
    }
    //Cuando ya pasa de segundo se vuelve a indicar que se debe dibujar 1 gota
    else if(segundo % 3 != 0)
    {
        gota_dibujada = false;
    }
}
