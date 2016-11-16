
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

     SDL_Surface* windowSurface=NULL;

     windowSurface=SDL_GetWindowSurface(Chessboard);

    int R=0,G=0,B=0,i;

     for(i=0; i<256; i++)
     {
     Uint32 color1= SDL_MapRGB(windowSurface-> format, R, G, B);

     SDL_FillRect(windowSurface, NULL, color1);

     SDL_UpdateWindowSurface( Chessboard );

     SDL_Delay(10);
     //change color

     R++; G++; B++;

     }



    SDL_Event event;

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
