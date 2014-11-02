#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "MatchTemplate.h"
#include "Constantes.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Inicia las variables
    mVideoLoader = new VideoLoader();
    mMatchTempl = new MatchTemplate();
    mBenchmark = &Benchmark::getInstance();

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

    if(mMatchTempl->isRunning()) { /// Brinque esta imagen
        mBenchmark->addSkippedImage();

    }else { /// Aplique matching

        mBenchmark->addProccesedImage();

        if(mMatchMethod == MATCH_NORMAL)
            mMatchTempl->normal(image);
    }
    imshow(NORMAL_IMG_NAME, image);
}

/** Recibe el evento de que a una imagen termino de hacerle el match template */
void MainWindow::matchCompleted(Mat image)
{
    imshow(RESULT_IMG_NAME, image);
}

/// =================================== EVENTOS DE BOTONES ===================================== ///

void MainWindow::on_video_normal_clicked()
{
    //Crea las ventanas que va a mostrar
    namedWindow(NORMAL_IMG_NAME, 1);
    namedWindow(RESULT_IMG_NAME, 1);

    if( mVideoLoader->startCaptureFromVideo())
        mMatchMethod = MATCH_NORMAL;
}

void MainWindow::on_detener_clicked()
{
    mVideoLoader->stop();
}

void MainWindow::on_benchmark_btn_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                    "/home/",
                                                    tr("CVS (*.cvs)"));

    mBenchmark->setPath(fileName);
}

void MainWindow::on_save_benchmarks_clicked()
{
    mBenchmark->saveAndRestart();
}
