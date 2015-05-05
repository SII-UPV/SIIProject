#include <math.h>

#include "crobot.h"

unsigned int CRobot::num_robots = 0;

float CRobot::NormalizarEnergia(float _energia)
{
    return _energia; //Completar
}

CRobot::CRobot()
{
    id               = num_robots++;
    color            = ROBOT_COLOR_DEFECTO;
    posicion.x       = ROBOT_POSICION_X_INICIAL;
    posicion.y       = ROBOT_POSICION_Y_INICIAL;
    orientacion      = ROBOT_ORIENTACION_INICIAL;
    velocidad_avance = ROBOT_VELOCIDAD_AVANCE_INICIAL;
    velocidad_giro   = ROBOT_VELOCIDAD_GIRO_INICIAL;
    energia          = ROBOT_ENERGIA_INICIAL;
    pose             = ROBOT_POSE_INICIAL;
}

CRobot::CRobot(TColor _color, float posicion_x, float posicion_y, float _orientacion, float _velocidad_avance, float _velocidad_giro, float _energia, TRobotPose _pose)
{
    if(posicion_x < (X_MIN + ROBOT_RADIO)) posicion_x = X_MIN + ROBOT_RADIO;
    if(posicion_x > (X_MAX - ROBOT_RADIO)) posicion_x = X_MAX - ROBOT_RADIO;
    if(posicion_y < (Y_MIN + ROBOT_RADIO)) posicion_y = Y_MIN + ROBOT_RADIO;
    if(posicion_y > (Y_MAX - ROBOT_RADIO)) posicion_y = Y_MAX - ROBOT_RADIO;
    _orientacion = NormalizarAnguloRadianes(_orientacion);
    if(_velocidad_avance < -ROBOT_VELOCIDAD_AVANCE_MAX) _velocidad_avance = -ROBOT_VELOCIDAD_AVANCE_MAX;
    if(_velocidad_avance >  ROBOT_VELOCIDAD_AVANCE_MAX) _velocidad_avance =  ROBOT_VELOCIDAD_AVANCE_MAX;
    if(_velocidad_giro   < -ROBOT_VELOCIDAD_GIRO_MAX)   _velocidad_giro   = -ROBOT_VELOCIDAD_GIRO_MAX;
    if(_velocidad_giro   >  ROBOT_VELOCIDAD_GIRO_MAX)   _velocidad_giro   =  ROBOT_VELOCIDAD_GIRO_MAX;
    _energia = NormalizarEnergia(_energia);
    id               = num_robots++;
    color            = _color;
    posicion.x       = posicion_x;
    posicion.y       = posicion_y;
    orientacion      = _orientacion;
    velocidad_avance = _velocidad_avance;
    velocidad_giro   = _velocidad_giro;
    energia          = _energia;
    pose             = _pose;
}

CRobot::CRobot(TColor _color, TPosicion _posicion, float _orientacion, float _velocidad_avance, float _velocidad_giro, float _energia, TRobotPose _pose)
{
    if(_posicion.x < (X_MIN + ROBOT_RADIO)) _posicion.x = X_MIN + ROBOT_RADIO;
    if(_posicion.x > (X_MAX - ROBOT_RADIO)) _posicion.x = X_MAX - ROBOT_RADIO;
    if(_posicion.y < (Y_MIN + ROBOT_RADIO)) _posicion.y = Y_MIN + ROBOT_RADIO;
    if(_posicion.y > (Y_MAX - ROBOT_RADIO)) _posicion.y = Y_MAX - ROBOT_RADIO;
    _orientacion = NormalizarAnguloRadianes(_orientacion);
    if(_velocidad_avance < -ROBOT_VELOCIDAD_AVANCE_MAX) _velocidad_avance = -ROBOT_VELOCIDAD_AVANCE_MAX;
    if(_velocidad_avance >  ROBOT_VELOCIDAD_AVANCE_MAX) _velocidad_avance =  ROBOT_VELOCIDAD_AVANCE_MAX;
    if(_velocidad_giro   < -ROBOT_VELOCIDAD_GIRO_MAX)   _velocidad_giro   = -ROBOT_VELOCIDAD_GIRO_MAX;
    if(_velocidad_giro   >  ROBOT_VELOCIDAD_GIRO_MAX)   _velocidad_giro   =  ROBOT_VELOCIDAD_GIRO_MAX;
    _energia = NormalizarEnergia(_energia);
    id               = num_robots++;
    color            = _color;
    posicion         = _posicion;
    orientacion      = _orientacion;
    velocidad_avance = _velocidad_avance;
    velocidad_giro   = _velocidad_giro;
    energia          = _energia;
    pose             = _pose;
}

unsigned int CRobot::NumRobots(void)
{
    return num_robots;
}

unsigned int CRobot::Id(void)
{
    return id;
}

TColor CRobot::Color(void)
{
    return color;
}

float CRobot::PosicionX(void)
{
    return posicion.x;
}

float CRobot::PosicionY(void)
{
    return posicion.y;
}

TPosicion CRobot::Posicion(void)
{
    return posicion;
}

float CRobot::Orientacion(void)
{
    return orientacion;
}

float CRobot::VelocidadAvance(void)
{
    return velocidad_avance;
}

float CRobot::VelocidadGiro(void)
{
    return velocidad_giro;
}

float CRobot::Energia(void)
{
    return energia;
}

CEsfera* CRobot::Esfera(void)
{
    return esfera;
}

bool CRobot::Empujar(void)
{
    return empujar;
}

TRobotPose CRobot::Pose(void)
{
    return pose;
}

void CRobot::Posicion(float posicion_x, float posicion_y)
{
    if(posicion_x < (X_MIN + ROBOT_RADIO)) posicion_x = X_MIN + ROBOT_RADIO;
    if(posicion_x > (X_MAX - ROBOT_RADIO)) posicion_x = X_MAX - ROBOT_RADIO;
    if(posicion_y < (Y_MIN + ROBOT_RADIO)) posicion_y = Y_MIN + ROBOT_RADIO;
    if(posicion_y > (Y_MAX - ROBOT_RADIO)) posicion_y = Y_MAX - ROBOT_RADIO;
    posicion.x = posicion_x;
    posicion.y = posicion_y;
}

void CRobot::Posicion(TPosicion _posicion)
{
    if(_posicion.x < (X_MIN + ROBOT_RADIO)) _posicion.x = X_MIN + ROBOT_RADIO;
    if(_posicion.x > (X_MAX - ROBOT_RADIO)) _posicion.x = X_MAX - ROBOT_RADIO;
    if(_posicion.y < (Y_MIN + ROBOT_RADIO)) _posicion.y = Y_MIN + ROBOT_RADIO;
    if(_posicion.y > (Y_MAX - ROBOT_RADIO)) _posicion.y = Y_MAX - ROBOT_RADIO;
    posicion = _posicion;
}

void CRobot::Orientacion(float _orientacion)
{
    orientacion = NormalizarAnguloRadianes(_orientacion);
}

void CRobot::VelocidadAvance(float _velocidad_avance)
{
    if(_velocidad_avance < -ROBOT_VELOCIDAD_AVANCE_MAX) _velocidad_avance = -ROBOT_VELOCIDAD_AVANCE_MAX;
    if(_velocidad_avance >  ROBOT_VELOCIDAD_AVANCE_MAX) _velocidad_avance =  ROBOT_VELOCIDAD_AVANCE_MAX;
    velocidad_avance = _velocidad_avance;
}

void CRobot::VelocidadGiro(float _velocidad_giro)
{
    if(_velocidad_giro   < -ROBOT_VELOCIDAD_GIRO_MAX)   _velocidad_giro   = -ROBOT_VELOCIDAD_GIRO_MAX;
    if(_velocidad_giro   >  ROBOT_VELOCIDAD_GIRO_MAX)   _velocidad_giro   =  ROBOT_VELOCIDAD_GIRO_MAX;
    velocidad_giro = _velocidad_giro;
}

void CRobot::Pose(TRobotPose _pose)
{
    pose = _pose;
}

void CRobot::ActualizarEnergia(void)
{
    //Completar: -Gasto +Recuperación
    //Ver si invocar en cada uno de los siguientes métodos, o si invocar de forma resumida
}

void CRobot::Parar(void)
{
    VelocidadAvance(0.0);
    VelocidadGiro  (0.0);
    //Establecer nueva energía según gasto energético
    //Establecer vx = vy = 0.0;
    //Poner en cola
}

void CRobot::Coger(CEsfera* _esfera)
{
    //Si manos libres, coger esfera
    //Establecer nueva energía según gasto energético
    //Poner en cola
}

void CRobot::Soltar(void)
{
    //Si manos ocupadas, soltar esfera
    //Establecer nueva energía según gasto energético
    //Poner en cola
}

void CRobot::Almacenar(CCaja* caja)
{

}

void CRobot::Patear(CEsfera* _esfera)
{
    //Establecer nueva energía según gasto energético
    //Poner en cola
}

void CRobot::Empujar(bool _empujar)
{
    empujar = _empujar;
}

void CRobot::Evolucionar(float t)
{
    orientacion += velocidad_giro * t;
    orientacion = NormalizarAnguloRadianes(orientacion);

    posicion.x += velocidad_avance * t * cos(orientacion);
    posicion.y -= velocidad_avance * t * sin(orientacion);

    //Llevar a Escena
    if(posicion.x <= (X_MIN + ROBOT_RADIO))
    {
        posicion.x = X_MIN + ROBOT_RADIO;
        Parar();
    }
    if(posicion.x >= (X_MAX - ROBOT_RADIO))
    {
        posicion.x = X_MAX - ROBOT_RADIO;
        Parar();
    }
    if(posicion.y <= (Y_MIN + ROBOT_RADIO))
    {
        posicion.y = Y_MIN + ROBOT_RADIO;
        Parar();
    }
    if(posicion.y >= (Y_MAX - ROBOT_RADIO))
    {
        posicion.y = Y_MAX - ROBOT_RADIO;
        Parar();
    }
    //Mientras operaciones en cola
    //Actualizar tiempo operación actual
    //Si nueva operación, señalizar a la escena
}

void CRobot::Guardar(FILE* archivo)
{

}

void CRobot::Recuperar(FILE *archivo)
{

}
