#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H

enum TColor{Rojo, Verde, Azul};

typedef struct{float x, y;} TPosicion;
typedef struct{float x, y;} TVelocidad;
typedef struct{float x, y;} TAceleracion;

//Esfera
#define ESFERA_RADIO                 0.05
#define ESFERA_MASA                  0.5
#define ESFERA_COLOR_DEFECTO         Rojo
#define ESFERA_POSICION_X_INICIAL    0.0
#define ESFERA_POSICION_Y_INICIAL    0.0
#define ESFERA_VELOCIDAD_X_INICIAL   0.0
#define ESFERA_VELOCIDAD_Y_INICIAL   0.0
#define ESFERA_ACELERACION_X_INICIAL 0.0
#define ESFERA_ACELERACION_Y_INICIAL 0.0
#define ESFERA_VELOCIDAD_MAX         9.0
#define ESFERA_ACELERACION_MAX       9.0

//Caja
#define CAJA_RADIO              0.4
#define CAJA_ALTURA             0.5
#define CAJA_MASA               1.5
#define CAJA_COLOR_DEFECTO      Rojo
#define CAJA_POSICION_X_INICIAL 0.0
#define CAJA_POSICION_Y_INICIAL 0.0
#define CAJA_CAPACIDAD_DEFECTO  25

//Persona
#define PERSONA_RADIO                    0.3
#define PERSONA_ANGULO                   10.0 //Grados
#define PERSONA_ALTURA                   1.75
#define PERSONA_ALCANCE                  0.75
#define PERSONA_COLOR_DEFECTO            Rojo
#define PERSONA_POSICION_X_INICIAL       0.0
#define PERSONA_POSICION_Y_INICIAL       0.0
#define PERSONA_ORIENTACION_INICIAL      0.0 //Radianes
#define PERSONA_VELOCIDAD_AVANCE_INICIAL 0.0
#define PERSONA_VELOCIDAD_GIRO_INICIAL   0.0 //Radianes/s
#define PERSONA_VELOCIDAD_AVANCE_MAX     3.0
#define PERSONA_VELOCIDAD_GIRO_MAX       6.0
#define PERSONA_ENERGIA_INICIAL          1.0
#define PERSONA_POSE_INICIAL             Parada

//Robot
#define ROBOT_RADIO                    0.5
#define ROBOT_ANGULO                   10.0 //Grados
#define ROBOT_ALTURA                   1.0
#define ROBOT_ALCANCE                  0.75
#define ROBOT_COLOR_DEFECTO            Rojo
#define ROBOT_POSICION_X_INICIAL       0.0
#define ROBOT_POSICION_Y_INICIAL       0.0
#define ROBOT_ORIENTACION_INICIAL      0.0 //Radianes
#define ROBOT_VELOCIDAD_AVANCE_INICIAL 0.0
#define ROBOT_VELOCIDAD_GIRO_INICIAL   0.0
#define ROBOT_VELOCIDAD_AVANCE_MAX     2.0
#define ROBOT_VELOCIDAD_GIRO_MAX       5.0
#define ROBOT_ENERGIA_INICIAL          1.0
#define ROBOT_POSE_INICIAL             Parado

//Escena
#define NUM_ESFERAS_INICIAL  90 //3x30
#define NUM_CAJAS_INICIAL    6  //3x2
#define NUM_PERSONAS_INICIAL 3  //3x1
#define NUM_ROBOTS_INICIAL   1  //1x1

//Escenario
#define X_MIN -5.0
#define X_MAX  5.0
#define Y_MIN -5.0
#define Y_MAX  5.0

//Rozamiento
#define CR_ESFERA_SUELO 0.1
#define CR_CAJA_SUELO   0.9

//Choque
#define K_ESFERA_ESFERA  0.95
#define K_ESFERA_PARED   0.9
#define K_ESFERA_CAJA    0.8
#define K_ESFERA_PERSONA 0.6
#define K_ESFERA_ROBOT   0.7

float RadianesAGrados(float _angulo);
float GradosARadianes(float _angulo);
float NormalizarAnguloGrados  (float _angulo);
float NormalizarAnguloRadianes(float _angulo);

#define TCP_PORT 12164
#define UDP_PORT 12164

#endif // VIDEOJUEGO_H
