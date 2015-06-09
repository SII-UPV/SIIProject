#include "cvista2d.h"
#include "ui_cvista2d.h"

CVista2D::CVista2D(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CVista2D)
{
    ui->setupUi(this);

    comunicacion_cliente = new CComunicacionCliente;

    escena   = NULL;
    escena2d = new QGraphicsScene(this);
    escena2d->setSceneRect(X_MIN, Y_MIN, X_MAX - X_MIN, Y_MAX - Y_MIN);
    escena2d->setBackgroundBrush(QPixmap("fondo.jpg"));

    ui->graphicsViewLocal ->setScene(escena2d);
    ui->graphicsViewGlobal->setScene(escena2d);

    ui->graphicsViewLocal->setDragMode(QGraphicsView::ScrollHandDrag);

    QTransform TransformacionLocal;
<<<<<<< HEAD
    TransformacionLocal.scale(0.8 * ui->graphicsViewLocal->geometry().width()  / (X_MAX - X_MIN),
                              0.8 * ui->graphicsViewLocal->geometry().height() / (Y_MAX - Y_MIN));
    ui->graphicsViewLocal->setTransform(TransformacionLocal, false);

    QTransform TransformacionGlobal;
    TransformacionGlobal.scale(0.8 * ui->graphicsViewGlobal->geometry().width()  / (X_MAX - X_MIN),
                               0.8 * ui->graphicsViewGlobal->geometry().height() / (Y_MAX - Y_MIN));
=======
    TransformacionLocal.scale(4.0, 4.0);
    ui->graphicsViewLocal->setTransform(TransformacionLocal, false);

    QTransform TransformacionGlobal;
    TransformacionGlobal.scale(2.0, 2.0);
>>>>>>> origin/master
    ui->graphicsViewGlobal->setTransform(TransformacionGlobal, false);

    lapiz_pared        .setColor(Qt::cyan);
    lapiz_eje          .setColor(Qt::cyan);
    lapiz_esfera_roja  .setColor(Qt::black);
    lapiz_esfera_verde .setColor(Qt::black);
    lapiz_esfera_azul  .setColor(Qt::black);
    lapiz_caja_roja    .setColor(Qt::black);
    lapiz_caja_verde   .setColor(Qt::black);
    lapiz_caja_azul    .setColor(Qt::black);
    lapiz_persona_roja .setColor(Qt::black);
    lapiz_persona_verde.setColor(Qt::black);
    lapiz_persona_azul .setColor(Qt::black);
    lapiz_robot_rojo   .setColor(Qt::black);
    lapiz_robot_verde  .setColor(Qt::black);
    lapiz_robot_azul   .setColor(Qt::black);

    lapiz_pared        .setWidth(1);
    lapiz_eje          .setWidth(1);
    lapiz_esfera_roja  .setWidth(1);
    lapiz_esfera_verde .setWidth(1);
    lapiz_esfera_azul  .setWidth(1);
    lapiz_caja_roja    .setWidth(1);
    lapiz_caja_verde   .setWidth(1);
    lapiz_caja_azul    .setWidth(1);
    lapiz_persona_roja .setWidth(1);
    lapiz_persona_verde.setWidth(1);
    lapiz_persona_azul .setWidth(1);
    lapiz_robot_rojo   .setWidth(1);
    lapiz_robot_verde  .setWidth(1);
    lapiz_robot_azul   .setWidth(1);

    lapiz_pared        .setCosmetic(true);
    lapiz_eje          .setCosmetic(true);
    lapiz_esfera_roja  .setCosmetic(true);
    lapiz_esfera_verde .setCosmetic(true);
    lapiz_esfera_azul  .setCosmetic(true);
    lapiz_caja_roja    .setCosmetic(true);
    lapiz_caja_verde   .setCosmetic(true);
    lapiz_caja_azul    .setCosmetic(true);
    lapiz_persona_roja .setCosmetic(true);
    lapiz_persona_verde.setCosmetic(true);
    lapiz_persona_azul .setCosmetic(true);
    lapiz_robot_rojo   .setCosmetic(true);
    lapiz_robot_verde  .setCosmetic(true);
    lapiz_robot_azul   .setCosmetic(true);

    pincel_esfera_roja  .setColor(QColor(255, 0  , 0  , 255));
    pincel_esfera_verde .setColor(QColor(0  , 255, 0  , 255));
    pincel_esfera_azul  .setColor(QColor(0  , 0  , 255, 255));
    pincel_caja_roja    .setColor(QColor(255, 0  , 0  , 255));
    pincel_caja_verde   .setColor(QColor(0  , 255, 0  , 255));
    pincel_caja_azul    .setColor(QColor(0  , 0  , 255, 255));
    pincel_persona_roja .setColor(QColor(255, 0  , 0  , 255));
    pincel_persona_verde.setColor(QColor(0  , 255, 0  , 255));
    pincel_persona_azul .setColor(QColor(0  , 0  , 255, 255));
    pincel_robot_rojo   .setColor(QColor(255, 0  , 0  , 255));
    pincel_robot_verde  .setColor(QColor(0  , 255, 0  , 255));
    pincel_robot_azul   .setColor(QColor(0  , 0  , 255, 255));

    pincel_esfera_roja  .setStyle(Qt::SolidPattern);
    pincel_esfera_verde .setStyle(Qt::SolidPattern);
    pincel_esfera_azul  .setStyle(Qt::SolidPattern);
    pincel_caja_roja    .setStyle(Qt::SolidPattern);
    pincel_caja_verde   .setStyle(Qt::SolidPattern);
    pincel_caja_azul    .setStyle(Qt::SolidPattern);
    pincel_persona_roja .setStyle(Qt::SolidPattern);
    pincel_persona_verde.setStyle(Qt::SolidPattern);
    pincel_persona_azul .setStyle(Qt::SolidPattern);
    pincel_robot_rojo   .setStyle(Qt::SolidPattern);
    pincel_robot_verde  .setStyle(Qt::SolidPattern);
    pincel_robot_azul   .setStyle(Qt::SolidPattern);

    QLine ejeX, ejeY;
    ejeX.setP1(QPoint(X_MIN, 0.0));
    ejeX.setP2(QPoint(X_MAX, 0.0));
    ejeY.setP1(QPoint(0.0, Y_MIN));
    ejeY.setP2(QPoint(0.0, Y_MAX));
    escena2d->addLine(ejeX, lapiz_eje);
    escena2d->addLine(ejeY, lapiz_eje);

    QLine paredXMin, paredXMax, paredYMin, paredYMax;
    paredXMin.setP1(QPoint(X_MIN, Y_MIN));
    paredXMin.setP2(QPoint(X_MIN, Y_MAX));
    paredXMax.setP1(QPoint(X_MAX, Y_MIN));
    paredXMax.setP2(QPoint(X_MAX, Y_MAX));
    paredYMin.setP1(QPoint(X_MIN, Y_MIN));
    paredYMin.setP2(QPoint(X_MAX, Y_MIN));
    paredYMax.setP1(QPoint(X_MIN, Y_MAX));
    paredYMax.setP2(QPoint(X_MAX, Y_MAX));
    escena2d->addLine(paredXMin, lapiz_pared);
    escena2d->addLine(paredXMax, lapiz_pared);
    escena2d->addLine(paredYMin, lapiz_pared);
    escena2d->addLine(paredYMax, lapiz_pared);

    connect(ui->checkBoxRemoto,          SIGNAL(clicked())       , this, SLOT(Remoto()));
    connect(ui->horizontalSliderEscala,  SIGNAL(sliderReleased()), this, SLOT(Escalar()));
    connect(ui->checkBoxMostrarEsferas,  SIGNAL(clicked())       , this, SLOT(MostrarOcultarEsferas()));
    connect(ui->checkBoxMostrarCajas,    SIGNAL(clicked())       , this, SLOT(MostrarOcultarCajas()));
    connect(ui->checkBoxMostrarPersonas, SIGNAL(clicked())       , this, SLOT(MostrarOcultarPersonas()));
    connect(ui->checkBoxMostrarRobots,   SIGNAL(clicked())       , this, SLOT(MostrarOcultarRobots()));
}

CVista2D::~CVista2D()
{
    if(escena)
    {
        escena->DesconectarVista2D(this);
    }
    delete escena2d;
    delete comunicacion_cliente;
    delete ui;
}

void CVista2D::keyPressEvent(QKeyEvent* e)
{
    ui->label->setText(e->text());
    QTransform t = ui->graphicsViewLocal->transform();
    switch(e->text().toStdString()[0])
    {
//DESACTIVAR DE ALGUNA FORMA EL CENTRADO DE LA ESCENA EN EL GRAPHICSVIEW PARA PODER TRASLADARLA
    case 'w':
    case 'W':
        t.translate(0.0, -10.0);
        break;
    case 'x':
    case 'X':
        t.translate(0.0, 10.0);
        break;
    case 'a':
    case 'A':
        t.translate(-10.0, 0.0);
        break;
    case 'd':
    case 'D':
        t.translate(10.0, 0.0);
        break;
    case 'q':
    case 'Q':
        t.rotate(-1.0);
        break;
    case 'e':
    case 'E':
        t.rotate(1.0);
        break;
    case '+':
        t.scale(1.1, 1.1);
        break;
    case '-':
        t.scale(0.9, 0.9);
        break;
    }
    ui->graphicsViewLocal->setTransform(t, false);
}

void CVista2D::Remoto(void)
{
    if(ui->checkBoxRemoto->isChecked())
    {
        comunicacion_cliente->Conectar(ui->lineEditServidor->text());
    }
    else
    {
        comunicacion_cliente->Desconectar();
    }
}

void CVista2D::Escena(CEscena* _escena)
{
    if(escena)
    {
        escena->DesconectarVista2D(this);
    }
    escena2d->clear();
    escena2d->setBackgroundBrush(QPixmap("fondo.jpg"));

    QLine ejeX, ejeY;
    ejeX.setP1(QPoint(X_MIN, 0.0));
    ejeX.setP2(QPoint(X_MAX, 0.0));
    ejeY.setP1(QPoint(0.0, Y_MIN));
    ejeY.setP2(QPoint(0.0, Y_MAX));
    escena2d->addLine(ejeX, lapiz_eje);
    escena2d->addLine(ejeY, lapiz_eje);

    QLine paredXMin, paredXMax, paredYMin, paredYMax;
    paredXMin.setP1(QPoint(X_MIN, Y_MIN));
    paredXMin.setP2(QPoint(X_MIN, Y_MAX));
    paredXMax.setP1(QPoint(X_MAX, Y_MIN));
    paredXMax.setP2(QPoint(X_MAX, Y_MAX));
    paredYMin.setP1(QPoint(X_MIN, Y_MIN));
    paredYMin.setP2(QPoint(X_MAX, Y_MIN));
    paredYMax.setP1(QPoint(X_MIN, Y_MAX));
    paredYMax.setP2(QPoint(X_MAX, Y_MAX));
    escena2d->addLine(paredXMin, lapiz_pared);
    escena2d->addLine(paredXMax, lapiz_pared);
    escena2d->addLine(paredYMin, lapiz_pared);
    escena2d->addLine(paredYMax, lapiz_pared);

    esferas2d .clear();
    cajas2d   .clear();
    personas2d.clear();
    robots2d  .clear();

    if(escena = _escena)
    {
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
        escena->ConectarVista2D(this);
    }
}

CEscena* CVista2D::Escena(void)
{
    return escena;
}

void CVista2D::NuevaEsfera(TColor color, TPosicion posicion)
{
    QGraphicsEllipseItem* esfera;
    QPen   lapiz;
    QBrush pincel;
    switch(color)
    {
    case Rojo:
        lapiz  = lapiz_esfera_roja;
        pincel = pincel_esfera_roja;
        break;
    case Verde:
        lapiz  = lapiz_esfera_verde;
        pincel = pincel_esfera_verde;
        break;
    case Azul:
        lapiz  = lapiz_esfera_azul;
        pincel = pincel_esfera_azul;
        break;
    }
    esferas2d.push_back(esfera = escena2d->addEllipse(posicion.x - ESFERA_RADIO,
                                                      posicion.y - ESFERA_RADIO,
                                                      ESFERA_RADIO * 2,
                                                      ESFERA_RADIO * 2,
                                                      lapiz,
                                                      pincel));
    if(ui->checkBoxMostrarEsferas->isChecked())
    {
        esfera->show();
    }
    else
    {
        esfera->hide();
    }
}

void CVista2D::NuevaCaja(TColor color, TPosicion posicion)
{
    QGraphicsEllipseItem* caja;
    QPen   lapiz;
    QBrush pincel;
    switch(color)
    {
    case Rojo:
        lapiz  = lapiz_caja_roja;
        pincel = pincel_caja_roja;
        break;
    case Verde:
        lapiz  = lapiz_caja_verde;
        pincel = pincel_caja_verde;
        break;
    case Azul:
        lapiz  = lapiz_caja_azul;
        pincel = pincel_caja_azul;
        break;
    }
    cajas2d.push_back(caja = escena2d->addEllipse(posicion.x - CAJA_RADIO,
                                                  posicion.y - CAJA_RADIO,
                                                  CAJA_RADIO * 2,
                                                  CAJA_RADIO * 2,
                                                  lapiz,
                                                  pincel));
    if(ui->checkBoxMostrarCajas->isChecked())
    {
        caja->show();
    }
    else
    {
        caja->hide();
    }
}

void CVista2D::NuevaPersona(TColor color, TPosicion posicion, float orientacion)
{
    QGraphicsEllipseItem* persona;
    QPen   lapiz;
    QBrush pincel;
    switch(color)
    {
    case Rojo:
        lapiz  = lapiz_persona_roja;
        pincel = pincel_persona_roja;
        break;
    case Verde:
        lapiz  = lapiz_persona_verde;
        pincel = pincel_persona_verde;
        break;
    case Azul:
        lapiz  = lapiz_persona_azul;
        pincel = pincel_persona_azul;
        break;
    }
    personas2d.push_back(persona = escena2d->addEllipse(posicion.x - PERSONA_RADIO,
                                                        posicion.y - PERSONA_RADIO,
                                                        PERSONA_RADIO * 2,
                                                        PERSONA_RADIO * 2,
                                                        lapiz,
                                                        pincel));
    persona->setStartAngle(NormalizarAnguloGrados(RadianesAGrados(orientacion) + PERSONA_ANGULO) * 16);
    persona->setSpanAngle (NormalizarAnguloGrados(                   360.0 - 2 * PERSONA_ANGULO) * 16);
    if(ui->checkBoxMostrarPersonas->isChecked())
    {
        persona->show();
    }
    else
    {
        persona->hide();
    }
}

void CVista2D::NuevoRobot(TColor color, TPosicion posicion, float orientacion)
{
    QGraphicsEllipseItem* robot;
    QPen   lapiz;
    QBrush pincel;
    switch(color)
    {
    case Rojo:
        lapiz  = lapiz_robot_rojo;
        pincel = pincel_robot_rojo;
        break;
    case Verde:
        lapiz  = lapiz_robot_verde;
        pincel = pincel_robot_verde;
        break;
    case Azul:
        lapiz  = lapiz_robot_azul;
        pincel = pincel_robot_azul;
        break;
    }
    robots2d.push_back(robot = escena2d->addEllipse(posicion.x - ROBOT_RADIO,
                                                    posicion.y - ROBOT_RADIO,
                                                    ROBOT_RADIO * 2,
                                                    ROBOT_RADIO * 2,
                                                    lapiz,
                                                    pincel));
    robot->setStartAngle(NormalizarAnguloGrados(RadianesAGrados(orientacion) + ROBOT_ANGULO) * 16);
    robot->setSpanAngle (NormalizarAnguloGrados(                   360.0 - 2 * ROBOT_ANGULO) * 16);
    if(ui->checkBoxMostrarRobots->isChecked())
    {
        robot->show();
    }
    else
    {
        robot->hide();
    }
}

void CVista2D::MostrarEsfera(unsigned int esfera)
{
    esferas2d[esfera]->show();
}

void CVista2D::MostrarCaja(unsigned int caja)
{
    cajas2d[caja]->show();
}

void CVista2D::MostrarPersona(unsigned int persona)
{
    personas2d[persona]->show();
}

void CVista2D::MostrarRobot(unsigned int robot)
{
    robots2d[robot]->show();
}

void CVista2D::OcultarEsfera(unsigned int esfera)
{
    esferas2d[esfera]->hide();
}

void CVista2D::OcultarCaja(unsigned int caja)
{
    cajas2d[caja]->hide();
}

void CVista2D::OcultarPersona(unsigned int persona)
{
    personas2d[persona]->hide();
}

void CVista2D::OcultarRobot(unsigned int robot)
{
    robots2d[robot]->hide();
}

void CVista2D::PosicionEsfera(unsigned int esfera, TPosicion posicion)
{
    esferas2d[esfera]->setRect(posicion.x - ESFERA_RADIO,
                               posicion.y - ESFERA_RADIO,
                               ESFERA_RADIO * 2,
                               ESFERA_RADIO * 2);
}

void CVista2D::PosicionCaja(unsigned int caja, TPosicion posicion)
{
    cajas2d[caja]->setRect(posicion.x - CAJA_RADIO,
                           posicion.y - CAJA_RADIO,
                           CAJA_RADIO * 2,
                           CAJA_RADIO * 2);
}

void CVista2D::PosicionPersona(unsigned int persona, TPosicion posicion)
{
    personas2d[persona]->setRect(posicion.x - PERSONA_RADIO,
                                 posicion.y - PERSONA_RADIO,
                                 PERSONA_RADIO * 2,
                                 PERSONA_RADIO * 2);
}

void CVista2D::PosicionRobot(unsigned int robot, TPosicion posicion)
{
    robots2d[robot]->setRect(posicion.x - ROBOT_RADIO,
                             posicion.y - ROBOT_RADIO,
                             ROBOT_RADIO * 2,
                             ROBOT_RADIO * 2);
}

void CVista2D::OrientacionPersona(unsigned int persona, float orientacion)
{
    personas2d[persona]->setStartAngle(NormalizarAnguloGrados(RadianesAGrados(orientacion) + PERSONA_ANGULO) * 16);
    personas2d[persona]->setSpanAngle (NormalizarAnguloGrados(                   360.0 - 2 * PERSONA_ANGULO) * 16);
}

void CVista2D::OrientacionRobot(unsigned int robot, float orientacion)
{
    robots2d[robot]->setStartAngle(NormalizarAnguloGrados(RadianesAGrados(orientacion) + ROBOT_ANGULO) * 16);
    robots2d[robot]->setSpanAngle (NormalizarAnguloGrados(                   360.0 - 2 * ROBOT_ANGULO) * 16);
}

void CVista2D::BorrarEsferas(void)
{
    std::vector<QGraphicsEllipseItem*>::iterator iesfera2d;
    for(iesfera2d = esferas2d.begin(); iesfera2d != esferas2d.end(); iesfera2d++)
    {
        escena2d->removeItem(*iesfera2d);
    }
    esferas2d.clear();
}

void CVista2D::BorrarCajas(void)
{
    std::vector<QGraphicsEllipseItem*>::iterator icaja2d;
    for(icaja2d = cajas2d.begin(); icaja2d != cajas2d.end(); icaja2d++)
    {
        escena2d->removeItem(*icaja2d);
    }
    cajas2d.clear();
}

void CVista2D::BorrarPersonas(void)
{
    std::vector<QGraphicsEllipseItem*>::iterator ipersona2d;
    for(ipersona2d = personas2d.begin(); ipersona2d != personas2d.end(); ipersona2d++)
    {
        escena2d->removeItem(*ipersona2d);
    }
    personas2d.clear();
}

void CVista2D::BorrarRobots(void)
{
    std::vector<QGraphicsEllipseItem*>::iterator irobot2d;
    for(irobot2d = robots2d.begin(); irobot2d != robots2d.end(); irobot2d++)
    {
        escena2d->removeItem(*irobot2d);
    }
    robots2d.clear();
}

void CVista2D::Actualizar(void)
{
    for(unsigned int esfera = 0; esfera < escena->NumEsferas(); esfera++)
    {
        PosicionEsfera(esfera, escena->Esfera(esfera)->Posicion());
    }
    for(unsigned int caja = 0; caja < escena->NumCajas(); caja++)
    {
        PosicionCaja(caja, escena->Caja(caja)->Posicion());
    }
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
}

void CVista2D::Mostrar(void)
{
    escena2d->update();
}

void CVista2D::Escalar(void)
{
    QTransform Transformacion;
    Transformacion.scale(ui->horizontalSliderEscala->value()/10.0,ui->horizontalSliderEscala->value()/10.0);
    ui->graphicsViewLocal->setTransform(Transformacion, false);
}

void CVista2D::MostrarOcultarEsferas(void)
{
    if(ui->checkBoxMostrarEsferas->isChecked())
    {
        for(unsigned int esfera = 0; esfera < esferas2d.size(); esfera++)
        {
            esferas2d[esfera]->show();
        }
    }
    else
    {
        for(unsigned int esfera = 0; esfera < esferas2d.size(); esfera++)
        {
            esferas2d[esfera]->hide();
        }
    }
}

void CVista2D::MostrarOcultarCajas(void)
{
    if(ui->checkBoxMostrarCajas->isChecked())
    {
        for(unsigned int caja = 0; caja < cajas2d.size(); caja++)
        {
            cajas2d[caja]->show();
        }
    }
    else
    {
        for(unsigned int caja = 0; caja < cajas2d.size(); caja++)
        {
            cajas2d[caja]->hide();
        }
    }
}

void CVista2D::MostrarOcultarPersonas(void)
{
    if(ui->checkBoxMostrarPersonas->isChecked())
    {
        for(unsigned int persona = 0; persona < personas2d.size(); persona++)
        {
            personas2d[persona]->show();
        }
    }
    else
    {
        for(unsigned int persona = 0; persona < personas2d.size(); persona++)
        {
            personas2d[persona]->hide();
        }
    }
}

void CVista2D::MostrarOcultarRobots(void)
{
    if(ui->checkBoxMostrarRobots->isChecked())
    {
        for(unsigned int robot = 0; robot < robots2d.size(); robot++)
        {
            robots2d[robot]->show();
        }
    }
    else
    {
        for(unsigned int robot = 0; robot < robots2d.size(); robot++)
        {
            robots2d[robot]->hide();
        }
    }
}

void CVista2D::Guardar(FILE* archivo)
{

}

void CVista2D::Recuperar(FILE *archivo)
{

}
