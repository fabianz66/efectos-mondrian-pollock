/********************************************************************************
** Form generated from reading UI file 'VentanaAjustes.ui'
**
** Created: Tue 13. Sep 21:03:20 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANAAJUSTES_H
#define UI_VENTANAAJUSTES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VentanaAjustes
{
public:
    QLabel *label;
    QFrame *frame_click_hsv;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *label_35;
    QLabel *label_click_h;
    QLabel *label_click_s;
    QLabel *label_click_v;
    QSlider *barra_erode_der;
    QSpinBox *h_min_der;
    QLabel *label_28;
    QSlider *barra_erode_izq;
    QLabel *label_20;
    QLabel *label_24;
    QLabel *label_19;
    QSpinBox *v_max_izq;
    QSpinBox *s_min_izq;
    QPushButton *btn_hsv_ajustes;
    QSpinBox *v_min_izq;
    QSpinBox *s_min_der;
    QSpinBox *s_max_izq;
    QLabel *label_26;
    QPushButton *btn_cerrar_hsv;
    QLabel *label_23;
    QLabel *label_18;
    QSpinBox *s_max_der;
    QLabel *label_30;
    QLabel *label_29;
    QLabel *label_39;
    QSpinBox *v_max_der;
    QLabel *label_41;
    QLabel *label_21;
    QLabel *label_17;
    QSpinBox *h_min_izq;
    QSpinBox *h_max_izq;
    QSpinBox *v_min_der;
    QLabel *label_40;
    QSpinBox *h_max_der;
    QLabel *label_27;
    QLabel *label_25;

    void setupUi(QWidget *VentanaAjustes)
    {
        if (VentanaAjustes->objectName().isEmpty())
            VentanaAjustes->setObjectName(QString::fromUtf8("VentanaAjustes"));
        VentanaAjustes->resize(400, 298);
        VentanaAjustes->setMinimumSize(QSize(400, 298));
        VentanaAjustes->setMaximumSize(QSize(400, 298));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        VentanaAjustes->setWindowIcon(icon);
        label = new QLabel(VentanaAjustes);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 400, 300));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/ventanaAjustes.jpg")));
        frame_click_hsv = new QFrame(VentanaAjustes);
        frame_click_hsv->setObjectName(QString::fromUtf8("frame_click_hsv"));
        frame_click_hsv->setGeometry(QRect(10, 250, 161, 33));
        frame_click_hsv->setFrameShape(QFrame::StyledPanel);
        frame_click_hsv->setFrameShadow(QFrame::Raised);
        label_33 = new QLabel(frame_click_hsv);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(10, 10, 11, 13));
        label_34 = new QLabel(frame_click_hsv);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(60, 10, 10, 13));
        label_35 = new QLabel(frame_click_hsv);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(110, 10, 10, 13));
        label_click_h = new QLabel(frame_click_hsv);
        label_click_h->setObjectName(QString::fromUtf8("label_click_h"));
        label_click_h->setGeometry(QRect(30, 10, 31, 16));
        label_click_s = new QLabel(frame_click_hsv);
        label_click_s->setObjectName(QString::fromUtf8("label_click_s"));
        label_click_s->setGeometry(QRect(80, 10, 31, 16));
        label_click_v = new QLabel(frame_click_hsv);
        label_click_v->setObjectName(QString::fromUtf8("label_click_v"));
        label_click_v->setGeometry(QRect(130, 10, 31, 16));
        label_33->raise();
        label_click_h->raise();
        label_click_s->raise();
        label_click_v->raise();
        label_35->raise();
        label_34->raise();
        barra_erode_der = new QSlider(VentanaAjustes);
        barra_erode_der->setObjectName(QString::fromUtf8("barra_erode_der"));
        barra_erode_der->setGeometry(QRect(220, 70, 160, 19));
        barra_erode_der->setMaximum(25);
        barra_erode_der->setPageStep(5);
        barra_erode_der->setValue(1);
        barra_erode_der->setOrientation(Qt::Horizontal);
        h_min_der = new QSpinBox(VentanaAjustes);
        h_min_der->setObjectName(QString::fromUtf8("h_min_der"));
        h_min_der->setGeometry(QRect(250, 140, 42, 22));
        h_min_der->setMaximum(500);
        h_min_der->setValue(99);
        label_28 = new QLabel(VentanaAjustes);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(230, 170, 6, 13));
        barra_erode_izq = new QSlider(VentanaAjustes);
        barra_erode_izq->setObjectName(QString::fromUtf8("barra_erode_izq"));
        barra_erode_izq->setGeometry(QRect(10, 70, 160, 19));
        barra_erode_izq->setMaximum(25);
        barra_erode_izq->setPageStep(5);
        barra_erode_izq->setValue(1);
        barra_erode_izq->setOrientation(Qt::Horizontal);
        label_20 = new QLabel(VentanaAjustes);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(300, 50, 46, 13));
        label_24 = new QLabel(VentanaAjustes);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(30, 170, 6, 13));
        label_19 = new QLabel(VentanaAjustes);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(230, 50, 46, 13));
        v_max_izq = new QSpinBox(VentanaAjustes);
        v_max_izq->setObjectName(QString::fromUtf8("v_max_izq"));
        v_max_izq->setGeometry(QRect(100, 200, 42, 22));
        v_max_izq->setMaximum(500);
        v_max_izq->setValue(255);
        s_min_izq = new QSpinBox(VentanaAjustes);
        s_min_izq->setObjectName(QString::fromUtf8("s_min_izq"));
        s_min_izq->setGeometry(QRect(50, 170, 42, 22));
        s_min_izq->setMaximum(500);
        s_min_izq->setValue(150);
        btn_hsv_ajustes = new QPushButton(VentanaAjustes);
        btn_hsv_ajustes->setObjectName(QString::fromUtf8("btn_hsv_ajustes"));
        btn_hsv_ajustes->setGeometry(QRect(220, 250, 75, 23));
        v_min_izq = new QSpinBox(VentanaAjustes);
        v_min_izq->setObjectName(QString::fromUtf8("v_min_izq"));
        v_min_izq->setGeometry(QRect(50, 200, 42, 22));
        v_min_izq->setMaximum(500);
        v_min_izq->setValue(130);
        s_min_der = new QSpinBox(VentanaAjustes);
        s_min_der->setObjectName(QString::fromUtf8("s_min_der"));
        s_min_der->setGeometry(QRect(250, 170, 42, 22));
        s_min_der->setMaximum(500);
        s_min_der->setValue(195);
        s_max_izq = new QSpinBox(VentanaAjustes);
        s_max_izq->setObjectName(QString::fromUtf8("s_max_izq"));
        s_max_izq->setGeometry(QRect(100, 170, 42, 22));
        s_max_izq->setMaximum(500);
        s_max_izq->setValue(230);
        label_26 = new QLabel(VentanaAjustes);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(230, 140, 7, 13));
        btn_cerrar_hsv = new QPushButton(VentanaAjustes);
        btn_cerrar_hsv->setObjectName(QString::fromUtf8("btn_cerrar_hsv"));
        btn_cerrar_hsv->setGeometry(QRect(300, 250, 75, 23));
        label_23 = new QLabel(VentanaAjustes);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(30, 140, 7, 13));
        label_18 = new QLabel(VentanaAjustes);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(90, 50, 46, 13));
        s_max_der = new QSpinBox(VentanaAjustes);
        s_max_der->setObjectName(QString::fromUtf8("s_max_der"));
        s_max_der->setGeometry(QRect(300, 170, 42, 22));
        s_max_der->setMaximum(500);
        s_max_der->setValue(215);
        label_30 = new QLabel(VentanaAjustes);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(120, 230, 46, 13));
        label_29 = new QLabel(VentanaAjustes);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(60, 230, 46, 13));
        label_39 = new QLabel(VentanaAjustes);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(220, 110, 94, 13));
        v_max_der = new QSpinBox(VentanaAjustes);
        v_max_der->setObjectName(QString::fromUtf8("v_max_der"));
        v_max_der->setGeometry(QRect(300, 200, 42, 22));
        v_max_der->setMaximum(500);
        v_max_der->setValue(255);
        label_41 = new QLabel(VentanaAjustes);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(310, 230, 46, 13));
        label_21 = new QLabel(VentanaAjustes);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(10, 110, 94, 13));
        label_17 = new QLabel(VentanaAjustes);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(20, 50, 46, 13));
        h_min_izq = new QSpinBox(VentanaAjustes);
        h_min_izq->setObjectName(QString::fromUtf8("h_min_izq"));
        h_min_izq->setGeometry(QRect(50, 140, 42, 22));
        h_min_izq->setMaximum(500);
        h_min_izq->setValue(25);
        h_max_izq = new QSpinBox(VentanaAjustes);
        h_max_izq->setObjectName(QString::fromUtf8("h_max_izq"));
        h_max_izq->setGeometry(QRect(100, 140, 42, 22));
        h_max_izq->setMaximum(500);
        h_max_izq->setValue(50);
        v_min_der = new QSpinBox(VentanaAjustes);
        v_min_der->setObjectName(QString::fromUtf8("v_min_der"));
        v_min_der->setGeometry(QRect(250, 200, 42, 22));
        v_min_der->setMaximum(500);
        v_min_der->setValue(150);
        label_40 = new QLabel(VentanaAjustes);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(250, 230, 46, 13));
        h_max_der = new QSpinBox(VentanaAjustes);
        h_max_der->setObjectName(QString::fromUtf8("h_max_der"));
        h_max_der->setGeometry(QRect(300, 140, 42, 22));
        h_max_der->setMaximum(500);
        h_max_der->setValue(110);
        label_27 = new QLabel(VentanaAjustes);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(230, 200, 6, 13));
        label_25 = new QLabel(VentanaAjustes);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(30, 200, 6, 13));

        retranslateUi(VentanaAjustes);
        QObject::connect(barra_erode_izq, SIGNAL(valueChanged(int)), label_18, SLOT(setNum(int)));
        QObject::connect(barra_erode_der, SIGNAL(valueChanged(int)), label_20, SLOT(setNum(int)));

        QMetaObject::connectSlotsByName(VentanaAjustes);
    } // setupUi

    void retranslateUi(QWidget *VentanaAjustes)
    {
        VentanaAjustes->setWindowTitle(QApplication::translate("VentanaAjustes", "Pollock Effect - Costa Rica Institute of Technology", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_33->setText(QApplication::translate("VentanaAjustes", "H:", 0, QApplication::UnicodeUTF8));
        label_34->setText(QApplication::translate("VentanaAjustes", "S:", 0, QApplication::UnicodeUTF8));
        label_35->setText(QApplication::translate("VentanaAjustes", "V:", 0, QApplication::UnicodeUTF8));
        label_click_h->setText(QApplication::translate("VentanaAjustes", "0", 0, QApplication::UnicodeUTF8));
        label_click_s->setText(QApplication::translate("VentanaAjustes", "0", 0, QApplication::UnicodeUTF8));
        label_click_v->setText(QApplication::translate("VentanaAjustes", "0", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("VentanaAjustes", "S", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("VentanaAjustes", "1", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("VentanaAjustes", "S", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("VentanaAjustes", "Erosion", 0, QApplication::UnicodeUTF8));
        btn_hsv_ajustes->setText(QApplication::translate("VentanaAjustes", "Open HSV", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("VentanaAjustes", "H", 0, QApplication::UnicodeUTF8));
        btn_cerrar_hsv->setText(QApplication::translate("VentanaAjustes", "Close HSV", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("VentanaAjustes", "H", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("VentanaAjustes", "1", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("VentanaAjustes", "Max", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("VentanaAjustes", "Min", 0, QApplication::UnicodeUTF8));
        label_39->setText(QApplication::translate("VentanaAjustes", "Color para detectar", 0, QApplication::UnicodeUTF8));
        label_41->setText(QApplication::translate("VentanaAjustes", "Max", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("VentanaAjustes", "Color para detectar", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("VentanaAjustes", "Erosion", 0, QApplication::UnicodeUTF8));
        label_40->setText(QApplication::translate("VentanaAjustes", "Min", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("VentanaAjustes", "V", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("VentanaAjustes", "V", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VentanaAjustes: public Ui_VentanaAjustes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAAJUSTES_H
