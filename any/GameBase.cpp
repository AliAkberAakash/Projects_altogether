/*
*
* Program Name:
* Details:
* Solved By: Liverwort
* Date:
*
*/

#include<SDL2/SDL.H>
#include<iostream>

#define pos SDL_WINDOWPOS_CENTERED

void keepWindowOpen();

const int sw=640;
const int sh=480;

int main(int argc, char* argv[])
{
    using namespace std;

    SDL_Window* chessBoard=NULL;
    SDL_Surface* windowSurface=NULL;

    char *title="Chess Board";

    SDL_Init(SDL_INIT_EVERYTHING);
    chessBoard= SDL_CreateWindow( title, pos,pos, sw, sh, SDL_WINDOW_SHOWN);

    if(chessBoard==NULL)
        cout<<"ERROR"<<SDL_GetError<<endl;

    windowSurface=SDL_GetWindowSurface(chessBoard);

    Uint32 color = SDL_MapRGB(windowSurface-> format, 255, 255, 255);

    SDL_FillRect(windowSurface, NULL, color);

    SDL_UpdateWindowSurface(chessBoard);

    keepWindowOpen();

    SDL_DestroyWindow(chessBoard);
    SDL_Quit();

    return 0;
}


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
