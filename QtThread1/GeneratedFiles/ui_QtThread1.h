/********************************************************************************
** Form generated from reading UI file 'QtThread1.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTTHREAD1_H
#define UI_QTTHREAD1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtThread1Class
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtThread1Class)
    {
        if (QtThread1Class->objectName().isEmpty())
            QtThread1Class->setObjectName(QString::fromUtf8("QtThread1Class"));
        QtThread1Class->resize(1141, 860);
        centralWidget = new QWidget(QtThread1Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QtThread1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtThread1Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1141, 26));
        QtThread1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtThread1Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtThread1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtThread1Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtThread1Class->setStatusBar(statusBar);

        retranslateUi(QtThread1Class);

        QMetaObject::connectSlotsByName(QtThread1Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtThread1Class)
    {
        QtThread1Class->setWindowTitle(QApplication::translate("QtThread1Class", "QtThread1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtThread1Class: public Ui_QtThread1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTTHREAD1_H
