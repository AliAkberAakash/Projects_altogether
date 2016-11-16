#include<SDL2/SDL.h>
#include<SDL2/SDL_keyboard.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<cstdlib>
#define pos SDL_WINDOWPOS_CENTERED

using namespace std;

const int sw=640;
const int sh=640;

SDL_Rect sprite;
SDL_Rect b_bishop;
SDL_Rect b_pawn1;

SDL_Window*  chessBoard=NULL;
SDL_Surface* boardSurface=NULL;
SDL_Surface* imageSurface=NULL;
SDL_Surface* selectorSurface=NULL;
SDL_Surface* b_bishopSurface=NULL;
SDL_Surface* b_pawn1Surface=NULL;


bool init();
bool loadMedia();
bool logic_bishop(int a, int b, int c, int d);
bool logic_pawn(int a, int b, int c, int d);
void freeMedia();
void movePawn();
void update(int a, int b);
void eventHandle(SDL_Event event, SDL_Rect selector);
int sprite_xpos(int h);
int sprite_ypos(int k);


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
            SDL_Rect selector;

            selector.x=160;
            selector.y=0;
            selector.h=80;
            selector.w=80;

            sprite.x=160;
            sprite.y=0;
            sprite.h=80;
            sprite.w=80;

            //SDL_Rect sprite;

            b_bishop.x=160;
            b_bishop.y=0;
            b_bishop.h=80;
            b_bishop.w=80;

            b_pawn1.x=0;
            b_pawn1.y=80;
            b_pawn1.h=80;
            b_pawn1.w=80;

            SDL_BlitSurface(selectorSurface, NULL, boardSurface, &selector);
            SDL_BlitSurface(b_pawn1Surface, NULL, boardSurface, &b_pawn1);
            SDL_BlitSurface(b_bishopSurface, NULL, boardSurface, &b_bishop);
            SDL_UpdateWindowSurface(chessBoard);

            //keepWindowOpen();
            SDL_Event movement;
            eventHandle(movement, selector);


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
		chessBoard = SDL_CreateWindow( "SUPER CHESS!!!", pos, pos, sh, sw, SDL_WINDOW_SHOWN );
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

    selectorSurface=IMG_Load("selector.png");
    if(selectorSurface==NULL)
    {
        cout<<"ERROR!!!"<<SDL_GetError()<<endl;
        success=false;
    }

    b_bishopSurface=IMG_Load("b_bishop.png");
    if(b_bishopSurface==NULL)
    {
        cout<<"ERROR!!!"<<SDL_GetError()<<endl;
        success=false;
    }

    b_pawn1Surface=IMG_Load("b_pawn.png");
    if(b_pawn1Surface==NULL)
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
    SDL_FreeSurface(selectorSurface);
    SDL_DestroyWindow(chessBoard);
    SDL_Quit();
}


void eventHandle(SDL_Event event, SDL_Rect selector)
{
    int p,q;
    sprite.x=0;
    sprite.y=0;
    bool running=true;
    char active='n';

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

//                    p=sprite_xpos(selector.x);
//                    q=sprite_ypos(selector.y);
                            /* handle selector movement */
                            const Uint8 *keystate = SDL_GetKeyboardState(NULL);
                            if (keystate[SDL_SCANCODE_A] )
                            {
                                selector.x -= 80;
                            }
                            if (keystate[SDL_SCANCODE_D] )
                            {
                                selector.x += 80;
                            }

                            if (keystate[SDL_SCANCODE_W] )
                            {
                                selector.y -= 80;
                            }
                            if (keystate[SDL_SCANCODE_S] )
                            {
                                selector.y += 80;
                            }

                            //pressing the enter key

                            if (keystate[SDL_SCANCODE_RETURN])
                            {
                                p=sprite_xpos(selector.x);
                                cout<<p<<endl;
                                q=sprite_ypos(selector.y);
                                cout<<q<<endl;

                                if(active=='y') //if the sprite is selected
                               {

                                    if(logic_bishop(selector.x,selector.y,p,q))
                                        {
                                            sprite=selector;
                                            update(sprite.x, sprite.y);
                                            active='n';
                                        }
                               }
                                    //if the sprite is not selected
                                    if((selector.x==p)&&(selector.y==q))
                                           {
                                               active='y';
                                           }
                            }

                            /* collide with edges of screen */
                            if ( selector.x < 0 )
                            {
                                selector.x = 0;
                            }
                            else if ( selector.x > 640-75 )
                            {
                                selector.x -= 80;
                            }
                            if ( selector.y < 0 )
                            {
                                selector.y = 0;
                            }
                            else if ( selector.y > 640-75 )
                            {
                                selector.y -= 80;
                            }


                              SDL_BlitSurface(imageSurface, NULL, boardSurface, NULL);
                              SDL_BlitSurface(b_bishopSurface, NULL, boardSurface, &b_bishop);
                              SDL_BlitSurface(b_pawn1Surface, NULL, boardSurface, &b_pawn1);
                              SDL_BlitSurface(selectorSurface, NULL, boardSurface, &selector);
                              SDL_UpdateWindowSurface(chessBoard);
            }

        }
        SDL_Delay(17);
    }
}


bool logic_bishop(int a, int b, int c, int d)
{
    if(abs(a-c)==abs(b-d))
    return true;
    else
    return false;
}

bool logic_pawn(int a, int b, int c, int d)
{
    if(abs(a-c)==0&&abs(b-d)==80)
    return true;
    else
    return false;
}

int sprite_xpos(int h)
{
   if(h==b_bishop.x)
   {
       return h;
   }

      else if(h==b_pawn1.x)
   {
       return h;
   }
   else
    return 0;

}
int sprite_ypos(int k)
{
   if(k==b_bishop.y)
    {
        return k;
    }
   else if(k==b_pawn1.y)
   {
       return k;
   }
   else
    return 0;
}

void update(int a, int b)
{
    b_bishop.x=a;
    b_bishop.y=b;
}
