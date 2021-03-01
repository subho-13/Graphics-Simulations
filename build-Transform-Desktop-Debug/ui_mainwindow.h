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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <screen.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    Screen *screen;
    QPushButton *sizeDown;
    QPushButton *sizeUp;
    QPushButton *delay;
    QPushButton *window;
    QPushButton *clip;
    QPushButton *reset;
    QPushButton *polygon;
    QPushButton *scaleDown;
    QPushButton *clock;
    QPushButton *down;
    QPushButton *pivot;
    QPushButton *line;
    QPushButton *changeColor;
    QPushButton *scaleUp;
    QPushButton *right;
    QPushButton *repaint;
    QPushButton *anticlock;
    QPushButton *up;
    QPushButton *reflect;
    QPushButton *shear;
    QLabel *location;
    QPushButton *left;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1118, 1025);
        MainWindow->setCursor(QCursor(Qt::PointingHandCursor));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #100f10;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        screen = new Screen(centralwidget);
        screen->setObjectName(QString::fromUtf8("screen"));
        screen->setGeometry(QRect(250, 20, 850, 851));
        screen->setStyleSheet(QString::fromUtf8("border-width: 2px;\n"
"border-style: solid;\n"
"border-color: #ffa631;"));
        sizeDown = new QPushButton(centralwidget);
        sizeDown->setObjectName(QString::fromUtf8("sizeDown"));
        sizeDown->setGeometry(QRect(520, 890, 100, 75));
        sizeDown->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 20pt;\n"
"color: #ffa631;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: #cbc2c4;\n"
"background-color: #080808 ;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"color: #080808;\n"
"background-color: #ffa631;\n"
"}"));
        sizeUp = new QPushButton(centralwidget);
        sizeUp->setObjectName(QString::fromUtf8("sizeUp"));
        sizeUp->setGeometry(QRect(640, 890, 100, 75));
        sizeUp->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 30pt;\n"
"color: #ffa631;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: #cbc2c4;\n"
"background-color: #080808 ;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"color: #080808;\n"
"background-color: #ffa631;\n"
"}"));
        delay = new QPushButton(centralwidget);
        delay->setObjectName(QString::fromUtf8("delay"));
        delay->setGeometry(QRect(1000, 890, 100, 75));
        delay->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 30pt;\n"
"color: #ffa631;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: #cbc2c4;\n"
"background-color: #080808 ;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"color: #080808;\n"
"background-color: #ffa631;\n"
"}"));
        window = new QPushButton(centralwidget);
        window->setObjectName(QString::fromUtf8("window"));
        window->setGeometry(QRect(130, 200, 100, 75));
        window->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 40pt ;\n"
"color: #ffa631;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: #cbc2c4;\n"
"background-color: #080808 ;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"color: #080808;\n"
"background-color: #ffa631;\n"
"}"));
        clip = new QPushButton(centralwidget);
        clip->setObjectName(QString::fromUtf8("clip"));
        clip->setGeometry(QRect(130, 800, 100, 70));
        clip->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 40pt;\n"
"color: #ffa631;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: #cbc2c4;\n"
"background-color: #080808 ;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"color: #080808;\n"
"background-color: #ffa631;\n"
"}"));
        clip->setAutoRepeat(false);
        clip->setAutoRepeatDelay(100);
        clip->setAutoRepeatInterval(300);
        reset = new QPushButton(centralwidget);
        reset->setObjectName(QString::fromUtf8("reset"));
        reset->setGeometry(QRect(10, 890, 100, 75));
        reset->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 20pt \"Fira Code\";\n"
"color: #ffa631;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: #cbc2c4;\n"
"background-color: #080808 ;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"color: #080808;\n"
"background-color: #ffa631;\n"
"}"));
        polygon = new QPushButton(centralwidget);
        polygon->setObjectName(QString::fromUtf8("polygon"));
        polygon->setGeometry(QRect(10, 100, 100, 75));
        polygon->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 30pt;\n"
"color: #ffa631;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: #cbc2c4;\n"
"background-color: #080808 ;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"color: #080808;\n"
"background-color: #ffa631;\n"
"}"));
        scaleDown = new QPushButton(centralwidget);
        scaleDown->setObjectName(QString::fromUtf8("scaleDown"));
        scaleDown->setGeometry(QRect(130, 300, 100, 75));
        scaleDown->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 30pt;\n"
"color: #ffa631;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: #cbc2c4;\n"
"background-color: #080808 ;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"color: #080808;\n"
"background-color: #ffa631;\n"
"}"));
        scaleDown->setAutoRepeatDelay(20);
        scaleDown->setAutoRepeatInterval(30);
        clock = new QPushButton(centralwidget);
        clock->setObjectName(QString::fromUtf8("clock"));
        clock->setGeometry(QRect(10, 600, 100, 75));
        clock->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 30pt;\n"
"color: #ffa631;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: #cbc2c4;\n"
"background-color: #080808 ;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"color: #080808;\n"
"background-color: #ffa631;\n"
"}"));
        clock->setAutoRepeat(true);
        clock->setAutoRepeatDelay(100);
        clock->setAutoRepeatInterval(30);
        down = new QPushButton(centralwidget);
        down->setObjectName(QString::fromUtf8("down"));
        down->setGeometry(QRect(130, 400, 100, 75));
        down->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 30pt;\n"
"color: #ffa631;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: #cbc2c4;\n"
"background-color: #080808 ;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"color: #080808;\n"
"background-color: #ffa631;\n"
"}"));
        down->setAutoRepeat(true);
        down->setAutoRepeatDelay(100);
        down->setAutoRepeatInterval(30);
        pivot = new QPushButton(centralwidget);
        pivot->setObjectName(QString::fromUtf8("pivot"));
        pivot->setGeometry(QRect(130, 100, 100, 75));
        pivot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 30pt;\n"
"color: #ffa631;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: #cbc2c4;\n"
"background-color: #080808 ;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"color: #080808;\n"
"background-color: #ffa631;\n"
"}"));
        line = new QPushButton(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 200, 100, 75));
        line->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 25pt;\n"
"color: #ffa631;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: #cbc2c4;\n"
"background-color: #080808 ;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"color: #080808;\n"
"background-color: #ffa631;\n"
"}"));
        changeColor = new QPushButton(centralwidget);
        changeColor->setObjectName(QString::fromUtf8("changeColor"));
        changeColor->setGeometry(QRect(130, 890, 100, 75));
        QFont font;
        font.setFamily(QString::fromUtf8("Noto Emoji"));
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        changeColor->setFont(font);
        changeColor->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 20pt  \"Noto Emoji\";\n"
"color: #ffa631;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: #cbc2c4;\n"
"background-color: #080808 ;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"color: #080808;\n"
"background-color: #ffa631;\n"
"}"));
        scaleUp = new QPushButton(centralwidget);
        scaleUp->setObjectName(QString::fromUtf8("scaleUp"));
        scaleUp->setGeometry(QRect(10, 300, 100, 75));
        scaleUp->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 30pt;\n"
"color: #ffa631;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: #cbc2c4;\n"
"background-color: #080808 ;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"color: #080808;\n"
"background-color: #ffa631;\n"
"}"));
        scaleUp->setAutoRepeatDelay(20);
        scaleUp->setAutoRepeatInterval(30);
        right = new QPushButton(centralwidget);
        right->setObjectName(QString::fromUtf8("right"));
        right->setGeometry(QRect(130, 500, 100, 75));
        right->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 30pt;\n"
"color: #ffa631;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: #cbc2c4;\n"
"background-color: #080808 ;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"color: #080808;\n"
"background-color: #ffa631;\n"
"}"));
        right->setAutoRepeat(true);
        right->setAutoRepeatDelay(100);
        right->setAutoRepeatInterval(30);
        repaint = new QPushButton(centralwidget);
        repaint->setObjectName(QString::fromUtf8("repaint"));
        repaint->setGeometry(QRect(10, 800, 100, 71));
        repaint->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 25pt;\n"
"color: #ffa631;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: #cbc2c4;\n"
"background-color: #080808 ;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"color: #080808;\n"
"background-color: #ffa631;\n"
"}"));
        repaint->setAutoRepeat(false);
        repaint->setAutoRepeatDelay(100);
        repaint->setAutoRepeatInterval(30);
        anticlock = new QPushButton(centralwidget);
        anticlock->setObjectName(QString::fromUtf8("anticlock"));
        anticlock->setGeometry(QRect(130, 600, 100, 75));
        anticlock->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 30pt;\n"
"color: #ffa631;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: #cbc2c4;\n"
"background-color: #080808 ;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"color: #080808;\n"
"background-color: #ffa631;\n"
"}"));
        anticlock->setAutoRepeat(true);
        anticlock->setAutoRepeatDelay(100);
        anticlock->setAutoRepeatInterval(30);
        up = new QPushButton(centralwidget);
        up->setObjectName(QString::fromUtf8("up"));
        up->setGeometry(QRect(10, 400, 100, 75));
        up->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 30pt;\n"
"color: #ffa631;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: #cbc2c4;\n"
"background-color: #080808 ;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"color: #080808;\n"
"background-color: #ffa631;\n"
"}"));
        up->setAutoRepeat(true);
        up->setAutoRepeatDelay(100);
        up->setAutoRepeatInterval(30);
        reflect = new QPushButton(centralwidget);
        reflect->setObjectName(QString::fromUtf8("reflect"));
        reflect->setGeometry(QRect(10, 700, 100, 71));
        reflect->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 20pt;\n"
"color: #ffa631;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: #cbc2c4;\n"
"background-color: #080808 ;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"color: #080808;\n"
"background-color: #ffa631;\n"
"}"));
        reflect->setAutoRepeat(false);
        reflect->setAutoRepeatDelay(100);
        reflect->setAutoRepeatInterval(30);
        shear = new QPushButton(centralwidget);
        shear->setObjectName(QString::fromUtf8("shear"));
        shear->setGeometry(QRect(130, 700, 100, 70));
        shear->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 40pt;\n"
"color: #ffa631;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: #cbc2c4;\n"
"background-color: #080808 ;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"color: #080808;\n"
"background-color: #ffa631;\n"
"}"));
        shear->setAutoRepeat(true);
        shear->setAutoRepeatDelay(100);
        shear->setAutoRepeatInterval(30);
        location = new QLabel(centralwidget);
        location->setObjectName(QString::fromUtf8("location"));
        location->setGeometry(QRect(10, 20, 221, 61));
        location->setStyleSheet(QString::fromUtf8("font: 20pt \"Fira Code\";\n"
"qproperty-alignment: \"AlignCenter\";\n"
"color: #ffa631;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: #cbc2c4;\n"
"background-color: #080808 ;\n"
""));
        left = new QPushButton(centralwidget);
        left->setObjectName(QString::fromUtf8("left"));
        left->setGeometry(QRect(10, 500, 100, 75));
        left->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 30pt;\n"
"color: #ffa631;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: #cbc2c4;\n"
"background-color: #080808 ;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"color: #080808;\n"
"background-color: #ffa631;\n"
"}"));
        left->setAutoRepeat(true);
        left->setAutoRepeatDelay(100);
        left->setAutoRepeatInterval(30);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1118, 26));
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
        sizeDown->setText(QCoreApplication::translate("MainWindow", "\342\226\246", nullptr));
        sizeUp->setText(QCoreApplication::translate("MainWindow", "\342\226\246", nullptr));
        delay->setText(QCoreApplication::translate("MainWindow", "\360\237\225\220", nullptr));
        window->setText(QCoreApplication::translate("MainWindow", "\342\226\255", nullptr));
        clip->setText(QCoreApplication::translate("MainWindow", "\342\234\202", nullptr));
        reset->setText(QCoreApplication::translate("MainWindow", "\342\217\273", nullptr));
        polygon->setText(QCoreApplication::translate("MainWindow", "\342\254\240", nullptr));
        scaleDown->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        clock->setText(QCoreApplication::translate("MainWindow", "\342\206\273", nullptr));
        down->setText(QCoreApplication::translate("MainWindow", "\342\206\223", nullptr));
        pivot->setText(QCoreApplication::translate("MainWindow", "\342\227\211", nullptr));
        line->setText(QCoreApplication::translate("MainWindow", "\342\225\261", nullptr));
        changeColor->setText(QCoreApplication::translate("MainWindow", "\360\237\216\250", nullptr));
        scaleUp->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        right->setText(QCoreApplication::translate("MainWindow", "\342\206\222", nullptr));
        repaint->setText(QCoreApplication::translate("MainWindow", "\360\237\226\214", nullptr));
        anticlock->setText(QCoreApplication::translate("MainWindow", "\342\206\272", nullptr));
        up->setText(QCoreApplication::translate("MainWindow", "\342\206\221", nullptr));
        reflect->setText(QCoreApplication::translate("MainWindow", "<\342\224\212>", nullptr));
        shear->setText(QCoreApplication::translate("MainWindow", "\342\226\261", nullptr));
        location->setText(QCoreApplication::translate("MainWindow", "Location", nullptr));
        left->setText(QCoreApplication::translate("MainWindow", "\342\206\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
