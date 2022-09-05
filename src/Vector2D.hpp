#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <math.h>
#include <vector>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

template<typename T>
struct Vector2D{
    Vector2D() = default;
    Vector2D(T _x, T _y):x(_x),y(_y){};
    T x = 0, y = 0;
    
    Vector2D operator+(const Vector2D& _r){return {_r.x+this->x, _r.y+this->y};}
    void operator+=(const Vector2D& _r){this->x+=_r.x;this->y+=_r.y;}
    Vector2D operator-(const Vector2D& _r){return {this->x-_r.x,this->y-_r.y};}
    void operator-=(const Vector2D& _r){this->x-=_r.x;this->y-=_r.y;}
    Vector2D operator/(const T _r){if(_r==0)return *this; return {this->x/_r, this->y/_r};}
    void operator/=(const T _r){if(_r==0)return;this->x/=_r;this->y/=_r;}
    Vector2D operator*(const T _r){return {this->x*_r,this->y*_r};}
    void operator*=(const T _r){this->x*=_r;this->y*=_r;}
    bool operator==(const Vector2D& _r){return this->x==_r.x&&this->y==_r.y;}
    bool operator!=(const Vector2D& _r){return !(*this==_r);}
    
    double magnitude(){
        return sqrt(x*x+y*y);
    }

    Vector2D norm(){
        if(magnitude()==0)return{0,0};
        return Vector2D(this->x,this->y)/magnitude();
    }

    double dir(){
        if(*this==Vector2D(0,0))return 0;
        double a = atan2(this->x,-(this->y))*(180./M_PI);
        return a;
    }



};

class Drawable{
public:
    Drawable* Parent = nullptr;
    std::vector<Drawable*> Children = {};
    void AddChild(Drawable* _child);

    void SetTexture(std::string _texName);
    void SetTexture(SDL_Texture* _tex);
    SDL_Texture* GetTexture(){return Texture;}

    void SetPosition(Vector2D<double>);
    Vector2D<double> GetPosition();

    void SetAngle(double);
    double GetAngle();

    void SetSize(Vector2D<int>);
    Vector2D<int> GetSize();

    void SetAnchor(Vector2D<double>);
    Vector2D<double> GetAnchor();

    void SetAlpha(double);
    double GetAlpha();

    void Draw();
    bool Update();

    void SetVisible(bool);
    bool GetVisible();
    int ZOrder = 0;
    uint64_t FrameCounter = 0;

    SDL_Rect* Rect(){return new SDL_Rect({
        static_cast<int>(Parent->Position.x+Position.x-AnchorPoint.x*Size.x), 
        static_cast<int>(Parent->Position.y+Position.y-AnchorPoint.y*Size.y), 
        Size.x, 
        Size.y});}
protected:
    double Scale = 1.f;
    Vector2D<double> Position = {0,0};
    Vector2D<int> Size = {1,1};
    Vector2D<double> AnchorPoint = {0.,0.};
    double Alpha = 1.;

    SDL_Texture* Texture = nullptr;
    bool Visible = true;
    double Angle = 0.f;


    virtual bool OnUpdate()=0;

};

#endif