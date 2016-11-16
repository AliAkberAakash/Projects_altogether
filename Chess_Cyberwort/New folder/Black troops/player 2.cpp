#include<SDL2/SDL.h>
#include<SDL2/SDL_keyboard.h>
#include"SDL2/SDL_image.h"
#include<iostream>
#define pos SDL_WINDOWPOS_CENTERED

using namespace std;

const int sw=640;
const int sh=640;

SDL_Window* chessBoard=NULL;
SDL_Surface* boardSurface=NULL;
SDL_Surface* imageSurface=NULL;
SDL_Surface* pawnSurface=NULL;


bool init();
bool loadMedia();
void freeMedia();
void movePawn();
void eventHandle(SDL_Event event, SDL_Rect sprite);
//void keepWindowOpen();

int main(int argc, char*argv[])
{


    if(!init())
    {
        cout<<"Failed to Initialize"<<endl;
    }

    else
    {
        if(!loadMedia())
        {
            cout<<"Failed to load Media"<<endl;
        }

        else
        {
            SDL_BlitSurface(imageSurface, NULL, boardSurface, NULL);

            SDL_UpdateWindowSurface(chessBoard);

            //setting the position of the pawn
            SDL_Rect pawn;

            pawn.x=80;
            pawn.y=560;
            pawn.h=80;
            pawn.w=80;

            SDL_BlitSurface(pawnSurface, NULL, boardSurface, &pawn);
            SDL_UpdateWindowSurface(chessBoard);

            //keepWindowOpen();
    SDL_Event movement;

    eventHandle(movement, pawn);


        }
    }

    freeMedia();

    return 0;
}


bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		cout<<"SDL could not initialize! SDL Error: %s\n"<<SDL_GetError()<<endl;
	}
	else
	{
		//Create window
		chessBoard = SDL_CreateWindow( "UPER CHESS!!!", pos, pos, sh, sw, SDL_WINDOW_SHOWN );
		if( chessBoard == NULL )
		{
			cout<<"Window could not be created! SDL Error:"<<SDL_GetError()<<endl;
			success = false;
		}
		else
		{
			//Get window surface
			boardSurface = SDL_GetWindowSurface( chessBoard );
		}
	}

	return success;
}

bool loadMedia()
{
    bool success= true;

    imageSurface=IMG_Load("chessBoard2.png");
    if(imageSurface==NULL)
    {
        cout<<"ERROR!!!"<<SDL_GetError()<<endl;
        success=false;
    }

    pawnSurface=IMG_Load("knight.png");
    if(pawnSurface==NULL)
    {
        cout<<"ERROR!!!"<<SDL_GetError()<<endl;
        success=false;
    }

    return success;
}

void freeMedia()
{
    SDL_FreeSurface(boardSurface);
    /** \brief
     *
     ** \param imageSurface
     *
     **/
    SDL_FreeSurface(imageSurface);
    SDL_FreeSurface(pawnSurface);
    SDL_DestroyWindow(chessBoard);
    SDL_Quit();
}


void eventHandle(SDL_Event event, SDL_Rect sprite)
{
    bool running=true;

        while(running)
    {
        while(SDL_PollEvent(&event))
        {
            SDL_Delay(17);
            if(event.type==SDL_QUIT)
            {
                running = false;
                break;
            }

            else if(event.type==SDL_KEYDOWN)
            {
                            /* handle sprite movement */
                            const Uint8 *keystate = SDL_GetKeyboardState(NULL);
                            if (keystate[SDL_SCANCODE_A] )
                            {
                                sprite.x -= 80;
                            }
                            if (keystate[SDL_SCANCODE_D] )
                            {
                                sprite.x += 80;
                            }
                            if (keystate[SDL_SCANCODE_W] )
                            {
                                sprite.y -= 80;
                            }
                            if (keystate[SDL_SCANCODE_S] )
                            {
                                sprite.y += 80;
                            }
                            /* collide with edges of screen */
                            if ( sprite.x < 0 )
                            {
                                sprite.x = 0;
                            }
                            else if ( sprite.x > 640-75 )
                            {
                                sprite.x -= 80;
                            }
                            if ( sprite.y < 0 )
                            {
                                sprite.y = 0;
                            }
                            else if ( sprite.y > 640-75 )
                            {
                                sprite.y -= 80;
                            }
                              //SDL_FreeSurface(pawnSurface);
                              SDL_FreeSurface(boardSurface);
                              SDL_BlitSurface(imageSurface, NULL, boardSurface, NULL);
                              //pawnSurface=IMG_Load("knight.png");
                              SDL_BlitSurface(pawnSurface, NULL, boardSurface, &sprite);
                              SDL_UpdateWindowSurface(chessBoard);
            }

        }
        SDL_Delay(17);
    }
}


