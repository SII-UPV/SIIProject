#ifndef CVISTA3D_H
#define CVISTA3D_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

#include <QThread>

#include <osg/Version>
#include <osg/Node>
#include <osg/Group>
#include <osg/PositionAttitudeTransform>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>
#include <osgGA/TrackballManipulator>
#include <osg/ShapeDrawable>
#include <osg/Material>
#include <osg/animationpath>
#include <osg/matrixtransform>
#include <osg/LightSource>

#include "videojuego.h"
#include "ccomunicacioncliente.h"
#include "cescena.h"

#define AnchuraBaldosaX 0.5
#define AnchuraBaldosaY 0.5
#define AlturaBaldosa   0.05
#define NumBaldosasXMin (X_MIN/AnchuraBaldosaX)
#define NumBaldosasXMax (X_MAX/AnchuraBaldosaX)
#define NumBaldosasYMin (Y_MIN/AnchuraBaldosaY)
#define NumBaldosasYMax (Y_MAX/AnchuraBaldosaY)
#define RobotZ AlturaBaldosa+ROBOT_ALTURA/2

class CEsfera3D
{
public:
    unsigned int id;
    float radio,x,y,z;
    TColor color;
};

class CCaja3D
{
public:
    unsigned int id;
    float radio,altura,x,y,z;
    TColor color;
};

class CPersona3D
{
public:
    unsigned int id;
    float radio,altura,x,y,z;
    TColor color;
};

class CRobot3D
{
public:
    unsigned int id;
    float radio,altura,x,y,z;
    TColor color;
};

class CEscena;

class CVista3D : public QThread
{
    CComunicacionCliente *comunicacion_cliente;
    CEscena *escena;

    osg::ref_ptr<osg::Group> escena3d;
    std::vector<CEsfera3D>  esferas3d;
    std::vector<CCaja3D>    cajas3d;
    std::vector<CPersona3D> personas3d;
    std::vector<CRobot3D>   robots3d;

    std::vector<osg::ref_ptr<osg::PositionAttitudeTransform> > nodos_esferas;
    std::vector<osg::ref_ptr<osg::PositionAttitudeTransform> > nodos_cajas;
    std::vector<osg::ref_ptr<osg::PositionAttitudeTransform> > nodos_personas;
    std::vector<osg::ref_ptr<osg::PositionAttitudeTransform> > nodos_robots;

    osgViewer::Viewer vista;
    osg::ref_ptr<osg::Node> Node_BaldosaBlanca,
                            Node_BaldosaGris,
                            Node_BaldosaNegra,
                            Node_PersonaFormaRoja,
                            Node_PersonaFormaVerde,
                            Node_PersonaFormaAzul,
                            Node_RobotRojo,
                            Node_RobotVerde,
                            Node_RobotAzul,
                            Node_CajaAzul,
                            Node_CajaRoja,
                            Node_CajaVerde;
                           // light0,
                            //light1;
    osg::ref_ptr<osg::StateSet> Node_BaldosaBlanca_SS,
                                Node_BaldosaGris_SS,
                                Node_BaldosaNegra_SS,
                                Node_EsferaRoja_SS,
                                Node_EsferaVerde_SS,
                                Node_EsferaAzul_SS,
                                Node_CajaRoja_SS,
                                Node_CajaVerde_SS,
                                Node_CajaAzul_SS,
                                Node_RobotRojo_SS,
                                Node_RobotVerde_SS,
                                Node_RobotAzul_SS,
                                Node_PersonaFormaRoja_SS,
                                Node_PersonaFormaVerde_SS,
                                Node_PersonaFormaAzul_SS;

    osg::ref_ptr<osg::Material> Node_BaldosaBlanca_Material,
                                Node_BaldosaGris_Material,
                                Node_BaldosaNegra_Material,
                                Node_EsferaRoja_Material,
                                Node_EsferaVerde_Material,
                                Node_EsferaAzul_Material,
                                Node_CajaRoja_Material,
                                Node_CajaVerde_Material,
                                Node_CajaAzul_Material,
                                Node_RobotRojo_Material,
                                Node_RobotVerde_Material,
                                Node_RobotAzul_Material,
                                Node_PersonaFormaRoja_Material,
                                Node_PersonaFormaVerde_Material,
                                Node_PersonaFormaAzul_Material;
    osg::ref_ptr<osg::Sphere> Esfera;
    osg::ref_ptr<osg::ShapeDrawable> ShapeDrawable_Esfera;
    osg::ref_ptr<osg::Geode> Geode_EsferaRoja,
                             Geode_EsferaVerde,
                             Geode_EsferaAzul;
    //osg::ref_ptr<osg::LightSource> createLightSource;
public:
    CVista3D();
    ~CVista3D();

    void Escena(CEscena* _escena);
    CEscena* Escena(void);

    void NuevaEsfera (TColor color, TPosicion posicion);
    void NuevaCaja   (TColor color, TPosicion posicion);
    void NuevaPersona(TColor color, TPosicion posicion, float orientacion);
    void NuevoRobot  (TColor color, TPosicion posicion, float orientacion);

    void PosicionEsfera (unsigned int esfera,  TPosicion posicion);
    void PosicionCaja   (unsigned int caja,    TPosicion posicion);
    void PosicionPersona(unsigned int persona, TPosicion posicion);
    void PosicionRobot  (unsigned int robot,   TPosicion posicion);

    void OrientacionPersona(unsigned int persona, float orientacion);
    void OrientacionRobot  (unsigned int robot,   float orientacion);

    void BorrarEsferas (void);
    void BorrarCajas   (void);
    void BorrarPersonas(void);
    void BorrarRobots  (void);

    void Actualizar(void);
    void Mostrar(void);

    void Guardar(FILE* archivo);
    void Recuperar(FILE *archivo);

    osg::Node* createLightSource( unsigned int num, const osg::Vec3& trans, const osg::Vec4& color );//Función luz

    //void run() Q_DECL_OVERRIDE;
};

#endif // CVISTA3D_H
