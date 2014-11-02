#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "VideoLoader.h"
#include "MatchTemplate.h"
#include "Benchmark.h"

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
    void imgCaptured(Mat image);
    void matchCompleted(Mat image);
    void on_video_normal_clicked();
    void on_detener_clicked();
    void on_benchmark_btn_clicked();
    void on_save_benchmarks_clicked();

private:
    Ui::MainWindow *ui;

    /// Variables
    Benchmark *mBenchmark;
    MatchTemplate* mMatchTempl;
    VideoLoader* mVideoLoader;
    int mMatchMethod;
};

#endif // MAINWINDOW_H
