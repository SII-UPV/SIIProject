#ifndef CESFERA_H
#define CESFERA_H

#include <stdio.h>

#include "videojuego.h"

class CCaja;
class CPersona;

class CEsfera
{
    static unsigned int num_esferas;
    unsigned int id;
    TColor color;

    TPosicion    posicion;
    TVelocidad   velocidad;
    TAceleracion aceleracion;

    CCaja*    caja;
    CPersona* persona;
public:
    CEsfera();
    CEsfera(TColor _color, float posicion_x, float posicion_y, float velocidad_x, float velocidad_y, float aceleracion_x, float aceleracion_y);
    CEsfera(TColor _color, TPosicion _posicion, TVelocidad _velocidad, TAceleracion _aceleracion);

    unsigned int NumEsferas(void);
    unsigned int Id(void);

    TColor Color(void);

    float PosicionX(void);
    float PosicionY(void);
    TPosicion Posicion(void);

    float VelocidadX(void);
    float VelocidadY(void);
    TVelocidad Velocidad(void);

    float AceleracionX(void);
    float AceleracionY(void);
    TAceleracion Aceleracion(void);

    CCaja*    Caja(void);
    CPersona* Persona(void);

    void Posicion(float posicion_x, float posicion_y);
    void Posicion(TPosicion _posicion);

    void Velocidad(float velocidad_x, float velocidad_y);
    void Velocidad(TVelocidad _velocidad);

    void Aceleracion(float aceleracion_x, float aceleracion_y);
    void Aceleracion(TAceleracion _aceleracion);

    void Caja   (CCaja* _caja);
    void Persona(CPersona* _persona);

    void Evolucionar(float t);

    void Guardar(FILE* archivo);
    void Recuperar(FILE *archivo);
};

#endif // CESFERA_H
