#include "App.hpp"
#include <iostream>

class Scene;

SDL_Window* App::_Window = nullptr;
SDL_Renderer* App::_Renderer = nullptr;
char App::_Input = 0x0;
uint64_t App::_FrameCount = 0;
double App::_dTime = 0;
std::chrono::steady_clock::time_point App::_Clock = std::chrono::steady_clock::now();
Scene* App::_Scene = nullptr;

Scene* App::Get_Scene(){return App::_Scene;}
void App::Set_Scene(Scene* _scn){App::_Scene = _scn;}

SDL_Window* App::Window(){return App::_Window;}
SDL_Renderer* App::Renderer(){return App::_Renderer;}

bool App::Up(){return App::_Input&App::_Up;}
bool App::Left(){return App::_Input&App::_Left;}
bool App::Down(){return App::_Input&App::_Down;}
bool App::Right(){return App::_Input&App::_Right;}
bool App::Switch(){return App::_Input&App::_Switch;}
bool App::Pause(){return App::_Input&App::_Pause;}
bool App::Click(){return App::_Input&App::_Click;}

bool App::Set_Window(SDL_Window* _win){
    App::_Window = _win;
    return true;    
}
bool App::Set_Renderer(SDL_Renderer* _rnd){
    App::_Renderer = _rnd;
    return true;
}

bool App::Process_Input(){
    App::_Input &= ~(App::_Switch | App::_Pause | App::_Click);

    SDL_Event e;

    while(SDL_PollEvent(&e)){

        switch(e.type){
            case SDL_KEYDOWN:            
                switch(e.key.keysym.sym){
                    case SDLK_UP:
                    case SDLK_w:
                        App::_Input |= App::_Up;
                        break;

                    case SDLK_LEFT:
                    case SDLK_a:
                        App::_Input |= App::_Left;
                        break;
                    
                    case SDLK_DOWN:
                    case SDLK_s:
                        App::_Input |= App::_Down;
                        break;

                    case SDLK_RIGHT:
                    case SDLK_d:
                        App::_Input |= App::_Right;
                        break;

                    case SDLK_SPACE:
                        App::_Input |= App::_Switch;
                        break;

                    case SDLK_p:
                    case SDLK_RETURN:
                        App::_Input |= App::_Pause;
                        break;

                    default:
                        break;
                }
                break;

            case SDL_KEYUP:            
                switch(e.key.keysym.sym){
                    case SDLK_UP:
                    case SDLK_w:
                        App::_Input &= ~App::_Up;
                        break;

                    case SDLK_LEFT:
                    case SDLK_a:
                        App::_Input &= ~App::_Left;
                        break;
                    
                    case SDLK_DOWN:
                    case SDLK_s:
                        App::_Input &= ~App::_Down;
                        break;

                    case SDLK_RIGHT:
                    case SDLK_d:
                        App::_Input &= ~App::_Right;
                        break;

                    default:
                        break;
                }
                break;

            case SDL_MOUSEBUTTONDOWN:
                if (e.button.button == SDL_BUTTON_LEFT){
                    App::_Input |= App::_Click;
                }
                break;

            case SDL_QUIT:
                SDL_Quit();
                return false;
                
            default:
                break;
        }
    }
    return true;
}

bool App::Update(){
    App::_dTime = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-App::_Clock).count())/1000.0f;
    App::_Clock = std::chrono::steady_clock::now();
    App::Get_Scene()->Update();
    _FrameCount++;
    return true;
}

bool App::Draw(){
    SDL_SetRenderDrawColor(App::Renderer(),0x80,0xff,0x0,0xff);
    SDL_RenderClear(App::Renderer());
    App::Get_Scene()->SDraw();
    SDL_RenderPresent(App::Renderer());
    return true;
}

