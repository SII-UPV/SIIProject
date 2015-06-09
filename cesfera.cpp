#include "cesfera.h"
#include "mainwindow.h"

#define NITRO 20.0

//float mu=0.4; //coeficiente rozamiento
float mu=0.01; //coeficiente rozamiento
float g=9.87; //aceleracion gravitacional

unsigned int CEsfera::num_esferas = 0;

CEsfera::CEsfera()
{
    id            = num_esferas++;
    color         = ESFERA_COLOR_DEFECTO;
    posicion.x    = ESFERA_POSICION_X_INICIAL;
    posicion.y    = ESFERA_POSICION_Y_INICIAL;
    velocidad.x   = ESFERA_VELOCIDAD_X_INICIAL;
    velocidad.y   = ESFERA_VELOCIDAD_Y_INICIAL;
    aceleracion.x = ESFERA_ACELERACION_X_INICIAL;
    aceleracion.y = ESFERA_ACELERACION_Y_INICIAL;
    caja          = NULL;
    persona       = NULL;
}

CEsfera::CEsfera(TColor _color, float posicion_x, float posicion_y, float velocidad_x, float velocidad_y, float aceleracion_x, float aceleracion_y)
{
    if(posicion_x    < (X_MIN + ESFERA_RADIO))  posicion_x    = X_MIN + ESFERA_RADIO;
    if(posicion_x    > (X_MAX - ESFERA_RADIO))  posicion_x    = X_MAX - ESFERA_RADIO;
    if(posicion_y    < (Y_MIN + ESFERA_RADIO))  posicion_y    = Y_MIN + ESFERA_RADIO;
    if(posicion_y    > (Y_MAX - ESFERA_RADIO))  posicion_y    = Y_MAX - ESFERA_RADIO;
    if(velocidad_x   < -ESFERA_VELOCIDAD_MAX)   velocidad_x   = -ESFERA_VELOCIDAD_MAX;
    if(velocidad_x   >  ESFERA_VELOCIDAD_MAX)   velocidad_x   =  ESFERA_VELOCIDAD_MAX;
    if(velocidad_y   < -ESFERA_VELOCIDAD_MAX)   velocidad_y   = -ESFERA_VELOCIDAD_MAX;
    if(velocidad_y   >  ESFERA_VELOCIDAD_MAX)   velocidad_y   =  ESFERA_VELOCIDAD_MAX;
    if(aceleracion_x < -ESFERA_ACELERACION_MAX) aceleracion_x = -ESFERA_ACELERACION_MAX;
    if(aceleracion_x >  ESFERA_ACELERACION_MAX) aceleracion_x =  ESFERA_ACELERACION_MAX;
    if(aceleracion_y < -ESFERA_ACELERACION_MAX) aceleracion_y = -ESFERA_ACELERACION_MAX;
    if(aceleracion_y >  ESFERA_ACELERACION_MAX) aceleracion_y =  ESFERA_ACELERACION_MAX;
    id            = num_esferas++;
    color         = _color;
    posicion.x    = posicion_x;
    posicion.y    = posicion_y;
    velocidad.x   = velocidad_x;
    velocidad.y   = velocidad_y;
    aceleracion.x = aceleracion_x;
    aceleracion.y = aceleracion_y;
    caja          = NULL;
    persona       = NULL;
}

CEsfera::CEsfera(TColor _color, TPosicion _posicion, TVelocidad _velocidad, TAceleracion _aceleracion)
{
    if(_posicion.x    < (X_MIN + ESFERA_RADIO))  _posicion.x    = X_MIN + ESFERA_RADIO;
    if(_posicion.x    > (X_MAX - ESFERA_RADIO))  _posicion.x    = X_MAX - ESFERA_RADIO;
    if(_posicion.y    < (Y_MIN + ESFERA_RADIO))  _posicion.y    = Y_MIN + ESFERA_RADIO;
    if(_posicion.y    > (Y_MAX - ESFERA_RADIO))  _posicion.y    = Y_MAX - ESFERA_RADIO;
    if(_velocidad.x   < -ESFERA_VELOCIDAD_MAX)   _velocidad.x   = -ESFERA_VELOCIDAD_MAX;
    if(_velocidad.x   >  ESFERA_VELOCIDAD_MAX)   _velocidad.x   =  ESFERA_VELOCIDAD_MAX;
    if(_velocidad.y   < -ESFERA_VELOCIDAD_MAX)   _velocidad.y   = -ESFERA_VELOCIDAD_MAX;
    if(_velocidad.y   >  ESFERA_VELOCIDAD_MAX)   _velocidad.y   =  ESFERA_VELOCIDAD_MAX;
    if(_aceleracion.x < -ESFERA_ACELERACION_MAX) _aceleracion.x = -ESFERA_ACELERACION_MAX;
    if(_aceleracion.x >  ESFERA_ACELERACION_MAX) _aceleracion.x =  ESFERA_ACELERACION_MAX;
    if(_aceleracion.y < -ESFERA_ACELERACION_MAX) _aceleracion.y = -ESFERA_ACELERACION_MAX;
    if(_aceleracion.y >  ESFERA_ACELERACION_MAX) _aceleracion.y =  ESFERA_ACELERACION_MAX;
    id          = num_esferas++;
    color       = _color;
    posicion    = _posicion;
    velocidad   = _velocidad;
    aceleracion = _aceleracion;
    caja        = NULL;
    persona     = NULL;
}

unsigned int CEsfera::NumEsferas(void)
{
    return num_esferas;
}

unsigned int CEsfera::Id(void)
{
    return id;
}

TColor CEsfera::Color(void)
{
    return color;
}

float CEsfera::PosicionX(void)
{
    return posicion.x;
}

float CEsfera::PosicionY(void)
{
    return posicion.y;
}

TPosicion CEsfera::Posicion(void)
{
    return posicion;
}

float CEsfera::VelocidadX(void)
{
    return velocidad.x;
}

float CEsfera::VelocidadY(void)
{
    return velocidad.y;
}

TVelocidad CEsfera::Velocidad(void)
{
    return velocidad;
}

float CEsfera::AceleracionX(void)
{
    return aceleracion.x;
}

float CEsfera::AceleracionY(void)
{
    return aceleracion.y;
}

TAceleracion CEsfera::Aceleracion(void)
{
    return aceleracion;
}

CCaja* CEsfera::Caja(void)
{
    return caja;
}

CPersona* CEsfera::Persona(void)
{
    return persona;
}

void CEsfera::Posicion(float posicion_x, float posicion_y)
{
    if(posicion_x < (X_MIN + ESFERA_RADIO)) posicion_x = X_MIN + ESFERA_RADIO;
    if(posicion_x > (X_MAX - ESFERA_RADIO)) posicion_x = X_MAX - ESFERA_RADIO;
    if(posicion_y < (Y_MIN + ESFERA_RADIO)) posicion_y = Y_MIN + ESFERA_RADIO;
    if(posicion_y > (Y_MAX - ESFERA_RADIO)) posicion_y = Y_MAX - ESFERA_RADIO;
    posicion.x = posicion_x;
    posicion.y = posicion_y;
}

void CEsfera::Posicion(TPosicion _posicion)
{
    if(_posicion.x < (X_MIN + ESFERA_RADIO)) _posicion.x = X_MIN + ESFERA_RADIO;
    if(_posicion.x > (X_MAX - ESFERA_RADIO)) _posicion.x = X_MAX - ESFERA_RADIO;
    if(_posicion.y < (Y_MIN + ESFERA_RADIO)) _posicion.y = Y_MIN + ESFERA_RADIO;
    if(_posicion.y > (Y_MAX - ESFERA_RADIO)) _posicion.y = Y_MAX - ESFERA_RADIO;
    posicion = _posicion;
}

void CEsfera::Velocidad(float velocidad_x, float velocidad_y)
{
    if(velocidad_x < -ESFERA_VELOCIDAD_MAX) velocidad_x = -ESFERA_VELOCIDAD_MAX;
    if(velocidad_x >  ESFERA_VELOCIDAD_MAX) velocidad_x =  ESFERA_VELOCIDAD_MAX;
    if(velocidad_y < -ESFERA_VELOCIDAD_MAX) velocidad_y = -ESFERA_VELOCIDAD_MAX;
    if(velocidad_y >  ESFERA_VELOCIDAD_MAX) velocidad_y =  ESFERA_VELOCIDAD_MAX;
    velocidad.x = velocidad_x;
    velocidad.y = velocidad_y;
}

void CEsfera::Velocidad(TVelocidad _velocidad)
{
    if(_velocidad.x < -ESFERA_VELOCIDAD_MAX) _velocidad.x = -ESFERA_VELOCIDAD_MAX;
    if(_velocidad.x >  ESFERA_VELOCIDAD_MAX) _velocidad.x =  ESFERA_VELOCIDAD_MAX;
    if(_velocidad.y < -ESFERA_VELOCIDAD_MAX) _velocidad.y = -ESFERA_VELOCIDAD_MAX;
    if(_velocidad.y >  ESFERA_VELOCIDAD_MAX) _velocidad.y =  ESFERA_VELOCIDAD_MAX;
    velocidad = _velocidad;
}

void CEsfera::Aceleracion(float aceleracion_x, float aceleracion_y)
{
    if(aceleracion_x < -ESFERA_ACELERACION_MAX) aceleracion_x = -ESFERA_ACELERACION_MAX;
    if(aceleracion_x >  ESFERA_ACELERACION_MAX) aceleracion_x =  ESFERA_ACELERACION_MAX;
    if(aceleracion_y < -ESFERA_ACELERACION_MAX) aceleracion_y = -ESFERA_ACELERACION_MAX;
    if(aceleracion_y >  ESFERA_ACELERACION_MAX) aceleracion_y =  ESFERA_ACELERACION_MAX;
    aceleracion.x = aceleracion_x;
    aceleracion.y = aceleracion_y;
}

void CEsfera::Aceleracion(TAceleracion _aceleracion)
{
    if(_aceleracion.x < -ESFERA_ACELERACION_MAX) _aceleracion.x = -ESFERA_ACELERACION_MAX;
    if(_aceleracion.x >  ESFERA_ACELERACION_MAX) _aceleracion.x =  ESFERA_ACELERACION_MAX;
    if(_aceleracion.y < -ESFERA_ACELERACION_MAX) _aceleracion.y = -ESFERA_ACELERACION_MAX;
    if(_aceleracion.y >  ESFERA_ACELERACION_MAX) _aceleracion.y =  ESFERA_ACELERACION_MAX;
    aceleracion = _aceleracion;
}

void CEsfera::Caja(CCaja* _caja)
{
    caja = _caja;
}

void CEsfera::Persona(CPersona* _persona)
{
    persona = _persona;
}

void CEsfera::Evolucionar(float t) //REVISAR
{
//EJE X
    if(velocidad.x > 0.0)
    {
        aceleracion.x = -mu*g;                        //aceleración fija como ROZAMIENTO (prohibe el movimiento infinito)
        if(velocidad.x + aceleracion.x * t > 0.0)
        {
            velocidad.x += aceleracion.x * t;
        }    //calculo del cero perfecto (para evitar que se ejecute el bloque inferior al cambiar V de sentido)
        else
        {
            velocidad.x = 0.0;
        }
        posicion.x += velocidad.x * t + aceleracion.x * t * t;
    }

    if(velocidad.x < 0.0)
    {
        aceleracion.x = mu*g;
        if(velocidad.x + aceleracion.x * t < 0.0)
        {
            velocidad.x += aceleracion.x * t;
        }
        else
        {
            velocidad.x = 0.0;
        }
        posicion.x += velocidad.x * t + aceleracion.x * t * t;
    }

    if(velocidad.x == 0.0)
    {
        aceleracion.x = 0.0;
    }

//EJE Y
    if(velocidad.y > 0.0)
    {
        aceleracion.y = -mu*g;                        //aceleración fija como ROZAMIENTO (prohibe el movimiento infinito)
        if(velocidad.y + aceleracion.y * t > 0.0)
        {
            velocidad.y += aceleracion.y * t;
        }    //calculo del cero perfecto (para evitar que se ejecute el bloque inferior al cambiar V de sentido)
        else
        {
            velocidad.y = 0.0;
        }
        posicion.y += velocidad.y * t + aceleracion.y * t * t;
    }

    if(velocidad.y < 0.0)
    {
        aceleracion.y = mu*g;
        if(velocidad.y + aceleracion.y * t < 0.0)
        {
            velocidad.y += aceleracion.y * t;
        }
        else
        {
            velocidad.y = 0.0;
        }
        posicion.y += velocidad.y * t + aceleracion.y * t * t;
    }

    if(velocidad.y == 0.0)
    {
        aceleracion.y = 0.0;
    }

    //EFECTO: REBOTE en los bordes
    //Llevar a Escena
//SII:    if((int)px+DiametroEsfera/2==gamespace_x || (int)px-DiametroEsfera/2==-gamespace_x)
    if(((posicion.x + ESFERA_RADIO) >= X_MAX) || ((posicion.x - ESFERA_RADIO) <= X_MIN))
    {
        velocidad.x = -velocidad.x;

    }
//SII:    if((int)py+DiametroEsfera/2==gamespace_y || (int)py-DiametroEsfera/2==-gamespace_y)
    if(((posicion.y + ESFERA_RADIO) >= Y_MAX) || ((posicion.y - ESFERA_RADIO) <= Y_MIN))
    {
        velocidad.y = -velocidad.y;
    }
}

void CEsfera::Guardar(FILE* archivo)
{

}

void CEsfera::Recuperar(FILE *archivo)
{

}
