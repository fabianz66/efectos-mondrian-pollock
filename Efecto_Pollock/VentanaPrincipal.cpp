#include "VentanaPrincipal.h"
#include "ui_VentanaPrincipal.h"

VentanaPrincipal::VentanaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);

    mCamActiva = false;

    //Initialize the timer
    mTimerImagenes = new QTimer(this);
    mImagenDeteccionUno = cvCreateImage(cvSize(270,190),8,3);
    mImagenDeteccionDos = cvCreateImage(cvSize(270,190),8,3);

    //Connects
    connect(ui->actionStart_Capture, SIGNAL(triggered()), this, SLOT(IniciarCaptura()));
    connect(ui->actionDetection_Color, SIGNAL(triggered()), this, SLOT(AbrirAjustes()));
    connect(ui->actionReset_Left, SIGNAL(triggered()), this, SLOT(ResetRecorridoIzq()));
    connect(ui->actionReset_Right, SIGNAL(triggered()), this, SLOT(ResetRecorridoDer()));
    ui->contenedor_ventanas->setCurrentIndex(0);
}

VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;
}

void VentanaPrincipal::IniciarCaptura()
{
    if(!mCamActiva)
    {
        //Notify the controller to start the capture
        Notify(CODIGO_INICIAR_CAPTURA);

        //Set the boolean used for setBackground and Settings buttons
        mCamActiva = true;

        //Show the image panel
        ui->contenedor_ventanas->setCurrentIndex(1);
    }else
    {
        MostrarMensaje("Warning", "Camera is already in use");
    }
}

/*
  Function to show a MessageWindow
 */
void VentanaPrincipal::MostrarMensaje(QString mTitulo, QString mMensaje)
{
    QMessageBox ventana;
    ventana.setText(mMensaje);
    ventana.setFont(QFont("Calibri",12));
    ventana.setWindowTitle(mTitulo);
    ventana.exec();
}

void VentanaPrincipal::ComenzarMostrarImagenes()
{
    if(!mTimerImagenes->isActive())
    {
        connect(mTimerImagenes, SIGNAL(timeout()), this, SLOT(ActualizarImagenes()));
        mTimerImagenes->start(DELAY_FRAME_CAMARA_MILI_SEG);
    }
}

void VentanaPrincipal::ActualizarImagenes()
{
    Notify(CODIGO_MOSTRAR_IMAGENES_RECORRIDO);
}

/*
  */
QImage VentanaPrincipal::IplImageToQImage(IplImage* mSrc)
{
    const uchar *data = (const uchar*)mSrc->imageData;
    int width = mSrc->width;
    int height = mSrc->height;
    QImage img(data, width, height, QImage::Format_RGB888);
    return img.rgbSwapped();
}

/*
        Se reciben las imagenes en el sgt orden:
        [0] ImagenDeteccionUno [1] ImagenRecorridoUno
        [2] ImagenDeteccionDos [3] ImagenRecorridoDos
*/
IplImage* ima = cvCreateImage(cvSize(640,480),8,3);
IplImage* ima2 = cvCreateImage(cvSize(640,480),8,3);

void VentanaPrincipal::SetImagenes(QVector<IplImage*>* rImagenes)
{

        IplImage* recorrido_uno = rImagenes->at(1);
        IplImage* recorrido_dos = rImagenes->at(3);

        ui->label_recorrido_iz->setPixmap(QPixmap::fromImage(IplImageToQImage(recorrido_uno),0));
        ui->label_recorrido_der->setPixmap(QPixmap::fromImage(IplImageToQImage(recorrido_dos), 0));

        //Se carga la imagen que detecta
        IplImage* deteccion_uno = rImagenes->at(0);
        IplImage* deteccion_dos = rImagenes->at(2);

        //Se le cambia el tamano
        cvMerge(deteccion_uno,NULL,NULL,NULL,ima);
        cvResize(ima, mImagenDeteccionUno);

        //Se le cambia el tamano
        cvMerge(deteccion_dos,NULL,NULL,NULL,ima2);
        cvResize(ima2, mImagenDeteccionDos);

        //
        ui->label_deteccion_iz->setPixmap(QPixmap::fromImage(IplImageToQImage( mImagenDeteccionUno),0));
        ui->label_deteccion_der->setPixmap(QPixmap::fromImage(IplImageToQImage( mImagenDeteccionDos),0));
}

void VentanaPrincipal::AbrirAjustes()
{
    if(mCamActiva)
    {
        //Notify the controller to start the settings window
        Notify(CODIGO_INICIAR_VENTANA_AJUSTES);
    }else
    {
        MostrarMensaje("Warning", "Start Capture First");
    }
}

void VentanaPrincipal::ResetRecorridoDer()
{
        Notify(CODIGO_RESET_DER);
}

void VentanaPrincipal::ResetRecorridoIzq()
{
        Notify(CODIGO_RESET_IZQ);
}
