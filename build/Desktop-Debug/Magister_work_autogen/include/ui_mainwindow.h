/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
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
    QGroupBox *MPU_gBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLabel *txt_gyro_x;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *txt_gyro_y;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *txt_gyro_z;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLabel *txt_accel_x;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLabel *txt_accel_y;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QLabel *txt_accel_z;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_16;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_7;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_9;
    QLabel *label_13;
    QGroupBox *Coord_gBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_10;
    QLabel *txt_width;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_12;
    QLabel *txt_long;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_14;
    QLabel *txt_angle_north;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_15;
    QLabel *label_17;
    QMenuBar *menubar;
    QMenu *menuH;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        txt_status_bar = new QTextBrowser(centralwidget);
        txt_status_bar->setObjectName(QString::fromUtf8("txt_status_bar"));
        txt_status_bar->setGeometry(QRect(9, 340, 491, 111));
        MPU_gBox = new QGroupBox(centralwidget);
        MPU_gBox->setObjectName(QString::fromUtf8("MPU_gBox"));
        MPU_gBox->setGeometry(QRect(9, 9, 257, 119));
        layoutWidget = new QWidget(MPU_gBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(12, 33, 138, 156));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        txt_gyro_x = new QLabel(layoutWidget);
        txt_gyro_x->setObjectName(QString::fromUtf8("txt_gyro_x"));

        horizontalLayout_3->addWidget(txt_gyro_x);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        txt_gyro_y = new QLabel(layoutWidget);
        txt_gyro_y->setObjectName(QString::fromUtf8("txt_gyro_y"));

        horizontalLayout->addWidget(txt_gyro_y);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        txt_gyro_z = new QLabel(layoutWidget);
        txt_gyro_z->setObjectName(QString::fromUtf8("txt_gyro_z"));

        horizontalLayout_2->addWidget(txt_gyro_z);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        txt_accel_x = new QLabel(layoutWidget);
        txt_accel_x->setObjectName(QString::fromUtf8("txt_accel_x"));

        horizontalLayout_4->addWidget(txt_accel_x);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);

        txt_accel_y = new QLabel(layoutWidget);
        txt_accel_y->setObjectName(QString::fromUtf8("txt_accel_y"));

        horizontalLayout_5->addWidget(txt_accel_y);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_6->addWidget(label_8);

        txt_accel_z = new QLabel(layoutWidget);
        txt_accel_z->setObjectName(QString::fromUtf8("txt_accel_z"));

        horizontalLayout_6->addWidget(txt_accel_z);


        verticalLayout_3->addLayout(horizontalLayout_6);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 170, 345, 119));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_10->addWidget(label_16);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_10->addWidget(label_4);


        verticalLayout_5->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_11->addWidget(label_7);

        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_11->addWidget(label_11);


        verticalLayout_5->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_12->addWidget(label_9);

        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_12->addWidget(label_13);


        verticalLayout_5->addLayout(horizontalLayout_12);


        gridLayout_2->addLayout(verticalLayout_5, 0, 0, 1, 1);

        Coord_gBox = new QGroupBox(centralwidget);
        Coord_gBox->setObjectName(QString::fromUtf8("Coord_gBox"));
        Coord_gBox->setGeometry(QRect(272, 9, 218, 119));
        gridLayout = new QGridLayout(Coord_gBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_10 = new QLabel(Coord_gBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_7->addWidget(label_10);

        txt_width = new QLabel(Coord_gBox);
        txt_width->setObjectName(QString::fromUtf8("txt_width"));

        horizontalLayout_7->addWidget(txt_width);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_12 = new QLabel(Coord_gBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_8->addWidget(label_12);

        txt_long = new QLabel(Coord_gBox);
        txt_long->setObjectName(QString::fromUtf8("txt_long"));

        horizontalLayout_8->addWidget(txt_long);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_14 = new QLabel(Coord_gBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_9->addWidget(label_14);

        txt_angle_north = new QLabel(Coord_gBox);
        txt_angle_north->setObjectName(QString::fromUtf8("txt_angle_north"));

        horizontalLayout_9->addWidget(txt_angle_north);


        verticalLayout_4->addLayout(horizontalLayout_9);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(534, 9, 195, 65));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_13->addWidget(label_15);

        label_17 = new QLabel(groupBox);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_13->addWidget(label_17);


        gridLayout_3->addLayout(horizontalLayout_13, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menuH = new QMenu(menubar);
        menuH->setObjectName(QString::fromUtf8("menuH"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
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
        txt_gyro_x->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Gyro y = ", nullptr));
        txt_gyro_y->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Gyro z = ", nullptr));
        txt_gyro_z->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Accel x= ", nullptr));
        txt_accel_x->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Accel y = ", nullptr));
        txt_accel_y->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Accel z = ", nullptr));
        txt_accel_z->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "BMP280", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "\320\220\321\202\320\276\320\274\321\201\321\204\320\265\321\200\320\275\320\276\320\265 \320\264\320\260\320\262\320\273\320\265\320\275\320\265 (\320\274\320\274.\321\200\321\202.\321\201\321\202) = ", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260 (\320\241) = ", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\201\320\276\321\202\320\260 \320\275\320\260\320\264 \321\203\321\200\320\276\320\262\320\275\320\265\320\274 \320\274\320\276\321\200\321\217 (\320\274) = ", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        Coord_gBox->setTitle(QCoreApplication::translate("MainWindow", "Coordinates", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\320\250\320\270\321\200\320\270\320\275\320\260 = ", nullptr));
        txt_width->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\273\320\263\320\276\321\202\320\260 =", nullptr));
        txt_long->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273 \320\276\321\202 \321\201\320\265\320\262\320\265\321\200\320\260 = ", nullptr));
        txt_angle_north->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\201\320\276\321\202\320\260 \320\277\320\276 \320\233\320\224", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\201\320\276\321\202\320\260 (\321\201\320\274) = ", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        menuH->setTitle(QCoreApplication::translate("MainWindow", "Kvadro_CTRL", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
