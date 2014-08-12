/********************************************************************************
** Form generated from reading UI file 'VentanaInicio.ui'
**
** Created: Tue 23. Aug 18:38:37 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANAINICIO_H
#define UI_VENTANAINICIO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VentanaInicio
{
public:
    QLabel *label_fondo;
    QPushButton *btn_inicio;

    void setupUi(QWidget *VentanaInicio)
    {
        if (VentanaInicio->objectName().isEmpty())
            VentanaInicio->setObjectName(QString::fromUtf8("VentanaInicio"));
        VentanaInicio->resize(800, 600);
        VentanaInicio->setMinimumSize(QSize(800, 600));
        VentanaInicio->setMaximumSize(QSize(800, 600));
        VentanaInicio->setCursor(QCursor(Qt::ArrowCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/Imagenes/icono.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        VentanaInicio->setWindowIcon(icon);
        label_fondo = new QLabel(VentanaInicio);
        label_fondo->setObjectName(QString::fromUtf8("label_fondo"));
        label_fondo->setGeometry(QRect(0, 0, 801, 601));
        label_fondo->setCursor(QCursor(Qt::PointingHandCursor));
        label_fondo->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/Imagenes/fondo_inicio.jpg")));
        btn_inicio = new QPushButton(VentanaInicio);
        btn_inicio->setObjectName(QString::fromUtf8("btn_inicio"));
        btn_inicio->setGeometry(QRect(520, 210, 141, 141));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/Imagenes/boton.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_inicio->setIcon(icon1);
        btn_inicio->setIconSize(QSize(150, 150));

        retranslateUi(VentanaInicio);

        QMetaObject::connectSlotsByName(VentanaInicio);
    } // setupUi

    void retranslateUi(QWidget *VentanaInicio)
    {
        VentanaInicio->setWindowTitle(QApplication::translate("VentanaInicio", "Mondrian Effect - Costa Rica Institute of Technology", 0, QApplication::UnicodeUTF8));
        label_fondo->setText(QString());
        btn_inicio->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VentanaInicio: public Ui_VentanaInicio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAINICIO_H
