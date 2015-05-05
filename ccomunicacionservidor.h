#ifndef CCOMUNICACIONSERVIDOR_H
#define CCOMUNICACIONSERVIDOR_H

#include <QTcpServer>
#include <list>

#include "videojuego.h"
#include "cconexion.h"

class CComunicacionServidor : public QTcpServer
{
    Q_OBJECT

public:
    CComunicacionServidor(QObject *parent = 0);

    void Abrir(void);
    void Cerrar(void);

    std::list<CConexion*> conexiones;

signals:
    void NuevaConexion(CConexion *conexion);

protected:
    void incomingConnection(qintptr socketDescriptor);
};

#endif // CCOMUNICACIONSERVIDOR_H

