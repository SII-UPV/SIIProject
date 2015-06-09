
/******************************************************************
 ******************************************************************
 *                                                                *
 * GamepadInfo Class                                              *
 *                                                                *
 * This Class Handles the full list of Gamepads and holds the     *
 *  information of all the current gamepads.                      *
 *                                                                *
 * It works with the Gamepad Class                                *
 *                                                                *
 *                                                                *
 ******************************************************************
 ******************************************************************
 */

#include "gamepadinfo.h"

/* When creating a new GamepadInfo object, the SDL subsystems needed are initialized
 * It also creates a list of all the currently connected gamepads, creating a new
 *  Gamepad object for each of them.
 *
 */
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

/* The toString Function returns a string that contains the names asigned to each of the connected pads
 *
 */
QString GamepadInfo::toString(void){
    QString result="Pads:\n ";

    if(availablePads()==0)return "No pad";
    for(int i=0;i<availablePads();i++){
        result += QString(SDL_JoystickName(i))+"\n";
    }
    return result;
}


// This function returns the number of available gamepads

int GamepadInfo::availablePads(){
    return SDL_NumJoysticks();
}


/* The getActive() Functions retunrs the first Gamepad object from the list that complies the following requirements:
 *
 *      -It is not currently marked as active.
 *      -The button (Button1 by default) is pressed
 *
 */
Gamepad* GamepadInfo::getActive(int button){

    for(int i=0; i<Gamepads->length();i++){
        if(!Gamepads->at(i)->isActive()){
            TState state = Gamepads->at(i)->getState();
            switch(button){
                case 1:
                    if(state.button1){
                        //Gamepads->at(i)->setActive(true);
                        return Gamepads->at(i);
                    }
                case 2:
                    if(state.button2){
                        //Gamepads->at(i)->setActive(true);
                        return Gamepads->at(i);
                    }
                case 3:
                    if(state.button3){
                        //Gamepads->at(i)->setActive(true);
                        return Gamepads->at(i);
                    }
                case 4:
                    if(state.button4){
                        //Gamepads->at(i)->setActive(true);
                        return Gamepads->at(i);
                    }
            }
        }
    }
    return NULL;
}

// The Update function udpates the data from the Gamepads and clears the event .

void GamepadInfo::update(){
    SDL_JoystickUpdate();

    SDL_Event event;
    while (SDL_PollEvent(&event)) {}   // Free the event poll and refresh data on the gamepads
}
