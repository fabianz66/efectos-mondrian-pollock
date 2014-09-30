#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "VideoLoader.h"
#include "MatchTemplate.h"

#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/gpu/gpu.hpp"

using namespace std;
using namespace cv;
using namespace cv::gpu;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void imgReceived(Mat image);
    void matchReceived(Mat image);

private:
    Ui::MainWindow *ui;

    /// TEMPLATE TESTS
    MatchTemplate* mMatchTempl;
    VideoLoader* mVideoLoader;
};

#endif // MAINWINDOW_H
