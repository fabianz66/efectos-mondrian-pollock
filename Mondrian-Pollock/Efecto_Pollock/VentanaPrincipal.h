#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>
#include <Observable.h>
#include <QTimer>
#include <QMessageBox>

//OpenCV
#include "opencv/cv.h"
#include "opencv/cxcore.h"
#include "opencv/highgui.h"

namespace Ui {
class VentanaPrincipal;
}

class VentanaPrincipal : public QMainWindow, public Observable
{
    Q_OBJECT

public:
    explicit VentanaPrincipal(QWidget *parent = 0);
    ~VentanaPrincipal();

    //Se inicia el QTimer
    void ComenzarMostrarImagenes();

    //Recibe las imagenes y las coloca
    void SetImagenes(QVector<IplImage*>* /*rImagenes*/);

private slots:
    //Indica al controller que actualice las imagenes
    void ActualizarImagenes();

    //Starts the camera
    void IniciarCaptura();

    //Shows the settings
    void AbrirAjustes();

    void ResetRecorridoIzq();

    void ResetRecorridoDer();

private:
    //Converts the IplImage into a QImage so it can be displayed into Qt windows
    QImage IplImageToQImage(IplImage* mSrc);

    //Shows a message window
    void MostrarMensaje(QString mTitulo, QString mMensaje);

private:

    Ui::VentanaPrincipal *ui;

    QTimer* mTimerImagenes;

    //Indicates if the cam is active
    bool mCamActiva;

    IplImage* mImagenDeteccionUno;
    IplImage* mImagenDeteccionDos;



};

#endif // VENTANAPRINCIPAL_H
