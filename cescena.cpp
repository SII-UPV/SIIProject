#include "cescena.h"

CEscena::CEscena()
{
}

unsigned int CEscena::NumEsferas(void)
{
    return esferas.size();
}

unsigned int CEscena::NumCajas(void)
{
    return cajas.size();
}

unsigned int CEscena::NumPersonas(void)
{
    return personas.size();
}

unsigned int CEscena::NumRobots(void)
{
    return robots.size();
}

void CEscena::NuevaEsfera(CEsfera* esfera)
{
    esferas.push_back(esfera);
    esferas_en_suelo.push_back(esfera);
}

void CEscena::NuevaCaja(CCaja* caja)
{
    cajas.push_back(caja);
}

void CEscena::NuevaPersona(CPersona* persona)
{
    personas.push_back(persona);
}

void CEscena::NuevoRobot(CRobot* robot)
{
    robots.push_back(robot);
}

CEsfera* CEscena::Esfera(unsigned int esfera)
{
    return esferas[esfera];
}

CCaja* CEscena::Caja(unsigned int caja)
{
    return cajas[caja];
}

CPersona* CEscena::Persona(unsigned int persona)
{
    return personas[persona];
}

CRobot* CEscena::Robot(unsigned int robot)
{
    return robots[robot];
}

void CEscena::BorrarEsferas(void)
{
    std::vector<CEsfera*>::iterator iesfera;
    for(iesfera = esferas.begin(); iesfera != esferas.end(); iesfera++)
    {
        delete (*iesfera);
    }
    esferas.clear();
}

void CEscena::BorrarCajas(void)
{
    std::vector<CCaja*>::iterator icaja;
    for(icaja = cajas.begin(); icaja != cajas.end(); icaja++)
    {
        delete (*icaja);
    }
    cajas.clear();
}

void CEscena::BorrarPersonas(void)
{
    std::vector<CPersona*>::iterator ipersona;
    for(ipersona = personas.begin(); ipersona != personas.end(); ipersona++)
    {
        delete (*ipersona);
    }
    personas.clear();
}

void CEscena::BorrarRobots(void)
{
    std::vector<CRobot*>::iterator irobot;
    for(irobot = robots.begin(); irobot != robots.end(); irobot++)
    {
        delete (*irobot);
    }
    robots.clear();
}

void CEscena::ConectarVista2D(CVista2D* vista2d)
{
    vistas2d.push_back(vista2d);
}

//void CEscena::ConectarVista3D(CVista3D* vista3d)
//{
//    vistas3d.push_back(vista3d);
//}

void CEscena::DesconectarVista2D(CVista2D* vista2d)
{
    vistas2d.remove(vista2d);
}

//void CEscena::DesconectarVista3D(CVista3D* vista3d)
//{
//    vistas3d.remove(vista3d);
//}

void CEscena::CogerEsfera(CEsfera* esfera, CPersona* persona)
{

}

void CEscena::CogerEsfera(CEsfera* esfera, CRobot* robot)
{

}

void CEscena::SoltarEsfera(CPersona* persona)
{

}

void CEscena::SoltarEsfera(CRobot* robot)
{

}

void CEscena::GuardarEsfera(CPersona* persona, CCaja* caja)
{

}

void CEscena::GuardarEsfera(CRobot* robot, CCaja* caja)
{

}

void CEscena::PatearEsfera(CEsfera* esfera, CPersona* persona, float intensidad)
{

}

void CEscena::PatearEsfera(CEsfera* esfera, CRobot* robot, float intensidad)
{

}

void CEscena::EmpujarCaja(CCaja* caja, CPersona* persona, float distancia)
{

}

void CEscena::EmpujarCaja(CCaja* caja, CRobot* robot, float distancia)
{

}

void CEscena::Colision(CEsfera *chocante, CEsfera *receptor)
{
    float v_colision = qSqrt(chocante->VelocidadX()*chocante->VelocidadX()+chocante->VelocidadY()*chocante->VelocidadY());
    float angulo_colision = qAcos((ESFERA_RADIO * 2) / v_colision);

    //SUPONIENDO QUE LAS BOLAS TIENEN LA MISMA MASA, MISMO RADIO Y QUE EL CHOQUE ES PERFECTAMENTE ELASTICO
    float v_final_chocante = v_colision * qSin(angulo_colision);
    chocante->Velocidad(v_final_chocante * qCos(90 - angulo_colision), v_final_chocante * qSin(90 - angulo_colision));

    float v_final_receptor = v_colision * qCos(angulo_colision);
    receptor->Velocidad(v_final_receptor * qCos(angulo_colision), v_final_receptor * qSin(angulo_colision));
}

void CEscena::ControlColisiones(void)
{
    std::vector<CEsfera*>::iterator iesfera1;
    for(iesfera1 = esferas.begin(); iesfera1 != esferas.end(); iesfera1++)
    {
       std::vector<CEsfera*>::iterator iesfera2;
       for(iesfera2 = iesfera1; iesfera2 != esferas.end(); iesfera2++)
       {
           if((*iesfera1) != (*iesfera2))
           {
              float dx = (*iesfera1)->PosicionX() - (*iesfera2)->PosicionX();
              float dy = (*iesfera1)->PosicionY() - (*iesfera2)->PosicionY();

              if( qSqrt(dx*dx + dy*dy) <= (ESFERA_RADIO * 2))
              {
                  if(qSqrt((*iesfera1)->VelocidadX() * (*iesfera1)->VelocidadX()+
                           (*iesfera1)->VelocidadY() * (*iesfera1)->VelocidadY()) >
                     qSqrt((*iesfera2)->VelocidadX() * (*iesfera2)->VelocidadX()+
                           (*iesfera2)->VelocidadY() * (*iesfera2)->VelocidadY()))
                  {
                     Colision(*iesfera1, *iesfera2);
                  }
                  else
                  {
                      if(qSqrt((*iesfera1)->VelocidadX() * (*iesfera1)->VelocidadX()+
                               (*iesfera1)->VelocidadY() * (*iesfera1)->VelocidadY()) <
                         qSqrt((*iesfera2)->VelocidadX() * (*iesfera2)->VelocidadX()+
                               (*iesfera2)->VelocidadY() * (*iesfera2)->VelocidadY()))
                      {
                      Colision(*iesfera2, *iesfera1);
                      }
                      else
                      {/*si v1==v2*/
                         (*iesfera1)->Velocidad(-(*iesfera1)->VelocidadX(), -(*iesfera1)->VelocidadY());
                         (*iesfera2)->Velocidad(-(*iesfera2)->VelocidadX(), -(*iesfera2)->VelocidadY());
                      }
                  }
              }
           }
       }
    }
}

void CEscena::Evolucionar(float t)
{
    std::vector<CEsfera*>::iterator iesfera;
    for(iesfera = esferas.begin(); iesfera != esferas.end(); iesfera++)
    {
        (*iesfera)->Evolucionar(t);
    }

    ControlColisiones();

    std::vector<CCaja*>::iterator icaja;
    for(icaja = cajas.begin(); icaja != cajas.end(); icaja++)
    {
        (*icaja)->Evolucionar(t);
    }

    std::vector<CPersona*>::iterator ipersona;
    for(ipersona = personas.begin(); ipersona != personas.end(); ipersona++)
    {
        (*ipersona)->Evolucionar(t);
    }

    std::vector<CRobot*>  ::iterator irobot;
    for(irobot = robots.begin(); irobot != robots.end(); irobot++)
    {
        (*irobot)->Evolucionar(t);
    }

    Mostrar();
}

void CEscena::Mostrar(void)
{
    std::list<CVista2D*>::iterator ivista2d;
    for(ivista2d = vistas2d.begin(); ivista2d != vistas2d.end(); ivista2d++)
    {
        (*ivista2d)->Actualizar();
        (*ivista2d)->Mostrar();
    }
}

void CEscena::Guardar(FILE* archivo)
{

}

void CEscena::Recuperar(FILE *archivo)
{

}
