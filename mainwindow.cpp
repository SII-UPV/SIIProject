#include "mainwindow.h"
#include "ui_mainwindow.h"

#define OrigenX        100
#define OrigenY        50
#define DiametroEsfera 10

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    temporizador = new QTimer(this);
    temporizador->setInterval(100); //0.1s
    tiempo = 0.0;

    escena = new QGraphicsScene(this);
    ui->graphicsView->setScene(escena);

    QBrush pincel(Qt::white);
    QPen   lapiz (Qt::black);
    lapiz.setWidth(1);
    elipse = escena->addEllipse(OrigenX-DiametroEsfera/2,OrigenY-DiametroEsfera/2,
                                DiametroEsfera,DiametroEsfera,
                                lapiz, pincel);
    QLine ejeX,ejeY;
    ejeX.setP1(QPoint(OrigenX-100,OrigenY));
    ejeX.setP2(QPoint(OrigenX+100,OrigenY));
    ejeY.setP1(QPoint(OrigenX,OrigenY-100));
    ejeY.setP2(QPoint(OrigenX,OrigenY+100));
    escena->addLine(ejeX,lapiz);
    escena->addLine(ejeY,lapiz);

    esfera = new CEsfera;

    connect(ui->horizontalSliderPosicion   ,SIGNAL(sliderReleased()),this,SLOT(Posicion()));
    connect(ui->horizontalSliderVelocidad  ,SIGNAL(sliderReleased()),this,SLOT(Velocidad()));
    connect(ui->horizontalSliderAceleracion,SIGNAL(sliderReleased()),this,SLOT(Aceleracion()));
    connect(ui->checkBoxSimular            ,SIGNAL(clicked())       ,this,SLOT(Simular()));
    connect(temporizador                   ,SIGNAL(timeout())       ,this,SLOT(Evolucionar()));
}

MainWindow::~MainWindow()
{
    delete ui;

    delete temporizador;
    delete escena;
    delete esfera;
}

void MainWindow::MostrarEscena(void)
{
    int x = (int) esfera->Posicion() + OrigenX;

    elipse->setRect(x-DiametroEsfera/2,OrigenY-DiametroEsfera/2,
                    DiametroEsfera,DiametroEsfera);
    escena->update();
}

void MainWindow::MostrarSliders(void)
{
    ui->horizontalSliderPosicion   ->setValue((int) esfera->Posicion()        );
    ui->horizontalSliderVelocidad  ->setValue((int) esfera->Velocidad()   * 10);
    ui->horizontalSliderAceleracion->setValue((int) esfera->Aceleracion() * 20);
}

void MainWindow::MostrarLabels(void)
{
    ui->labelTiempo     ->setText(QString("t = ") + QString::number(tiempo               , 'g', 5));
    ui->labelPosicion   ->setText(QString("p = ") + QString::number(esfera->Posicion()   , 'g', 5));
    ui->labelVelocidad  ->setText(QString("v = ") + QString::number(esfera->Velocidad()  , 'g', 5));
    ui->labelAceleracion->setText(QString("a = ") + QString::number(esfera->Aceleracion(), 'g', 5));
}

void MainWindow::Posicion(void)
{
    esfera->Posicion((float)ui->horizontalSliderPosicion->value());
    MostrarLabels();
    MostrarEscena();
}

void MainWindow::Velocidad(void)
{
    esfera->Velocidad((float)ui->horizontalSliderVelocidad->value() / 10.0);
    MostrarLabels();
    MostrarEscena();
}

void MainWindow::Aceleracion(void)
{
    esfera->Aceleracion((float)ui->horizontalSliderAceleracion->value() / 20.0);
    MostrarLabels();
    MostrarEscena();
}

void MainWindow::Simular(void)
{
    if(ui->checkBoxSimular->checkState())
        temporizador->start();
    else
        temporizador->stop();
}

void MainWindow::Evolucionar(void)
{
    tiempo += temporizador->interval() / 1000.0;
    esfera->Evolucionar(temporizador->interval() / 1000.0);
    MostrarSliders();
    MostrarLabels();
    MostrarEscena();
}
