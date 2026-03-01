/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextBrowser *txt_status_bar;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_7;
    QGroupBox *MPU_gBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLabel *gyro_x_txt;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *gyro_y_txt;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *gyro_z_txt;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QLabel *label_9;
    QGroupBox *Coord_gBox;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox;
    QMenuBar *menubar;
    QMenu *menuH;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        txt_status_bar = new QTextBrowser(centralwidget);
        txt_status_bar->setObjectName("txt_status_bar");
        txt_status_bar->setGeometry(QRect(20, 250, 691, 71));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 20, 385, 203));
        horizontalLayout_7 = new QHBoxLayout(widget);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        MPU_gBox = new QGroupBox(widget);
        MPU_gBox->setObjectName("MPU_gBox");
        gridLayout = new QGridLayout(MPU_gBox);
        gridLayout->setObjectName("gridLayout");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_5 = new QLabel(MPU_gBox);
        label_5->setObjectName("label_5");

        horizontalLayout_3->addWidget(label_5);

        gyro_x_txt = new QLabel(MPU_gBox);
        gyro_x_txt->setObjectName("gyro_x_txt");

        horizontalLayout_3->addWidget(gyro_x_txt);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(MPU_gBox);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        gyro_y_txt = new QLabel(MPU_gBox);
        gyro_y_txt->setObjectName("gyro_y_txt");

        horizontalLayout->addWidget(gyro_y_txt);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(MPU_gBox);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        gyro_z_txt = new QLabel(MPU_gBox);
        gyro_z_txt->setObjectName("gyro_z_txt");

        horizontalLayout_2->addWidget(gyro_z_txt);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_2 = new QLabel(MPU_gBox);
        label_2->setObjectName("label_2");

        horizontalLayout_4->addWidget(label_2);

        label_4 = new QLabel(MPU_gBox);
        label_4->setObjectName("label_4");

        horizontalLayout_4->addWidget(label_4);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_6 = new QLabel(MPU_gBox);
        label_6->setObjectName("label_6");

        horizontalLayout_5->addWidget(label_6);

        label_7 = new QLabel(MPU_gBox);
        label_7->setObjectName("label_7");

        horizontalLayout_5->addWidget(label_7);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_8 = new QLabel(MPU_gBox);
        label_8->setObjectName("label_8");

        horizontalLayout_6->addWidget(label_8);

        label_9 = new QLabel(MPU_gBox);
        label_9->setObjectName("label_9");

        horizontalLayout_6->addWidget(label_9);


        verticalLayout_3->addLayout(horizontalLayout_6);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        horizontalLayout_7->addWidget(MPU_gBox);

        Coord_gBox = new QGroupBox(widget);
        Coord_gBox->setObjectName("Coord_gBox");

        horizontalLayout_7->addWidget(Coord_gBox);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        groupBox_3 = new QGroupBox(widget);
        groupBox_3->setObjectName("groupBox_3");

        verticalLayout_4->addWidget(groupBox_3);

        groupBox = new QGroupBox(widget);
        groupBox->setObjectName("groupBox");

        verticalLayout_4->addWidget(groupBox);


        horizontalLayout_7->addLayout(verticalLayout_4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menuH = new QMenu(menubar);
        menuH->setObjectName("menuH");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuH->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        MPU_gBox->setTitle(QCoreApplication::translate("MainWindow", "Gyro_Accel", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Gyro x = ", nullptr));
        gyro_x_txt->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Gyro y = ", nullptr));
        gyro_y_txt->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Gyro z = ", nullptr));
        gyro_z_txt->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Accel x= ", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Accel y = ", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Accel z = ", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        Coord_gBox->setTitle(QCoreApplication::translate("MainWindow", "Coordinates", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        menuH->setTitle(QCoreApplication::translate("MainWindow", "Kvadro_CTRL", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
