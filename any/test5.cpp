#include<SDL2/SDL.H>
#include<iostream>

#define pos SDL_WINDOWPOS_CENTERED

const int sw=640;
const int sh=480;

//SDL_Window *d=NULL;

void keepWindowOpen()
{
        bool running= true;

    SDL_Event event;

    while(running)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type==SDL_QUIT)
            {
                running= false;
                break;
            }
        }
    }
}

void createWindow(SDL_Window* window)
{
    using namespace std;

        char* title="Chess Board";

    SDL_Init(SDL_INIT_EVERYTHING);
    window= SDL_CreateWindow( title, pos,pos, sw, sh, SDL_WINDOW_SHOWN);

    if(window==NULL)
        cout<<"ERROR"<<SDL_GetError<<endl;
}

void windowSurface(SDL_Window* window, SDL_Surface* windowSurface)
{
    windowSurface=SDL_GetWindowSurface(window);
}

void windowColor(SDL_Window* window, SDL_Surface* windowSurface)
{
    Uint32 color = SDL_MapRGB(windowSurface-> format, 0, 0, 0);

    SDL_FillRect(windowSurface, NULL, SDL_MapRGB(windowSurface-> format, 0, 0, 0));

    SDL_UpdateWindowSurface(window);
}


int main(int argc, char* argv[])
{
    SDL_Window* d=NULL;
    SDL_Surface* e=NULL;

    createWindow(d);

    windowSurface(d,e);

    //windowColor(d,e);

    keepWindowOpen();

    SDL_DestroyWindow(d);
    SDL_Quit();
}
