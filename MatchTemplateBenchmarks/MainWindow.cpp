#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "MatchTemplate.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Inicia las variables
    mVideoLoader = new VideoLoader();
    mMatchTempl = new MatchTemplate();

    //Crea las ventanas que va a mostrar
    namedWindow("original", 1);
    namedWindow("result", 1);

    //Registra el evento de nueva imagen recibida y de match template terminado
    qRegisterMetaType< cv::Mat >("Mat");
    connect(mVideoLoader, SIGNAL(onNewImageCaptured(Mat)), this, SLOT(imgCaptured(Mat)));
    connect(mMatchTempl, SIGNAL(onMatchTemplateFinished(Mat)), this, SLOT(matchCompleted(Mat)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

/** Recibe el evento de una nueva imagen en la camara o video */
void MainWindow::imgCaptured(Mat image)
{
    if(mMatchTempl->isRunning()) {
        qDebug() << "isRunning - Brinque esta imagen";
    }else {
        qDebug() << "NOT Running - Aplique matching";

        if(mMatchMethod == MATCH_NORMAL)
        {
            mMatchTempl->normal(image);
        }else if(mMatchMethod == MATCH_TBB)
        {
            mMatchTempl->tbb(image);
        }
    }
    imshow("original", image);
}

/** Recibe el evento de que a una imagen termino de hacerle el match template */
void MainWindow::matchCompleted(Mat image)
{
    imshow("result", image);
}

/// =================================== EVENTOS DE BOTONES ===================================== ///

void MainWindow::on_video_normal_clicked()
{
    mMatchMethod = MATCH_NORMAL;
    mVideoLoader->startCaptureFromVideo();
}

void MainWindow::on_video_tbb_clicked()
{
    mMatchMethod = MATCH_TBB;
    mVideoLoader->startCaptureFromVideo();
}

void MainWindow::on_cam_normal_clicked()
{
    mMatchMethod = MATCH_NORMAL;
    mVideoLoader->startCaptureFromCamera();
}

void MainWindow::on_cam_tbb_clicked()
{
    mMatchMethod = MATCH_TBB;
    mVideoLoader->startCaptureFromCamera();
}
