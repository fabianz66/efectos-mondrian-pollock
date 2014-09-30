#include "MainWindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    VideoLoader* vl = new VideoLoader();

    // Connect each Widget to correcponding thread
    connect(vl, SIGNAL(onNewImageCaptured(Mat&)), this, SLOT(onNewImageCaptured(Mat&)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNewImageCaptured(Mat& capturedFrame)
{
    namedWindow("video", 1);
    imshow("video", capturedFrame);
}
