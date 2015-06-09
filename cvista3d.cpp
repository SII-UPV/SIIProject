#include "cvista3d.h"

<<<<<<< HEAD
osg::Node* CVista3D::createLightSource( unsigned int num, const osg::Vec3& trans, const osg::Vec4& color )//Función luz
{
 osg::ref_ptr<osg::Light> light = new osg::Light;
 light->setLightNum( num );
 light->setDiffuse( color );
 light->setPosition( osg::Vec4(0.0f, 0.0f, 0.0f, 1.0f) );
 osg::ref_ptr<osg::LightSource> lightSource = new
 osg::LightSource;
 lightSource->setLight( light );
 osg::ref_ptr<osg::MatrixTransform> sourceTrans =
  new osg::MatrixTransform;
  sourceTrans->setMatrix( osg::Matrix::translate(trans) );
  sourceTrans->addChild( lightSource.get() );
  return sourceTrans.release();
 }//Fin funcion fuente de  luz


CVista3D::CVista3D()
{



=======
CVista3D::CVista3D()
{
>>>>>>> origin/master
    comunicacion_cliente = new CComunicacionCliente;
    escena = new CEscena;
    escena3d = new osg::Group();

<<<<<<< HEAD
    //Iluminación
    osg::Node* light0 = createLightSource(
     0, osg::Vec3(0.0f,0.0f,5.0f), osg::Vec4(
     1.0f,1.0f,0.0f,1.0f) );
    osg::Node* light1 = createLightSource(
     1, osg::Vec3(5.0f,-5.0f,5.0f), osg::Vec4(0.0f,1.0f,1.0f,1.0f)
    );

    escena3d->getOrCreateStateSet()->setMode( GL_LIGHT0,
     osg::StateAttribute::ON );
    escena3d->getOrCreateStateSet()->setMode( GL_LIGHT1,
     osg::StateAttribute::ON );
    escena3d->addChild( light0 );
    escena3d->addChild( light1 );
    //Fin Iluminación


=======
>>>>>>> origin/master
    //Modelos Baldosas
    Node_BaldosaBlanca = osgDB::readNodeFile( "sii-baldosa.3ds" );
    Node_BaldosaGris   = osgDB::readNodeFile( "sii-baldosa.3ds" );
    Node_BaldosaNegra  = osgDB::readNodeFile( "sii-baldosa.3ds" );

    Node_BaldosaBlanca_SS = Node_BaldosaBlanca->getOrCreateStateSet();
    Node_BaldosaGris_SS   = Node_BaldosaGris  ->getOrCreateStateSet();
    Node_BaldosaNegra_SS  = Node_BaldosaNegra ->getOrCreateStateSet();

    Node_BaldosaBlanca_Material = new osg::Material;
    Node_BaldosaGris_Material   = new osg::Material;
    Node_BaldosaNegra_Material  = new osg::Material;

    Node_BaldosaBlanca_Material->setDiffuse(osg::Material::FRONT,osg::Vec4(1.0f ,1.0f ,1.0f ,1.0f));
    Node_BaldosaGris_Material  ->setDiffuse(osg::Material::FRONT,osg::Vec4(0.75f,0.75f,0.75f,1.0f));
    Node_BaldosaNegra_Material ->setDiffuse(osg::Material::FRONT,osg::Vec4(0.0f ,0.0f ,0.0f ,1.0f));

    Node_BaldosaBlanca_SS->setAttribute(Node_BaldosaBlanca_Material.get());
    Node_BaldosaGris_SS  ->setAttribute(Node_BaldosaGris_Material  .get());
    Node_BaldosaNegra_SS ->setAttribute(Node_BaldosaNegra_Material .get());

    //Modelos Esferas
    Esfera               = new osg::Sphere(osg::Vec3(0,0,0), 1.0);
    ShapeDrawable_Esfera = new osg::ShapeDrawable(Esfera);

    Geode_EsferaRoja  = new osg::Geode();
    Geode_EsferaVerde = new osg::Geode();
    Geode_EsferaAzul  = new osg::Geode();

    Node_EsferaRoja_SS  = Geode_EsferaRoja ->getOrCreateStateSet();
    Node_EsferaVerde_SS = Geode_EsferaVerde->getOrCreateStateSet();
    Node_EsferaAzul_SS  = Geode_EsferaAzul ->getOrCreateStateSet();

    Node_EsferaRoja_Material  = new osg::Material;
    Node_EsferaVerde_Material = new osg::Material;
    Node_EsferaAzul_Material  = new osg::Material;

    Geode_EsferaRoja ->addDrawable(ShapeDrawable_Esfera);
    Geode_EsferaVerde->addDrawable(ShapeDrawable_Esfera);
    Geode_EsferaAzul ->addDrawable(ShapeDrawable_Esfera);

    Node_EsferaRoja_Material ->setDiffuse(osg::Material::FRONT,osg::Vec4(1.0f,0.0f,0.0f,1.0f));
    Node_EsferaVerde_Material->setDiffuse(osg::Material::FRONT,osg::Vec4(0.0f,1.0f,0.0f,1.0f));
    Node_EsferaAzul_Material ->setDiffuse(osg::Material::FRONT,osg::Vec4(0.0f,0.0f,1.0f,1.0f));

    Node_EsferaRoja_SS ->setAttribute(Node_EsferaRoja_Material .get());
    Node_EsferaVerde_SS->setAttribute(Node_EsferaVerde_Material.get());
    Node_EsferaAzul_SS ->setAttribute(Node_EsferaAzul_Material .get());

<<<<<<< HEAD
    //Modelo Caja
    Node_CajaRoja  = osgDB::readNodeFile( "chest.stl" );
    Node_CajaVerde = osgDB::readNodeFile( "chest.stl" );
    Node_CajaAzul  = osgDB::readNodeFile( "chest.stl" );

    Node_CajaRoja_SS  = Node_CajaRoja ->getOrCreateStateSet();
    Node_CajaVerde_SS = Node_CajaVerde->getOrCreateStateSet();
    Node_CajaAzul_SS  = Node_CajaAzul ->getOrCreateStateSet();
=======
    //Modelos Cajas
    Caja               = new osg::Cylinder(osg::Vec3(0,0,0), 0.5,0.5);
    ShapeDrawable_Caja = new osg::ShapeDrawable(Caja);
    Geode_CajaRoja     = new osg::Geode();
    Geode_CajaVerde    = new osg::Geode();
    Geode_CajaAzul     = new osg::Geode();

    Node_CajaRoja_SS  = Geode_CajaRoja ->getOrCreateStateSet();
    Node_CajaVerde_SS = Geode_CajaVerde->getOrCreateStateSet();
    Node_CajaAzul_SS  = Geode_CajaAzul ->getOrCreateStateSet();
>>>>>>> origin/master

    Node_CajaRoja_Material  = new osg::Material;
    Node_CajaVerde_Material = new osg::Material;
    Node_CajaAzul_Material  = new osg::Material;

<<<<<<< HEAD
=======
    Geode_CajaRoja ->addDrawable(ShapeDrawable_Caja);
    Geode_CajaVerde->addDrawable(ShapeDrawable_Caja);
    Geode_CajaAzul ->addDrawable(ShapeDrawable_Caja);

>>>>>>> origin/master
    Node_CajaRoja_Material ->setDiffuse(osg::Material::FRONT,osg::Vec4(1.0f,0.0f,0.0f,1.0f));
    Node_CajaVerde_Material->setDiffuse(osg::Material::FRONT,osg::Vec4(0.0f,1.0f,0.0f,1.0f));
    Node_CajaAzul_Material ->setDiffuse(osg::Material::FRONT,osg::Vec4(0.0f,0.0f,1.0f,1.0f));

    Node_CajaRoja_SS ->setAttribute(Node_CajaRoja_Material .get());
    Node_CajaVerde_SS->setAttribute(Node_CajaVerde_Material.get());
    Node_CajaAzul_SS ->setAttribute(Node_CajaAzul_Material .get());

<<<<<<< HEAD
=======
    //Modelos Personas
    Persona               = new osg::Cylinder(osg::Vec3(0,0,0), 0.25,2.0);
    ShapeDrawable_Persona = new osg::ShapeDrawable(Persona);

    Geode_PersonaRoja  = new osg::Geode();
    Geode_PersonaVerde = new osg::Geode();
    Geode_PersonaAzul  = new osg::Geode();

    Geode_PersonaRoja ->addDrawable(ShapeDrawable_Persona);
    Geode_PersonaVerde->addDrawable(ShapeDrawable_Persona);
    Geode_PersonaAzul ->addDrawable(ShapeDrawable_Persona);

    Node_PersonaRoja_SS  = Geode_PersonaRoja ->getOrCreateStateSet();
    Node_PersonaVerde_SS = Geode_PersonaVerde->getOrCreateStateSet();
    Node_PersonaAzul_SS  = Geode_PersonaAzul ->getOrCreateStateSet();

    Node_PersonaRoja_Material  = new osg::Material;
    Node_PersonaVerde_Material = new osg::Material;
    Node_PersonaAzul_Material  = new osg::Material;

    Node_PersonaRoja_Material ->setDiffuse(osg::Material::FRONT,osg::Vec4(1.0f,0.0f,0.0f,1.0f));
    Node_PersonaVerde_Material->setDiffuse(osg::Material::FRONT,osg::Vec4(0.0f,1.0f,0.0f,1.0f));
    Node_PersonaAzul_Material ->setDiffuse(osg::Material::FRONT,osg::Vec4(0.0f,0.0f,1.0f,1.0f));

    Node_PersonaRoja_SS ->setAttribute(Node_PersonaRoja_Material .get());
    Node_PersonaVerde_SS->setAttribute(Node_PersonaVerde_Material.get());
    Node_PersonaAzul_SS ->setAttribute(Node_PersonaAzul_Material .get());

>>>>>>> origin/master
    //Modelo Persona Forma
    Node_PersonaFormaRoja  = osgDB::readNodeFile( "sii-persona.stl" );
    Node_PersonaFormaVerde = osgDB::readNodeFile( "sii-persona.stl" );
    Node_PersonaFormaAzul  = osgDB::readNodeFile( "sii-persona.stl" );

    Node_PersonaFormaRoja_SS  = Node_PersonaFormaRoja ->getOrCreateStateSet();
    Node_PersonaFormaVerde_SS = Node_PersonaFormaVerde->getOrCreateStateSet();
    Node_PersonaFormaAzul_SS  = Node_PersonaFormaAzul ->getOrCreateStateSet();

    Node_PersonaFormaRoja_Material  = new osg::Material;
    Node_PersonaFormaVerde_Material = new osg::Material;
    Node_PersonaFormaAzul_Material  = new osg::Material;

    Node_PersonaFormaRoja_Material ->setDiffuse(osg::Material::FRONT,osg::Vec4(1.0f,0.0f,0.0f,1.0f));
    Node_PersonaFormaVerde_Material->setDiffuse(osg::Material::FRONT,osg::Vec4(0.0f,1.0f,0.0f,1.0f));
    Node_PersonaFormaAzul_Material ->setDiffuse(osg::Material::FRONT,osg::Vec4(0.0f,0.0f,1.0f,1.0f));

    Node_PersonaFormaRoja_SS ->setAttribute(Node_PersonaFormaRoja_Material .get());
    Node_PersonaFormaVerde_SS->setAttribute(Node_PersonaFormaVerde_Material.get());
    Node_PersonaFormaAzul_SS ->setAttribute(Node_PersonaFormaAzul_Material .get());

<<<<<<< HEAD
    //Modelo Robot
    Node_RobotRojo  = osgDB::readNodeFile( "walle.stl" );
    Node_RobotVerde = osgDB::readNodeFile( "walle.stl" );
    Node_RobotAzul  = osgDB::readNodeFile( "walle.stl" );

    Node_RobotRojo_SS  = Node_RobotRojo ->getOrCreateStateSet();
    Node_RobotVerde_SS = Node_RobotVerde->getOrCreateStateSet();
    Node_RobotAzul_SS  = Node_RobotAzul ->getOrCreateStateSet();

    Node_RobotRojo_Material  = new osg::Material;
    Node_RobotVerde_Material = new osg::Material;
    Node_RobotAzul_Material  = new osg::Material;

    Node_RobotRojo_Material ->setDiffuse(osg::Material::FRONT,osg::Vec4(1.0f ,0.0f ,0.0f ,1.0f));
    Node_RobotVerde_Material->setDiffuse(osg::Material::FRONT,osg::Vec4(0.0f ,1.0f ,0.0f ,1.0f));
    Node_RobotAzul_Material ->setDiffuse(osg::Material::FRONT,osg::Vec4(0.0f ,0.0f ,1.0f ,1.0f));

    Node_RobotRojo_SS ->setAttribute(Node_RobotRojo_Material .get());
    Node_RobotVerde_SS->setAttribute(Node_RobotVerde_Material.get());
    Node_RobotAzul_SS ->setAttribute(Node_RobotAzul_Material .get());

=======
>>>>>>> origin/master
    //Objetos Baldosas
    for(int i = NumBaldosasXMin; i <= NumBaldosasXMax; i++)
    {
        for(int j = NumBaldosasYMin; j <= NumBaldosasYMax; j++)
        {
        osg::ref_ptr<osg::PositionAttitudeTransform> trasformacion = new osg::PositionAttitudeTransform();
        osg::Vec3 posicion(i*0.5,j*0.5,0);
        trasformacion->setPosition(posicion);
        if((i==-100) && (j==-100))
<<<<<<< HEAD
            trasformacion->addChild(Node_BaldosaGris);
        else
            if((i+j)%2)
                trasformacion->addChild(Node_BaldosaNegra);
=======
            trasformacion->addChild(Node_BaldosaNegra);
        else
            if((i+j)%2)
                trasformacion->addChild(Node_BaldosaGris);
>>>>>>> origin/master
            else
                trasformacion->addChild(Node_BaldosaBlanca);
        escena3d->addChild(trasformacion);
        }
    }

<<<<<<< HEAD

=======
>>>>>>> origin/master
    //Vista
    vista.setSceneData( escena3d );
    vista.setCameraManipulator(new osgGA::TrackballManipulator);
    vista.setUpViewInWindow(0, 0, 500, 500);
    vista.realize();
}

CVista3D::~CVista3D()
{
    if(escena)
<<<<<<< HEAD
        escena->DesconectarVista3D(this);

=======
    {
        escena->DesconectarVista3D(this);
    }
>>>>>>> origin/master
    delete comunicacion_cliente;
}

void CVista3D::Escena(CEscena* _escena)
{
    if(escena)
<<<<<<< HEAD
        escena->DesconectarVista3D(this);
=======
    {
        escena->DesconectarVista3D(this);
    }
>>>>>>> origin/master

    esferas3d .clear();
    cajas3d   .clear();
    personas3d.clear();
    robots3d  .clear();

<<<<<<< HEAD
    nodos_esferas .clear();
    nodos_cajas   .clear();
    nodos_personas.clear();
    nodos_robots  .clear();

    escena=_escena;

    for(unsigned int esfera = 0; esfera < escena->NumEsferas(); esfera++)
        NuevaEsfera(escena->Esfera(esfera)->Color(), escena->Esfera(esfera)->Posicion());

    for(unsigned int caja = 0; caja < escena->NumCajas(); caja++)
        NuevaCaja(escena->Caja(caja)->Color(), escena->Caja(caja)->Posicion());

    for(unsigned int persona = 0; persona < escena->NumPersonas(); persona++)
        NuevaPersona(escena->Persona(persona)->Color(), escena->Persona(persona)->Posicion(), escena->Persona(persona)->Orientacion());

    for(unsigned int robot = 0; robot < escena->NumRobots(); robot++)
        NuevoRobot(escena->Robot(robot)->Color(), escena->Robot(robot)->Posicion(), escena->Robot(robot)->Orientacion());

    escena->ConectarVista3D(this);
=======
    if(escena = _escena)
    {
        //Objetos Esferas
        for(unsigned int esfera = 0; esfera < escena->NumEsferas(); esfera++)
        {
            CEsfera3D* esfera3d = new CEsfera3D;
            esfera3d->id    = escena->Esfera(esfera)->Id();
            esfera3d->radio = ESFERA_RADIO;
            esfera3d->x     = escena->Esfera(esfera)->PosicionX();
            esfera3d->y     = escena->Esfera(esfera)->PosicionY();
            esfera3d->z     = AlturaBaldosa + esfera3d->radio;
            esfera3d->color = escena->Esfera(esfera)->Color();
            esferas3d.push_back(*esfera3d);

            osg::ref_ptr<osg::PositionAttitudeTransform> trasformacion = new osg::PositionAttitudeTransform();
            osg::Vec3 posicion(esfera3d->x, esfera3d->y, esfera3d->z);
            trasformacion->setPosition(posicion);
            trasformacion->setScale(osg::Vec3(esfera3d->radio, esfera3d->radio, esfera3d->radio));
            switch(esfera3d->color)
            {
            case Rojo:
                trasformacion->addChild(Geode_EsferaRoja);
                break;
            case Verde:
                trasformacion->addChild(Geode_EsferaVerde);
                break;
            case Azul:
                trasformacion->addChild(Geode_EsferaAzul);
                break;
            }
            escena3d->addChild(trasformacion);
        }

        //Objetos Cajas
        for(unsigned int caja = 0; caja < escena->NumCajas(); caja++)
        {
            CCaja3D* caja3d = new CCaja3D;
            caja3d->id     = escena->Caja(caja)->Id();
            caja3d->radio  = CAJA_RADIO;
            caja3d->altura = CAJA_ALTURA;
            caja3d->x      = escena->Caja(caja)->PosicionX();
            caja3d->y      = escena->Caja(caja)->PosicionY();
            caja3d->z      = AlturaBaldosa + caja3d->altura / 2;
            caja3d->color  = escena->Caja(caja)->Color();
            cajas3d.push_back(*caja3d);

            osg::ref_ptr<osg::PositionAttitudeTransform> trasformacion = new osg::PositionAttitudeTransform();
            osg::Vec3 posicion(caja3d->x, caja3d->y, caja3d->z);
            trasformacion->setPosition(posicion);
            switch(caja3d->color)
            {
            case Rojo:
                trasformacion->addChild(Geode_CajaRoja);
                break;
            case Verde:
                trasformacion->addChild(Geode_CajaVerde);
                break;
            case Azul:
                trasformacion->addChild(Geode_CajaAzul);
                break;
            }
            escena3d->addChild(trasformacion);
        }

        //Objetos Personas
        for(unsigned int persona = 0; persona < escena->NumPersonas() ; persona++)
        {
            CPersona3D* persona3d = new CPersona3D;
            persona3d->id     = escena->Persona(persona)->Id();
            persona3d->radio  = PERSONA_RADIO;
            persona3d->altura = PERSONA_ALTURA;
            persona3d->x      = escena->Persona(persona)->PosicionX();
            persona3d->y      = escena->Persona(persona)->PosicionY();
            persona3d->z      = AlturaBaldosa + persona3d->altura / 2;
            persona3d->color  = escena->Persona(persona)->Color();
            personas3d.push_back(*persona3d);

            osg::ref_ptr<osg::PositionAttitudeTransform> trasformacion = new osg::PositionAttitudeTransform();
            osg::Vec3 posicion(persona3d->x, persona3d->y, persona3d->z);
            trasformacion->setPosition(posicion);
            switch(persona3d->color)
            {
            case Rojo:
                trasformacion->addChild(Geode_PersonaRoja);
                break;
            case Verde:
                trasformacion->addChild(Geode_PersonaVerde);
                break;
            case Azul:
                trasformacion->addChild(Geode_PersonaAzul);
                break;
            }
            escena3d->addChild(trasformacion);
        }

        for(unsigned int esfera = 0; esfera < escena->NumEsferas(); esfera++)
        {
            NuevaEsfera(escena->Esfera(esfera)->Color(), escena->Esfera(esfera)->Posicion());
        }
        for(unsigned int caja = 0; caja < escena->NumCajas(); caja++)
        {
            NuevaCaja(escena->Caja(caja)->Color(), escena->Caja(caja)->Posicion());
        }
        for(unsigned int persona = 0; persona < escena->NumPersonas(); persona++)
        {
            NuevaPersona(escena->Persona(persona)->Color(), escena->Persona(persona)->Posicion(), escena->Persona(persona)->Orientacion());
        }
        for(unsigned int robot = 0; robot < escena->NumRobots(); robot++)
        {
            NuevoRobot(escena->Robot(robot)->Color(), escena->Robot(robot)->Posicion(), escena->Robot(robot)->Orientacion());
        }
        escena->ConectarVista3D(this);
    }
>>>>>>> origin/master
}

CEscena* CVista3D::Escena(void)
{
    return escena;
}

void CVista3D::NuevaEsfera(TColor color, TPosicion posicion)
{
<<<<<<< HEAD
    CEsfera3D* esfera3d = new CEsfera3D;

    esfera3d->id    = escena->NumEsferas();
    esfera3d->radio = ESFERA_RADIO*2;
    esfera3d->x     = posicion.x;
    esfera3d->y     = posicion.y;
    esfera3d->z     = AlturaBaldosa + esfera3d->radio;
    esfera3d->color = color;
    esferas3d.push_back(*esfera3d);

    osg::ref_ptr<osg::PositionAttitudeTransform> trasformacion = new osg::PositionAttitudeTransform();
    nodos_esferas.push_back(trasformacion);
    osg::Vec3 position(esfera3d->x, -esfera3d->y, esfera3d->z);
    trasformacion->setPosition(position);
    trasformacion->setScale(osg::Vec3(esfera3d->radio, esfera3d->radio, esfera3d->radio));

    switch(color)
    {
    case Rojo:
        trasformacion->addChild(Geode_EsferaRoja);
        break;
    case Verde:
        trasformacion->addChild(Geode_EsferaVerde);
        break;
    case Azul:
        trasformacion->addChild(Geode_EsferaAzul);
        break;
    }

    escena3d->addChild(trasformacion);
=======

>>>>>>> origin/master
}

void CVista3D::NuevaCaja(TColor color, TPosicion posicion)
{
<<<<<<< HEAD
    float height;
    CCaja3D* caja3d = new CCaja3D;

    caja3d->id     = escena->NumCajas();
    caja3d->radio  = CAJA_RADIO;
    caja3d->altura = CAJA_ALTURA;
    caja3d->x      = posicion.x;
    caja3d->y      = posicion.y;
    caja3d->z      = AlturaBaldosa;
    caja3d->color  = color;
    cajas3d.push_back(*caja3d);

    osg::ref_ptr<osg::PositionAttitudeTransform> trasformacion = new osg::PositionAttitudeTransform();
    nodos_cajas.push_back(trasformacion);
    osg::Vec3 position(caja3d->x, -caja3d->y, caja3d->z);
    trasformacion->setPosition(position);
    height=Node_CajaRoja->getBound().radius();
    trasformacion->setScale(osg::Vec3(CAJA_ALTURA/height,CAJA_ALTURA/height,CAJA_ALTURA/height));

    switch(color)
    {
        case Rojo:
            trasformacion->addChild(Node_CajaRoja);
            break;
        case Verde:
            trasformacion->addChild(Node_CajaVerde);
            break;
        case Azul:
            trasformacion->addChild(Node_CajaAzul);
            break;
    }

    escena3d->addChild(trasformacion);
=======

>>>>>>> origin/master
}

void CVista3D::NuevaPersona(TColor color, TPosicion posicion, float orientacion)
{
<<<<<<< HEAD
    float height;
    CPersona3D* persona3d = new CPersona3D;

    persona3d->id     = escena->NumPersonas();
    persona3d->radio  = PERSONA_RADIO;
    persona3d->altura = PERSONA_ALTURA;
    persona3d->x      = posicion.x;
    persona3d->y      = posicion.y;
    persona3d->z      = AlturaBaldosa + persona3d->altura/2;
    persona3d->color  = color;
    personas3d.push_back(*persona3d);

    osg::ref_ptr<osg::PositionAttitudeTransform> trasformacion = new osg::PositionAttitudeTransform();
    nodos_personas.push_back(trasformacion);
    osg::Vec3 position(persona3d->x, -persona3d->y, persona3d->z);
    trasformacion->setPosition(position);
    height=2*(Node_PersonaFormaRoja->getBound().radius());
    trasformacion->setScale(osg::Vec3(PERSONA_ALTURA/height,PERSONA_ALTURA/height,PERSONA_ALTURA/height));
    trasformacion->setAttitude(osg::Quat(orientacion+osg::DegreesToRadians(90.0), osg::Vec3(0,0,1)));

    switch(color)
    {
        case Rojo:
            trasformacion->addChild(Node_PersonaFormaRoja);
            break;
        case Verde:
            trasformacion->addChild(Node_PersonaFormaVerde);
            break;
        case Azul:
            trasformacion->addChild(Node_PersonaFormaAzul);
            break;
    }

    escena3d->addChild(trasformacion);
=======

>>>>>>> origin/master
}

void CVista3D::NuevoRobot(TColor color, TPosicion posicion, float orientacion)
{
<<<<<<< HEAD
    float height;
    CRobot3D* robot3d = new CRobot3D;

    robot3d->id     = escena->NumRobots();
    robot3d->radio  = ROBOT_RADIO;
    robot3d->altura = ROBOT_ALTURA;
    robot3d->x      = posicion.x;
    robot3d->y      = posicion.y;
    robot3d->z      = RobotZ;
    robot3d->color  = color;
    robots3d.push_back(*robot3d);

    osg::ref_ptr<osg::PositionAttitudeTransform> trasformacion = new osg::PositionAttitudeTransform();
    nodos_robots.push_back(trasformacion);
    osg::Vec3 position(robot3d->x, -robot3d->y, robot3d->z);
    trasformacion->setPosition(position);
    height=Node_RobotRojo->getBound().radius();
    trasformacion->setScale(osg::Vec3(ROBOT_ALTURA/height,ROBOT_ALTURA/height,ROBOT_ALTURA/height));
    trasformacion->setAttitude(osg::Quat(orientacion-osg::DegreesToRadians(90.0), osg::Vec3(0,0,1)));

    switch(color)
    {
        case Rojo:
            trasformacion->addChild(Node_RobotRojo);
            break;
        case Verde:
            trasformacion->addChild(Node_RobotVerde);
            break;
        case Azul:
            trasformacion->addChild(Node_RobotAzul);
            break;
    }

    escena3d->addChild(trasformacion);
=======

>>>>>>> origin/master
}

void CVista3D::PosicionEsfera(unsigned int esfera, TPosicion posicion)
{
<<<<<<< HEAD
    osg::Vec3 position(posicion.x, -posicion.y, AlturaBaldosa + ESFERA_RADIO);
    nodos_esferas[esfera]->setPosition(position);
=======

>>>>>>> origin/master
}

void CVista3D::PosicionCaja(unsigned int caja, TPosicion posicion)
{
<<<<<<< HEAD
    osg::Vec3 position(posicion.x, -posicion.y, AlturaBaldosa);
    nodos_cajas[caja]->setPosition(position);
=======

>>>>>>> origin/master
}

void CVista3D::PosicionPersona(unsigned int persona, TPosicion posicion)
{
<<<<<<< HEAD
    osg::Vec3 position(posicion.x, -posicion.y, AlturaBaldosa + PERSONA_ALTURA / 2);
    nodos_personas[persona]->setPosition(position);
=======

>>>>>>> origin/master
}

void CVista3D::PosicionRobot(unsigned int robot, TPosicion posicion)
{
<<<<<<< HEAD
    osg::Vec3 position(posicion.x, -posicion.y, RobotZ);
    nodos_robots[robot]->setPosition(position);
=======

>>>>>>> origin/master
}

void CVista3D::OrientacionPersona(unsigned int persona, float orientacion)
{
<<<<<<< HEAD
    osg::Quat orientation(orientacion+osg::DegreesToRadians(90.0), osg::Vec3(0,0,1));
    nodos_personas[persona]->setAttitude(orientation);
=======

>>>>>>> origin/master
}

void CVista3D::OrientacionRobot(unsigned int robot, float orientacion)
{
<<<<<<< HEAD
    osg::Quat orientation(orientacion-osg::DegreesToRadians(90.0), osg::Vec3(0,0,1));
    nodos_robots[robot]->setAttitude(orientation);
=======

>>>>>>> origin/master
}

void CVista3D::BorrarEsferas(void)
{
<<<<<<< HEAD
    for(unsigned int esfera = 0; esfera < escena->NumEsferas(); esfera++)
       escena3d->removeChild(nodos_esferas[esfera]);

    nodos_esferas.clear();
=======

>>>>>>> origin/master
}

void CVista3D::BorrarCajas(void)
{
<<<<<<< HEAD
    for(unsigned int caja = 0; caja < escena->NumCajas(); caja++)
       escena3d->removeChild(nodos_cajas[caja]);

    nodos_cajas.clear();
=======

>>>>>>> origin/master
}

void CVista3D::BorrarPersonas(void)
{
<<<<<<< HEAD
    for(unsigned int persona = 0; persona < escena->NumPersonas(); persona++)
       escena3d->removeChild(nodos_personas[persona]);

    nodos_personas.clear();
=======

>>>>>>> origin/master
}

void CVista3D::BorrarRobots(void)
{
<<<<<<< HEAD
    for(unsigned int robot = 0; robot < escena->NumRobots(); robot++)
       escena3d->removeChild(nodos_robots[robot]);

    nodos_robots.clear();
=======

>>>>>>> origin/master
}

void CVista3D::Actualizar(void)
{
<<<<<<< HEAD
    for(unsigned int esfera = 0; esfera < escena->NumEsferas(); esfera++)
        PosicionEsfera(esfera, escena->Esfera(esfera)->Posicion());

    for(unsigned int caja = 0; caja < escena->NumCajas(); caja++)
        PosicionCaja(caja, escena->Caja(caja)->Posicion());

    for(unsigned int persona = 0; persona < escena->NumPersonas(); persona++)
    {
        PosicionPersona(persona, escena->Persona(persona)->Posicion());
        OrientacionPersona(persona, escena->Persona(persona)->Orientacion());
    }

    for(unsigned int robot = 0; robot < escena->NumRobots(); robot++)
    {
        PosicionRobot(robot, escena->Robot(robot)->Posicion());
        OrientacionRobot(robot, escena->Robot(robot)->Orientacion());
    }
=======

>>>>>>> origin/master
}

void CVista3D::Mostrar(void)
{
<<<<<<< HEAD
    vista.frame();
=======

>>>>>>> origin/master
}

void CVista3D::Guardar(FILE* archivo)
{

}

void CVista3D::Recuperar(FILE *archivo)
{

}

<<<<<<< HEAD
=======
void CVista3D::run()
{
/*
    //Simulacion Movimiento - Carro
    osg::Geode* Geode_Carro = new osg::Geode();
    Geode_Carro->addDrawable( new osg::ShapeDrawable( new osg::Box(osg::Vec3(0.0f,0.0f,0.0f),0.5f) ) );

    osg::MatrixTransform* MatrixTransform_Carro = new osg::MatrixTransform;
    MatrixTransform_Carro->addChild( Geode_Carro );

    osg::ref_ptr<osg::AnimationPath> AnimationPath_Camino = new osg::AnimationPath;
    AnimationPath_Camino->setLoopMode( osg::AnimationPath::SWING );

    osg::AnimationPath::ControlPoint ControlPoint_0(osg::Vec3(-10.0,-10.0,0.0));
    osg::AnimationPath::ControlPoint ControlPoint_1(osg::Vec3( 10.0, 10.0,0.0));
    AnimationPath_Camino->insert( 0.0f, ControlPoint_0 );
    AnimationPath_Camino->insert( 5.0f, ControlPoint_1 );

    osg::ref_ptr<osg::AnimationPathCallback> AnimationPathCallback_Camino = new osg::AnimationPathCallback( AnimationPath_Camino );
    MatrixTransform_Carro->setUpdateCallback( AnimationPathCallback_Camino );
    escena3d->addChild(MatrixTransform_Carro);
*/

    while(!vista.done())
    {
        vista.frame();
    }
}
>>>>>>> origin/master

