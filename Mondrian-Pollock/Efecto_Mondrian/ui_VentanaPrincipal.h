/********************************************************************************
** Form generated from reading UI file 'VentanaPrincipal.ui'
**
** Created: Tue Sep 9 07:45:58 2014
**      by: Qt User Interface Compiler version 4.8.1
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
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VentanaPrincipal
{
public:
    QAction *actionStar_Capture;
    QAction *action_set_background;
    QAction *action_Set_Filters;
    QAction *action_iniciar_captura;
    QAction *action_about;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QStackedWidget *contenedor_ventanas;
    QWidget *pagina_inicial;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_fondo_inicio;
    QWidget *pagina_camara;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QFrame *line;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_foto_mondrian;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_foto_original;
    QFrame *frame;
    QFrame *frame_2;
    QLabel *label_4;
    QLabel *label_5;
    QSlider *barra_thres1;
    QLabel *label;
    QLabel *label_2;
    QSlider *barra_erode;
    QPushButton *btn_default_ajustes;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QMenuBar *barra_heramientas;
    QMenu *barra_file;
    QMenu *barra_settings;
    QMenu *barra_help;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *VentanaPrincipal)
    {
        if (VentanaPrincipal->objectName().isEmpty())
            VentanaPrincipal->setObjectName(QString::fromUtf8("VentanaPrincipal"));
        VentanaPrincipal->resize(1120, 677);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/icono.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        VentanaPrincipal->setWindowIcon(icon);
        actionStar_Capture = new QAction(VentanaPrincipal);
        actionStar_Capture->setObjectName(QString::fromUtf8("actionStar_Capture"));
        action_set_background = new QAction(VentanaPrincipal);
        action_set_background->setObjectName(QString::fromUtf8("action_set_background"));
        action_Set_Filters = new QAction(VentanaPrincipal);
        action_Set_Filters->setObjectName(QString::fromUtf8("action_Set_Filters"));
        action_iniciar_captura = new QAction(VentanaPrincipal);
        action_iniciar_captura->setObjectName(QString::fromUtf8("action_iniciar_captura"));
        action_about = new QAction(VentanaPrincipal);
        action_about->setObjectName(QString::fromUtf8("action_about"));
        centralwidget = new QWidget(VentanaPrincipal);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        contenedor_ventanas = new QStackedWidget(centralwidget);
        contenedor_ventanas->setObjectName(QString::fromUtf8("contenedor_ventanas"));
        contenedor_ventanas->setLineWidth(0);
        pagina_inicial = new QWidget();
        pagina_inicial->setObjectName(QString::fromUtf8("pagina_inicial"));
        horizontalLayout_2 = new QHBoxLayout(pagina_inicial);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_fondo_inicio = new QLabel(pagina_inicial);
        label_fondo_inicio->setObjectName(QString::fromUtf8("label_fondo_inicio"));
        label_fondo_inicio->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/fondo_inicio.jpg")));
        label_fondo_inicio->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_fondo_inicio);

        contenedor_ventanas->addWidget(pagina_inicial);
        pagina_camara = new QWidget();
        pagina_camara->setObjectName(QString::fromUtf8("pagina_camara"));
        verticalLayout = new QVBoxLayout(pagina_camara);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(pagina_camara);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/titulo.jpg")));
        label_3->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout->addWidget(label_3);

        line = new QFrame(pagina_camara);
        line->setObjectName(QString::fromUtf8("line"));
        line->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"gridline-color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 255, 255);"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_foto_mondrian = new QLabel(pagina_camara);
        label_foto_mondrian->setObjectName(QString::fromUtf8("label_foto_mondrian"));
        label_foto_mondrian->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_foto_mondrian);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_foto_original = new QLabel(pagina_camara);
        label_foto_original->setObjectName(QString::fromUtf8("label_foto_original"));
        label_foto_original->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout_2->addWidget(label_foto_original);

        frame = new QFrame(pagina_camara);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(0, 200));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(0, 10, 221, 191));
        frame_2->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 255, 255);\n"
"gridline-color: rgb(255, 255, 255);"));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_2->setMidLineWidth(1);
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 20, 46, 13));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255,255, 255);"));
        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(140, 20, 46, 13));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255,255, 255);"));
        barra_thres1 = new QSlider(frame_2);
        barra_thres1->setObjectName(QString::fromUtf8("barra_thres1"));
        barra_thres1->setGeometry(QRect(30, 40, 160, 19));
        barra_thres1->setOrientation(Qt::Horizontal);
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 80, 46, 13));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(140, 80, 46, 13));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        barra_erode = new QSlider(frame_2);
        barra_erode->setObjectName(QString::fromUtf8("barra_erode"));
        barra_erode->setGeometry(QRect(30, 110, 160, 19));
        barra_erode->setOrientation(Qt::Horizontal);
        btn_default_ajustes = new QPushButton(frame_2);
        btn_default_ajustes->setObjectName(QString::fromUtf8("btn_default_ajustes"));
        btn_default_ajustes->setGeometry(QRect(70, 140, 75, 23));

        verticalLayout_2->addWidget(frame);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout_3);

        contenedor_ventanas->addWidget(pagina_camara);

        horizontalLayout->addWidget(contenedor_ventanas);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        VentanaPrincipal->setCentralWidget(centralwidget);
        barra_heramientas = new QMenuBar(VentanaPrincipal);
        barra_heramientas->setObjectName(QString::fromUtf8("barra_heramientas"));
        barra_heramientas->setGeometry(QRect(0, 0, 1120, 21));
        barra_file = new QMenu(barra_heramientas);
        barra_file->setObjectName(QString::fromUtf8("barra_file"));
        barra_settings = new QMenu(barra_heramientas);
        barra_settings->setObjectName(QString::fromUtf8("barra_settings"));
        barra_help = new QMenu(barra_heramientas);
        barra_help->setObjectName(QString::fromUtf8("barra_help"));
        VentanaPrincipal->setMenuBar(barra_heramientas);
        statusbar = new QStatusBar(VentanaPrincipal);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        VentanaPrincipal->setStatusBar(statusbar);

        barra_heramientas->addAction(barra_file->menuAction());
        barra_heramientas->addAction(barra_settings->menuAction());
        barra_heramientas->addAction(barra_help->menuAction());
        barra_file->addAction(action_iniciar_captura);
        barra_settings->addAction(action_set_background);
        barra_help->addAction(action_about);

        retranslateUi(VentanaPrincipal);
        QObject::connect(barra_erode, SIGNAL(valueChanged(int)), label_2, SLOT(setNum(int)));
        QObject::connect(barra_thres1, SIGNAL(valueChanged(int)), label_5, SLOT(setNum(int)));

        contenedor_ventanas->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(VentanaPrincipal);
    } // setupUi

    void retranslateUi(QMainWindow *VentanaPrincipal)
    {
        VentanaPrincipal->setWindowTitle(QApplication::translate("VentanaPrincipal", "Mondrian Effect - Costa Rica Institute of Technology", 0, QApplication::UnicodeUTF8));
        actionStar_Capture->setText(QApplication::translate("VentanaPrincipal", "Start Capture", 0, QApplication::UnicodeUTF8));
        action_set_background->setText(QApplication::translate("VentanaPrincipal", "Set Backgroud", 0, QApplication::UnicodeUTF8));
        action_Set_Filters->setText(QApplication::translate("VentanaPrincipal", "Set Filters", 0, QApplication::UnicodeUTF8));
        action_iniciar_captura->setText(QApplication::translate("VentanaPrincipal", "Start Capture", 0, QApplication::UnicodeUTF8));
        action_about->setText(QApplication::translate("VentanaPrincipal", "About", 0, QApplication::UnicodeUTF8));
        label_fondo_inicio->setText(QString());
        label_3->setText(QString());
        label_foto_mondrian->setText(QApplication::translate("VentanaPrincipal", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_foto_original->setText(QApplication::translate("VentanaPrincipal", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("VentanaPrincipal", "Threshold", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("VentanaPrincipal", "TextLabel", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("VentanaPrincipal", "Erosion", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("VentanaPrincipal", "TextLabel", 0, QApplication::UnicodeUTF8));
        btn_default_ajustes->setText(QApplication::translate("VentanaPrincipal", "Default", 0, QApplication::UnicodeUTF8));
        barra_file->setTitle(QApplication::translate("VentanaPrincipal", "File", 0, QApplication::UnicodeUTF8));
        barra_settings->setTitle(QApplication::translate("VentanaPrincipal", "Settings", 0, QApplication::UnicodeUTF8));
        barra_help->setTitle(QApplication::translate("VentanaPrincipal", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VentanaPrincipal: public Ui_VentanaPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAPRINCIPAL_H
