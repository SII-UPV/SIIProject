#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include "cesfera.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void MostrarEscena (void);
    void MostrarSliders(void);
    void MostrarLabels (void);

private:
    Ui::MainWindow *ui;

    float                tiempo;
    QTimer               *temporizador;
    QGraphicsScene       *escena;
    QGraphicsEllipseItem *elipse;

    CEsfera              *esfera;

public slots:
    void Posicion   (void);
    void Velocidad  (void);
    void Aceleracion(void);
    void Simular    (void);
    void Evolucionar(void);
};

#endif // MAINWINDOW_H
