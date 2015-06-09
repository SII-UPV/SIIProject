#include "ccaja.h"

unsigned int CCaja::num_cajas = 0;

CCaja::CCaja()
{
    id         = num_cajas++;
    color      = CAJA_COLOR_DEFECTO;
    capacidad  = CAJA_CAPACIDAD_DEFECTO;
    posicion.x = CAJA_POSICION_X_INICIAL;
    posicion.y = CAJA_POSICION_Y_INICIAL;
}

CCaja::CCaja(TColor _color, unsigned int _capacidad, float posicion_x, float posicion_y)
{
    if(posicion_x < (X_MIN + CAJA_RADIO)) posicion_x = X_MIN + CAJA_RADIO;
    if(posicion_x > (X_MAX - CAJA_RADIO)) posicion_x = X_MAX - CAJA_RADIO;
    if(posicion_y < (Y_MIN + CAJA_RADIO)) posicion_y = Y_MIN + CAJA_RADIO;
    if(posicion_y > (Y_MAX - CAJA_RADIO)) posicion_y = Y_MAX - CAJA_RADIO;
    id         = num_cajas++;
    color      = _color;
    capacidad  = _capacidad;
    posicion.x = posicion_x;
    posicion.y = posicion_y;
}

CCaja::CCaja(TColor _color, unsigned int _capacidad, TPosicion _posicion)
{
    if(_posicion.x < (X_MIN + CAJA_RADIO)) _posicion.x = X_MIN + CAJA_RADIO;
    if(_posicion.x > (X_MAX - CAJA_RADIO)) _posicion.x = X_MAX - CAJA_RADIO;
    if(_posicion.y < (Y_MIN + CAJA_RADIO)) _posicion.y = Y_MIN + CAJA_RADIO;
    if(_posicion.y > (Y_MAX - CAJA_RADIO)) _posicion.y = Y_MAX - CAJA_RADIO;
    id        = num_cajas++;
    color     = _color;
    capacidad = _capacidad;
    posicion  = _posicion;
}

unsigned int CCaja::NumCajas(void)
{
    return num_cajas;
}

unsigned int CCaja::Id(void)
{
    return id;
}

TColor CCaja::Color(void)
{
    return color;
}

unsigned int CCaja::Capacidad(void)
{
    return capacidad;
}

unsigned int CCaja::Contenido(void)
{
    return esferas.size();
}

CEsfera* CCaja::Contenido(unsigned int elemento)
{
    if(elemento < esferas.size())
    {
        return esferas[elemento];
    }
    else
    {
        return 0;
    }
}

float CCaja::PosicionX(void)
{
    return posicion.x;
}

float CCaja::PosicionY(void)
{
    return posicion.y;
}

TPosicion CCaja::Posicion(void)
{
    return posicion;
}

void CCaja::Posicion(float posicion_x, float posicion_y)
{
    if(posicion_x < (X_MIN + CAJA_RADIO)) posicion_x = X_MIN + CAJA_RADIO;
    if(posicion_x > (X_MAX - CAJA_RADIO)) posicion_x = X_MAX - CAJA_RADIO;
    if(posicion_y < (Y_MIN + CAJA_RADIO)) posicion_y = Y_MIN + CAJA_RADIO;
    if(posicion_y > (Y_MAX - CAJA_RADIO)) posicion_y = Y_MAX - CAJA_RADIO;
    posicion.x = posicion_x;
    posicion.y = posicion_y;
}

void CCaja::Posicion(TPosicion _posicion)
{
    if(_posicion.x < (X_MIN + CAJA_RADIO)) _posicion.x = X_MIN + CAJA_RADIO;
    if(_posicion.x > (X_MAX - CAJA_RADIO)) _posicion.x = X_MAX - CAJA_RADIO;
    if(_posicion.y < (Y_MIN + CAJA_RADIO)) _posicion.y = Y_MIN + CAJA_RADIO;
    if(_posicion.y > (Y_MAX - CAJA_RADIO)) _posicion.y = Y_MAX - CAJA_RADIO;
    posicion = _posicion;
}

bool CCaja::Introducir(CEsfera* esfera)
{
    if(capacidad && (color == esfera->Color()))
    {
        capacidad--;
        esferas.push_back(esfera);
        esfera->Caja(this);
        return true;
    }
    else
    {
        return false;
    }
}

void CCaja::Evolucionar(float t)
{

}

void CCaja::Guardar(FILE* archivo)
{

}

void CCaja::Recuperar(FILE *archivo)
{

}
