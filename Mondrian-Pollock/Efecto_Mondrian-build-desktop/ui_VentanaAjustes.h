/********************************************************************************
** Form generated from reading UI file 'VentanaAjustes.ui'
**
** Created: Tue 23. Aug 18:38:38 2011
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
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VentanaAjustes
{
public:
    QLabel *label_fondo;
    QLabel *label_valor_thres1;
    QPushButton *btn_default;
    QLabel *label_11;
    QSlider *barra_thres1;
    QLabel *label_12;
    QLabel *ayuda_thres1;
    QPushButton *btn_guardar_fondo;
    QLabel *ayuda_erode;
    QLabel *label_valor_erode;
    QSlider *barra_erode;

    void setupUi(QWidget *VentanaAjustes)
    {
        if (VentanaAjustes->objectName().isEmpty())
            VentanaAjustes->setObjectName(QString::fromUtf8("VentanaAjustes"));
        VentanaAjustes->resize(335, 301);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/Imagenes/icono.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        VentanaAjustes->setWindowIcon(icon);
        label_fondo = new QLabel(VentanaAjustes);
        label_fondo->setObjectName(QString::fromUtf8("label_fondo"));
        label_fondo->setGeometry(QRect(0, 0, 341, 301));
        label_fondo->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/Imagenes/fondo_ajustes.jpg")));
        label_valor_thres1 = new QLabel(VentanaAjustes);
        label_valor_thres1->setObjectName(QString::fromUtf8("label_valor_thres1"));
        label_valor_thres1->setGeometry(QRect(170, 30, 46, 13));
        btn_default = new QPushButton(VentanaAjustes);
        btn_default->setObjectName(QString::fromUtf8("btn_default"));
        btn_default->setGeometry(QRect(200, 210, 75, 23));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        btn_default->setFont(font);
        label_11 = new QLabel(VentanaAjustes);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(40, 30, 46, 13));
        barra_thres1 = new QSlider(VentanaAjustes);
        barra_thres1->setObjectName(QString::fromUtf8("barra_thres1"));
        barra_thres1->setGeometry(QRect(30, 60, 211, 19));
        barra_thres1->setMaximum(255);
        barra_thres1->setValue(15);
        barra_thres1->setOrientation(Qt::Horizontal);
        label_12 = new QLabel(VentanaAjustes);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(40, 110, 46, 13));
        ayuda_thres1 = new QLabel(VentanaAjustes);
        ayuda_thres1->setObjectName(QString::fromUtf8("ayuda_thres1"));
        ayuda_thres1->setGeometry(QRect(250, 40, 21, 21));
        ayuda_thres1->setCursor(QCursor(Qt::WhatsThisCursor));
        ayuda_thres1->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/Imagenes/help_icon.jpg")));
        btn_guardar_fondo = new QPushButton(VentanaAjustes);
        btn_guardar_fondo->setObjectName(QString::fromUtf8("btn_guardar_fondo"));
        btn_guardar_fondo->setGeometry(QRect(34, 210, 101, 23));
        btn_guardar_fondo->setFont(font);
        ayuda_erode = new QLabel(VentanaAjustes);
        ayuda_erode->setObjectName(QString::fromUtf8("ayuda_erode"));
        ayuda_erode->setGeometry(QRect(250, 140, 21, 21));
        ayuda_erode->setCursor(QCursor(Qt::WhatsThisCursor));
        ayuda_erode->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/Imagenes/help_icon.jpg")));
        label_valor_erode = new QLabel(VentanaAjustes);
        label_valor_erode->setObjectName(QString::fromUtf8("label_valor_erode"));
        label_valor_erode->setGeometry(QRect(170, 110, 46, 13));
        barra_erode = new QSlider(VentanaAjustes);
        barra_erode->setObjectName(QString::fromUtf8("barra_erode"));
        barra_erode->setGeometry(QRect(30, 150, 211, 19));
        barra_erode->setMaximum(7);
        barra_erode->setOrientation(Qt::Horizontal);

        retranslateUi(VentanaAjustes);
        QObject::connect(barra_erode, SIGNAL(valueChanged(int)), label_valor_erode, SLOT(setNum(int)));
        QObject::connect(barra_thres1, SIGNAL(valueChanged(int)), label_valor_thres1, SLOT(setNum(int)));

        QMetaObject::connectSlotsByName(VentanaAjustes);
    } // setupUi

    void retranslateUi(QWidget *VentanaAjustes)
    {
        VentanaAjustes->setWindowTitle(QApplication::translate("VentanaAjustes", "Mondrian Effect - Costa Rica Institute of Technology", 0, QApplication::UnicodeUTF8));
        label_fondo->setText(QString());
        label_valor_thres1->setText(QApplication::translate("VentanaAjustes", "15", 0, QApplication::UnicodeUTF8));
        btn_default->setText(QApplication::translate("VentanaAjustes", "Default", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("VentanaAjustes", "Thres1", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("VentanaAjustes", "Erosion", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        ayuda_thres1->setToolTip(QApplication::translate("VentanaAjustes", "Aumente este valor en caso de que se distorsione mucho la imagen al estar una persona frente a la camara", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        ayuda_thres1->setText(QString());
        btn_guardar_fondo->setText(QApplication::translate("VentanaAjustes", "Set background", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        ayuda_erode->setToolTip(QApplication::translate("VentanaAjustes", "Aumente este valor para eliminar pequenos puntos de color no deseados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        ayuda_erode->setText(QString());
        label_valor_erode->setText(QApplication::translate("VentanaAjustes", "0", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VentanaAjustes: public Ui_VentanaAjustes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAAJUSTES_H
