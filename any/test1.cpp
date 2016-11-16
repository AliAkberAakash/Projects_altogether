#include<SDL2/SDL.H>
#include<iostream>

const int sw = 1080;
const int sh = 600;

int main(int argc, char* argv[])
{
    using namespace std;

    char* title="SUPER CHESS!!!";

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* ChessBoard;

    ChessBoard=SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, sw, sh, SDL_WINDOW_SHOWN);

    if(ChessBoard==NULL)
        cout<<"Error!!!"<<SDL_GetError()<<endl;

    SDL_Delay(5000);

    SDL_DestroyWindow(ChessBoard);

    SDL_Quit();

}
