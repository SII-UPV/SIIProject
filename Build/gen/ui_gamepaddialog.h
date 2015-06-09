/********************************************************************************
** Form generated from reading UI file 'gamepaddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEPADDIALOG_H
#define UI_GAMEPADDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GamepadDialog
{
public:
    QWidget *centralwidget;
    QCheckBox *Button1;
    QCheckBox *Button2;
    QCheckBox *Button3;
    QCheckBox *Button4;
    QProgressBar *xAxis;
    QProgressBar *yAxis;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GamepadDialog)
    {
        if (GamepadDialog->objectName().isEmpty())
            GamepadDialog->setObjectName(QStringLiteral("GamepadDialog"));
        GamepadDialog->resize(462, 230);
        centralwidget = new QWidget(GamepadDialog);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        Button1 = new QCheckBox(centralwidget);
        Button1->setObjectName(QStringLiteral("Button1"));
        Button1->setGeometry(QRect(290, 130, 75, 30));
        Button2 = new QCheckBox(centralwidget);
        Button2->setObjectName(QStringLiteral("Button2"));
        Button2->setGeometry(QRect(370, 80, 70, 30));
        Button2->setLayoutDirection(Qt::LeftToRight);
        Button3 = new QCheckBox(centralwidget);
        Button3->setObjectName(QStringLiteral("Button3"));
        Button3->setGeometry(QRect(215, 80, 91, 30));
        Button4 = new QCheckBox(centralwidget);
        Button4->setObjectName(QStringLiteral("Button4"));
        Button4->setGeometry(QRect(290, 30, 70, 30));
        Button4->setLayoutDirection(Qt::LeftToRight);
        xAxis = new QProgressBar(centralwidget);
        xAxis->setObjectName(QStringLiteral("xAxis"));
        xAxis->setGeometry(QRect(40, 30, 118, 23));
        xAxis->setValue(24);
        yAxis = new QProgressBar(centralwidget);
        yAxis->setObjectName(QStringLiteral("yAxis"));
        yAxis->setGeometry(QRect(40, 60, 118, 23));
        yAxis->setValue(24);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 47, 13));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 30, 21, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 65, 21, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 102, 171, 81));
        GamepadDialog->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GamepadDialog);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 462, 21));
        GamepadDialog->setMenuBar(menubar);
        statusbar = new QStatusBar(GamepadDialog);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        GamepadDialog->setStatusBar(statusbar);

        retranslateUi(GamepadDialog);

        QMetaObject::connectSlotsByName(GamepadDialog);
    } // setupUi

    void retranslateUi(QMainWindow *GamepadDialog)
    {
        GamepadDialog->setWindowTitle(QApplication::translate("GamepadDialog", "MainWindow", 0));
        Button1->setText(QString());
        Button2->setText(QString());
        Button3->setText(QString());
        Button4->setText(QString());
        label->setText(QApplication::translate("GamepadDialog", "Stick 1:", 0));
        label_2->setText(QApplication::translate("GamepadDialog", "X:", 0));
        label_3->setText(QApplication::translate("GamepadDialog", "Y:", 0));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GamepadDialog: public Ui_GamepadDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEPADDIALOG_H
