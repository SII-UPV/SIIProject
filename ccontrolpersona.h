#ifndef CCONTROLPERSONA_H
#define CCONTROLPERSONA_H

#include <QMainWindow>

#include "ccomunicacioncliente.h"
#include "cescena.h"

namespace Ui {
class CControlPersona;
}

class CControlPersona : public QMainWindow
{
    Q_OBJECT

    CComunicacionCliente *comunicacion_cliente;
    CEscena *escena;
    unsigned int id_persona;

public:
    explicit CControlPersona(QWidget *parent = 0);
    ~CControlPersona();

    void Escena(CEscena* _escena);
    CEscena* Escena(void);

    void IdPersona(unsigned int _id_persona);
    unsigned int IdPersona(void);

private:
    Ui::CControlPersona *ui;

public slots:
    void Remoto(void);
    void SeleccionarPersona(void);
    void Avanzar(void);
    void Girar(void);
    void Parar(void);
    void Coger(void);
    void Soltar(void);
    void Almacenar(void);
    void Patear(void);
    void Empujar(void);
};

#endif // CCONTROLPERSONA_H
