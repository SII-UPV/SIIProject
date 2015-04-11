#ifndef CESFERA_H
#define CESFERA_H

class CEsfera
{
    float px, py;
    float vx, vy;
    float ax, ay;
    float radio;
    int color;   //Formato RGB:0xFF FF FF

    bool llevada;

public:
    CEsfera();
    CEsfera(float _px, float _vx, float _ax, float _py, float _vy, float _ay);
    CEsfera(float _px, float _vx, float _ax, float _py, float _vy, float _ay, float _radio, int _color);

    void Posicion   (float _px, float _py);
    void Velocidad  (float _vx, float _vy);
    void Aceleracion(float _ax, float _ay);
    void SetRadio   (float _radio);
    void SetColor   (int _color);
    void SetLlevada (bool _llevada);

    float Posicionx   (void);
    float Velocidadx  (void);
    float Aceleracionx(void);
    float Posiciony   (void);
    float Velocidady  (void);
    float Aceleraciony(void);

    float Radio       (void);
    int   Color       (void);
    bool  esLlevada   (void);


    void Evolucionar(float _t);
    void Nitro      (int eje);
};

#endif // CESFERA_H
