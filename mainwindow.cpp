#include "mainwindow.h"
#include "ui_mainwindow.h"

    float tiempo_juego=0.0;
    int velocidad_juego=1.0; //PROPOCIONALIDAD DE TIEMPO: tiempo juego=n(%)* tiempo real

    static const double Pi = 3.14159265358979323846264338327950288419717;
    static double TwoPi = 2.0 * Pi;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene *escena_fondo = new QGraphicsScene;
    escena_fondo->setBackgroundBrush(QPixmap("saturno.png"));
    escena_fondo->setSceneRect(0, 0 ,ui->graphicsView->width() - 5, ui->graphicsView->height() - 5);
    ui->graphicsView->setScene(escena_fondo);
    ui->graphicsView->show();

    comunicacion_servidor = new CComunicacionServidor(this);
    num_conexiones = 0;

    srand(time(NULL));

    temporizador = new QTimer(this);
    temporizador->setInterval(1); //1 ms
    tiempo = 0.0;
    VelocidadJuego();
    escena = new CEscena();
    acerca_de = new CAcercaDe;

    connect(ui->checkBoxRemoto   , SIGNAL(clicked())                , this, SLOT(Remoto()));
    connect(comunicacion_servidor, SIGNAL(NuevaConexion(CConexion*)), this, SLOT(NuevaConexion(CConexion*)));

    connect(ui->checkBoxSimular               , SIGNAL(clicked())       , this, SLOT(Simular()));
    connect(temporizador                      , SIGNAL(timeout())       , this, SLOT(Evolucionar()));
    connect(ui->horizontalSliderVelocidadJuego, SIGNAL(sliderMoved(int)), this, SLOT(VelocidadJuego()));

    connect(ui->pushButtonNuevaEsfera , SIGNAL(clicked()), this, SLOT(NuevaEsfera()));
    connect(ui->pushButtonNuevaCaja   , SIGNAL(clicked()), this, SLOT(NuevaCaja()));
    connect(ui->pushButtonNuevaPersona, SIGNAL(clicked()), this, SLOT(NuevaPersona()));
    connect(ui->pushButtonNuevoRobot  , SIGNAL(clicked()), this, SLOT(NuevoRobot()));

    connect(ui->pushButtonBorrarEscena  , SIGNAL(clicked()), this, SLOT(BorrarEscena()));
    connect(ui->pushButtonBorrarEsferas , SIGNAL(clicked()), this, SLOT(BorrarEsferas()));
    connect(ui->pushButtonBorrarCajas   , SIGNAL(clicked()), this, SLOT(BorrarCajas()));
    connect(ui->pushButtonBorrarPersonas, SIGNAL(clicked()), this, SLOT(BorrarPersonas()));
    connect(ui->pushButtonBorrarRobots  , SIGNAL(clicked()), this, SLOT(BorrarRobots()));

    connect(ui->pushButtonNuevaVista2D, SIGNAL(clicked()), this, SLOT(NuevaVista2D()));
    connect(ui->pushButtonNuevaVista3D, SIGNAL(clicked()), this, SLOT(NuevaVista3D()));

    connect(ui->pushButtonNuevoControlPersona, SIGNAL(clicked()), this, SLOT(NuevoControlPersona()));
    connect(ui->pushButtonNuevoControlRobot  , SIGNAL(clicked()), this, SLOT(NuevoControlRobot()));

    connect(ui->menuAyuda  , SIGNAL(triggered(QAction*)), this, SLOT(Ayuda()));
    connect(ui->actionSalir, SIGNAL(triggered())        , this, SLOT(Salir()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete comunicacion_servidor;
    delete temporizador;
    delete escena;
}

void MainWindow::Remoto(void)
{
    if(ui->checkBoxRemoto->isChecked())
    {
        comunicacion_servidor->Abrir();
    }
    else
    {
        comunicacion_servidor->Cerrar();
    }
}

void MainWindow::NuevaConexion(CConexion* conexion)
{
    ui->labelNumeroConexiones->setText(QString("Numero Conexiones = ") + QString::number(++num_conexiones));
    comunicacion_servidor->conexiones.push_back(conexion);
    connect(conexion, SIGNAL(readyRead()), this, SLOT(Leer()));
}

void MainWindow::Leer(void)
{
    QTcpSocket *conector = static_cast<QTcpSocket*>(sender());
    QString mensaje;
    if(conector->bytesAvailable() > 0)
    {
        mensaje = conector->readAll();
        Interpretar(mensaje);
    }
}

void MainWindow::Interpretar(QString mensaje)
{
    ui->textEditMensajes->setText(mensaje);
}

void MainWindow::Simular(void)
{
    if(ui->checkBoxSimular->checkState())
        temporizador->start();
    else
        temporizador->stop();
}

void MainWindow::VelocidadJuego(void)
{
    velocidad_juego = ui->horizontalSliderVelocidadJuego->value();
    ui->labelVelocidadJuego->setText(QString("Velocidad Juego = x") + QString::number(velocidad_juego, 10));
}

void MainWindow::Evolucionar(void)
{
    escena->Evolucionar(velocidad_juego * temporizador->interval() / 1000.0);
    tiempo += velocidad_juego * temporizador->interval() / 1000.0;
    ui->labelTiempo->setText(QString("t = ") + QString::number(tiempo, 'g', 5));
}

void MainWindow::NuevaEsfera(void)
{
#define NUM_ESFERAS 50
    for(unsigned int num_esferas = 0; num_esferas < NUM_ESFERAS; num_esferas++)
    {
    float posicion_x    = X_MIN                   +     rand() * (X_MAX - X_MIN )       / RAND_MAX,
          velocidad_x   = -ESFERA_VELOCIDAD_MAX   + 2 * rand() * ESFERA_VELOCIDAD_MAX   / RAND_MAX,
          aceleracion_x = -ESFERA_ACELERACION_MAX + 2 * rand() * ESFERA_ACELERACION_MAX / RAND_MAX,
          posicion_y    = Y_MIN                   +     rand() * (Y_MAX - Y_MIN )       / RAND_MAX,
          velocidad_y   = -ESFERA_VELOCIDAD_MAX   + 2 * rand() * ESFERA_VELOCIDAD_MAX   / RAND_MAX,
          aceleracion_y = -ESFERA_ACELERACION_MAX + 2 * rand() * ESFERA_ACELERACION_MAX / RAND_MAX;
    TColor color = (TColor) (rand() * (Azul + 1) / RAND_MAX);
    TPosicion posicion;
    posicion.x = posicion_x;
    posicion.y = posicion_y;
    CEsfera* esfera = new CEsfera(color, posicion_x, posicion_y, velocidad_x, velocidad_y, aceleracion_x, aceleracion_y);
    escena->NuevaEsfera(esfera);
    std::vector<CVista2D*>::iterator ivista2d;
    for(ivista2d = vistas2d.begin(); ivista2d != vistas2d.end(); ivista2d++)
    {
        (*ivista2d)->NuevaEsfera(color, posicion);
    }
    std::vector<CVista3D*>::iterator ivista3d;
    for(ivista3d = vistas3d.begin(); ivista3d != vistas3d.end(); ivista3d++)
    {
        (*ivista3d)->NuevaEsfera(color, posicion);
    }
    }
}

void MainWindow::NuevaCaja(void)
{
#define NUM_CAJAS 5
    for(unsigned int num_cajas = 0; num_cajas < NUM_CAJAS; num_cajas++)
    {
    float posicion_x = X_MIN + rand() * (X_MAX - X_MIN ) / RAND_MAX,
          posicion_y = Y_MIN + rand() * (Y_MAX - Y_MIN ) / RAND_MAX;
    TColor color = (TColor) (rand() * (Azul + 1) / RAND_MAX);
    TPosicion posicion;
    posicion.x = posicion_x;
    posicion.y = posicion_y;
    CCaja* caja = new CCaja(color, CAJA_CAPACIDAD_DEFECTO, posicion_x, posicion_y);
    escena->NuevaCaja(caja);
    std::vector<CVista2D*>::iterator ivista2d;
    for(ivista2d = vistas2d.begin(); ivista2d != vistas2d.end(); ivista2d++)
    {
        (*ivista2d)->NuevaCaja(color, posicion);
    }
    std::vector<CVista3D*>::iterator ivista3d;
    for(ivista3d = vistas3d.begin(); ivista3d != vistas3d.end(); ivista3d++)
    {
        (*ivista3d)->NuevaCaja(color, posicion);
    }
    }
}

void MainWindow::NuevaPersona(void)
{
#define NUM_PERSONAS 15
    for(unsigned int num_personas = 0; num_personas < NUM_PERSONAS; num_personas++)
    {
    float posicion_x       = X_MIN                         +     rand() * (X_MAX - X_MIN )             / RAND_MAX,
          posicion_y       = Y_MIN                         +     rand() * (Y_MAX - Y_MIN )             / RAND_MAX,
          velocidad_avance = -PERSONA_VELOCIDAD_AVANCE_MAX + 2 * rand() * PERSONA_VELOCIDAD_AVANCE_MAX / RAND_MAX,
          velocidad_giro   = -PERSONA_VELOCIDAD_GIRO_MAX   + 2 * rand() * PERSONA_VELOCIDAD_GIRO_MAX   / RAND_MAX,
          orientacion      =                                     rand() * TwoPi                        / RAND_MAX,
          energia          = PERSONA_ENERGIA_INICIAL;
    TColor color = (TColor) (rand() * (Azul + 1) / RAND_MAX);
    TPosicion posicion;
    posicion.x = posicion_x;
    posicion.y = posicion_y;
    CPersona* persona = new CPersona(color, posicion, orientacion, velocidad_avance, velocidad_giro, energia, PERSONA_POSE_INICIAL);
    escena->NuevaPersona(persona);
    std::vector<CVista2D*>::iterator ivista2d;
    for(ivista2d = vistas2d.begin(); ivista2d != vistas2d.end(); ivista2d++)
    {
        (*ivista2d)->NuevaPersona(color, posicion, orientacion);
    }
    std::vector<CVista3D*>::iterator ivista3d;
    for(ivista3d = vistas3d.begin(); ivista3d != vistas3d.end(); ivista3d++)
    {
        (*ivista3d)->NuevaPersona(color, posicion, orientacion);
    }
    }
}

void MainWindow::NuevoRobot(void)
{
#define NUM_ROBOTS 5
    for(unsigned int num_robots = 0; num_robots < NUM_ROBOTS; num_robots++)
    {
    float posicion_x       = X_MIN                       +     rand() * (X_MAX - X_MIN)            / RAND_MAX,
          posicion_y       = Y_MIN                       +     rand() * (Y_MAX - Y_MIN           ) / RAND_MAX,
          velocidad_avance = -ROBOT_VELOCIDAD_AVANCE_MAX + 2 * rand() * ROBOT_VELOCIDAD_AVANCE_MAX / RAND_MAX,
          velocidad_giro   = -ROBOT_VELOCIDAD_GIRO_MAX   + 2 * rand() * ROBOT_VELOCIDAD_GIRO_MAX   / RAND_MAX,
          orientacion      =                                   rand() * TwoPi                      / RAND_MAX,
          energia          = ROBOT_ENERGIA_INICIAL;
    TColor color = (TColor) (rand() * (Azul + 1) / RAND_MAX);
    TPosicion posicion;
    posicion.x = posicion_x;
    posicion.y = posicion_y;
    CRobot* robot = new CRobot(color, posicion, orientacion, velocidad_avance, velocidad_giro, energia, ROBOT_POSE_INICIAL);
    escena->NuevoRobot(robot);
    std::vector<CVista2D*>::iterator ivista2d;
    for(ivista2d = vistas2d.begin(); ivista2d != vistas2d.end(); ivista2d++)
    {
        (*ivista2d)->NuevoRobot(color, posicion, orientacion);
    }
    std::vector<CVista3D*>::iterator ivista3d;
    for(ivista3d = vistas3d.begin(); ivista3d != vistas3d.end(); ivista3d++)
    {
        (*ivista3d)->NuevoRobot(color, posicion, orientacion);
    }
    }
}

void MainWindow::BorrarEscena(void)
{
    BorrarEsferas();
    BorrarCajas();
    BorrarPersonas();
    BorrarRobots();
}

void MainWindow::BorrarEsferas(void)
{
    std::vector<CVista2D*>::iterator ivista2d;
    for(ivista2d = vistas2d.begin(); ivista2d != vistas2d.end(); ivista2d++)
    {
        (*ivista2d)->BorrarEsferas();
    }
    std::vector<CVista3D*>::iterator ivista3d;
    for(ivista3d = vistas3d.begin(); ivista3d != vistas3d.end(); ivista3d++)
    {
        (*ivista3d)->BorrarEsferas();
    }
    escena->BorrarEsferas();
}

void MainWindow::BorrarCajas(void)
{
    std::vector<CVista2D*>::iterator ivista2d;
    for(ivista2d = vistas2d.begin(); ivista2d != vistas2d.end(); ivista2d++)
    {
        (*ivista2d)->BorrarCajas();
    }
    std::vector<CVista3D*>::iterator ivista3d;
    for(ivista3d = vistas3d.begin(); ivista3d != vistas3d.end(); ivista3d++)
    {
        (*ivista3d)->BorrarCajas();
    }
    escena->BorrarCajas();
}

void MainWindow::BorrarPersonas(void)
{
    std::vector<CVista2D*>::iterator ivista2d;
    for(ivista2d = vistas2d.begin(); ivista2d != vistas2d.end(); ivista2d++)
    {
        (*ivista2d)->BorrarPersonas();
    }
    std::vector<CVista3D*>::iterator ivista3d;
    for(ivista3d = vistas3d.begin(); ivista3d != vistas3d.end(); ivista3d++)
    {
        (*ivista3d)->BorrarPersonas();
    }
    escena->BorrarPersonas();
}

void MainWindow::BorrarRobots(void)
{
    std::vector<CVista2D*>::iterator ivista2d;
    for(ivista2d = vistas2d.begin(); ivista2d != vistas2d.end(); ivista2d++)
    {
        (*ivista2d)->BorrarRobots();
    }
    std::vector<CVista3D*>::iterator ivista3d;
    for(ivista3d = vistas3d.begin(); ivista3d != vistas3d.end(); ivista3d++)
    {
        (*ivista3d)->BorrarRobots();
    }
    escena->BorrarRobots();
}

void MainWindow::NuevaVista2D(void)
{
    CVista2D* vista2d = new CVista2D();
    vistas2d.push_back(vista2d);
    vista2d->Escena(escena);
    vista2d->show();
}

void MainWindow::NuevaVista3D(void)
{
    CVista3D* vista3d = new CVista3D();
    vistas3d.push_back(vista3d);
    vista3d->Escena(escena);
    vista3d->start();
}

void MainWindow::NuevoControlPersona(void)
{
    CControlPersona* control_persona = new CControlPersona;
    controles_personas.push_back(control_persona);
    control_persona->Escena(escena);
    control_persona->show();
}

void MainWindow::NuevoControlRobot(void)
{
    CControlRobot* control_robot = new CControlRobot;
    controles_robots.push_back(control_robot);
    control_robot->Escena(escena);
    control_robot->show();
}

void MainWindow::Ayuda(void)
{
    acerca_de->show();
}

void MainWindow::Salir(void)
{
    exit(0);
}
