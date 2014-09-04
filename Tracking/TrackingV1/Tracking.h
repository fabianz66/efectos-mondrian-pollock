#ifndef TRACKING_H
#define TRACKING_H
#define NUM_CAM -1
#define TAMANO_CUADRICULA 7
#define FIREWIRE false

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <QRect>

using namespace std;
using namespace cv;

class Tracking
{

private:

    /** Capture que contiene lo que se lee de la cam */
    CvCapture* mCamCapture;

    /** Imagenes necesarias para el programa */

    //Contiene los frames que se leen de la camara
    IplImage* mCameraFrame;

    //Template que se esta rastreando
    IplImage* mTemplateImage;

    /** Imagenes para leer a color de firewire */

    // bucket for channel 1 of grabbed image
    IplImage* mBayerImage;

    // create interleaved 8 bit, 3 channel image
    IplImage* mRgbCameraFrame;

    /** Tamano de cada cuadro de la cuadricula */
    int tamano_cuadro[2];

public:

    /** Singleton */
    static Tracking& getInstance();

    /** Comienza la camara, retorna True si se leyo correctamente */
    bool iniciarCamara();

    /** Se libera la memoria que se pidio */
    void liberarMemoria();

    /** Devuelve la imagen de la camara, ya con los efectos incluidos */
    IplImage* getTrackingFrame();

    /** Proceso de rastreo. Recibe el rectangulo que contiene las posiciones que
    se van a tomar como template */
    void comenzarRastreo(QRect pRectTemp);

private:

    /** Constructor */
    Tracking();

    /** Inicia las imagenes tomando el tamano de una imagen leida de la camara */
    void iniciarImagenes();

    /** Una camara firewire debe leerse de un modo distinto.
    Cuando se lee normalmente de una camara firewire, utilizando
    openCV, esta aparece en blanco y negro.
    Esta funcion convierte esa imagen en blanco y negro a una imagen
    a color rgb. */
    void getRgbCameraFrame(bool pFirewire);

    /** Se le dibuja una cuadricula a la imagen */
    void dibujarCuadricula(IplImage* /*src*/);

    /** Se crea el tamplate que se va comparar en la imagen */
    void crearTemplate(CvRect /*box*/);

};

#endif // TRACKING_H
