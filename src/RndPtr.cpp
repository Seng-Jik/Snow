#include "Snow/RndPtr.h"
#include "Snow/Activity.h"
#include <stack>

using namespace Snow;
using namespace std;

namespace Snow{
    RndPtr pRnd;
    Activity* nowFocus;
    Activity* nextFocus;
    stack<Activity*> actStack;
    bool jumpDraw = false;
}


void RndPtr::Create(const std::string& title,const bool FullScreen,const int w,const int h)
{
    m_fps = 0;
    if(FullScreen){
        if(w == -1)   m_wnd = SDL_CreateWindow("",
                            SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,
                            0,0,
                            SDL_WINDOW_FULLSCREEN_DESKTOP |
                            SDL_WINDOW_OPENGL);
        else m_wnd = SDL_CreateWindow("",
                            SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,
                            w,h,
                            SDL_WINDOW_FULLSCREEN |
                            SDL_WINDOW_OPENGL);
    }else{
        m_wnd = SDL_CreateWindow(title.c_str(),
                            SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,
                            w,h,
                            SDL_WINDOW_OPENGL);
    }
    m_rnd = SDL_CreateRenderer(m_wnd,-1,
                            SDL_RENDERER_ACCELERATED|
                            SDL_RENDERER_PRESENTVSYNC|
                            SDL_RENDERER_TARGETTEXTURE);
    SDL_SetRenderTarget(pRnd,nullptr);
    SDL_RenderPresent(m_rnd);
    SDL_GetWindowSize(m_wnd,&m_w,&m_h);
}

void RndPtr::Destory(){
    SDL_DestroyRenderer(m_rnd);
    SDL_DestroyWindow(m_wnd);
}

SDL_Texture* RndPtr::GetRenderTarget(){
    return SDL_GetRenderTarget(pRnd);
}

bool RndPtr::RenderTargetSupported(){
    return SDL_RenderTargetSupported(pRnd);
}

int RndPtr::GetH()
{
    return nowFocus -> m_logic_h;
}

int RndPtr::GetW()
{
    return nowFocus -> m_logic_w;
}

