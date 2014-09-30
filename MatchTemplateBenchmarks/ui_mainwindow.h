/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Sep 30 14:47:40 2014
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
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QPushButton *video_normal;
    QPushButton *video_tbb;
    QPushButton *cam_normal;
    QPushButton *cam_tbb;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(410, 254);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 30, 51, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(270, 30, 51, 31));
        video_normal = new QPushButton(centralWidget);
        video_normal->setObjectName(QString::fromUtf8("video_normal"));
        video_normal->setGeometry(QRect(50, 80, 98, 27));
        video_tbb = new QPushButton(centralWidget);
        video_tbb->setObjectName(QString::fromUtf8("video_tbb"));
        video_tbb->setGeometry(QRect(50, 120, 98, 27));
        cam_normal = new QPushButton(centralWidget);
        cam_normal->setObjectName(QString::fromUtf8("cam_normal"));
        cam_normal->setGeometry(QRect(250, 80, 98, 27));
        cam_tbb = new QPushButton(centralWidget);
        cam_tbb->setObjectName(QString::fromUtf8("cam_tbb"));
        cam_tbb->setGeometry(QRect(250, 120, 98, 27));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 410, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Video", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Camara", 0, QApplication::UnicodeUTF8));
        video_normal->setText(QApplication::translate("MainWindow", "Normal", 0, QApplication::UnicodeUTF8));
        video_tbb->setText(QApplication::translate("MainWindow", "TBB", 0, QApplication::UnicodeUTF8));
        cam_normal->setText(QApplication::translate("MainWindow", "Normal", 0, QApplication::UnicodeUTF8));
        cam_tbb->setText(QApplication::translate("MainWindow", "TBB", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
