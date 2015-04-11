#include "mainwindow.h"
#include "ui_mainwindow.h"

    float tiempo_juego=0.0;
    int velocidad_juego=30.0; //PROPOCIONALIDAD DE TIEMPO: tiempo juego=n(%)* tiempo real

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srand(time(NULL));

    temporizador = new QTimer(this);
    temporizador->setInterval(1); //1 ms
    tiempo = 0.0;

    escena = new QGraphicsScene(this);
    ui->graphicsView->setScene(escena);

    QBrush pincel(Qt::white);
    QPen   lapiz (Qt::black);
    lapiz.setWidth(1);
    QPen   lapizrojo (Qt::red);
    lapiz.setWidth(1);
    QPen   rotulador (Qt::blue);
    rotulador.setWidth(5);

    elipse = escena->addEllipse(OrigenX-DiametroEsfera/2,OrigenY-DiametroEsfera/2,
                               DiametroEsfera,DiametroEsfera,
                                 lapizrojo, pincel);
    elipse2 = escena->addEllipse(OrigenX+50-DiametroEsfera/2,OrigenY+25-DiametroEsfera/2,
                               DiametroEsfera,DiametroEsfera,
                                 lapiz, pincel);
    elipse3 = escena->addEllipse(OrigenX+100-DiametroEsfera/2,OrigenY+50-DiametroEsfera/2,
                               DiametroEsfera,DiametroEsfera,
                                 lapiz, pincel);
    //EJES DEL ESPACIO
    QLine ejeX,ejeY;
    ejeX.setP1(QPoint(OrigenX-gamespace_x,OrigenY)); //los valores estan calculados a partir de: LONGITUD ESPACIO JUEGO/2 -10 (-10 para no sobrexpandir el menú)
    ejeX.setP2(QPoint(OrigenX+gamespace_x,OrigenY));
    ejeY.setP1(QPoint(OrigenX,OrigenY-gamespace_y));
    ejeY.setP2(QPoint(OrigenX,OrigenY+gamespace_y));

    escena->addLine(ejeX,lapiz);
    escena->addLine(ejeY,lapiz);

    //BORDES DEL ESPACIO DE JUEGO
    QLine borde_der,borde_izq, borde_sup, borde_inf;
    borde_der.setP1(QPoint(OrigenX+1+gamespace_x,OrigenY-1-gamespace_y)); //+1 para darle mas calidad visual al borde solamente
    borde_der.setP2(QPoint(OrigenX+1+gamespace_x,OrigenY+1+gamespace_y));

    borde_izq.setP1(QPoint(OrigenX-2-gamespace_x,OrigenY-1-gamespace_y));
    borde_izq.setP2(QPoint(OrigenX-2-gamespace_x,OrigenY+1+gamespace_y));

    borde_sup.setP1(QPoint(OrigenX-1-gamespace_x,OrigenY+1+gamespace_y));
    borde_sup.setP2(QPoint(OrigenX+1+gamespace_x,OrigenY+1+gamespace_y));

    borde_inf.setP1(QPoint(OrigenX-1-gamespace_x,OrigenY-1-gamespace_y));
    borde_inf.setP2(QPoint(OrigenX+1+gamespace_x,OrigenY-1-gamespace_y));

    escena->addLine(borde_der,rotulador);
    escena->addLine(borde_izq,rotulador);
    escena->addLine(borde_sup,rotulador);
    escena->addLine(borde_inf,rotulador);

    esfera = new CEsfera;
    esfera2 = new CEsfera;
    esfera3 = new CEsfera;

    NuevaPersona();
    NuevaCaja();
    NuevaCaja();
    NuevaCaja();

    connect(ui->xSliderPosicion   ,SIGNAL(sliderMoved(int)),this,SLOT(Posicion()));
    connect(ui->xSliderVelocidad  ,SIGNAL(sliderMoved(int)),this,SLOT(Velocidad()));

    connect(ui->ySliderPosicion   ,SIGNAL(sliderMoved(int)),this,SLOT(Posicion()));
    connect(ui->ySliderVelocidad  ,SIGNAL(sliderMoved(int)),this,SLOT(Velocidad()));

    connect(ui->boton_nitrox      ,SIGNAL(clicked())       ,this,SLOT(Nitrox()) );
    connect(ui->boton_nitroy      ,SIGNAL(clicked())       ,this,SLOT(Nitroy()) );

    //connect(ui->scrollVelocidad_juego, SIGNAL(valueChanged(int)) ,this,SLOT(Tiempo_juego(ui->scrollVelocidad_juego->value())) );

    connect(ui->checkBoxSimular   ,SIGNAL(clicked())       ,this,SLOT(Simular()));
    //ACCION SECUENCIAL
    connect(temporizador          ,SIGNAL(timeout())       ,this,SLOT(Evolucionar()));

    connect(ui->pushButtonNuevaEsfera, SIGNAL(clicked()),this,SLOT(NuevaEsfera()));
    connect(ui->pushButtonNitro      , SIGNAL(clicked()),this,SLOT(Nitro()));
}

MainWindow::~MainWindow()
{
    delete ui;

    delete temporizador;
    delete escena;
    delete esfera;
    delete esfera2;
    delete esfera3;
}

void MainWindow::MostrarEscena(void)
{
    int x = (int) esfera->Posicionx() + OrigenX;
    int y = (int) esfera->Posiciony() + OrigenY;

    int x2 = (int) esfera2->Posicionx() + OrigenX+50;
    int y2 = (int) esfera2->Posiciony() + OrigenY;

    int x3 = (int) esfera3->Posicionx() + OrigenX+150;
    int y3 = (int) esfera3->Posiciony() + OrigenY;

    elipse->setRect(x-DiametroEsfera/2,y-DiametroEsfera/2,
                    DiametroEsfera,DiametroEsfera);
    elipse2->setRect(x2-DiametroEsfera/2,y2-DiametroEsfera/2,
                    DiametroEsfera,DiametroEsfera);
    elipse3->setRect(x3-DiametroEsfera/2,y3-DiametroEsfera/2,
                    DiametroEsfera,DiametroEsfera);

    std::list<TEsfera *>::iterator iesfera;
    for(iesfera = esferas.begin(); iesfera != esferas.end(); iesfera++)
    {
        (*iesfera)->elipse->setRect(OrigenX-(*iesfera)->esfera->Posicionx()-(*iesfera)->esfera->Radio(),
                                    OrigenY-(*iesfera)->esfera->Posiciony()-(*iesfera)->esfera->Radio(),
                                    (*iesfera)->esfera->Radio()*2,
                                    (*iesfera)->esfera->Radio()*2);
    }
    std::list<TPersona *>::iterator ipersona;
    for(ipersona = personas.begin(); ipersona != personas.end(); ipersona++)
    {
        (*ipersona)->elipse->setRect(OrigenX-(*ipersona)->persona->Posicionx()-DiametroPersona/2,
                                    OrigenY-(*ipersona)->persona->Posiciony()-DiametroPersona/2,
                                    DiametroPersona,
                                    DiametroPersona);
    }
    std::list<TCaja *>::iterator icaja;
    for(icaja = cajas.begin(); icaja != cajas.end(); icaja++)
    {
        (*icaja)->rectangulo->setBrush(QColor(QRgb((*icaja)->caja->Color())));      //Para poder cambiar el color de la caja hay que actualizar el QBrush
        (*icaja)->rectangulo->setRect(OrigenX-(*icaja)->caja->Posicionx()-(*icaja)->caja->Lado()/2,
                                    OrigenY-(*icaja)->caja->Posiciony()-(*icaja)->caja->Lado()/2,
                                    (*icaja)->caja->Lado(),
                                    (*icaja)->caja->Lado());
    }

    escena->update();
}

void MainWindow::MostrarSliders(void)
{
    ui->xSliderPosicion   ->setValue((int) esfera->Posicionx()   );
    ui->xSliderVelocidad  ->setValue((int) esfera->Velocidadx()  );

    ui->ySliderPosicion   ->setValue((int) esfera->Posiciony()   );
    ui->ySliderVelocidad  ->setValue((int) esfera->Velocidady()  );
}

void MainWindow::MostrarLabels(void)
{
    ui->labelTiempo     ->setText(QString("t = ") + QString::number(tiempo               , 'g', 5));
    ui->labelTiempo_juego->setText(QString("t_game = ") + QString::number(tiempo_juego               , 'g', 5));

    ui->labelPosicionx   ->setText(QString("px = ") + QString::number(esfera->Posicionx()   , 'g', 5));
    ui->labelVelocidadx  ->setText(QString("vx = ") + QString::number(esfera->Velocidadx()  , 'g', 5));
    ui->labelAceleracionx->setText(QString("ax = ") + QString::number(esfera->Aceleracionx(), 'g', 5));

    ui->labelPosiciony   ->setText(QString("py = ") + QString::number(esfera->Posiciony()   , 'g', 5));
    ui->labelVelocidady  ->setText(QString("vy = ") + QString::number(esfera->Velocidady()  , 'g', 5));
    ui->labelAceleraciony->setText(QString("ay = ") + QString::number(esfera->Aceleraciony(), 'g', 5));
}

void MainWindow::Posicion(void)
{
    esfera->Posicion((float)ui->xSliderPosicion->value(),(float)ui->ySliderPosicion->value());
    MostrarLabels();
    MostrarEscena();
}

void MainWindow::Velocidad(void)
{
    esfera->Velocidad((float)ui->xSliderVelocidad->value(), (float)ui->ySliderVelocidad->value());
    MostrarLabels();
    MostrarEscena();
}

/*void MainWindow::Aceleracion(void)
{
    esfera->Aceleracion((float)ui->xSliderAceleracion->value() / 20.0, (float)ui->ySliderAceleracion->value() / 20.0);
    MostrarLabels();
    MostrarEscena();
}*/

void MainWindow::Simular(void)
{
    if(ui->checkBoxSimular->checkState())
        temporizador->start();
    else
        temporizador->stop();
}

void MainWindow::Evolucionar(void)
{
    tiempo += temporizador->interval() / 1000.0;
    tiempo_juego += temporizador->interval() / (velocidad_juego*10.0);

    esfera->Evolucionar(temporizador->interval() / (velocidad_juego*10.0) );
    esfera2->Evolucionar(temporizador->interval() / (velocidad_juego*10.0) );
    esfera3->Evolucionar(temporizador->interval() / (velocidad_juego*10.0) );

    float _x= (esfera->Posicionx()+ OrigenX) - (esfera2->Posicionx()+ OrigenX+50);
    float _y= (esfera->Posiciony()+ OrigenY) - (esfera2->Posiciony()+ OrigenY);
    ui->label->setText(QString("distancia de esf1 a esf2 = ") +QString::number( (int)qSqrt(_x*_x + _y*_y) ) );

    if( (int)qSqrt(_x*_x + _y*_y)== DiametroEsfera)
    {
        if(qSqrt(esfera->Velocidadx()*esfera->Velocidadx()+esfera->Velocidady()*esfera->Velocidady()) > qSqrt( esfera2->Velocidadx()*esfera2->Velocidadx()+esfera2->Velocidady()*esfera2->Velocidady()) )
        { Colision(esfera, esfera2); }
        else{
            if(qSqrt(esfera->Velocidadx()*esfera->Velocidadx()+esfera->Velocidady()*esfera->Velocidady()) < qSqrt( esfera2->Velocidadx()*esfera2->Velocidadx()+esfera2->Velocidady()*esfera2->Velocidady()) )
            { Colision(esfera2, esfera); }
 /*si v1==v2*/ else{
                esfera->Velocidad(-esfera->Velocidadx(),-esfera->Velocidady());
                esfera2->Velocidad(-esfera2->Velocidadx(),-esfera2->Velocidady());
            }
        }
    }
    std::list<TPersona *>::iterator ipersona;
    for(ipersona = personas.begin(); ipersona != personas.end(); ipersona++)
    {
        (*ipersona)->persona->Evolucionar(temporizador->interval() / (velocidad_juego*10.0));
    }

    std::list<TEsfera *>::iterator iesfera;
    for(iesfera = esferas.begin(); iesfera != esferas.end(); iesfera++)
    {
        (*iesfera)->esfera->Evolucionar(temporizador->interval() / (velocidad_juego*10.0));
    }

    ControlColisiones();

    MostrarSliders();
    MostrarLabels();
    MostrarEscena();
}

void MainWindow::ControlColisiones(void)
{
    std::list<TEsfera *>::iterator iesfera;
    for(iesfera = esferas.begin(); iesfera != esferas.end(); iesfera++)
    {
       std::list<TEsfera *>::iterator iesfera2;
       for(iesfera2 = iesfera; iesfera2 != esferas.end(); iesfera2++)
       {
           if((*iesfera) != (*iesfera2))
           {
              float dx = (*iesfera)->esfera->Posicionx() - (*iesfera2)->esfera->Posicionx();
              float dy = (*iesfera)->esfera->Posiciony() - (*iesfera2)->esfera->Posiciony();

              if( qSqrt(dx*dx + dy*dy) <= (*iesfera)->esfera->Radio()+(*iesfera2)->esfera->Radio())
              {
                  if(qSqrt((*iesfera )->esfera->Velocidadx()*(*iesfera )->esfera->Velocidadx()+
                           (*iesfera )->esfera->Velocidady()*(*iesfera )->esfera->Velocidady()) >
                     qSqrt((*iesfera2)->esfera->Velocidadx()*(*iesfera2)->esfera->Velocidadx()+
                           (*iesfera2)->esfera->Velocidady()*(*iesfera2)->esfera->Velocidady()))
                  {
                     Colision((*iesfera)->esfera, (*iesfera2)->esfera);
                  }
                  else
                  {
                      if(qSqrt((*iesfera )->esfera->Velocidadx()*(*iesfera )->esfera->Velocidadx()+
                               (*iesfera )->esfera->Velocidady()*(*iesfera )->esfera->Velocidady()) <
                         qSqrt((*iesfera2)->esfera->Velocidadx()*(*iesfera2)->esfera->Velocidadx()+
                               (*iesfera2)->esfera->Velocidady()*(*iesfera2)->esfera->Velocidady()))
                      {
                      Colision((*iesfera2)->esfera, (*iesfera)->esfera);
                      }
                      else
                      {/*si v1==v2*/
                         (*iesfera )->esfera->Velocidad(-(*iesfera )->esfera->Velocidadx(),-(*iesfera )->esfera->Velocidady());
                         (*iesfera2)->esfera->Velocidad(-(*iesfera2)->esfera->Velocidadx(),-(*iesfera2)->esfera->Velocidady());
                      }
                  }
              }
           }
       }

       std::list<TCaja *>::iterator icaja;
       for(icaja=cajas.begin(); icaja != cajas.end(); icaja++)
       {
           float dx = abs((*iesfera)->esfera->Posicionx() - (*icaja)->caja->Posicionx());
           float dy = abs((*iesfera)->esfera->Posiciony() - (*icaja)->caja->Posiciony());
           if(dx<=((*iesfera)->esfera->Radio()+(*icaja)->caja->Lado()/2) && dy<=((*iesfera)->esfera->Radio()+((*icaja)->caja->Lado()/2)))
               Colision((*iesfera)->esfera,(*icaja)->caja);
       }
       std::list<TPersona *>::iterator ipersona;
       for(ipersona=personas.begin(); ipersona != personas.end(); ipersona++)
       {
           float dx = (*iesfera)->esfera->Posicionx() - (*ipersona)->persona->Posicionx();
           float dy = (*iesfera)->esfera->Posiciony() - (*ipersona)->persona->Posiciony();
           if(qSqrt(dx*dx+dy*dy)<=(*iesfera)->esfera->Radio()+DiametroPersona/2)
               Colision((*iesfera)->esfera,(*ipersona)->persona);
       }
    }
    std::list<TPersona *>::iterator ipersona;
    for(ipersona=personas.begin(); ipersona != personas.end(); ipersona++)
    {
        std::list<TCaja *>::iterator icaja;
        for(icaja=cajas.begin(); icaja != cajas.end(); icaja++)
        {
        float dx = (*icaja)->caja->Posicionx() - (*ipersona)->persona->Posicionx();
        float dy = (*icaja)->caja->Posiciony() - (*ipersona)->persona->Posiciony();
        if(abs(dx)<=((*icaja)->caja->Lado()/2+DiametroPersona/2)&& abs(dy)<=((*icaja)->caja->Lado()/2+DiametroPersona/2.0))
            Colision((*ipersona)->persona,(*icaja)->caja);
        }
    }

}

void MainWindow::Nitrox(void)
{
    esfera->Nitro(0);
}

void MainWindow::Nitroy(void)
{
    esfera->Nitro(1);
}

void MainWindow::Colision(CEsfera *chocante, CEsfera *receptor)
{
 float v_colision = qSqrt(chocante->Velocidadx()*chocante->Velocidadx()+chocante->Velocidady()*chocante->Velocidady()) ;
 float angulo_colision = qAcos(DiametroEsfera / v_colision);

         //SUPONIENDO QUE LAS BOLAS TIENEN LA MISMA MASA, MISMO RADIO Y QUE EL CHOQUE ES PERFECTAMENTE ELASTICO
 float v_final_chocante = v_colision*qSin(angulo_colision);

 chocante->Velocidad(v_final_chocante*qCos(90-angulo_colision), v_final_chocante*qSin(90-angulo_colision));

 float v_final_receptor = v_colision*qCos(angulo_colision);

 receptor->Velocidad(v_final_receptor*qCos(angulo_colision), v_final_receptor*qSin(angulo_colision));

}

//Evalua un choque entre esfera y caja
//Se asume que la caja es un objeto inmovil
void MainWindow::Colision(CEsfera *chocante, cCaja *receptor)
{
    float dx = chocante->Posicionx() - receptor->Posicionx();
    float dy = chocante->Posiciony() - receptor->Posiciony();
    if(abs(dx)<abs(dy))
        chocante->Velocidad(chocante->Velocidadx(),-chocante->Velocidady());
    else
        chocante->Velocidad(-chocante->Velocidadx(),chocante->Velocidady());

}
//Evalua un choque entre una persona y una esfera
//Se asume que la persona tiene una masa mucho mayor que la esfera y por tanto no se ve afectada por el choque
//Cuando una persona choca con una esfera la coge, dejando la anterior parada tras de si
//
// Bug: En caso de coger una esfera, la persona no podra volver a cogerla hasta que deposite una esfera en una caja

void MainWindow::Colision(CEsfera *chocante, cPersona *receptor)
{
    if(receptor->Lleva()!=chocante){

        //if(receptor->Color()==chocante->Color()){  //Posible comprobación de color para que solo se puedan coger las esferas de su color
        receptor->CogerEsfera(chocante);
        chocante->SetLlevada(true);

    /*}else{
         chocante->Velocidad((chocante->Velocidadx()+receptor->Velocidadx()),(chocante->Velocidady()+receptor->Velocidady()));*/
     }


}
//Evalua una colision entre una persona y una caja
//Se asume que la caja es un objeto inmovil
//Ademas de resolver la colision fisica, coge la esfera que lleva la persona (si lleva alguna) y la elimina de la lista de esferas
//
// Bug: el modelo fisico causa errores en caso de choques tangentes o si una esfera se origina aleatoriamente en el interior de una caja
void MainWindow::Colision(cPersona *chocante, cCaja *receptor){
    if(chocante->Lleva()!=NULL){
        receptor->EntraEsfera(chocante->Lleva());
        chocante->Lleva()->SetLlevada(false);
        std::list<TEsfera *>::iterator iesfera;
        for(iesfera = esferas.begin(); iesfera != esferas.end(); iesfera++){
            if((*iesfera)->esfera->Posicionx()==chocante->Lleva()->Posicionx()&&(*iesfera)->esfera->Posiciony()==chocante->Lleva()->Posiciony())
            {
                escena->removeItem((*iesfera)->elipse);
                esferas.erase(iesfera);
            }

        }
        chocante->CogerEsfera(new CEsfera());

    }
    float dx = chocante->Posicionx() - receptor->Posicionx();
    float dy = chocante->Posiciony() - receptor->Posiciony();
    if(abs(dx)<abs(dy))
        chocante->Velocidad(chocante->Velocidadx(),-chocante->Velocidady());
    else
        chocante->Velocidad(-chocante->Velocidadx(),chocante->Velocidady());

}


//SII: void MainWindow::Tiempo_juego(int t)
void MainWindow::Tiempo_juego(int t)
{
   velocidad_juego=100-t;
}

//Crea una nueva esfera con posicion, velocidad y aceleracion aleatorias
void MainWindow::NuevaEsfera(void)
{
#define MinX -100.0 //Ajustar
#define MaxX  100.0
#define MinY -100.0
#define MaxY  100.0
#define MinVX -100.0
#define MaxVX  100.0
#define MinVY -100.0
#define MaxVY  100.0
#define MinAX -100.0
#define MaxAX  100.0
#define MinAY -100.0
#define MaxAY  100.0
#define MaxRad 12.0
#define MinRad 5.0


    float px = MinX  + rand()*(MaxX  - MinX )/RAND_MAX,
          vx = MinVX + rand()*(MaxVX - MinVX)/RAND_MAX,
          ax = MinAX + rand()*(MaxAX - MinAX)/RAND_MAX,
          py = MinY  + rand()*(MaxY  - MinY )/RAND_MAX,
          vy = MinVY + rand()*(MaxVY - MinVY)/RAND_MAX,
          ay = MinAY + rand()*(MaxAY - MinAY)/RAND_MAX,
          rad= MinRad+ rand()*(MaxRad- MinRad)/RAND_MAX;
    int   color=(int)(rand()*4/RAND_MAX);

    if(color==1)color=0xFF0000;
    else if(color==2)color=0xFF00;
         else if(color==3)color=0xFF;
              else color=0xFFFFFF;

    TEsfera* nueva = new TEsfera;
    nueva->esfera = new CEsfera(px, vx, ax, py, vy, ay,rad,color);
    nueva->elipse = new QGraphicsEllipseItem();

    QBrush pincel=(QBrush(QColor(QRgb(nueva->esfera->Color()))));
    QPen   lapiz =(QPen(QColor(QRgb(0xFFFFFFFF-nueva->esfera->Color()))));
    lapiz.setWidth(1);

    nueva->elipse = escena->addEllipse(OrigenX-nueva->esfera->Radio(),OrigenY-nueva->esfera->Radio(),
                                       nueva->esfera->Radio()*2,nueva->esfera->Radio()*2,
                                       lapiz, pincel);
    esferas.push_back(nueva);
}


// Crea una nueva caja con posicion aleatoria.
void MainWindow::NuevaCaja(void){
#define MinX -100.0 //Ajustar
#define MaxX  100.0
#define MinY -100.0
#define MaxY  100.0

    float px = MinX  + rand()*(MaxX  - MinX )/RAND_MAX,
          py = MinY  + rand()*(MaxY  - MinY )/RAND_MAX;

    TCaja* nueva = new TCaja;
    nueva->caja = new cCaja(px,py,25,0xFFFFFF);
    nueva->rectangulo = new QGraphicsRectItem();
    QBrush pincel=(QBrush(QColor(QRgb(nueva->caja->Color()))));
    QPen   lapiz =(QPen(QColor(QRgb(0xFFFFFFFF-nueva->caja->Color()))));
    lapiz.setWidth(1);

    nueva->rectangulo = escena->addRect(OrigenX-nueva->caja->Lado()/2,OrigenY-nueva->caja->Lado()/2,
                                       nueva->caja->Lado(),nueva->caja->Lado(),
                                       lapiz, pincel);
    cajas.push_back(nueva);


}
//Crea una nueva persona, situada en el centro
void MainWindow::NuevaPersona(void)
{
    int color =0xFFFFFF;
    TPersona* nueva = new TPersona;
    nueva->persona = new cPersona();
    nueva->persona->SetColor(color);
    nueva->elipse = new QGraphicsEllipseItem();

    QBrush pincel=(QBrush(QColor(QRgb(color))));
    QPen   lapiz =(QPen(QColor(QRgb(0xFFFFFFFF-color))));
    lapiz.setWidth(2);

    nueva->elipse = escena->addEllipse(OrigenX-DiametroPersona/2,OrigenY-DiametroPersona/2,
                                       DiametroPersona,DiametroPersona,
                                       lapiz, pincel);
    personas.push_back(nueva);
}

void MainWindow::Nitro(void)
{
    std::list<TEsfera *>::iterator iesfera;
    for(iesfera = esferas.begin(); iesfera != esferas.end(); iesfera++)
    {
        float incv = -100+rand()*200.0/RAND_MAX;
        (*iesfera)->esfera->Velocidad((*iesfera)->esfera->Velocidadx() + incv,
                                      (*iesfera)->esfera->Velocidady() + incv);
    }

}



//Funciones para controlar a la persona
//En caso de usar mas de una persona se pueden añadir mas teclas de control

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    std::list<TPersona *>::iterator ipersona;
    ipersona=personas.begin();
    if(event->key()==Qt::Key_W)
        (*ipersona)->persona->Velocidad((*ipersona)->persona->Velocidadx(),100);
    if(event->key()==Qt::Key_S)
        (*ipersona)->persona->Velocidad((*ipersona)->persona->Velocidadx(),-100);
    if(event->key()==Qt::Key_D)
        (*ipersona)->persona->Velocidad(-100,(*ipersona)->persona->Velocidady());
    if(event->key()==Qt::Key_A)
        (*ipersona)->persona->Velocidad(100,(*ipersona)->persona->Velocidady());

}
void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    std::list<TPersona *>::iterator ipersona;
    ipersona=personas.begin();
    if(event->key()==Qt::Key_W)
        (*ipersona)->persona->Velocidad((*ipersona)->persona->Velocidadx(),0);
    if(event->key()==Qt::Key_S)
        (*ipersona)->persona->Velocidad((*ipersona)->persona->Velocidadx(),0);
    if(event->key()==Qt::Key_D)
        (*ipersona)->persona->Velocidad(0,(*ipersona)->persona->Velocidady());
    if(event->key()==Qt::Key_A)
        (*ipersona)->persona->Velocidad(0,(*ipersona)->persona->Velocidady());

}
