/*
  Costa Rica Institute of Technology
  Computer Engineering

  Fab Lab Costa Rica - Lutec Project
  Mondrian Efect V1

  Fabian Zamora Ramirez
  Cartago, Agosto 2011
*/

#include "VentanaPrincipal.h"
#include "ui_VentanaPrincipal.h"

VentanaPrincipal::VentanaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);
    ui->contenedor_ventanas->setCurrentIndex(0);

    //
    mCamActiva = false;

    //This images are used to change the size of the original images
    mImagenOriginal = cvCreateImage(cvSize(ANCHO_ORIGINAL,ALTURA_ORIGINAL),8,3);
    mImagenMondrian = cvCreateImage(cvSize(ANCHO_MONDRIAN,ALTURA_MONDRIAN),8,3);

    //Initialize the timer
    mTimerImagenes = new QTimer(this);

    //Connect events to slots
    connect(ui->action_iniciar_captura, SIGNAL(triggered()), this, SLOT(IniciarCaptura()));
    connect(ui->action_set_background, SIGNAL(triggered()), this, SLOT(GuardarFondo()));
    connect(ui->btn_default_ajustes, SIGNAL(clicked()), this, SLOT(DefaultButtonClicked()));
    connect(ui->barra_thres1, SIGNAL(valueChanged(int)), this, SLOT(ValorAjustesCambiado()));
    connect(ui->barra_erode, SIGNAL(valueChanged(int)), this, SLOT(ValorAjustesCambiado()));

    //Set values
    DefaultButtonClicked();
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

void VentanaPrincipal::GuardarFondo()
{
    if(mCamActiva)
    {
        Notify(CODIGO_GUARDAR_IMAGEN_FONDO);
    }else
    {
        MostrarMensaje("Error", "Start capture first");
    }
}

void VentanaPrincipal::DefaultButtonClicked()
{
    ui->barra_erode->setSliderPosition(DEFAULT_ERODE);
    ui->barra_thres1->setSliderPosition(DEFAULT_THRES1);
}

void VentanaPrincipal::ValorAjustesCambiado()
{
    Notify(CODIGO_VALOR_AJUSTES_CAMBIADO);
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

void VentanaPrincipal::MostrarImagenes(IplImage* rImgMondrian, IplImage* rImgOriginal)
{
    //Se modifica el tamano de las imagenes
    cvResize(rImgOriginal,mImagenOriginal);
    cvResize(rImgMondrian,mImagenMondrian);

    //Se les aplica el efecto mirror
    cvFlip(mImagenOriginal,mImagenOriginal,1);
    cvFlip(mImagenMondrian,mImagenMondrian,1);

    //Se muestran en la ventana
    ui->label_foto_original->setPixmap(QPixmap::fromImage(IplImageToQImage(mImagenOriginal),0));
    ui->label_foto_mondrian->setPixmap(QPixmap::fromImage(IplImageToQImage(mImagenMondrian), 0));
}

/*
  This function starts the timer, so it starts calling a function that updates the images
  from the camera
  */
void VentanaPrincipal::ComenzarVisualizarCamara()
{
    if(!mTimerImagenes->isActive()) //If it isn't already been started
    {
        //It calls ActualizaImagenes each DELAY_FRAME_CAMARA_MILI_SEG seconds
        connect(mTimerImagenes, SIGNAL(timeout()), this, SLOT(ActualizaImagenes()));
        mTimerImagenes->start(DELAY_FRAME_CAMARA_MILI_SEG);
    }
}

//Makes the controller update the images
void VentanaPrincipal::ActualizaImagenes()
{
    Notify(CODIGO_ACTUALIZAR_IMAGENES);
}


int VentanaPrincipal::GetValorErode()
{
    return ui->barra_erode->value();
}

int VentanaPrincipal::GetValorThres1()
{
    return ui->barra_thres1->value();
}
