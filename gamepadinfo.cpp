#include "gamepadinfo.h"

GamepadInfo::GamepadInfo()
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
    SDL_JoystickEventState(SDL_ENABLE);

    Gamepads = new QList<Gamepad *>;
    for(int i=0;i<availablePads();i++){
        Gamepads->append(new Gamepad(SDL_JoystickOpen(i),SDL_JoystickName(i)));
    }
}

GamepadInfo::~GamepadInfo()
{
    for(int i=0;i<availablePads();i++){
        Gamepads->at(i)->close();
    }
    SDL_QuitSubSystem(SDL_INIT_JOYSTICK);
}

QString GamepadInfo::toString(void){
    QString result="Pads:\n ";

    if(availablePads()==0)return "No pad";
    for(int i=0;i<availablePads();i++){
        result += QString(SDL_JoystickName(i))+"\n";
    }
    return result;
}

int GamepadInfo::availablePads(){
    return SDL_NumJoysticks();
}

Gamepad* GamepadInfo::getActive(){

    for(int i=0; i<Gamepads->length();i++){
        if(!Gamepads->at(i)->isActive()){
            TState state = Gamepads->at(i)->getState();

            if(state.button1){
                Gamepads->at(i)->setActive(true);
                return Gamepads->at(i);
            }
        }
    }
    return NULL;
}
void GamepadInfo::update(){
    SDL_JoystickUpdate();

    SDL_Event event;
    while (SDL_PollEvent(&event)) {}   // Free the event poll and refresh data on the gamepads
}
