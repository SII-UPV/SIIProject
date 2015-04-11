#ifndef CCAJA_H
#define CCAJA_H
#include "cesfera.h"

class cCaja
{

    float px, py;
    float lado;
    int contenido;
    int color; // Formato RGB:0xFF FF FF




public:
    cCaja();
    cCaja(float _px,float _py, float _lado, int _color);
    void Posicion   (float _px, float _py);
    void SetColor   (int _color);
    void SetLado    (float _lado);

    float Posicionx   (void);
    float Posiciony   (void);

    float Lado        (void);
    int   Color       (void);

    void  EntraEsfera (CEsfera* esfera);

};

#endif // CCAJA_H
