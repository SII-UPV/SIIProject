#ifndef CCONEXION_H
#define CCONEXION_H

#include <QTcpSocket>

class CConexion : public QTcpSocket
{
    Q_OBJECT

public:
    CConexion(QObject *parent = 0);

signals:

public slots:

};

#endif // CCONEXION_H
