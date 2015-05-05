#include "ccomunicacioncliente.h"

CComunicacionCliente::CComunicacionCliente()
{
    conector = new QTcpSocket;
}

void CComunicacionCliente::Conectar(QString direccion_ip)
{
    conector->connectToHost(direccion_ip, TCP_PORT, QIODevice::ReadWrite | QIODevice::Unbuffered);
}

void CComunicacionCliente::Desconectar(void)
{
    conector->disconnectFromHost();
}

void CComunicacionCliente::Enviar(QString mensaje)
{
    if(mensaje.isEmpty())
        return;

    QByteArray msg = mensaje.toUtf8();
    QByteArray data = "#" + QByteArray::number(msg.size()) + ' ' + msg;

    conector->write(data);
}
