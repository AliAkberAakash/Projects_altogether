#ifndef INITIALIZE_H_INCLUDED
#define INITIALIZE_H_INCLUDED
#define pos SDL_WINDOWPOS_CENTERED

using namespace std;

const int sw=642, sh=642;

bool initialize(SDL_Window* window, SDL_Surface* surface)
{
    bool success = true;

    SDL_Init( SDL_INIT_EVERYTHING );
    window=SDL_CreateWindow("Super chess", pos, pos, sw, sh, SDL_WINDOW_SHOWN);
    if(window==NULL)
        success = false;
    IMG_Init( IMG_INIT_PNG );

    surface=SDL_GetWindowSurface(window);
    if(surface==NULL)
        success=false;
    return success;
}

void close()
{
    IMG_Quit();
    SDL_Quit();
}

#endif // INITIALIZE_H_INCLUDED
