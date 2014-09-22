/*
  Costa Rica Institute of Technology
  Computer Engineering

  Fab Lab Costa Rica - Lutec Project
  Mondrian Efect V1

  Fabian Zamora Ramirez
  Cartago, Agosto 2011
*/

#ifndef MANEJOCAMARA_H
#define MANEJOCAMARA_H

/*
Clase para el manejo de los frames tomados desde una camara, se tienen barras para el control de ciertos
filtros en la imagen.
Estos filtros se le aplican a la resta de la imagen actual de la camara y otra imagen tomada como
fondo
*/

//INCLUDES
#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <opencv/cxcore.h>
#include <iostream>
#include <string>
#include <QTime>

using namespace std;

class ManejoCamara
{
private:

    //Constructor privado para aplicar patron sinigleton
    ManejoCamara();

    //Esto contiene la informacion tomada de la cam, contiene los frames, aca es donde pedimos el frame que esta tomando la camara
    CvCapture* mCamCapture;

    //Imagen que contiene lo que esta viendo la camara
    IplImage* mImagenActualCamara;

    //Imagen que contiene lo que esta viendo la camara, a escala de grises
    IplImage* mImagenActualCamaraGrises;

    //Imagen que contiene el fondo tomado para la sacar la diferencia
    IplImage* mImagenFondo;

    //Imagen que se va a utilizar para rellenar la cilueta
    IplImage* mImagenFondoMondrian;

    //Es la imagen que contiene la cilueta de la persona, rellena con la obra de Mondrian
    IplImage* mImagenRellenaMondrian;

    //Imagen que contiene la diferencia entre mImagenActualCamara y mImagenFondo
    IplImage* mImagenDiferencia;

    //Puntero a la informacion de la imagen mImagenFondoMondrian
    uchar* pDataImagenFondoMondrian;

    //Puntero a la informacion de la imagen mImagenRellenaMondrian
    uchar* pDataImagenRellenaMondrian;

    int mThres1;

    int mThres2;

    int mErode;

    /*
  Crea todas las imagenes a utilizar, se recibe una imagen modelo, que es una imagen tomada de la camara,
  esto para tomar las medidas de la imagen, tomar el depth y tomar la cantidad que canales soportados por la
  camara
  */
    void CrearImagenes(IplImage* /*ImagenModelo*/);

    /*
  Rellena los espacios blancos de la imagen mImagenDiferencia, con el fondo de Mondrian
  */
    void RellenarImagenMondrian();

    /*
  Funcion que cambia la imagen de fondo de mondrian cada cierto tiempo segundos
  */
    void GeneraImagenFondoMondrian();

    /*
  Aplica los filtro a la imagen mImagenDiferencia para el sacar la cilueta de la persona
  */
    void AplicarFiltrosImagenDiferencia();

public:

    //Funcion que devuelve la unica instancia de la clase
    static ManejoCamara& GetInstance();

    void SetValoresErodeThres(int /*rErode*/, int /*rThres*/);

    /*
  Comienza a leer de la camara, recibe el numero de camara que se va a utilizar
  Utilice 0 para tomar la camara default
  */
    void SetCamara(int/*NumCam*/);

    /*
  Toma la imagen que se encuentre en mImagenActualCamara, la convierte a escala de grises y la guarda en mImagenFondo
  */
    void GuardarFondo();

    /*
  TODO revisar!!!!!
  Devuelve la imagen que esta en la camara en el momento que se llama la funcion,
  Se debe saber, que los videos son imagenes que se presentan muy seguido, por eso para presentar
  El 'video' tomado de la camara, lo que se hace es pedir la iamgen de la camara e irla mostrando en un ciclo
  */
    IplImage* GetImagenVideoCamara();

    /*
  Hace la resta de mImagenFondo con mImagenActualCamara y la muestra en pantalla
  */
    IplImage* GetImagenEfectoMondrian();
};

#endif // MANEJOCAMARA_H
