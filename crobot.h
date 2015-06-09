#ifndef CROBOT_H
#define CROBOT_H

#include <stdio.h>
#include <queue>
#include <QTime>

#include "videojuego.h"
#include "cesfera.h"
#include "ccaja.h"

enum TRobotEstado{}; //Revisar
enum TRobotPose{Parado}; //Revisar

class CRobotEstado //(*)
{
public:
    TRobotEstado estado;
    QTime tiempo_pendiente;
};

class CRobot
{
    static unsigned int num_robots;
    unsigned int id;
    TColor color;
    TPosicion posicion;
    float orientacion,
          velocidad_avance,
          velocidad_giro,
          energia;
    CEsfera* esfera;
    bool empujar;
    TRobotPose pose;

    float NormalizarEnergia(float _energia);
public:
    CRobot();
    CRobot(TColor _color, float px, float py, float _orientacion, float _velocidad_avance, float _velocidad_giro, float _energia, TRobotPose _pose);
    CRobot(TColor _color, TPosicion _posicion, float _orientacion, float _velocidad_avance, float velocidad_giro, float _energia, TRobotPose _pose);

    unsigned int NumRobots(void);
    unsigned int Id(void);

    TColor Color(void);

    float PosicionX(void);
    float PosicionY(void);
    TPosicion Posicion(void);

    float Orientacion    (void);
    float VelocidadAvance(void);
    float VelocidadGiro  (void);
    float Energia        (void);
    CEsfera* Esfera(void);
    bool Empujar(void);
    TRobotPose Pose(void);

    void Posicion(float px, float py);
    void Posicion(TPosicion _posicion);
    void Orientacion(float _orientacion);
    void VelocidadAvance(float _velocidad);
    void VelocidadGiro  (float _velocidad);
    void Energia(float _energia);
    void Pose(TRobotPose _pose);

    void ActualizarEnergia(void);
    void Parar(void);

    void Coger    (CEsfera* _esfera);
    void Soltar   (void);
    void Almacenar(CCaja* caja);

    void Patear (CEsfera* _esfera);
    void Empujar(bool _empujar);

    void Evolucionar(float t);

    void Guardar  (FILE* archivo);
    void Recuperar(FILE *archivo);
};

#endif // CROBOT_H
