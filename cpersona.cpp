#include "cpersona.h"
#include "mainwindow.h"
#define mu 5
#define g 9.8



/*Clase cPersona
/
/   Se ha usado el mismo modelo fisico que con la esfera, solo que cambiando las constantes
/
/   Una persona puede llevar una CEsfera consigo, ese detalle se ha añadido al metodo Evolucionar()
/
/
*/
cPersona::cPersona()
{
    px=0;
    py=0;
    vx=0;
    vy=0;
    ax=0;
    ay=0;
    color=0x0;
    lleva= NULL;
}

cPersona::~cPersona()
{

}
cPersona::cPersona(float _px, float _vx, float _ax, float _py, float _vy, float _ay, int _color){
    px=_px;
    py=_py;
    vx=_vx;
    vy=_vy;
    ax=_ax;
    ay=_ay;
    color=_color;
    lleva = new CEsfera();
}
void cPersona::Posicion(float _px, float _py){
    px=_px;
    py=_py;
}
void cPersona::Velocidad(float _vx, float _vy){
    vx=_vx;
    vy=_vy;
}
void cPersona::Aceleracion(float _ax, float _ay){
    ax=_ax;
    ay=_ay;
}
void cPersona::SetColor(int _color){
    color=_color;
}
void cPersona::CogerEsfera(CEsfera* _esfera){
    lleva=_esfera;
}
float cPersona::Posicionx(){
    return px;
}
float cPersona::Posiciony(){
    return py;
}
float cPersona::Velocidadx(){
    return vx;
}
float cPersona::Velocidady(){
    return vy;
}
float cPersona::Aceleracionx(){
    return ax;
}
float cPersona::Aceleraciony(){
    return ay;
}

int cPersona::Color(){
    return color;
}
CEsfera* cPersona::Lleva(){
    return lleva;
}


void cPersona::Evolucionar(float _t){
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
        if(((int)px)>=gamespace_x || ((int)px)<=-gamespace_x)
        {
            vx=-vx;

        }
    //SII:    if((int)py+DiametroEsfera/2==gamespace_y || (int)py-DiametroEsfera/2==-gamespace_y)
        if(((int)py)>=gamespace_y || ((int)py)<=-gamespace_y)
        {
            vy=-vy;
        }
        if(lleva!=NULL){
            lleva->Posicion(px,py);
            lleva->Velocidad(0,0);
            lleva->Aceleracion(0,0);
        }


}
