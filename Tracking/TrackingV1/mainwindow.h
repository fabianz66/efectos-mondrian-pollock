#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define DELAY_ENTRE_FRAMES_MS 15

#include <QMainWindow>
#include <QTimer>
#include <highgui.h>
#include <Tracking.h>
#include <QMessageBox>
#include <LabelImagen.h>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    QTimer* mTimerCam;
    Tracking* mManejoTracking;
    LabelImagen* mLabelImagenCamara;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void closeEvent(QCloseEvent* /*event*/);

private:
    QImage IplImageToQImage(IplImage* /*src*/);
    void colocarNumerosCuadricula();

private slots:
    void comenzarMostrarCamara();
    void mostrarCamara();





};

#endif // MAINWINDOW_H
