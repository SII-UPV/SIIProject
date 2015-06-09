#include "cacercade.h"
#include "ui_cacercade.h"

CAcercaDe::CAcercaDe(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CAcercaDe)
{
    ui->setupUi(this);
}

CAcercaDe::~CAcercaDe()
{
    delete ui;
}
