#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <list>
#include <vector>

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>

#include "ccomunicacionservidor.h"
#include "cesfera.h"
#include "cescena.h"
#include "cacercade.h"
#include "cvista2d.h"
#include "cvista3d.h"
#include "ccontrolpersona.h"
#include "ccontrolrobot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    Ui::MainWindow *ui;

    CComunicacionServidor *comunicacion_servidor;
    unsigned int num_conexiones;

    float tiempo;
    unsigned int velocidad_juego;
    QTimer    *temporizador;
    CEscena   *escena;
    CAcercaDe *acerca_de;

    std::vector<CVista2D*> vistas2d;
    std::vector<CVista3D*> vistas3d;

    std::vector<CControlPersona*> controles_personas;
    std::vector<CControlRobot*>   controles_robots;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void Remoto(void);
    void NuevaConexion(CConexion* conexion);
    void Leer(void);
    void Interpretar(QString mensaje);

    void Simular(void);
    void VelocidadJuego(void);
    void Evolucionar(void);

    void NuevaEsfera (void);
    void NuevaCaja   (void);
    void NuevaPersona(void);
    void NuevoRobot  (void);

    void BorrarEscena  (void);
    void BorrarEsferas (void);
    void BorrarCajas   (void);
    void BorrarPersonas(void);
    void BorrarRobots  (void);

    void NuevaVista2D(void);
    void NuevaVista3D(void);

    void NuevoControlPersona(void);
    void NuevoControlRobot(void);

    void Ayuda(void);
    void Salir(void);
};

#endif // MAINWINDOW_H
