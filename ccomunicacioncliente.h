#ifndef CCOMUNICACIONCLIENTE_H
#define CCOMUNICACIONCLIENTE_H

#include <QHostAddress>
#include <QTcpSocket>

#include "videojuego.h"

class CComunicacionCliente
{
    QTcpSocket *conector;

public:
    CComunicacionCliente();

    void Conectar(QString direccion_ip);
    void Desconectar(void);

    void Enviar(QString mensaje);
};

#endif // CCOMUNICACIONCLIENTE_H
