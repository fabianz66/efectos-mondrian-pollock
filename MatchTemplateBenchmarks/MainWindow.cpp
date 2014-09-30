#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "MatchTemplate.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /// =================== MATCH TEMPLATE TESTS ========================= ///

    namedWindow("original", 1);
    namedWindow("result", 1);
    mVideoLoader = new VideoLoader();
    mMatchTempl = new MatchTemplate();

    //Registra el evento de nueva imagen recibida y de match template terminado
    qRegisterMetaType< cv::Mat >("Mat");
    connect(mVideoLoader, SIGNAL(onNewImageCaptured(Mat)), this, SLOT(imgReceived(Mat)));
    connect(mMatchTempl, SIGNAL(onMatchTemplateFinished(Mat)), this, SLOT(matchReceived(Mat)));

    qDebug() << "CUDA ENABLED" << gpu::getCudaEnabledDeviceCount();

        mVideoLoader->startCaptureFromVideo();
//    mVideoLoader->startCaptureFromCamera();

    /// =================== MATCH TEMPLATE TESTS ========================= ///

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::imgReceived(Mat image)
{
    if(mMatchTempl->isRunning()) {
        qDebug() << "isRunning - Brinque esta imagen";
    }else {
        qDebug() << "NOT Running - Aplique matching";
//                mMatchTempl->normal(image);

        mMatchTempl->tbb(image);
    }

    imshow("original", image);

    //    image.release();
}

void MainWindow::matchReceived(Mat image)
{
    imshow("result", image);

    //    image.release();
}
