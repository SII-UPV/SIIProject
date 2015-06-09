#include <math.h>

#include "cpersona.h"

unsigned int CPersona::num_personas = 0;

float CPersona::NormalizarEnergia(float _energia)
{
    return _energia; //Completar
}

CPersona::CPersona()
{
    id               = num_personas++;
    color            = PERSONA_COLOR_DEFECTO;
    posicion.x       = PERSONA_POSICION_X_INICIAL;
    posicion.y       = PERSONA_POSICION_Y_INICIAL;
    orientacion      = PERSONA_ORIENTACION_INICIAL;
    velocidad_avance = PERSONA_VELOCIDAD_AVANCE_INICIAL;
    velocidad_giro   = PERSONA_VELOCIDAD_GIRO_INICIAL;
    energia          = PERSONA_ENERGIA_INICIAL;
    pose             = PERSONA_POSE_INICIAL;
}

CPersona::CPersona(TColor _color, float posicion_x, float posicion_y, float _orientacion, float _velocidad_avance, float _velocidad_giro, float _energia, TPersonaPose _pose)
{
    if(posicion_x < (X_MIN + PERSONA_RADIO)) posicion_x = X_MIN + PERSONA_RADIO;
    if(posicion_x > (X_MAX - PERSONA_RADIO)) posicion_x = X_MAX - PERSONA_RADIO;
    if(posicion_y < (Y_MIN + PERSONA_RADIO)) posicion_y = Y_MIN + PERSONA_RADIO;
    if(posicion_y > (Y_MAX - PERSONA_RADIO)) posicion_y = Y_MAX - PERSONA_RADIO;
    _orientacion = NormalizarAnguloRadianes(_orientacion);
    if(_velocidad_avance < -PERSONA_VELOCIDAD_AVANCE_MAX) _velocidad_avance = -PERSONA_VELOCIDAD_AVANCE_MAX;
    if(_velocidad_avance >  PERSONA_VELOCIDAD_AVANCE_MAX) _velocidad_avance =  PERSONA_VELOCIDAD_AVANCE_MAX;
    if(_velocidad_giro   < -PERSONA_VELOCIDAD_GIRO_MAX)   _velocidad_giro   = -PERSONA_VELOCIDAD_GIRO_MAX;
    if(_velocidad_giro   >  PERSONA_VELOCIDAD_GIRO_MAX)   _velocidad_giro   =  PERSONA_VELOCIDAD_GIRO_MAX;
    _energia = NormalizarEnergia(_energia);
    id               = num_personas++;
    color            = _color;
    posicion.x       = posicion_x;
    posicion.y       = posicion_y;
    orientacion      = _orientacion;
    velocidad_avance = _velocidad_avance;
    velocidad_giro   = _velocidad_giro;
    energia          = _energia;
    pose             = _pose;
}

CPersona::CPersona(TColor _color, TPosicion _posicion, float _orientacion, float _velocidad_avance, float _velocidad_giro, float _energia, TPersonaPose _pose)
{
    if(_posicion.x < (X_MIN + PERSONA_RADIO)) _posicion.x = X_MIN + PERSONA_RADIO;
    if(_posicion.x > (X_MAX - PERSONA_RADIO)) _posicion.x = X_MAX - PERSONA_RADIO;
    if(_posicion.y < (Y_MIN + PERSONA_RADIO)) _posicion.y = Y_MIN + PERSONA_RADIO;
    if(_posicion.y > (Y_MAX - PERSONA_RADIO)) _posicion.y = Y_MAX - PERSONA_RADIO;
    _orientacion = NormalizarAnguloRadianes(_orientacion);
    if(_velocidad_avance < -PERSONA_VELOCIDAD_AVANCE_MAX) _velocidad_avance = -PERSONA_VELOCIDAD_AVANCE_MAX;
    if(_velocidad_avance >  PERSONA_VELOCIDAD_AVANCE_MAX) _velocidad_avance =  PERSONA_VELOCIDAD_AVANCE_MAX;
    if(_velocidad_giro   < -PERSONA_VELOCIDAD_GIRO_MAX)   _velocidad_giro   = -PERSONA_VELOCIDAD_GIRO_MAX;
    if(_velocidad_giro   >  PERSONA_VELOCIDAD_GIRO_MAX)   _velocidad_giro   =  PERSONA_VELOCIDAD_GIRO_MAX;
    _energia = NormalizarEnergia(_energia);
    id               = num_personas++;
    color            = _color;
    posicion.x       = _posicion.x;
    posicion.y       = _posicion.y;
    orientacion      = _orientacion;
    velocidad_avance = _velocidad_avance;
    velocidad_giro   = _velocidad_giro;
    energia          = _energia;
    pose             = _pose;
}

unsigned int CPersona::NumPersonas(void)
{
    return num_personas;
}

unsigned int CPersona::Id(void)
{
    return id;
}

TColor CPersona::Color(void)
{
    return color;
}

float CPersona::PosicionX(void)
{
    return posicion.x;
}

float CPersona::PosicionY(void)
{
    return posicion.y;
}

TPosicion CPersona::Posicion(void)
{
    return posicion;
}

float CPersona::Orientacion(void)
{
    return orientacion;
}

float CPersona::VelocidadAvance(void)
{
    return velocidad_avance;
}

float CPersona::VelocidadGiro(void)
{
    return velocidad_giro;
}

float CPersona::Energia(void)
{
    return energia;
}

CEsfera* CPersona::Esfera(void)
{
    return esfera;
}

bool CPersona::Empujar(void)
{
    return empujar;
}

TPersonaPose CPersona::Pose(void)
{
    return pose;
}

void CPersona::Posicion(float posicion_x, float posicion_y)
{
    if(posicion_x < (X_MIN + PERSONA_RADIO)) posicion_x = X_MIN + PERSONA_RADIO;
    if(posicion_x > (X_MAX - PERSONA_RADIO)) posicion_x = X_MAX - PERSONA_RADIO;
    if(posicion_y < (Y_MIN + PERSONA_RADIO)) posicion_y = Y_MIN + PERSONA_RADIO;
    if(posicion_y > (Y_MAX - PERSONA_RADIO)) posicion_y = Y_MAX - PERSONA_RADIO;
    posicion.x = posicion_x;
    posicion.y = posicion_y;
}

void CPersona::Posicion(TPosicion _posicion)
{
    if(_posicion.x < (X_MIN + PERSONA_RADIO)) _posicion.x = X_MIN + PERSONA_RADIO;
    if(_posicion.x > (X_MAX - PERSONA_RADIO)) _posicion.x = X_MAX - PERSONA_RADIO;
    if(_posicion.y < (Y_MIN + PERSONA_RADIO)) _posicion.y = Y_MIN + PERSONA_RADIO;
    if(_posicion.y > (Y_MAX - PERSONA_RADIO)) _posicion.y = Y_MAX - PERSONA_RADIO;
    posicion = _posicion;
}

void CPersona::Orientacion(float _orientacion)
{
    orientacion = NormalizarAnguloRadianes(_orientacion);
}

void CPersona::VelocidadAvance(float _velocidad_avance)
{
    if(_velocidad_avance < -PERSONA_VELOCIDAD_AVANCE_MAX) _velocidad_avance = -PERSONA_VELOCIDAD_AVANCE_MAX;
    if(_velocidad_avance >  PERSONA_VELOCIDAD_AVANCE_MAX) _velocidad_avance =  PERSONA_VELOCIDAD_AVANCE_MAX;
    velocidad_avance = _velocidad_avance;
}

void CPersona::VelocidadGiro(float _velocidad_giro)
{
    if(_velocidad_giro < -PERSONA_VELOCIDAD_GIRO_MAX) _velocidad_giro = -PERSONA_VELOCIDAD_GIRO_MAX;
    if(_velocidad_giro >  PERSONA_VELOCIDAD_GIRO_MAX) _velocidad_giro =  PERSONA_VELOCIDAD_GIRO_MAX;
    velocidad_giro = _velocidad_giro;
}

void CPersona::Pose(TPersonaPose _pose)
{
    pose = _pose;
}

void CPersona::ActualizarEnergia(void)
{
    //Completar: -Gasto +Recuperación
    //Ver si invocar en cada uno de los siguientes métodos, o si invocar de forma resumida
}

void CPersona::Parar(void)
{
    VelocidadAvance(0.0);
    VelocidadGiro  (0.0);
    //Establecer nueva energía según gasto energético
    //Establecer vx = vy = 0.0;
    //Poner en cola
}

void CPersona::Coger(CEsfera* _esfera)
{
    //Si manos libres, coger esfera
    //Establecer nueva energía según gasto energético
    //Poner en cola
}

void CPersona::Soltar(void)
{
    //Si manos ocupadas, soltar esfera
    //Establecer nueva energía según gasto energético
    //Poner en cola
}

void CPersona::Almacenar(CCaja* caja)
{

}

void CPersona::Patear(CEsfera* _esfera)
{
    //Establecer nueva energía según gasto energético
    //Poner en cola
}

void CPersona::Empujar(bool _empujar)
{
    empujar = _empujar;
}

void CPersona::Evolucionar(float t)
{
    orientacion += velocidad_giro * t;
    orientacion = NormalizarAnguloRadianes(orientacion);

    posicion.x += velocidad_avance * t * cos(orientacion);
    posicion.y -= velocidad_avance * t * sin(orientacion);

    //Llevar a Escena
    if(posicion.x <= (X_MIN + PERSONA_RADIO))
    {
        posicion.x = X_MIN + PERSONA_RADIO;
        Parar();
    }
    if(posicion.x >= (X_MAX - PERSONA_RADIO))
    {
        posicion.x = X_MAX - PERSONA_RADIO;
        Parar();
    }
    if(posicion.y <= (Y_MIN + PERSONA_RADIO))
    {
        posicion.y = Y_MIN + PERSONA_RADIO;
        Parar();
    }
    if(posicion.y >= (Y_MAX - PERSONA_RADIO))
    {
        posicion.y = Y_MAX - PERSONA_RADIO;
        Parar();
    }
    //Mientras operaciones en cola
    //Actualizar tiempo operación actual
    //Si nueva operación, señalizar a la escena
}

void CPersona::Guardar(FILE* archivo)
{

}

void CPersona::Recuperar(FILE *archivo)
{

}
