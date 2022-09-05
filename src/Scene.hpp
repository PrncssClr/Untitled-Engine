#ifndef SCENE_H
#define SCENE_H
#include <SDL2/SDL.h> 
#include <vector>
#include "Sprite.hpp"

class App;
// class Sprite;
class Scene : public Drawable{
public:
    Scene();

    SDL_Renderer* renderer();

    virtual bool OnUpdate();
    virtual bool SDraw();

private:
    SDL_Renderer* _renderer = nullptr;
};

#endif