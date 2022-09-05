#ifndef APP_H
#define APP_H

#include <SDL2/SDL.h>
#include <chrono>


#include "Scene.hpp"

class App{
public:
    static Scene* Get_Scene();
    static void Set_Scene(Scene*);
private:
    static Scene* _Scene;
public:
    static SDL_Window* Window();
    static SDL_Renderer* Renderer();
    static bool Up();
    static bool Left();
    static bool Down();
    static bool Right();
    static bool Switch();
    static bool Pause();
    static bool Click();

public:
    static bool Set_Window(SDL_Window*);
    static bool Set_Renderer(SDL_Renderer*);
public:
    static bool Process_Input();
    static bool Update();
    static bool Draw();
public:

private:
    static const char _Up = 0x1<<0;
    static const char _Left = 0x1<<1;
    static const char _Down = 0x1<<2;
    static const char _Right = 0x1<<3;
    static const char _Switch = 0x1<<4;
    static const char _Pause = 0x1<<5;
    static const char _Click = 0x1<<6;

private:
    static SDL_Window* _Window;
    static SDL_Renderer* _Renderer;
    static char _Input;
    static uint64_t _FrameCount;
    static double _dTime;
    static std::chrono::steady_clock::time_point _Clock;


};

#endif