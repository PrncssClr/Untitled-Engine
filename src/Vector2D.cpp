#include "App.hpp"
#include "Vector2D.hpp"

void Drawable::AddChild(Drawable* _child){
        Children.push_back(_child);
        _child->Parent = this;
    }
void Drawable::SetTexture(std::string _texName){
        SDL_Surface* img = IMG_Load(_texName.c_str());
        this->Texture = SDL_CreateTextureFromSurface(App::Renderer(), img);
        SDL_FreeSurface(img);
    }
void Drawable::SetTexture(SDL_Texture* _tex){
        this->Texture = _tex;
    }
void Drawable::Draw(){
    if(Visible){
        SDL_SetTextureAlphaMod(Texture,static_cast<Uint8>(GetAlpha()*0xff));
        SDL_Point _a = {static_cast<int>(Size.x * AnchorPoint.x), static_cast<int>(Size.y * AnchorPoint.y)};
        SDL_RenderCopyEx(App::Renderer(), Texture, NULL, Rect(), Angle, &_a, SDL_FLIP_NONE);
        for (auto &&_child : Children)
        {
            _child->Draw();
        }
    }
}

bool Drawable::Update(){
        bool _update = OnUpdate();
        for (auto &&_child : Children)
        {
            _update &= _child->Update();
        }
        FrameCounter++;
        return _update;
    }
void Drawable::SetPosition(Vector2D<double> _p){Position = _p;}
Vector2D<double> Drawable::GetPosition(){return Position;}

void Drawable::SetAngle(double _a){Angle = _a;}
double Drawable::GetAngle(){return Angle;}

void Drawable::SetAnchor(Vector2D<double> _p){AnchorPoint = _p;}
Vector2D<double> Drawable::GetAnchor(){return AnchorPoint;}

void Drawable::SetSize(Vector2D<int> _s){Size = _s;}
Vector2D<int> Drawable::GetSize(){return Size;}

void Drawable::SetVisible(bool _v){Visible = _v;}
bool Drawable::GetVisible()       {return Visible;}

void Drawable::SetAlpha(double _a){Alpha = _a;}
double Drawable::GetAlpha(){return Alpha*(Parent?Parent->GetAlpha():1.);}