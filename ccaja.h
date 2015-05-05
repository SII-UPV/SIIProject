#ifndef CCAJA_H
#define CCAJA_H

#include <stdio.h>
#include <vector>

#include "videojuego.h"
#include "cesfera.h"

class CCaja
{
    static unsigned int num_cajas;
    unsigned int id;
    TColor color;
    unsigned int capacidad;
    std::vector<CEsfera*> esferas;
    TPosicion posicion;
public:
    CCaja();
    CCaja(TColor _color, unsigned int _capacidad, float posicion_x, float posicion_y);
    CCaja(TColor _color, unsigned int _capacidad, TPosicion _posicion);

    unsigned int NumCajas(void);
    unsigned int Id(void);

    TColor Color(void);

    unsigned int Capacidad(void);
    unsigned int Contenido(void);
    CEsfera* Contenido(unsigned int elemento);

    float PosicionX(void);
    float PosicionY(void);
    TPosicion Posicion(void);

    void Posicion(float posicion_x, float posicion_y);
    void Posicion(TPosicion _posicion);

    bool Introducir(CEsfera* esfera);

    void Evolucionar(float t);

    void Guardar  (FILE* archivo);
    void Recuperar(FILE *archivo);
};

#endif // CCAJA_H
