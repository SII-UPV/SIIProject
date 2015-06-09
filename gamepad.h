#ifndef GAMEPAD_H
#define GAMEPAD_H

#include <SDL.h>
#include <QDebug>
#include <QString>

#define JoyMax 32768
#define DeadZone 10         //DeadZone Expressed in %


typedef struct{int x;
               int y;     }TJoy;

typedef struct{bool button1;
               bool button2;
               bool button3;
               bool button4;
               TJoy joy1;
               TJoy joy2;    }TState;

typedef enum{XBOX,PS3,OTHER}EnumType;

class Gamepad
{
public:
    Gamepad();
    Gamepad(SDL_Joystick* _joystick, QString _name);
    ~Gamepad();
    bool isActive();
    void setActive(bool _active);
    TState getState();
    QString getButtonIcon(int button);
    QString getName();

    void close();
private:
    SDL_Joystick* joystick;
    TState* State;
    bool active;
    QString name;
    EnumType tipo;
};

#endif // GAMEPAD_H
