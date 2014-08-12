/********************************************************************************
** Form generated from reading UI file 'VentanaPrincipal.ui'
**
** Created: Tue 13. Sep 21:12:38 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANAPRINCIPAL_H
#define UI_VENTANAPRINCIPAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VentanaPrincipal
{
public:
    QAction *actionStart_Capture;
    QAction *actionDetection_Color;
    QAction *actionReset_Left;
    QAction *actionReset_Right;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *contenedor_ventanas;
    QWidget *page;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame;
    QLabel *label_recorrido_iz;
    QLabel *label_deteccion_iz;
    QFrame *frame_2;
    QLabel *label_recorrido_der;
    QLabel *label_deteccion_der;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuSettings;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VentanaPrincipal)
    {
        if (VentanaPrincipal->objectName().isEmpty())
            VentanaPrincipal->setObjectName(QString::fromUtf8("VentanaPrincipal"));
        VentanaPrincipal->resize(1369, 772);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        VentanaPrincipal->setWindowIcon(icon);
        actionStart_Capture = new QAction(VentanaPrincipal);
        actionStart_Capture->setObjectName(QString::fromUtf8("actionStart_Capture"));
        actionDetection_Color = new QAction(VentanaPrincipal);
        actionDetection_Color->setObjectName(QString::fromUtf8("actionDetection_Color"));
        actionReset_Left = new QAction(VentanaPrincipal);
        actionReset_Left->setObjectName(QString::fromUtf8("actionReset_Left"));
        actionReset_Right = new QAction(VentanaPrincipal);
        actionReset_Right->setObjectName(QString::fromUtf8("actionReset_Right"));
        centralWidget = new QWidget(VentanaPrincipal);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8("background-image: url(:/images/fondo.jpg);"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        contenedor_ventanas = new QStackedWidget(centralWidget);
        contenedor_ventanas->setObjectName(QString::fromUtf8("contenedor_ventanas"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_3 = new QVBoxLayout(page);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_4 = new QLabel(page);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/images/fondo_inicio.jpg")));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_4);

        contenedor_ventanas->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_2 = new QVBoxLayout(page_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(page_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/fondo_principal.jpg")));
        label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout->addWidget(label);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        frame = new QFrame(page_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(640, 480));
        frame->setMaximumSize(QSize(640, 480));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_recorrido_iz = new QLabel(frame);
        label_recorrido_iz->setObjectName(QString::fromUtf8("label_recorrido_iz"));
        label_recorrido_iz->setGeometry(QRect(0, 0, 640, 480));
        label_recorrido_iz->setMinimumSize(QSize(640, 480));
        label_deteccion_iz = new QLabel(frame);
        label_deteccion_iz->setObjectName(QString::fromUtf8("label_deteccion_iz"));
        label_deteccion_iz->setGeometry(QRect(360, 285, 270, 190));
        label_deteccion_iz->setMinimumSize(QSize(270, 190));
        label_deteccion_iz->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 255, 255);\n"
"selection-color: rgb(255, 255, 255);\n"
"gridline-color: rgb(255, 255, 255);"));
        label_deteccion_iz->setFrameShape(QFrame::StyledPanel);
        label_deteccion_iz->setLineWidth(1);

        horizontalLayout_3->addWidget(frame);

        frame_2 = new QFrame(page_2);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMinimumSize(QSize(640, 480));
        frame_2->setMaximumSize(QSize(640, 480));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_recorrido_der = new QLabel(frame_2);
        label_recorrido_der->setObjectName(QString::fromUtf8("label_recorrido_der"));
        label_recorrido_der->setGeometry(QRect(0, 0, 640, 480));
        label_recorrido_der->setMinimumSize(QSize(640, 480));
        label_deteccion_der = new QLabel(frame_2);
        label_deteccion_der->setObjectName(QString::fromUtf8("label_deteccion_der"));
        label_deteccion_der->setGeometry(QRect(360, 285, 270, 190));
        label_deteccion_der->setMinimumSize(QSize(270, 190));
        label_deteccion_der->setFrameShape(QFrame::StyledPanel);
        label_deteccion_der->setLineWidth(1);
        label_deteccion_der->setMidLineWidth(1);

        horizontalLayout_3->addWidget(frame_2);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        contenedor_ventanas->addWidget(page_2);

        horizontalLayout->addWidget(contenedor_ventanas);


        horizontalLayout_2->addLayout(horizontalLayout);

        VentanaPrincipal->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(VentanaPrincipal);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1369, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        VentanaPrincipal->setMenuBar(menuBar);
        mainToolBar = new QToolBar(VentanaPrincipal);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        VentanaPrincipal->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(VentanaPrincipal);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        VentanaPrincipal->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuFile->addAction(actionStart_Capture);
        menuSettings->addSeparator();
        menuSettings->addAction(actionDetection_Color);
        menuSettings->addAction(actionReset_Left);
        menuSettings->addAction(actionReset_Right);

        retranslateUi(VentanaPrincipal);

        contenedor_ventanas->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(VentanaPrincipal);
    } // setupUi

    void retranslateUi(QMainWindow *VentanaPrincipal)
    {
        VentanaPrincipal->setWindowTitle(QApplication::translate("VentanaPrincipal", "Pollock Effect - Costa Rica Institute of Technology", 0, QApplication::UnicodeUTF8));
        actionStart_Capture->setText(QApplication::translate("VentanaPrincipal", "Start Capture", 0, QApplication::UnicodeUTF8));
        actionDetection_Color->setText(QApplication::translate("VentanaPrincipal", "Color Detection", 0, QApplication::UnicodeUTF8));
        actionReset_Left->setText(QApplication::translate("VentanaPrincipal", "Reset Left", 0, QApplication::UnicodeUTF8));
        actionReset_Right->setText(QApplication::translate("VentanaPrincipal", "Reset Right", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
        label->setText(QString());
        label_recorrido_iz->setText(QApplication::translate("VentanaPrincipal", "Camara1", 0, QApplication::UnicodeUTF8));
        label_deteccion_iz->setText(QApplication::translate("VentanaPrincipal", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_recorrido_der->setText(QApplication::translate("VentanaPrincipal", "Camara2", 0, QApplication::UnicodeUTF8));
        label_deteccion_der->setText(QApplication::translate("VentanaPrincipal", "TextLabel", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("VentanaPrincipal", "File", 0, QApplication::UnicodeUTF8));
        menuSettings->setTitle(QApplication::translate("VentanaPrincipal", "Settings", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VentanaPrincipal: public Ui_VentanaPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAPRINCIPAL_H
