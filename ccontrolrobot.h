#ifndef CCONTROLROBOT_H
#define CCONTROLROBOT_H

#include <QMainWindow>

#include "ccomunicacioncliente.h"
#include "cescena.h"

namespace Ui {
class CControlRobot;
}

class CControlRobot : public QMainWindow
{
    Q_OBJECT

    CComunicacionCliente *comunicacion_cliente;
    CEscena *escena;
    unsigned int id_robot;

public:
    explicit CControlRobot(QWidget *parent = 0);
    ~CControlRobot();

    void Escena(CEscena* _escena);
    CEscena* Escena(void);

    void IdRobot(unsigned int _id_robot);
    unsigned int IdRobot(void);

private:
    Ui::CControlRobot *ui;

public slots:
    void Remoto(void);
    void SeleccionarRobot(void);
    void Avanzar(void);
    void Girar(void);
    void Parar(void);
    void Coger(void);
    void Soltar(void);
    void Almacenar(void);
    void Patear(void);
    void Empujar(void);
};

#endif // CCONTROLROBOT_H
