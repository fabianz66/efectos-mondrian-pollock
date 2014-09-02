/*
  Costa Rica Institute of Technology
  Computer Engineering

  Fab Lab Costa Rica - Lutec Project
  Mondrian Efect V1

  Fabian Zamora Ramirez
  Cartago, Agosto 2011
*/

#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include <Observable.h>
#include <highgui.h>
#include <cv.h>
#include <cvaux.h>

namespace Ui {
    class VentanaPrincipal;
}

class VentanaPrincipal : public QMainWindow, public Observable
{
    Q_OBJECT

private:
    Ui::VentanaPrincipal *ui;

    //Timer for showing the images
    QTimer* mTimerImagenes;

    //The image already modified
    IplImage* mImagenMondrian;

    //The original frame of the camera
    IplImage* mImagenOriginal;

    //Indicates if the cam is active
    bool mCamActiva;

    //Shows a message window
    void MostrarMensaje(QString mTitulo, QString mMensaje);

private slots:

    //Starts the camera
    void IniciarCaptura();

    //Set the background for substraction
    void GuardarFondo();

    //Converts the IplImage into a QImage so it can be displayed into Qt windows
    QImage IplImageToQImage(IplImage* mSrc);

    //Sends a signal to the controller so it updates the images
    void ActualizaImagenes();

    //
    void DefaultButtonClicked();

    //
    void ValorAjustesCambiado();

public:

    //Constructor
    explicit VentanaPrincipal(QWidget *parent = 0);

    //Destructor
    ~VentanaPrincipal();

    //Update the images
    void MostrarImagenes(IplImage* rImgMondrian, IplImage* rImgOriginal);

    //Starts showing the images
    void ComenzarVisualizarCamara();

    int GetValorErode();

    int GetValorThres1();

};

#endif // VENTANAPRINCIPAL_H
