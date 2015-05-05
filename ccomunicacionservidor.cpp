#include "ccomunicacionservidor.h"

CComunicacionServidor::CComunicacionServidor(QObject *parent)
    : QTcpServer(parent)
{
    listen(QHostAddress::Any, TCP_PORT);
}

void CComunicacionServidor::Abrir(void)
{
    listen(QHostAddress::Any, TCP_PORT);
}

void CComunicacionServidor::Cerrar(void)
{
    std::list<CConexion*>::iterator iconexion;
    for(iconexion = conexiones.begin(); iconexion != conexiones.end(); iconexion++)
    {
        (*iconexion)->close();
    }
    close();
}

void CComunicacionServidor::incomingConnection(qintptr socketDescriptor)
{
    CConexion *conexion = new CConexion(this);
    conexion->setSocketDescriptor(socketDescriptor);
    emit NuevaConexion(conexion);
}


