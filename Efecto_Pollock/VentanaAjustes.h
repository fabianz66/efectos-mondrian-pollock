#ifndef VENTANAAJUSTES_H
#define VENTANAAJUSTES_H

#include <QWidget>
#include "Observable.h"
#include <QTimer>
#include "cv.h"
#include "cxcore.h"
#include "highgui.h"

namespace Ui {
class VentanaAjustes;
}

class VentanaAjustes : public QWidget, public Observable
{
    Q_OBJECT

public:
    //Singleton: returns the only instance of the class
    static VentanaAjustes& GetInstance();

    //
    void SetClickedValues(int, int, int);

    //
    int GetErosionIzq();

    //
    int GetErosionDer();

    //
    CvScalar GetMinHsvIzq();
    CvScalar GetMaxHsvIzq();

    //
    CvScalar GetMinHsvDer();
    CvScalar GetMaxHsvDer();

public slots:

    //
    void MostrarImagenHsv();

    //
    void HsvBtnClicked();

    //
    void CerrarHsvBtnClicked();

    //
    void ErosionValueChanged();

    //
    void HsvIzqValueChanged();

    //
    void HsvDerValueChanged();

private:
    explicit VentanaAjustes(QWidget *parent = 0);
    Ui::VentanaAjustes *ui;
    QTimer* mTimerImagenHsv;
};

#endif // VENTANAAJUSTES_H
