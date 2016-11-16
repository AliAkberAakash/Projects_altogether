#include<SDL2/SDL.h>
#include<iostream>

#define pos SDL_WINDOWPOS_CENTERED

const int sw=640;
const int sh=480;

int main(int argc, char* argv[])
{
    using namespace std;

    char* title="Super Chess";

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* Chessboard= SDL_CreateWindow(title, pos, pos, sw, sh, SDL_WINDOW_SHOWN);

    if(Chessboard==NULL)
        cout<<"Error!!!"<<SDL_GetError()<<endl;

    SDL_Event event;

    //SDL_Event *pass=&event;

    bool running =true;

    while(running)
    {
        while(SDL_PollEvent(&event))
            if(event.type== SDL_QUIT)
        {
            running=false;
            break;
        }
    }

    SDL_DestroyWindow(Chessboard);

    SDL_Quit();

    return 0;
}
