#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Clase que maneja openCV
    mManejoTracking = &Tracking::getInstance();

    //Initialize the timer
    mTimerCam = new QTimer(this);

    //Label que va a contener la imagen de la camara
    mLabelImagenCamara = new LabelImagen();
    ui->contenedor_imagen->addWidget(mLabelImagenCamara);

    //Connects
    connect(ui->actionIniciarRastreo, SIGNAL(triggered()), this, SLOT(comenzarMostrarCamara()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QImage MainWindow::IplImageToQImage(IplImage* src)
{
    const uchar *data = (const uchar*)src->imageData;
    int width = src->width;
    int height = src->height;
    QImage img(data, width, height, QImage::Format_RGB888);
    return img.rgbSwapped();
}

void MainWindow::colocarNumerosCuadricula()
{
    ui->numeros_arriba->addWidget(new QLabel());
    for(int num=0; num < TAMANO_CUADRICULA; num++)
    {
        ui->numeros_arriba->addWidget(new QLabel(QString::number(num)));
        ui->numeros_iz->addWidget(new QLabel(QString::number(num)));
    }
}

void MainWindow::comenzarMostrarCamara()
{
    if(mManejoTracking->iniciarCamara())
    {
        ui->panel_principal->setCurrentIndex(1);
        colocarNumerosCuadricula();
        if(!mTimerCam->isActive())
        {
            connect(mTimerCam, SIGNAL(timeout()), this, SLOT(mostrarCamara()));
            mTimerCam->start(DELAY_ENTRE_FRAMES_MS);
        }
    }else
    {
        QMessageBox ventana;
        ventana.setText("No se pudo iniciar la camara. \n Revise si la camara se encuentra conectada o esta en uso.");
        ventana.setFont(QFont("Calibri",12));
        ventana.setWindowTitle("Error");
        ventana.exec();
    }
}

void MainWindow::mostrarCamara()
{
    IplImage* camera_frame = mManejoTracking->getTrackingFrame();
    mLabelImagenCamara->setPixmap(QPixmap::fromImage(IplImageToQImage(camera_frame),0));
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    if(mTimerCam->isActive())
    {
        mTimerCam->stop();
        mTimerCam->deleteLater();
    }
    mManejoTracking->liberarMemoria();
}
