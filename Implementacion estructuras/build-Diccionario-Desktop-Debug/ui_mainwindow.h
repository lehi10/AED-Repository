/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextEdit *significado;
    QPushButton *buscar;
    QPushButton *pushButton_2;
    QTableWidget *Lista;
    QPushButton *agregar;
    QLabel *label;
    QLineEdit *nueva_palabra;
    QLineEdit *nueva_definicion;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(818, 604);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        significado = new QTextEdit(centralWidget);
        significado->setObjectName(QStringLiteral("significado"));
        significado->setGeometry(QRect(310, 80, 431, 191));
        buscar = new QPushButton(centralWidget);
        buscar->setObjectName(QStringLiteral("buscar"));
        buscar->setGeometry(QRect(230, 180, 75, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 110, 75, 23));
        Lista = new QTableWidget(centralWidget);
        if (Lista->columnCount() < 1)
            Lista->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        Lista->setHorizontalHeaderItem(0, __qtablewidgetitem);
        Lista->setObjectName(QStringLiteral("Lista"));
        Lista->setGeometry(QRect(60, 100, 141, 361));
        agregar = new QPushButton(centralWidget);
        agregar->setObjectName(QStringLiteral("agregar"));
        agregar->setGeometry(QRect(620, 370, 75, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(290, 310, 231, 16));
        nueva_palabra = new QLineEdit(centralWidget);
        nueva_palabra->setObjectName(QStringLiteral("nueva_palabra"));
        nueva_palabra->setGeometry(QRect(280, 340, 281, 20));
        nueva_definicion = new QLineEdit(centralWidget);
        nueva_definicion->setObjectName(QStringLiteral("nueva_definicion"));
        nueva_definicion->setGeometry(QRect(280, 370, 281, 71));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(310, 30, 231, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 818, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        buscar->setText(QApplication::translate("MainWindow", "BUSCAR", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "CARGAR", 0));
        QTableWidgetItem *___qtablewidgetitem = Lista->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Palabra", 0));
        agregar->setText(QApplication::translate("MainWindow", "AGREGAR", 0));
        label->setText(QApplication::translate("MainWindow", "AGREGAR DEFINICION AL DICCIONARIO", 0));
        label_2->setText(QApplication::translate("MainWindow", "DICCIONARIO", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
