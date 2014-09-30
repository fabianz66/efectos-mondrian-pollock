#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "QDebug"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    VideoLoader* vl = new VideoLoader();

    qRegisterMetaType< cv::Mat >("Mat");

    // Connect each Widget to correcponding thread
    connect(vl, SIGNAL(onNewImageCaptured(Mat)), this, SLOT(imgReceived(Mat)));

//    vl->startCaptureFromVideo();
    vl->startCaptureFromCamera();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::imgReceived(Mat image)
{
    qDebug() << "12";
    namedWindow("video", 1);
    imshow("video", image);
}
