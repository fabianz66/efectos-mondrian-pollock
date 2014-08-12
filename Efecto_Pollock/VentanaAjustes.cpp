#include "VentanaAjustes.h"
#include "ui_VentanaAjustes.h"

VentanaAjustes::VentanaAjustes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VentanaAjustes)
{
    ui->setupUi(this);

    //Se oculta lo necesario
    ui->btn_cerrar_hsv->hide();

    //Se instancia el QTimer para actualizar la ventana
    mTimerImagenHsv = new QTimer();

    //Se conectan los eventos con los widgets
    connect(ui->btn_hsv_ajustes, SIGNAL(clicked()), this, SLOT(HsvBtnClicked()));
    connect(ui->btn_cerrar_hsv, SIGNAL(clicked()), this, SLOT(CerrarHsvBtnClicked()));
    connect(ui->barra_erode_der, SIGNAL(valueChanged(int)), this, SLOT(ErosionValueChanged()));
    connect(ui->barra_erode_izq, SIGNAL(valueChanged(int)), this, SLOT(ErosionValueChanged()));

    //Se conectan
    connect(ui->h_max_der, SIGNAL(valueChanged(int)), this, SLOT(HsvDerValueChanged()));
    connect(ui->s_max_der, SIGNAL(valueChanged(int)), this, SLOT(HsvDerValueChanged()));
    connect(ui->v_max_der, SIGNAL(valueChanged(int)), this, SLOT(HsvDerValueChanged()));
    connect(ui->h_min_der, SIGNAL(valueChanged(int)), this, SLOT(HsvDerValueChanged()));
    connect(ui->h_min_der, SIGNAL(valueChanged(int)), this, SLOT(HsvDerValueChanged()));
    connect(ui->h_min_der, SIGNAL(valueChanged(int)), this, SLOT(HsvDerValueChanged()));

    connect(ui->h_max_izq, SIGNAL(valueChanged(int)), this, SLOT(HsvIzqValueChanged()));
    connect(ui->s_max_izq, SIGNAL(valueChanged(int)), this, SLOT(HsvIzqValueChanged()));
    connect(ui->v_max_izq, SIGNAL(valueChanged(int)), this, SLOT(HsvIzqValueChanged()));
    connect(ui->h_min_izq, SIGNAL(valueChanged(int)), this, SLOT(HsvIzqValueChanged()));
    connect(ui->s_min_izq, SIGNAL(valueChanged(int)), this, SLOT(HsvIzqValueChanged()));
    connect(ui->v_min_izq, SIGNAL(valueChanged(int)), this, SLOT(HsvIzqValueChanged()));

    HsvDerValueChanged();
    HsvIzqValueChanged();
}

VentanaAjustes& VentanaAjustes::GetInstance()
{
    static VentanaAjustes instance;
    return instance;
}

void VentanaAjustes::HsvBtnClicked()
{
    cvNamedWindow("Hsv Image");
    ui->btn_cerrar_hsv->show();
    if(!mTimerImagenHsv->isActive())
    {
        connect(mTimerImagenHsv, SIGNAL(timeout()), this, SLOT(MostrarImagenHsv()));
        mTimerImagenHsv->start(DELAY_FRAME_CAMARA_MILI_SEG);
    }
}

void VentanaAjustes::SetClickedValues(int rH, int rS, int rV)
{
    ui->label_click_h->setNum(rH);
    ui->label_click_s->setNum(rS);
    ui->label_click_v->setNum(rV);
}

void VentanaAjustes::MostrarImagenHsv()
{
    Notify(CODIGO_MOSTRAR_CAM_HSV);
}

void VentanaAjustes::CerrarHsvBtnClicked()
{
    //Se detiene el QTimer
    mTimerImagenHsv->stop();
    mTimerImagenHsv->disconnect();

    //Se destruye la ventana y se oculta el boton
    cvDestroyAllWindows();
    ui->btn_cerrar_hsv->hide();
}

void VentanaAjustes::ErosionValueChanged()
{
    Notify(CODIGO_CAMBIO_EROSION);
}

int VentanaAjustes::GetErosionDer()
{
    return ui->barra_erode_der->value();
}

int VentanaAjustes::GetErosionIzq()
{
    return ui->barra_erode_izq->value();
}

void VentanaAjustes::HsvDerValueChanged()
{
    Notify(CODIGO_CAMBIO_HSV_DER);
}

void VentanaAjustes::HsvIzqValueChanged()
{
    Notify(CODIGO_CAMBIO_HSV_IZQ);
}

CvScalar VentanaAjustes::GetMaxHsvDer()
{
    return cvScalar(ui->h_max_der->value(),ui->s_max_der->value(),ui->v_max_der->value());
}

CvScalar VentanaAjustes::GetMinHsvDer()
{
    return cvScalar(ui->h_min_der->value(),ui->s_min_der->value(),ui->v_min_der->value());
}

CvScalar VentanaAjustes::GetMaxHsvIzq()
{
    return cvScalar(ui->h_max_izq->value(),ui->s_max_izq->value(),ui->v_max_izq->value());
}

CvScalar VentanaAjustes::GetMinHsvIzq()
{
    return cvScalar(ui->h_min_izq->value(),ui->s_min_izq->value(),ui->v_min_izq->value());
}
