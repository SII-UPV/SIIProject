#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_2->setPixmap(QPixmap(":/images/xBox/Images/xBox/A.jpg"));
    ui->label_3->setPixmap(QPixmap(":/images/PS3/Images/PS3/cross.jpg"));
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


