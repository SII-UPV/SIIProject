#ifndef CESFERA_H
#define CESFERA_H

class CEsfera
{
    float p;
    float v;
    float a;
public:
    CEsfera();
    CEsfera(float _p, float _v, float _a);

    void Posicion   (float _p);
    void Velocidad  (float _v);
    void Aceleracion(float _a);

    float Posicion   (void);
    float Velocidad  (void);
    float Aceleracion(void);

    void Evolucionar(float _t);
};

#endif // CESFERA_H
