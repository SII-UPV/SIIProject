#ifndef CESCENA_H
#define CESCENA_H

#include <stdio.h>
#include <list>
#include <vector>
#include <qmath.h>

#include "cesfera.h"
#include "ccaja.h"
#include "cpersona.h"
#include "crobot.h"
#include "cvista2d.h"
//#include "cvista3d.h"

class CVista2D;
//class CVista3D;

class CEscena
{
    std::vector<CEsfera*>  esferas;
    std::vector<CCaja*>    cajas;
    std::vector<CPersona*> personas;
    std::vector<CRobot*>   robots;

    std::list<CEsfera*> esferas_en_suelo;
    std::list<CVista2D*> vistas2d;
//    std::list<CVista3D*> vistas3d;
public:
    CEscena();

    unsigned int NumEsferas (void);
    unsigned int NumCajas   (void);
    unsigned int NumPersonas(void);
    unsigned int NumRobots  (void);

    void NuevaEsfera (CEsfera*  esfera);
    void NuevaCaja   (CCaja*    caja);
    void NuevaPersona(CPersona* persona);
    void NuevoRobot  (CRobot*   robot);
    CEsfera*  Esfera (unsigned int esfera);
    CCaja*    Caja   (unsigned int caja);
    CPersona* Persona(unsigned int persona);
    CRobot*   Robot  (unsigned int robot);

    void BorrarEsferas (void);
    void BorrarCajas   (void);
    void BorrarPersonas(void);
    void BorrarRobots  (void);

    void ConectarVista2D(CVista2D* vista2d);
//    void ConectarVista3D(CVista3D* vista3d);
    void DesconectarVista2D(CVista2D* vista2d);
//    void DesconectarVista3D(CVista3D* vista3d);
    void Mostrar(void);
    void Evolucionar(float t);

    void Guardar(FILE* archivo);
    void Recuperar(FILE *archivo);
protected:
    void CogerEsfera  (CEsfera* esfera, CPersona* persona);
    void CogerEsfera  (CEsfera* esfera, CRobot*   robot);
    void SoltarEsfera (CPersona* persona);
    void SoltarEsfera (CRobot*   robot);
    void GuardarEsfera(CPersona* persona, CCaja* caja);
    void GuardarEsfera(CRobot*   robot,   CCaja* caja);
    void PatearEsfera (CEsfera* esfera, CPersona* persona, float intensidad);
    void PatearEsfera (CEsfera* esfera, CRobot*   robot,   float intensidad);
    void EmpujarCaja  (CCaja* caja, CPersona* persona, float distancia);
    void EmpujarCaja  (CCaja* caja, CRobot*   robot,   float distancia);
/*
    DetectarColision()
    Colisionar()
    Impulsar()
*/
    void Colision(CEsfera *chocante, CEsfera *receptor);
    void ControlColisiones(void);
};

#endif // CESCENA_H
