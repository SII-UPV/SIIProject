#include "ccaja.h"



cCaja::cCaja(){
    px=0;
    py=0;
    lado=1;
    contenido=0;
    color=0x0;
}

cCaja::cCaja(float _px, float _py, float _lado, int _color)
{
    px=_px;
    py=_py;
    lado=_lado;
    color=_color;
    contenido=0;
}


void cCaja::Posicion(float _px, float _py)
{
px = _px;
py = _py;
}

void cCaja::SetColor(int _color){
    color=_color;
}


void cCaja::SetLado(float _lado){
    lado=_lado;
}

float cCaja::Posicionx(void)
{
return px;
}

float cCaja::Posiciony(void)
{
return py;
}

float cCaja::Lado(void){
    return lado;
}

int cCaja::Color(void){
    return color;
}


// En caso de entrar una esfera, el contador contenido aumentara si el color de la esfera corresponde al de la caja
// Simplemente, para visualizar esto, la caja cambia de color con cada esfera correcta
void cCaja::EntraEsfera(CEsfera* esfera){
    if(esfera->Color()==color){
        contenido++;
        if(contenido%2!=0)color=0xFF0000;
        else color=0xFFFFFF;
    }
}
