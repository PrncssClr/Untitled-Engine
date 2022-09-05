#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <vector>
#include <string>
#include "Utility.hpp"

class Drawable;
template<typename T>
struct Vector2D;

class Sprite : public Drawable{
public:
    Sprite() = delete;
    Sprite(std::string, Vector2D<double>, Vector2D<int>);
    Sprite(SDL_Texture*,Vector2D<double>, Vector2D<int>);
    Sprite(std::string);
    Sprite(SDL_Texture*);


public:

    Drawable* Parent = nullptr;

    virtual bool OnUpdate(){return true;}    

};


#endif

