/*
*
* Program Name: Sample image Using Functions
* Details:
* Solved By: Liverwort
* Date: 1.7.2016
*
*/

#include<SDL2/SDL.H>
#include<iostream>
#define pos SDL_WINDOWPOS_CENTERED

using namespace std;

const int sw=640, sh=640;

SDL_Window* chessBoard=NULL;
SDL_Surface* screenSurface=NULL;
SDL_Surface* imageSurface=NULL;
SDL_Event event;

bool init();
bool loadMedia();
void close();

bool init()
{
    bool success= true;

    if(SDL_Init(SDL_INIT_VIDEO)<0)
        {
            cout<<"ERROR!!"<<SDL_GetError()<<endl;
            success= false;
        }
    else
        {
            chessBoard=SDL_CreateWindow("Super Chess", pos, pos, sw, sh, SDL_WINDOW_SHOWN);
            if(chessBoard==NULL)
                {
                    cout<<"ERROR"<<SDL_GetError()<<endl;
                    success==false;
                }
            else
            {
                screenSurface=SDL_GetWindowSurface(chessBoard);
            }

        }

    return success;

}

bool loadMedia()
{
    bool success= true;

    imageSurface=SDL_LoadBMP("chessBoard.bmp");
    if(imageSurface==NULL)
    {
        cout<<"ERROR!!!"<<SDL_GetError()<<endl;
        success=false;
    }

    return success;
}

void keepWindowOpen()
{
    bool running= true;



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

void close()
{
    SDL_FreeSurface(screenSurface);
    SDL_FreeSurface(imageSurface);
    SDL_DestroyWindow(chessBoard);
    SDL_Quit();
}

int main(int argc, char* argv[])
{
    if(!init())
    {
        cout<<"Failed to Initialize"<<endl;
    }
    else
    {
        if(!loadMedia())
        {
            cout<<"Failed to load image"<<endl;
        }
        else
        {

            SDL_BlitSurface(imageSurface, NULL, screenSurface, NULL);

            SDL_UpdateWindowSurface(chessBoard);

            keepWindowOpen();
        }
    }

    close();

    return 0;
}
