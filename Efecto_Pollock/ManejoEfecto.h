
#include "cv.h"
#include "cxcore.h"
#include "highgui.h"

#include <QTime>

class ManejoEfecto
{
private:

    //
    IplImage* mImagenDeteccion;

    //
    IplImage* mImagenRecorrido;

    //
    uchar* mDataImagenRecorrido;

    //
    bool mMarcarRecorrido;

    //
    bool mAnteriorGuardado;

    int mCiclosErosion;

    CvPoint mAnterior;

    CvScalar mValorMinColor;

    CvScalar mValorMaxColor;

    CvScalar mColorLineaUno;

    CvScalar mColorLineaDos;

    CvScalar mColorLineaTres;

    /*
  Crea todas las imagenes a utilizar, se recibe una imagen modelo, que es una imagen tomada de la camara,
  esto para tomar las medidas de la imagen, tomar el depth y tomar la cantidad que canales soportados por la
  camara*/
    void CrearImagenes(IplImage* /*ImagenModelo*/);

    void DibujarGota();



public:

    //
    ManejoEfecto(IplImage* /*rImagenModelo*/ );

    //
    IplImage* GetImagenFiltrada(IplImage* mImagenHsvCamara);

    //
    IplImage* GetImagenRecorrido();

    void ResetRecorrido();

    void SetValoresColorDeteccion(CvScalar/*min*/, CvScalar/*max*/);

    void SetColoresLineas(CvScalar/*uno*/,CvScalar/*dos*/, CvScalar/*tres*/);

    void SetValorErosion(int/*erosion*/);

};
