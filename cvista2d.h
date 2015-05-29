#ifndef CVISTA2D_H
#define CVISTA2D_H

#include <stdio.h>
#include <vector>
#include <QMainWindow>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QtNetwork>

#include "videojuego.h"
#include "ccomunicacioncliente.h"
#include "ccomunicacionservidor.h"
#include "cescena.h"

QT_BEGIN_NAMESPACE
class QUdpSocket;
QT_END_NAMESPACE

namespace Ui {
class CVista2D;
}

class CEscena;

class CVista2D : public QMainWindow
{
    Q_OBJECT
    Ui::CVista2D *ui;
    CComunicacionCliente *comunicacion_cliente;
    CComunicacionServidor *comunicacion_servidor;

       QUdpSocket *udpSocket;

    CEscena        *escena;
    QGraphicsScene *escena2d;
    std::vector<QGraphicsEllipseItem*> esferas2d;
    std::vector<QGraphicsEllipseItem*> cajas2d;
    std::vector<QGraphicsEllipseItem*> personas2d;
    std::vector<QGraphicsEllipseItem*> robots2d;
    QPen lapiz_eje,
         lapiz_pared,
         lapiz_esfera_roja,
         lapiz_esfera_verde,
         lapiz_esfera_azul,
         lapiz_caja_roja,
         lapiz_caja_verde,
         lapiz_caja_azul,
         lapiz_persona_roja,
         lapiz_persona_verde,
         lapiz_persona_azul,
         lapiz_robot_rojo,
         lapiz_robot_verde,
         lapiz_robot_azul;
    QBrush pincel_esfera_roja,
           pincel_esfera_verde,
           pincel_esfera_azul,
           pincel_caja_roja,
           pincel_caja_verde,
           pincel_caja_azul,
           pincel_persona_roja,
           pincel_persona_verde,
           pincel_persona_azul,
           pincel_robot_rojo,
           pincel_robot_verde,
           pincel_robot_azul;



public:
    explicit CVista2D(QWidget *parent = 0);
    ~CVista2D();

    void keyPressEvent(QKeyEvent* e);

    void Escena(CEscena* _escena);
    CEscena* Escena(void);

    void NuevaEsfera (TColor color, TPosicion posicion);
    void NuevaCaja   (TColor color, TPosicion posicion);
    void NuevaPersona(TColor color, TPosicion posicion, float orientacion);
    void NuevoRobot  (TColor color, TPosicion posicion, float orientacion);



    void MostrarEsfera (unsigned int esfera);
    void MostrarCaja   (unsigned int caja);
    void MostrarPersona(unsigned int persona);
    void MostrarRobot  (unsigned int robot);

    void OcultarEsfera (unsigned int esfera);
    void OcultarCaja   (unsigned int caja);
    void OcultarPersona(unsigned int persona);
    void OcultarRobot  (unsigned int robot);

    void PosicionEsfera (unsigned int esfera,  TPosicion posicion);
    void PosicionCaja   (unsigned int caja,    TPosicion posicion);
    void PosicionPersona(unsigned int persona, TPosicion posicion);
    void PosicionRobot  (unsigned int robot,   TPosicion posicion);

    void OrientacionPersona(unsigned int persona, float orientacion);
    void OrientacionRobot  (unsigned int robot,   float orientacion);

    void BorrarEsferas (void);
    void BorrarCajas   (void);
    void BorrarPersonas(void);
    void BorrarRobots  (void);


    void Actualizar(void);
    void Mostrar(void);

    void Guardar(FILE* archivo);
    void Recuperar(FILE *archivo);
public slots:


    void Escalar(void);
    void MostrarOcultarEsferas (void);
    void MostrarOcultarCajas   (void);
    void MostrarOcultarPersonas(void);
    void MostrarOcultarRobots  (void);

private slots:
        void processPendingDatagrams(void);
};

#endif // CVISTA2D_H
