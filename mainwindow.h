#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QRgb>
#include <QKeyEvent>
#include "ccaja.h"
#include "cpersona.h"
#include <qmath.h>

#include <list>
#include <cmath>
#include <stdlib.h>
#include <time.h>

#define OrigenX        100
#define OrigenY        50
#define DiametroEsfera 10
#define DiametroPersona 15
#define gamespace_x 265
#define gamespace_y 200

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void MostrarEscena (void);
    void MostrarSliders(void);
    void MostrarLabels (void);

private:
    Ui::MainWindow *ui;

    float                tiempo;
    QTimer               *temporizador;
    QGraphicsScene       *escena;

    QGraphicsEllipseItem *elipse;
    QGraphicsEllipseItem *elipse2;
    QGraphicsEllipseItem *elipse3;

    CEsfera              *esfera;
    CEsfera              *esfera2;
    CEsfera              *esfera3;

    typedef struct{CEsfera              *esfera;
                   QGraphicsEllipseItem *elipse;}TEsfera;
    std::list<TEsfera *> esferas;

    typedef struct{cCaja              *caja;
                   QGraphicsRectItem  *rectangulo;}TCaja;
    std::list<TCaja *> cajas;

    typedef struct{cPersona             *persona;
                   QGraphicsEllipseItem *elipse;}TPersona;
    std::list<TPersona *> personas;

public slots:
    void Posicion   (void);
    void Velocidad  (void);
    //void Aceleracion(void);
    void Simular    (void);
    void Evolucionar(void);
    void Nitrox      (void);
    void Nitroy      (void);
    void Tiempo_juego(int t);
    void ControlColisiones(void);
    void Colision(CEsfera *chocante,  CEsfera *receptor);
    void Colision(CEsfera *chocante,  cCaja *receptor);
    void Colision(cPersona *chocante, cCaja *receptor);
    void Colision(CEsfera *chocante,  cPersona *receptor);
    void NuevaEsfera(void);
    void NuevaCaja(void);
    void NuevaPersona(void);

    void Nitro(void);

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
