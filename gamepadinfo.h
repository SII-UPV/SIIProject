#ifndef GAMEPADINFO_H
#define GAMEPADINFO_H
#include <QString>
#include <QList>

#include <QObject>
#include <QList>
#include <SDL.h>
#include <SDL_events.h>

#include "gamepad.h"

class GamepadInfo
{
public:
    GamepadInfo();
    ~GamepadInfo();
    QString toString();
    int availablePads();
    Gamepad* getActive();
    void update();
    QList<Gamepad *>* Gamepads;

private:
};

#endif // GAMEPADINFO_H
