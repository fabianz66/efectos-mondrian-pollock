/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Nov 19 05:10:16 2014
**      by: Qt User Interface Compiler version 4.8.2
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
    QPushButton *video_normal;
    QPushButton *detener;
    QPushButton *benchmark_btn;
    QLabel *label_3;
    QPushButton *save_benchmarks;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(313, 226);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 20, 51, 31));
        video_normal = new QPushButton(centralWidget);
        video_normal->setObjectName(QString::fromUtf8("video_normal"));
        video_normal->setGeometry(QRect(50, 60, 98, 27));
        detener = new QPushButton(centralWidget);
        detener->setObjectName(QString::fromUtf8("detener"));
        detener->setGeometry(QRect(50, 100, 98, 27));
        benchmark_btn = new QPushButton(centralWidget);
        benchmark_btn->setObjectName(QString::fromUtf8("benchmark_btn"));
        benchmark_btn->setGeometry(QRect(170, 60, 98, 27));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(170, 30, 91, 17));
        save_benchmarks = new QPushButton(centralWidget);
        save_benchmarks->setObjectName(QString::fromUtf8("save_benchmarks"));
        save_benchmarks->setGeometry(QRect(170, 100, 98, 27));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 313, 25));
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
        video_normal->setText(QApplication::translate("MainWindow", "Normal", 0, QApplication::UnicodeUTF8));
        detener->setText(QApplication::translate("MainWindow", "Detener", 0, QApplication::UnicodeUTF8));
        benchmark_btn->setText(QApplication::translate("MainWindow", "Path", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Benchmarks", 0, QApplication::UnicodeUTF8));
        save_benchmarks->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
