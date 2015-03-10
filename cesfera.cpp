#include "cesfera.h"

CEsfera::CEsfera()
{
p = v = a = 0.0;
}

CEsfera::CEsfera(float _p, float _v, float _a)
{
p = _p;
v = _v;
a = _a;
}

void CEsfera::Posicion(float _p)
{
p = _p;
}

void CEsfera::Velocidad(float _v)
{
v = _v;
}

void CEsfera::Aceleracion(float _a)
{
a = _a;
}

float CEsfera::Posicion(void)
{
return p;
}

float CEsfera::Velocidad(void)
{
return v;
}

float CEsfera::Aceleracion(void)
{
return a;
}

void CEsfera::Evolucionar(float _t)
{
v += a * _t;
p += v * _t;
}
