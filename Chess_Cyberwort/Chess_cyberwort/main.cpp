#include <SDL2/SDL.h>
#include <iostream>
int main(int argc, char *argv[]){ //main er vitor parameter gula hubuhu emon dite hobe
    SDL_Init( SDL_INIT_EVERYTHING );
    SDL_Window *window;
    window = SDL_CreateWindow( "Chess by Cyberwort" ,//title
                              SDL_WINDOWPOS_UNDEFINED, //x position of window
                              SDL_WINDOWPOS_UNDEFINED, // y pos
                              600, // width
                              400, //height
                              SDL_WINDOW_OPENGL
                              );
    if ( window == NULL ){
        std::cout << "Yahoo error!\n" << SDL_GetError() << std::endl; //yahoo
    }
    SDL_Delay(5000); //delay in mili sec!!

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
