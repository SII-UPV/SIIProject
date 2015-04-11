#ifndef CPERSONA_H
#define CPERSONA_H
#include "cesfera.h"

class cPersona
{
    float px, py;
    float vx, vy;
    float ax, ay;
    int color;   // Formato RGB:0xFF FF FF
    CEsfera* lleva;


public:
    cPersona();
    ~cPersona();
    cPersona(float _px, float _vx, float _ax, float _py, float _vy, float _ay, int _color);

    void Posicion   (float _px, float _py);
    void Velocidad  (float _vx, float _vy);
    void Aceleracion(float _ax, float _ay);
    void SetColor   (int _color);
    void CogerEsfera(CEsfera* _esfra);
    void DejarEsfera(void);

    float Posicionx   (void);
    float Velocidadx  (void);
    float Aceleracionx(void);
    float Posiciony   (void);
    float Velocidady  (void);
    float Aceleraciony(void);

    int   Color       (void);
    CEsfera* Lleva     (void);

    void Evolucionar(float _t);
};


#endif // CPERSONA_H
