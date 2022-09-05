#include "Button.hpp"
#include "App.hpp"
#include <stdio.h>
Button::Button(std::string _texName) : Sprite(_texName){}

bool Button::OnUpdate(){
    if(App::Click() && IsActive){
        SDL_Point* _p = new SDL_Point();
        SDL_GetMouseState(&(_p->x), &(_p->y));

        if(SDL_PointInRect(_p, Rect())){
            OnPress();
        }
        delete _p;
    }
    return true;
}