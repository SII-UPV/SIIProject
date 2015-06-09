#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_2->setPixmap((QIcon(":/images/xBox/Images/xBox/A.png").pixmap(QSize(30,30))));
    ui->label_3->setPixmap((QIcon(":/images/PS3/Images/PS3/CROSS.jpg").pixmap(QSize(30,30))));
    time = new QTimer();

    connect(time, SIGNAL(timeout()),this,SLOT(checkActive()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow::checkActive(void)
{
    gamepadInfo->update();

    ui->textBrowser->setText(gamepadInfo->toString());

    Gamepad* temp = gamepadInfo->getActive();
    if (temp!=NULL){
        GamepadDialog* D = new GamepadDialog(this, temp);
        D->show();
    }
}

void MainWindow::on_StartButton_clicked()
{
    gamepadInfo = new GamepadInfo();

    time->start(100);

    ui->StartButton->setEnabled(false);
}


