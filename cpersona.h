#ifndef CPERSONA_H
#define CPERSONA_H

#include <stdio.h>
#include <queue>
#include <QTime>

#include "videojuego.h"
#include "cesfera.h"
#include "ccaja.h"

enum TPersonaEstado{}; //Revisar
enum TPersonaPose{Parada,Caminando,Girando,Cogiendo,Soltando,Pateando}; //Revisar

class CPersonaEstado //(*)
{
public:
    TPersonaEstado estado;
    QTime tiempo_pendiente;
};

class CPersona
{
    static unsigned int num_personas;
    unsigned int id;
    TColor color;
    TPosicion posicion;
    float orientacion,
          velocidad_avance,
          velocidad_giro,
          energia;
    CEsfera* esfera;
    bool empujar;
    TPersonaPose pose;

//    QTime tiempo_operacion;
//    std::queue<CPersonaEstado*> estados; //(*) Para encolar secuencia de operaciones/poses y acelerar interfaz usuario
    float NormalizarEnergia(float _energia);
public:
    CPersona();
    CPersona(TColor _color, float posicion_x, float posicion_y, float _orientacion, float _velocidad_avance, float _velocidad_giro, float _energia, TPersonaPose _pose);
    CPersona(TColor _color, TPosicion _posicion, float _orientacion, float _velocidad_avance, float _velocidad_giro, float _energia, TPersonaPose _pose);

    unsigned int NumPersonas(void);
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
    TPersonaPose Pose(void);

    void Posicion       (float posicion_x, float posicion_y);
    void Posicion       (TPosicion _posicion);
    void Orientacion    (float _orientacion);

    void VelocidadAvance(float _velocidad_avance);
    void VelocidadGiro  (float _velocidad_giro);
    void Energia        (float _energia);
    void Pose           (TPersonaPose _pose);
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

#endif // CPERSONA_H
