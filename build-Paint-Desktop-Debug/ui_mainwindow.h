/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <screen.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    Screen *screen;
    QPushButton *reset;
    QPushButton *chngPixClr;
    QPushButton *incPixSz;
    QPushButton *decPixSz;
    QPushButton *draw;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *line_ba;
    QRadioButton *line_dda;
    QRadioButton *circle_s;
    QRadioButton *circle_p;
    QRadioButton *circle_b;
    QRadioButton *ellipse_m;
    QRadioButton *scan_f;
    QRadioButton *flood_f;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *location;
    QLabel *time;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(912, 776);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 54)"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        screen = new Screen(centralwidget);
        screen->setObjectName(QString::fromUtf8("screen"));
        screen->setGeometry(QRect(10, 20, 625, 625));
        screen->setMinimumSize(QSize(621, 621));
        screen->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 255, 255);"));
        reset = new QPushButton(centralwidget);
        reset->setObjectName(QString::fromUtf8("reset"));
        reset->setGeometry(QRect(20, 660, 50, 50));
        reset->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu Mono\";\n"
"color: rgb(255, 255, 255);\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: rgb(255, 255, 255);\n"
"background-color: rgb(63, 61, 61);"));
        chngPixClr = new QPushButton(centralwidget);
        chngPixClr->setObjectName(QString::fromUtf8("chngPixClr"));
        chngPixClr->setGeometry(QRect(80, 660, 50, 50));
        chngPixClr->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu Mono\";\n"
"color: rgb(255, 255, 255);\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: rgb(255, 255, 255);\n"
"background-color: rgb(63, 61, 61);"));
        incPixSz = new QPushButton(centralwidget);
        incPixSz->setObjectName(QString::fromUtf8("incPixSz"));
        incPixSz->setGeometry(QRect(140, 660, 50, 50));
        incPixSz->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu Mono\";\n"
"color: rgb(255, 255, 255);\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: rgb(255, 255, 255);\n"
"background-color: rgb(63, 61, 61);"));
        decPixSz = new QPushButton(centralwidget);
        decPixSz->setObjectName(QString::fromUtf8("decPixSz"));
        decPixSz->setGeometry(QRect(200, 660, 50, 50));
        decPixSz->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu Mono\";\n"
"color: rgb(255, 255, 255);\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: rgb(255, 255, 255);\n"
"background-color: rgb(63, 61, 61);"));
        draw = new QPushButton(centralwidget);
        draw->setObjectName(QString::fromUtf8("draw"));
        draw->setGeometry(QRect(330, 660, 230, 50));
        draw->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu Mono\";\n"
"color: rgb(255, 255, 255);\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: rgb(255, 255, 255);\n"
"background-color: rgb(63, 61, 61);"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(660, 200, 231, 371));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        line_ba = new QRadioButton(verticalLayoutWidget);
        line_ba->setObjectName(QString::fromUtf8("line_ba"));
        line_ba->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu Mono\";\n"
"color: rgb(255, 255, 255);\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: rgb(255, 255, 255);\n"
"background-color: rgb(61, 61, 61);"));

        verticalLayout->addWidget(line_ba);

        line_dda = new QRadioButton(verticalLayoutWidget);
        line_dda->setObjectName(QString::fromUtf8("line_dda"));
        line_dda->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu Mono\";\n"
"color: rgb(255, 255, 255);\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: rgb(255, 255, 255);\n"
"background-color: rgb(61, 61, 61);"));

        verticalLayout->addWidget(line_dda);

        circle_s = new QRadioButton(verticalLayoutWidget);
        circle_s->setObjectName(QString::fromUtf8("circle_s"));
        circle_s->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu Mono\";\n"
"color: rgb(255, 255, 255);\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: rgb(255, 255, 255);\n"
"background-color: rgb(61, 61, 61);"));

        verticalLayout->addWidget(circle_s);

        circle_p = new QRadioButton(verticalLayoutWidget);
        circle_p->setObjectName(QString::fromUtf8("circle_p"));
        circle_p->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu Mono\";\n"
"color: rgb(255, 255, 255);\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: rgb(255, 255, 255);\n"
"background-color: rgb(61, 61, 61);"));

        verticalLayout->addWidget(circle_p);

        circle_b = new QRadioButton(verticalLayoutWidget);
        circle_b->setObjectName(QString::fromUtf8("circle_b"));
        circle_b->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu Mono\";\n"
"color: rgb(255, 255, 255);\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: rgb(255, 255, 255);\n"
"background-color: rgb(61, 61, 61);"));

        verticalLayout->addWidget(circle_b);

        ellipse_m = new QRadioButton(verticalLayoutWidget);
        ellipse_m->setObjectName(QString::fromUtf8("ellipse_m"));
        ellipse_m->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu Mono\";\n"
"color: rgb(255, 255, 255);\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: rgb(255, 255, 255);\n"
"background-color: rgb(61, 61, 61);"));

        verticalLayout->addWidget(ellipse_m);

        scan_f = new QRadioButton(verticalLayoutWidget);
        scan_f->setObjectName(QString::fromUtf8("scan_f"));
        scan_f->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu Mono\";\n"
"color: rgb(255, 255, 255);\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: rgb(255, 255, 255);\n"
"background-color: rgb(61, 61, 61);"));

        verticalLayout->addWidget(scan_f);

        flood_f = new QRadioButton(verticalLayoutWidget);
        flood_f->setObjectName(QString::fromUtf8("flood_f"));
        flood_f->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu Mono\";\n"
"color: rgb(255, 255, 255);\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: rgb(255, 255, 255);\n"
"background-color: rgb(61, 61, 61);"));

        verticalLayout->addWidget(flood_f);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(660, 20, 231, 91));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        location = new QLabel(verticalLayoutWidget_2);
        location->setObjectName(QString::fromUtf8("location"));
        location->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu Mono\";\n"
"color: rgb(255, 255, 255);\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: rgb(255, 255, 255);\n"
"background-color: rgb(63, 61, 61);"));

        verticalLayout_2->addWidget(location);

        time = new QLabel(verticalLayoutWidget_2);
        time->setObjectName(QString::fromUtf8("time"));
        time->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu Mono\";\n"
"color: rgb(255, 255, 255);\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: rgb(255, 255, 255);\n"
"background-color: rgb(63, 61, 61);"));

        verticalLayout_2->addWidget(time);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 912, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        reset->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
        chngPixClr->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        incPixSz->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        decPixSz->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        draw->setText(QCoreApplication::translate("MainWindow", "Draw", nullptr));
        line_ba->setText(QCoreApplication::translate("MainWindow", "Line_BA", nullptr));
        line_dda->setText(QCoreApplication::translate("MainWindow", "Line_DDA", nullptr));
        circle_s->setText(QCoreApplication::translate("MainWindow", "Circle_S", nullptr));
        circle_p->setText(QCoreApplication::translate("MainWindow", "Circle_P", nullptr));
        circle_b->setText(QCoreApplication::translate("MainWindow", "Circle_B", nullptr));
        ellipse_m->setText(QCoreApplication::translate("MainWindow", "Ellipse_M", nullptr));
        scan_f->setText(QCoreApplication::translate("MainWindow", "Scan_Fill", nullptr));
        flood_f->setText(QCoreApplication::translate("MainWindow", "Flood_Fill", nullptr));
        location->setText(QString());
        time->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
