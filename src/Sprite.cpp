#include "App.hpp"
#include "Sprite.hpp"

#include <SDL2/SDL_image.h>

Sprite::Sprite(std::string _texName){
    Position = {0,0};
    SetTexture(_texName);
    SDL_QueryTexture(Texture, NULL, NULL, &Size.x, &Size.y);
}

Sprite::Sprite(SDL_Texture* _tex){
    Position={0,0};
    SetTexture(_tex);
    SDL_QueryTexture(Texture, NULL, NULL, &Size.x, &Size.y);
}

Sprite::Sprite(std::string _texName, Vector2D<double> _pos, Vector2D<int> _size){
    Position=_pos; 
    Size=_size;
    SetTexture(_texName);
    }

Sprite::Sprite(SDL_Texture* _tex, Vector2D<double> _pos, Vector2D<int> _size){
    Position=_pos; 
    Size=_size;
    SetTexture(_tex);
    }

