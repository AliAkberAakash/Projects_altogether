#include<SDL2/SDL.H>
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
void keepWindowOpen();

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

            pawn.x=30;
            pawn.y=580;
            pawn.h=50;
            pawn.w=50;

            SDL_BlitSurface(pawnSurface, NULL, boardSurface, &pawn);
            SDL_UpdateWindowSurface(chessBoard);

            //keepWindowOpen();
    SDL_Event event;

    bool running=true;

    while(running)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type==SDL_QUIT)
            {
                running = false;
                break;
            }

            else if(event.type==SDL_KEYDOWN)
            {
                switch(event.key.keysym.sym)
                {
                    case SDLK_RIGHT:
                        {
                              pawn.x=pawn.x+30;
                              SDL_FreeSurface(pawnSurface);
                              pawnSurface=SDL_LoadBMP("pawn.bmp");
                              SDL_BlitSurface(pawnSurface, NULL, boardSurface, &pawn);
                              SDL_UpdateWindowSurface(chessBoard);
                              break;
                        }
                }
            }
        }
    }


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

    imageSurface=SDL_LoadBMP("chessBoard2.bmp");
    if(imageSurface==NULL)
    {
        cout<<"ERROR!!!"<<SDL_GetError()<<endl;
        success=false;
    }

    pawnSurface=SDL_LoadBMP("pawn.bmp");
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
    SDL_FreeSurface(imageSurface);
    SDL_FreeSurface(pawnSurface);
    SDL_DestroyWindow(chessBoard);
    SDL_Quit();
}
