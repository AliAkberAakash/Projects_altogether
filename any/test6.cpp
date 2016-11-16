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
    SDL_Surface* image;

    char *title="Chess Board";

    SDL_Init(SDL_INIT_EVERYTHING);
    chessBoard= SDL_CreateWindow( title, pos,pos, sw, sh, SDL_WINDOW_SHOWN);

    if(chessBoard==NULL)
        cout<<"ERROR"<<SDL_GetError<<endl;

    windowSurface=SDL_GetWindowSurface(chessBoard);

    Uint32 color = SDL_MapRGB(windowSurface-> format, 0, 0, 0);

    SDL_FillRect(windowSurface, NULL, color);

    SDL_UpdateWindowSurface(chessBoard);

    //loading an image

    image= SDL_LoadBMP("hello_world.bmp");

    if( chessBoard == NULL )
	{
		cout<<"Unable to load image %s! SDL Error: %s\n"<<
         "02_getting_an_image_on_the_screen/hello_world.bmp"<<SDL_GetError()<<endl;
	}

	//Apply the image
			SDL_BlitSurface(image, NULL, windowSurface, NULL);

    //Update the surface
			SDL_UpdateWindowSurface( chessBoard );

	keepWindowOpen();

	//freeing the memory

	SDL_FreeSurface( windowSurface );
	chessBoard = NULL;

    //SDL_DestroyWindow(chessBoard);
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
