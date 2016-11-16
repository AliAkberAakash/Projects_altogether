#include"SDL2/SDL.H"
#include<stdio.h>

const int SCREEN_WIDTH=640;
const int SCREEN_HEIGHT=480;

int main(int argc, char* argv[])
{
    SDL_Window* window=NULL;
    SDL_Surface* ScreenSurface=NULL;

    if(SDL_Init(SDL_INIT_VIDEO)<0)
        printf("SDL Couldn't Initialize\nSDL Error: %s", SDL_GetError());

    window=SDL_CreateWindow("My name is Aakash",
                            SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,
                            SCREEN_WIDTH,
                            SCREEN_HEIGHT,
                            SDL_WINDOW_SHOWN
                            );

    if(window==NULL)
    {
     printf("SDL Couldn't Initialize\nSDL Error: %s", SDL_GetError());
    }

    else
    {
        ScreenSurface=SDL_GetWindowSurface(window);

        SDL_FillRect(ScreenSurface, NULL, SDL_MapRGB(ScreenSurface->format, 0xFF, 0xFF, 0xFF));

        SDL_UpdateWindowSurface(window);

        SDL_Delay(5000);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
