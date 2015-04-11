#include "cesfera.h"
#include "mainwindow.h"

#define mu 0.4 //coeficiente rozamiento
#define g 9.87 //aceleracion gravitacional

CEsfera::CEsfera()
{
px = vx = ax = 0.0;
py = vy = ay = 0.0;
}

CEsfera::CEsfera(float _px, float _vx, float _ax, float _py, float _vy, float _ay){
    CEsfera(_px,_vx,_ax,_py,_vy,_ay,5,0xFFFFFF);
}

CEsfera::CEsfera(float _px, float _vx, float _ax, float _py, float _vy, float _ay, float _radio, int _color)
{
px = _px;
vx = _vx;
ax = _ax;
py = _py;
vy = _vy;
ay = _ay;
color = _color;
radio = _radio;
llevada=false;
}

void CEsfera::Posicion(float _px, float _py)
{
px = _px;
py = _py;
}

void CEsfera::Velocidad(float _vx, float _vy)
{
vx = _vx;
vy = _vy;
}

void CEsfera::Aceleracion(float _ax, float _ay)
{
ax = _ax;
ay = _ay;
}

void CEsfera::SetColor(int _color){
    color=_color;
}

void CEsfera::SetLlevada(bool _llevada){
    llevada=_llevada;
}

void CEsfera::SetRadio(float _radio){
    radio=_radio;
}

float CEsfera::Posicionx(void)
{
return px;
}

float CEsfera::Velocidadx(void)
{
return vx;
}

float CEsfera::Aceleracionx(void)
{
return ax;
}

float CEsfera::Posiciony(void)
{
return py;
}

float CEsfera::Velocidady(void)
{
return vy;
}

float CEsfera::Aceleraciony(void)
{
return ay;
}

float CEsfera::Radio(void){
    return radio;
}

int CEsfera::Color(void){
    return color;
}

bool CEsfera::esLlevada(void){
    return llevada;
}

void CEsfera::Evolucionar(float _t)
{
//EJE X
    if(vx>0)
    {
    ax=-mu*g;                        //aceleración fija como ROZAMIENTO (prohibe el movimiento infinito)
    if(vx+ax*_t>0){ vx += ax * _t; }    //calculo del cero perfecto (para evitar que se ejecute el bloque inferior al cambiar V de sentido)
    else{ vx=0; }
    px += vx * _t + ax * _t*_t;

    }

    if(vx<0)
    {
    ax=mu*g;
    if(vx+ax*_t<0){ vx += ax * _t; }
    else{ vx=0; }
    px += vx * _t + ax * _t*_t;
    }

    if(vx==0)
    { ax=0; }

//EJE Y
    if(vy>0)
    {
    ay=-mu*g;                        //aceleración fija como ROZAMIENTO (prohibe el movimiento infinito)
    if(vy+ay*_t>0){ vy += ay * _t; }    //calculo del cero perfecto (para evitar que se ejecute el bloque inferior al cambiar V de sentido)
    else{ vy=0; }
    py += vy * _t + ay * _t*_t;
    }

    if(vy<0)
    {
    ay=mu*g;
    if(vy+ay*_t<0){ vy += ay * _t; }
    else{ vy=0; }
    py += vy * _t + ay * _t*_t;
    }

    if(vy==0)
    { ay=0; }

    //EFECTO: REBOTE en los bordes
//SII:    if((int)px+DiametroEsfera/2==gamespace_x || (int)px-DiametroEsfera/2==-gamespace_x)
    if(((int)px+DiametroEsfera/2)>=gamespace_x || ((int)px-DiametroEsfera/2)<=-gamespace_x)
    {
        vx=-vx;

    }
//SII:    if((int)py+DiametroEsfera/2==gamespace_y || (int)py-DiametroEsfera/2==-gamespace_y)
    if(((int)py+DiametroEsfera/2)>=gamespace_y || ((int)py-DiametroEsfera/2)<=-gamespace_y)
    {
        vy=-vy;
    }

}

void CEsfera::Nitro(int eje)
{
    if(eje==0)
    {   if(vx>0){ vx += 20; }
        if(vx<0){ vx -= 20; }
    }
    if(eje==1)
    {   if(vy>0){ vy += 20; }
        if(vy<0){ vy -= 20; }
    }
}
