#include "ccontrolpersona.h"
#include "ui_ccontrolpersona.h"

CControlPersona::CControlPersona(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CControlPersona)
{
    ui->setupUi(this);

    comunicacion_cliente = new CComunicacionCliente;

    connect(ui->checkBoxRemoto,               SIGNAL(clicked()),        this, SLOT(Remoto()));
    connect(ui->pushButtonSeleccionarPersona, SIGNAL(clicked()),        this, SLOT(SeleccionarPersona()));
    connect(ui->verticalSliderAvanzar,        SIGNAL(sliderMoved(int)), this, SLOT(Avanzar()));
    connect(ui->verticalSliderAvanzar,        SIGNAL(sliderReleased()), this, SLOT(Parar()));
    connect(ui->horizontalSliderGirar,        SIGNAL(sliderMoved(int)), this, SLOT(Girar()));
    connect(ui->horizontalSliderGirar,        SIGNAL(sliderReleased()), this, SLOT(Parar()));
    connect(ui->pushButtonParar,              SIGNAL(clicked()),        this, SLOT(Parar()));
    connect(ui->pushButtonCoger,              SIGNAL(clicked()),        this, SLOT(Coger()));
    connect(ui->pushButtonSoltar,             SIGNAL(clicked()),        this, SLOT(Soltar()));
    connect(ui->pushButtonAlmacenar,          SIGNAL(clicked()),        this, SLOT(Almacenar()));
    connect(ui->pushButtonPatear,             SIGNAL(clicked()),        this, SLOT(Patear()));
    connect(ui->checkBoxEmpujar,              SIGNAL(clicked()),        this, SLOT(Empujar()));
}

CControlPersona::~CControlPersona()
{
    delete comunicacion_cliente;
    delete ui;
}

void CControlPersona::Escena(CEscena* _escena)
{
    escena = _escena;
}

CEscena* CControlPersona::Escena(void)
{
    return escena;
}

void CControlPersona::IdPersona(unsigned int _id_persona)
{
    if(escena && (_id_persona < escena->NumPersonas()))
    {
        id_persona = _id_persona;
    }
}

unsigned int CControlPersona::IdPersona(void)
{
    return id_persona;
}

void CControlPersona::Remoto(void)
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

void CControlPersona::SeleccionarPersona(void)
{
    if(ui->checkBoxRemoto->isChecked())
    {
        QString mensaje = "Persona = ";
        comunicacion_cliente->Enviar(mensaje + ui->lineEditIdPersona->text());
    }
    else
    {
        IdPersona(ui->lineEditIdPersona->text().toULong());
    }
}

void CControlPersona::Avanzar(void)
{
    float velocidad_avance = ui->verticalSliderAvanzar->value() * PERSONA_VELOCIDAD_AVANCE_MAX / ui->verticalSliderAvanzar->maximum();
    if(ui->checkBoxRemoto->isChecked())
    {
        QString mensaje = "P";
        comunicacion_cliente->Enviar(mensaje + ui->lineEditIdPersona->text() + " " + "A" + QString::number(velocidad_avance, 'g', 5));
    }
    else
    {
        escena->Persona(id_persona)->VelocidadAvance(velocidad_avance);
    }
}

void CControlPersona::Girar(void)
{
    float velocidad_giro = -ui->horizontalSliderGirar->value() * PERSONA_VELOCIDAD_GIRO_MAX / ui->horizontalSliderGirar->maximum();
    if(ui->checkBoxRemoto->isChecked())
    {
        QString mensaje = "P";
        comunicacion_cliente->Enviar(mensaje + ui->lineEditIdPersona->text() + " " + "G" + QString::number(velocidad_giro, 'g', 5));
    }
    else
    {
        escena->Persona(id_persona)->VelocidadGiro(velocidad_giro);
    }
}

void CControlPersona::Parar(void)
{
    if(ui->checkBoxRemoto->isChecked())
    {
        QString mensaje = "P";
        comunicacion_cliente->Enviar(mensaje + ui->lineEditIdPersona->text() + " " + "P");
    }
    else
    {
        escena->Persona(id_persona)->VelocidadAvance(0.0);
        escena->Persona(id_persona)->VelocidadGiro  (0.0);
    }
    ui->verticalSliderAvanzar->setValue(0);
    ui->horizontalSliderGirar->setValue(0);
}

void CControlPersona::Coger(void)
{
    if(ui->checkBoxRemoto->isChecked())
    {
        QString mensaje = "P";
        comunicacion_cliente->Enviar(mensaje + ui->lineEditIdPersona->text() + " " + "C");
    }
    else
    {
        escena->Persona(id_persona)->Coger(NULL);
    }
}

void CControlPersona::Soltar(void)
{
    if(ui->checkBoxRemoto->isChecked())
    {
        QString mensaje = "P";
        comunicacion_cliente->Enviar(mensaje + ui->lineEditIdPersona->text() + " " + "S");
    }
    else
    {
        escena->Persona(id_persona)->Soltar();
    }
}

void CControlPersona::Almacenar(void)
{
    if(ui->checkBoxRemoto->isChecked())
    {
        QString mensaje = "P";
        comunicacion_cliente->Enviar(mensaje + ui->lineEditIdPersona->text() + " " + "a");
    }
    else
    {
        escena->Persona(id_persona)->Almacenar(NULL);
    }
}

void CControlPersona::Patear(void)
{
    if(ui->checkBoxRemoto->isChecked())
    {
        QString mensaje = "P";
        comunicacion_cliente->Enviar(mensaje + ui->lineEditIdPersona->text() + " " + "p");
    }
    else
    {
        escena->Persona(id_persona)->Patear(NULL);
    }
}

void CControlPersona::Empujar(void)
{
    if(ui->checkBoxRemoto->isChecked())
    {
        QString mensaje = "P";
        if(ui->checkBoxEmpujar->isChecked())
        {
            comunicacion_cliente->Enviar(mensaje + ui->lineEditIdPersona->text() + " " + "ES");
        }
        else
        {
            comunicacion_cliente->Enviar(mensaje + ui->lineEditIdPersona->text() + " " + "EN");
        }
    }
    else
    {
        if(ui->checkBoxEmpujar->isChecked())
        {
            escena->Persona(id_persona)->Empujar(true);
        }
        else
        {
            escena->Persona(id_persona)->Empujar(false);
        }
    }
}
