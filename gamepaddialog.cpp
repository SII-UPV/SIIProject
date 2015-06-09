#include "gamepaddialog.h"
#include "ui_gamepaddialog.h"

GamepadDialog::GamepadDialog(QWidget *parent, Gamepad *_gamepad) :
    QMainWindow(parent),
    ui(new Ui::GamepadDialog)
{

    gamepad=_gamepad;

    ui->setupUi(this);

    this->setWindowTitle(gamepad->getName());

    ui->Button1->setIcon(QIcon(gamepad->getButtonIcon(1)));
    ui->Button1->setIconSize(QSize(30,30));
    ui->Button2->setIcon(QIcon(gamepad->getButtonIcon(2)));
    ui->Button2->setIconSize(QSize(30,30));
    ui->Button3->setIcon(QIcon(gamepad->getButtonIcon(3)));
    ui->Button3->setIconSize(QSize(30,30));
    ui->Button4->setIcon(QIcon(gamepad->getButtonIcon(4)));
    ui->Button4->setIconSize(QSize(30,30));
    timer = new QTimer();
    timer->start(100);
    connect(timer,SIGNAL(timeout()),this,SLOT(Update()));


}

GamepadDialog::~GamepadDialog()
{
    delete ui;
}

void GamepadDialog::Update(){
    TState state=gamepad->getState();
    ui->Button1->setChecked(state.button1);
    ui->Button2->setChecked(state.button2);
    ui->Button3->setChecked(state.button3);
    ui->Button4->setChecked(state.button4);

    ui->xAxis->setValue(((state.joy1.x+JoyMax)/(2.0*JoyMax))*100);
    if(ui->xAxis->value()>50-DeadZone&&ui->xAxis->value()<50+DeadZone)ui->xAxis->setValue(50);

    ui->yAxis->setValue(((state.joy1.y+JoyMax)/(2.0*JoyMax))*100);
    if(ui->yAxis->value()>50-DeadZone&&ui->yAxis->value()<50+DeadZone)ui->yAxis->setValue(50);

}
