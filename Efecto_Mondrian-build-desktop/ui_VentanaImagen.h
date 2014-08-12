/********************************************************************************
** Form generated from reading UI file 'VentanaImagen.ui'
**
** Created: Tue 23. Aug 18:38:38 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANAIMAGEN_H
#define UI_VENTANAIMAGEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VentanaImagen
{
public:
    QLabel *label_foto_mondrian;
    QLabel *label_foto_original;
    QLabel *label_titulo;
    QPushButton *btn_ajustes;

    void setupUi(QWidget *VentanaImagen)
    {
        if (VentanaImagen->objectName().isEmpty())
            VentanaImagen->setObjectName(QString::fromUtf8("VentanaImagen"));
        VentanaImagen->resize(960, 720);
        VentanaImagen->setMinimumSize(QSize(960, 720));
        VentanaImagen->setMaximumSize(QSize(960, 720));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/Imagenes/icono.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        VentanaImagen->setWindowIcon(icon);
        label_foto_mondrian = new QLabel(VentanaImagen);
        label_foto_mondrian->setObjectName(QString::fromUtf8("label_foto_mondrian"));
        label_foto_mondrian->setGeometry(QRect(0, 0, 960, 720));
        label_foto_original = new QLabel(VentanaImagen);
        label_foto_original->setObjectName(QString::fromUtf8("label_foto_original"));
        label_foto_original->setGeometry(QRect(710, 140, 237, 178));
        label_titulo = new QLabel(VentanaImagen);
        label_titulo->setObjectName(QString::fromUtf8("label_titulo"));
        label_titulo->setGeometry(QRect(0, 0, 960, 200));
        label_titulo->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/Imagenes/titulo.jpg")));
        btn_ajustes = new QPushButton(VentanaImagen);
        btn_ajustes->setObjectName(QString::fromUtf8("btn_ajustes"));
        btn_ajustes->setGeometry(QRect(70, 170, 75, 23));

        retranslateUi(VentanaImagen);

        QMetaObject::connectSlotsByName(VentanaImagen);
    } // setupUi

    void retranslateUi(QWidget *VentanaImagen)
    {
        VentanaImagen->setWindowTitle(QApplication::translate("VentanaImagen", "Mondrian Effect - Costa Rica Institute of Technology", 0, QApplication::UnicodeUTF8));
        label_foto_mondrian->setText(QString());
        label_foto_original->setText(QString());
        label_titulo->setText(QString());
        btn_ajustes->setText(QApplication::translate("VentanaImagen", "Settings", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VentanaImagen: public Ui_VentanaImagen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAIMAGEN_H
