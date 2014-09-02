/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Sep 2 12:32:13 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionIniciarRastreo;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_4;
    QStackedWidget *panel_principal;
    QWidget *pagina_inicio;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QWidget *pagina_camara;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *numeros_iz;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *numeros_arriba;
    QVBoxLayout *contenedor_imagen;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(958, 637);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionIniciarRastreo = new QAction(MainWindow);
        actionIniciarRastreo->setObjectName(QString::fromUtf8("actionIniciarRastreo"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/cam.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionIniciarRastreo->setIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"font: 12pt \"Arial\";\n"
"color: rgb(255, 255, 255);"));
        horizontalLayout_4 = new QHBoxLayout(centralWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        panel_principal = new QStackedWidget(centralWidget);
        panel_principal->setObjectName(QString::fromUtf8("panel_principal"));
        pagina_inicio = new QWidget();
        pagina_inicio->setObjectName(QString::fromUtf8("pagina_inicio"));
        horizontalLayout_2 = new QHBoxLayout(pagina_inicio);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(pagina_inicio);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        panel_principal->addWidget(pagina_inicio);
        pagina_camara = new QWidget();
        pagina_camara->setObjectName(QString::fromUtf8("pagina_camara"));
        verticalLayout = new QVBoxLayout(pagina_camara);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        numeros_iz = new QVBoxLayout();
        numeros_iz->setSpacing(6);
        numeros_iz->setObjectName(QString::fromUtf8("numeros_iz"));

        horizontalLayout->addLayout(numeros_iz);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        numeros_arriba = new QHBoxLayout();
        numeros_arriba->setSpacing(6);
        numeros_arriba->setObjectName(QString::fromUtf8("numeros_arriba"));

        verticalLayout_2->addLayout(numeros_arriba);

        contenedor_imagen = new QVBoxLayout();
        contenedor_imagen->setSpacing(6);
        contenedor_imagen->setObjectName(QString::fromUtf8("contenedor_imagen"));

        verticalLayout_2->addLayout(contenedor_imagen);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        panel_principal->addWidget(pagina_camara);

        horizontalLayout_4->addWidget(panel_principal);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addAction(actionIniciarRastreo);

        retranslateUi(MainWindow);

        panel_principal->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionIniciarRastreo->setText(QApplication::translate("MainWindow", "IniciarRastreo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionIniciarRastreo->setToolTip(QApplication::translate("MainWindow", "Iniciar Camara", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("MainWindow", "PAGINA INICIO DEMOSRACION", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
