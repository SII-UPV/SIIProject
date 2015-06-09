#include "ccontrolrobot.h"
#include "ui_ccontrolrobot.h"

CControlRobot::CControlRobot(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CControlRobot)
{
    ui->setupUi(this);

    comunicacion_cliente = new CComunicacionCliente;

    connect(ui->checkBoxRemoto,             SIGNAL(clicked()),        this, SLOT(Remoto()));
    connect(ui->pushButtonSeleccionarRobot, SIGNAL(clicked()),        this, SLOT(SeleccionarRobot()));
    connect(ui->verticalSliderAvanzar,      SIGNAL(sliderMoved(int)), this, SLOT(Avanzar()));
    connect(ui->verticalSliderAvanzar,      SIGNAL(sliderReleased()), this, SLOT(Parar()));
    connect(ui->horizontalSliderGirar,      SIGNAL(sliderMoved(int)), this, SLOT(Girar()));
    connect(ui->horizontalSliderGirar,      SIGNAL(sliderReleased()), this, SLOT(Parar()));
    connect(ui->pushButtonParar,            SIGNAL(clicked()),        this, SLOT(Parar()));
    connect(ui->pushButtonCoger,            SIGNAL(clicked()),        this, SLOT(Coger()));
    connect(ui->pushButtonSoltar,           SIGNAL(clicked()),        this, SLOT(Soltar()));
    connect(ui->pushButtonAlmacenar,        SIGNAL(clicked()),        this, SLOT(Almacenar()));
    connect(ui->pushButtonPatear,           SIGNAL(clicked()),        this, SLOT(Patear()));
    connect(ui->checkBoxEmpujar,            SIGNAL(clicked()),        this, SLOT(Empujar()));
}

CControlRobot::~CControlRobot()
{
    delete comunicacion_cliente;
    delete ui;
}

void CControlRobot::Escena(CEscena* _escena)
{
    escena = _escena;
}

CEscena* CControlRobot::Escena(void)
{
    return escena;
}

void CControlRobot::IdRobot(unsigned int _id_robot)
{
    if(escena && (_id_robot < escena->NumRobots()))
    {
        id_robot = _id_robot;
    }
}

unsigned int CControlRobot::IdRobot(void)
{
    return id_robot;
}

void CControlRobot::Remoto(void)
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

void CControlRobot::SeleccionarRobot(void)
{
    if(ui->checkBoxRemoto->isChecked())
    {
        QString mensaje = "Robot = ";
        comunicacion_cliente->Enviar(mensaje + ui->lineEditIdRobot->text());
    }
    else
    {
        IdRobot(ui->lineEditIdRobot->text().toULong());
    }
}

void CControlRobot::Avanzar(void)
{
    escena->Robot(id_robot)->VelocidadAvance(ui->verticalSliderAvanzar->value() * ROBOT_VELOCIDAD_AVANCE_MAX / ui->verticalSliderAvanzar->maximum());
}

void CControlRobot::Girar(void)
{
    escena->Robot(id_robot)->VelocidadGiro(-ui->horizontalSliderGirar->value() * ROBOT_VELOCIDAD_GIRO_MAX / ui->horizontalSliderGirar->maximum());
}

void CControlRobot::Parar(void)
{
    escena->Robot(id_robot)->VelocidadAvance(0.0);
    escena->Robot(id_robot)->VelocidadGiro  (0.0);
    ui->verticalSliderAvanzar->setValue(0);
    ui->horizontalSliderGirar->setValue(0);
}

void CControlRobot::Coger(void)
{
    escena->Robot(id_robot)->Coger(NULL);
}

void CControlRobot::Soltar(void)
{
    escena->Robot(id_robot)->Soltar();
}

void CControlRobot::Almacenar(void)
{
    escena->Robot(id_robot)->Almacenar(NULL);
}

void CControlRobot::Patear(void)
{
    escena->Robot(id_robot)->Patear(NULL);
}

void CControlRobot::Empujar(void)
{
    if(ui->checkBoxEmpujar->isChecked())
    {
        escena->Robot(id_robot)->Empujar(true);
    }
    else
    {
        escena->Robot(id_robot)->Empujar(false);
    }
}
