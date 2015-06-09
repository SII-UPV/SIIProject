#include "gamepad.h"


Gamepad::Gamepad()
{
}
Gamepad::Gamepad(SDL_Joystick* _joystick, QString _name){
    joystick = _joystick;
    name     = _name;
    active   = false;
    State    = new TState;
    if(name.contains("XBOX",Qt::CaseInsensitive)){
        tipo = XBOX;
    }else if(name.contains("PS3",Qt::CaseInsensitive)||name.contains("MotioninJoy",Qt::CaseInsensitive)){
        tipo = PS3;
    }
        else tipo = OTHER;

}

Gamepad::~Gamepad()
{
}
TState Gamepad::getState(){

    SDL_JoystickUpdate();
    if(tipo==PS3){
        State->button1=SDL_JoystickGetButton(joystick,2);
        State->button2=SDL_JoystickGetButton(joystick,1);
        State->button3=SDL_JoystickGetButton(joystick,3);
        State->button4=SDL_JoystickGetButton(joystick,0);

        State->joy2.x =SDL_JoystickGetAxis(joystick,2);
        State->joy2.y =SDL_JoystickGetAxis(joystick,3);

    }else{
        State->button1=SDL_JoystickGetButton(joystick,0);
        State->button2=SDL_JoystickGetButton(joystick,1);
        State->button3=SDL_JoystickGetButton(joystick,2);
        State->button4=SDL_JoystickGetButton(joystick,3);

        State->joy2.x =SDL_JoystickGetAxis(joystick,4);
        State->joy2.y =SDL_JoystickGetAxis(joystick,3);

    }
    State->joy1.x =SDL_JoystickGetAxis(joystick,0);
    State->joy1.y =SDL_JoystickGetAxis(joystick,1);


    return *State;
}
bool Gamepad::isActive(){
    return active;
}
void Gamepad::setActive(bool _active){
    active=_active;
}
QString Gamepad::getName(){
    return name;
}

QString Gamepad::getButtonIcon(int button){
    if(tipo==PS3){
        switch(button){
            case 4: return ":/images/PS3/Images/PS3/Triangle.jpg" ;
            case 2: return ":/images/PS3/Images/PS3/Circle.jpg" ;
            case 1: return ":/images/PS3/Images/PS3/cross.jpg" ;
            case 3: return ":/images/PS3/Images/PS3/Square.jpg" ;
            default: return "";
        }
    }
    else{
        switch(button){
            case 1: return ":/images/xBox/Images/xBox/A.jpg" ;
            case 2: return ":/images/xBox/Images/xBox/B.jpg" ;
            case 3: return ":/images/xBox/Images/xBox/X.jpg" ;
            case 4: return ":/images/xBox/Images/xBox/Y.jpg" ;
            default: return "";
        }
    }
}

void Gamepad::close(){
    SDL_JoystickClose(joystick);
}
