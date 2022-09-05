#include "Scene.hpp"
#include "App.hpp"
#include <iostream>
Scene::Scene(){
    this->_renderer = App::Renderer();
}

SDL_Renderer* Scene::renderer(){return _renderer;}

bool Scene::OnUpdate(){
    return true;
}

bool Scene::SDraw(){
    SDL_SetRenderDrawColor(App::Renderer(),0x00,0x00,0x00,0xff);
    // if(App::Up())   SDL_SetRenderDrawColor(App::Renderer(),0xff,0,0,0xff);
    // if(App::Left()) SDL_SetRenderDrawColor(App::Renderer(),0,0xff,0,0xff);
    // if(App::Down()) SDL_SetRenderDrawColor(App::Renderer(),0,0,0xff,0xff);
    // if(App::Right())SDL_SetRenderDrawColor(App::Renderer(),0xff,0xff,0,0xff);    
    
    SDL_RenderClear(App::Renderer());
    for (auto &&_child : Children)
    {
        _child->Draw();
    }
    
    SDL_RenderPresent(App::Renderer());
    return true;

}