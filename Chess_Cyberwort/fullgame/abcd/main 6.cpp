#include<SDL2/SDL.h>
#include<SDL2/SDL_keyboard.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<cstdlib>
#define pos SDL_WINDOWPOS_CENTERED
#define BSIZE 80
using namespace std;

int player=1;
char active='n';
int p=0,q=0,s=-1,r=-1;

SDL_Window* window=NULL;

SDL_Surface* fullBoard=IMG_Load("PNG/chessboard2.png");

SDL_Surface* b_pawn0=IMG_Load("PNG/b_pawn.png");
SDL_Surface* b_pawn1=IMG_Load("PNG/b_pawn.png");
SDL_Surface* b_pawn2=IMG_Load("PNG/b_pawn.png");
SDL_Surface* b_pawn3=IMG_Load("PNG/b_pawn.png");
SDL_Surface* b_pawn4=IMG_Load("PNG/b_pawn.png");
SDL_Surface* b_pawn5=IMG_Load("PNG/b_pawn.png");
SDL_Surface* b_pawn6=IMG_Load("PNG/b_pawn.png");
SDL_Surface* b_pawn7=IMG_Load("PNG/b_pawn.png");

SDL_Surface* b_rook0=IMG_Load("PNG/b_rook.png");
SDL_Surface* b_rook1=IMG_Load("PNG/b_rook.png");

SDL_Surface* b_bishop0=IMG_Load("PNG/b_bishop.png");
SDL_Surface* b_bishop1=IMG_Load("PNG/b_bishop.png");

SDL_Surface* b_knight0=IMG_Load("PNG/b_knight.png");
SDL_Surface* b_king0=IMG_Load("PNG/b_king.png");
SDL_Surface* b_queen0=IMG_Load("PNG/b_queen.png");
SDL_Surface* b_knight1=IMG_Load("PNG/b_knight.png");
//SDL_Surface* b_king1=IMG_Load("PNG/b_king.png");
//SDL_Surface* b_queen1=IMG_Load("PNG/b_queen.png");

SDL_Surface* w_pawn0=IMG_Load("PNG/w_pawn.png");
SDL_Surface* w_pawn1=IMG_Load("PNG/w_pawn.png");
SDL_Surface* w_pawn2=IMG_Load("PNG/w_pawn.png");
SDL_Surface* w_pawn3=IMG_Load("PNG/w_pawn.png");
SDL_Surface* w_pawn4=IMG_Load("PNG/w_pawn.png");
SDL_Surface* w_pawn5=IMG_Load("PNG/w_pawn.png");
SDL_Surface* w_pawn6=IMG_Load("PNG/w_pawn.png");
SDL_Surface* w_pawn7=IMG_Load("PNG/w_pawn.png");

SDL_Surface* w_rook0=IMG_Load("PNG/w_rook.png");
SDL_Surface* w_bishop0=IMG_Load("PNG/w_bishop.png");
SDL_Surface* w_knight0=IMG_Load("PNG/w_knight.png");
SDL_Surface* w_king0=IMG_Load("PNG/w_king.png");
SDL_Surface* w_queen0=IMG_Load("PNG/w_queen.png");
SDL_Surface* w_rook1=IMG_Load("PNG/w_rook.png");
SDL_Surface* w_bishop1=IMG_Load("PNG/w_bishop.png");
SDL_Surface* w_knight1=IMG_Load("PNG/w_knight.png");
//SDL_Surface* w_king1=IMG_Load("PNG/w_king.png");
//SDL_Surface* w_queen1=IMG_Load("PNG/w_queen.png");

SDL_Surface* selector=IMG_Load("PNG/selector.png");
SDL_Surface* selected=IMG_Load("PNG/selected.png");

SDL_Renderer* renderer=NULL;

SDL_Rect block_rect[8][8];
SDL_Rect selector_rect;

SDL_Texture* t_fullBoard=NULL;

SDL_Texture* t_b_pawn0=NULL;
SDL_Texture* t_b_pawn1=NULL;
SDL_Texture* t_b_pawn2=NULL;
SDL_Texture* t_b_pawn3=NULL;
SDL_Texture* t_b_pawn4=NULL;
SDL_Texture* t_b_pawn5=NULL;
SDL_Texture* t_b_pawn6=NULL;
SDL_Texture* t_b_pawn7=NULL;

SDL_Texture* t_b_rook0=NULL;
SDL_Texture* t_b_bishop0=NULL;
SDL_Texture* t_b_knight0=NULL;
SDL_Texture* t_b_king0=NULL;
SDL_Texture* t_b_queen0=NULL;
SDL_Texture* t_b_rook1=NULL;
SDL_Texture* t_b_bishop1=NULL;
SDL_Texture* t_b_knight1=NULL;
//SDL_Texture* t_b_king1=NULL;
//SDL_Texture* t_b_queen1=NULL;

SDL_Texture* t_w_pawn0=NULL;
SDL_Texture* t_w_pawn1=NULL;
SDL_Texture* t_w_pawn2=NULL;
SDL_Texture* t_w_pawn3=NULL;
SDL_Texture* t_w_pawn4=NULL;
SDL_Texture* t_w_pawn5=NULL;
SDL_Texture* t_w_pawn6=NULL;
SDL_Texture* t_w_pawn7=NULL;

SDL_Texture* t_w_rook0=NULL;
SDL_Texture* t_w_bishop0=NULL;
SDL_Texture* t_w_knight0=NULL;
SDL_Texture* t_w_king0=NULL;
SDL_Texture* t_w_queen0=NULL;
SDL_Texture* t_w_rook1=NULL;
SDL_Texture* t_w_bishop1=NULL;
SDL_Texture* t_w_knight1=NULL;
//SDL_Texture* t_w_king1=NULL;
//SDL_Texture* t_w_queen1=NULL;

SDL_Texture* t_selector=NULL;
SDL_Texture* t_selected=NULL;


//USER DEFINED FUNCTIONS
void draw();
void close();
void playerOneControls(SDL_Event e);
void playerTwoControls(SDL_Event e);
void update1(int a, int b, int c, int d);
void update2(int a, int b, int c, int d);
void del1(int a, int b);
void del2(int a, int b);
bool logicP1(int a, int b, int c, int d);
bool logicP2(int a, int b, int c, int d);
bool b_pawnlogic(int a, int b, int c, int d);
bool w_pawnlogic(int a, int b, int c, int d);
bool bishoplogic(int a, int b, int c, int d);
bool knightlogic(int a, int b, int c, int d);
bool kinglogic(int a, int b, int c, int d);
bool rooklogic(int a, int b, int c, int d);
bool check1(int a, int b);
bool check2(int a, int b);
bool permitBishop1(int a, int b, int c, int d);


int main(int argc, char *argv[])
{
    for(int i=0; i<8; i++)
    {
        for (int  j=0; j<8; j++)
        {
            block_rect[i][j].x=j*BSIZE;
            block_rect[i][j].y=i*BSIZE;
            block_rect[i][j].h=BSIZE;
            block_rect[i][j].w=BSIZE;
        }
    }

    //SETTING THE SELECTOR POSITION
    selector_rect.x=0,
    selector_rect.y=560;
    selector_rect.h=80;
    selector_rect.w=80;

    SDL_Init( SDL_INIT_EVERYTHING );
    IMG_Init( IMG_INIT_PNG );
    window = SDL_CreateWindow("Chess", pos, pos, 640,640, SDL_WINDOW_SHOWN);
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

     t_fullBoard=SDL_CreateTextureFromSurface(renderer,fullBoard);

     t_b_pawn0=SDL_CreateTextureFromSurface(renderer,b_pawn0);
     t_b_pawn1=SDL_CreateTextureFromSurface(renderer,b_pawn1);
     t_b_pawn2=SDL_CreateTextureFromSurface(renderer,b_pawn2);
     t_b_pawn3=SDL_CreateTextureFromSurface(renderer,b_pawn3);
     t_b_pawn4=SDL_CreateTextureFromSurface(renderer,b_pawn4);
     t_b_pawn5=SDL_CreateTextureFromSurface(renderer,b_pawn5);
     t_b_pawn6=SDL_CreateTextureFromSurface(renderer,b_pawn6);
     t_b_pawn7=SDL_CreateTextureFromSurface(renderer,b_pawn7);

     t_b_rook0=SDL_CreateTextureFromSurface(renderer,b_rook0);
     t_b_bishop0=SDL_CreateTextureFromSurface(renderer,b_bishop0);
     t_b_knight0=SDL_CreateTextureFromSurface(renderer,b_knight0);
     t_b_king0=SDL_CreateTextureFromSurface(renderer,b_king0);
     t_b_queen0=SDL_CreateTextureFromSurface(renderer,b_queen0);
     t_b_rook1=SDL_CreateTextureFromSurface(renderer,b_rook1);
     t_b_bishop1=SDL_CreateTextureFromSurface(renderer,b_bishop1);
     t_b_knight1=SDL_CreateTextureFromSurface(renderer,b_knight1);
     //t_b_king1=SDL_CreateTextureFromSurface(renderer,b_king1);
     //t_b_queen1=SDL_CreateTextureFromSurface(renderer,b_queen1);

     t_w_pawn0=SDL_CreateTextureFromSurface(renderer,w_pawn0);
     t_w_pawn1=SDL_CreateTextureFromSurface(renderer,w_pawn1);
     t_w_pawn2=SDL_CreateTextureFromSurface(renderer,w_pawn2);
     t_w_pawn3=SDL_CreateTextureFromSurface(renderer,w_pawn3);
     t_w_pawn4=SDL_CreateTextureFromSurface(renderer,w_pawn4);
     t_w_pawn5=SDL_CreateTextureFromSurface(renderer,w_pawn5);
     t_w_pawn6=SDL_CreateTextureFromSurface(renderer,w_pawn6);
     t_w_pawn7=SDL_CreateTextureFromSurface(renderer,w_pawn7);

     t_w_rook0=SDL_CreateTextureFromSurface(renderer,w_rook0);
     t_w_bishop0=SDL_CreateTextureFromSurface(renderer,w_bishop0);
     t_w_knight0=SDL_CreateTextureFromSurface(renderer,w_knight0);
     t_w_king0=SDL_CreateTextureFromSurface(renderer,w_king0);
     t_w_queen0=SDL_CreateTextureFromSurface(renderer,w_queen0);
     t_w_rook1=SDL_CreateTextureFromSurface(renderer,w_rook1);
     t_w_bishop1=SDL_CreateTextureFromSurface(renderer,w_bishop1);
     t_w_knight1=SDL_CreateTextureFromSurface(renderer,w_knight1);
     //t_w_king1=SDL_CreateTextureFromSurface(renderer,w_king1);
     //t_w_queen1=SDL_CreateTextureFromSurface(renderer,w_queen1);

     t_selector=SDL_CreateTextureFromSurface(renderer,selector);
     t_selected=SDL_CreateTextureFromSurface(renderer,selected);

    //free all the surface

    SDL_FreeSurface(fullBoard);
    fullBoard=NULL;

    SDL_FreeSurface(b_pawn0);
    b_pawn0=NULL;
    SDL_FreeSurface(b_pawn1);
    b_pawn1=NULL;
    SDL_FreeSurface(b_pawn2);
    b_pawn2=NULL;
    SDL_FreeSurface(b_pawn3);
    b_pawn3=NULL;
    SDL_FreeSurface(b_pawn4);
    b_pawn4=NULL;
    SDL_FreeSurface(b_pawn5);
    b_pawn5=NULL;
    SDL_FreeSurface(b_pawn6);
    b_pawn6=NULL;
    SDL_FreeSurface(b_pawn7);
    b_pawn7=NULL;


    SDL_FreeSurface(b_rook0);
    b_rook0=NULL;
    SDL_FreeSurface(b_bishop0);
    b_bishop0=NULL;
    SDL_FreeSurface(b_knight0);
    b_knight0=NULL;
    SDL_FreeSurface(b_king0);
    b_king0=NULL;
    SDL_FreeSurface(b_queen0);
    b_queen0=NULL;
    SDL_FreeSurface(b_rook1);
    b_rook1=NULL;
    SDL_FreeSurface(b_bishop1);
    b_bishop1=NULL;
    SDL_FreeSurface(b_knight1);
    b_knight1=NULL;
//    SDL_FreeSurface(b_king1);
//    b_king1=NULL;
//    SDL_FreeSurface(b_queen1);
//    b_queen1=NULL;

    SDL_FreeSurface(w_pawn0);
    w_pawn0=NULL;
    SDL_FreeSurface(w_pawn1);
    w_pawn1=NULL;
    SDL_FreeSurface(w_pawn2);
    w_pawn2=NULL;
    SDL_FreeSurface(w_pawn3);
    w_pawn3=NULL;
    SDL_FreeSurface(w_pawn4);
    w_pawn4=NULL;
    SDL_FreeSurface(w_pawn5);
    w_pawn5=NULL;
    SDL_FreeSurface(w_pawn6);
    w_pawn6=NULL;
    SDL_FreeSurface(w_pawn7);
    w_pawn7=NULL;

    SDL_FreeSurface(w_rook0);
    w_rook0=NULL;
    SDL_FreeSurface(w_bishop0);
    w_bishop0=NULL;
    SDL_FreeSurface(w_knight0);
    w_knight0=NULL;
    SDL_FreeSurface(w_king0);
    w_king0=NULL;
    SDL_FreeSurface(w_queen0);
    w_queen0=NULL;
    SDL_FreeSurface(w_rook1);
    w_rook1=NULL;
    SDL_FreeSurface(w_bishop1);
    w_bishop1=NULL;
    SDL_FreeSurface(w_knight1);
    w_knight1=NULL;
//    SDL_FreeSurface(w_king1);
//    w_king1=NULL;
//    SDL_FreeSurface(w_queen1);
//    w_queen1=NULL;


    SDL_Event event;
    bool work=true;
    while(work)
    {
        SDL_Delay(16);
        while(SDL_PollEvent(&event))
        {
            SDL_Delay(16);
            if(event.type==SDL_QUIT)
            {
                work=false;
                break;
            }
        draw();
        if(player==1)
                playerOneControls(event);
            else
                playerTwoControls(event);

            draw();
        }
    }
    close();
    IMG_Quit();
    SDL_Quit();
    return 0;
}


void draw(){

            SDL_RenderClear(renderer);

            SDL_RenderCopy(renderer, t_fullBoard, NULL, NULL);

            //for(int i=0; i<=7; i++)
            //if(t_b_pawn0!=NULL)
            SDL_RenderCopy(renderer, t_b_pawn0, NULL, &block_rect[1][0]);

            SDL_RenderCopy(renderer, t_b_pawn1, NULL, &block_rect[1][1]);
            SDL_RenderCopy(renderer, t_b_pawn2, NULL, &block_rect[1][2]);
            SDL_RenderCopy(renderer, t_b_pawn3, NULL, &block_rect[1][3]);
            SDL_RenderCopy(renderer, t_b_pawn4, NULL, &block_rect[1][4]);
            SDL_RenderCopy(renderer, t_b_pawn5, NULL, &block_rect[1][5]);
            SDL_RenderCopy(renderer, t_b_pawn6, NULL, &block_rect[1][6]);
            SDL_RenderCopy(renderer, t_b_pawn7, NULL, &block_rect[1][7]);

            SDL_RenderCopy(renderer, t_b_bishop0, NULL, &block_rect[0][2]);
            SDL_RenderCopy(renderer, t_b_bishop1, NULL, &block_rect[0][5]);
            SDL_RenderCopy(renderer, t_b_king0, NULL, &block_rect[0][4]);
            SDL_RenderCopy(renderer, t_b_knight0, NULL, &block_rect[0][1]);
            SDL_RenderCopy(renderer, t_b_knight1, NULL, &block_rect[0][6]);
            SDL_RenderCopy(renderer, t_b_queen0, NULL, &block_rect[0][3]);
            SDL_RenderCopy(renderer, t_b_rook0, NULL, &block_rect[0][0]);
            SDL_RenderCopy(renderer, t_b_rook1, NULL, &block_rect[0][7]);

            //for(int i=0; i<=7; i++)
            SDL_RenderCopy(renderer, t_w_pawn0, NULL, &block_rect[6][0]);
            SDL_RenderCopy(renderer, t_w_pawn1, NULL, &block_rect[6][1]);
            SDL_RenderCopy(renderer, t_w_pawn2, NULL, &block_rect[6][2]);
            SDL_RenderCopy(renderer, t_w_pawn3, NULL, &block_rect[6][3]);
            SDL_RenderCopy(renderer, t_w_pawn4, NULL, &block_rect[6][4]);
            SDL_RenderCopy(renderer, t_w_pawn5, NULL, &block_rect[6][5]);
            SDL_RenderCopy(renderer, t_w_pawn6, NULL, &block_rect[6][6]);
            SDL_RenderCopy(renderer, t_w_pawn7, NULL, &block_rect[6][7]);

            SDL_RenderCopy(renderer, t_w_bishop0, NULL, &block_rect[7][2]);
            SDL_RenderCopy(renderer, t_w_bishop1, NULL, &block_rect[7][5]);
            SDL_RenderCopy(renderer, t_w_king0, NULL, &block_rect[7][4]);
            SDL_RenderCopy(renderer, t_w_knight0, NULL, &block_rect[7][1]);
            SDL_RenderCopy(renderer, t_w_knight1, NULL, &block_rect[7][6]);
            SDL_RenderCopy(renderer, t_w_queen0, NULL, &block_rect[7][3]);
            SDL_RenderCopy(renderer, t_w_rook0, NULL, &block_rect[7][0]);
            SDL_RenderCopy(renderer, t_w_rook1, NULL, &block_rect[7][7]);

            SDL_RenderCopy(renderer, t_selector, NULL, &selector_rect);

            SDL_RenderPresent(renderer);

}

void close(){

    SDL_FreeSurface(fullBoard);

    SDL_FreeSurface(b_pawn0);
    SDL_FreeSurface(b_pawn1);
    SDL_FreeSurface(b_pawn2);
    SDL_FreeSurface(b_pawn3);
    SDL_FreeSurface(b_pawn4);
    SDL_FreeSurface(b_pawn5);
    SDL_FreeSurface(b_pawn5);
    SDL_FreeSurface(b_pawn6);
    SDL_FreeSurface(b_pawn7);

    SDL_FreeSurface(b_rook0);
    SDL_FreeSurface(b_bishop0);
    SDL_FreeSurface(b_knight0);
    SDL_FreeSurface(b_king0);
    SDL_FreeSurface(b_queen0);
    SDL_FreeSurface(b_rook1);
    SDL_FreeSurface(b_bishop1);
    SDL_FreeSurface(b_knight1);

    SDL_FreeSurface(w_pawn0);
    SDL_FreeSurface(w_pawn1);
    SDL_FreeSurface(w_pawn2);
    SDL_FreeSurface(w_pawn3);
    SDL_FreeSurface(w_pawn4);
    SDL_FreeSurface(w_pawn5);
    SDL_FreeSurface(w_pawn6);
    SDL_FreeSurface(w_pawn7);

    SDL_FreeSurface(w_rook0);
    SDL_FreeSurface(w_bishop0);
    SDL_FreeSurface(w_knight0);
    SDL_FreeSurface(w_king0);
    SDL_FreeSurface(w_queen0);
    SDL_FreeSurface(w_rook1);
    SDL_FreeSurface(w_bishop1);
    SDL_FreeSurface(w_knight1);


    SDL_DestroyTexture(t_w_pawn0);
    SDL_DestroyTexture(t_w_pawn1);
    SDL_DestroyTexture(t_w_pawn2);
    SDL_DestroyTexture(t_w_pawn3);
    SDL_DestroyTexture(t_w_pawn4);
    SDL_DestroyTexture(t_w_pawn5);
    SDL_DestroyTexture(t_w_pawn6);
    SDL_DestroyTexture(t_w_pawn7);

    SDL_DestroyTexture(t_w_bishop0);
    SDL_DestroyTexture(t_w_king0);
    SDL_DestroyTexture(t_w_knight0);
    SDL_DestroyTexture(t_w_queen0);
    SDL_DestroyTexture(t_w_rook0);
    SDL_DestroyTexture(t_w_bishop1);
    SDL_DestroyTexture(t_w_knight1);
    SDL_DestroyTexture(t_w_rook1);

    SDL_DestroyTexture(t_b_pawn0);
    SDL_DestroyTexture(t_b_pawn1);
    SDL_DestroyTexture(t_b_pawn2);
    SDL_DestroyTexture(t_b_pawn3);
    SDL_DestroyTexture(t_b_pawn4);
    SDL_DestroyTexture(t_b_pawn5);
    SDL_DestroyTexture(t_b_pawn6);
    SDL_DestroyTexture(t_b_pawn7);

    SDL_DestroyTexture(t_b_bishop0);
    SDL_DestroyTexture(t_b_knight0);
    SDL_DestroyTexture(t_b_rook0);
     SDL_DestroyTexture(t_b_bishop1);
    SDL_DestroyTexture(t_b_knight1);
    SDL_DestroyTexture(t_b_rook1);
    SDL_DestroyTexture(t_b_king0);
    SDL_DestroyTexture(t_b_queen0);

    SDL_DestroyTexture(t_fullBoard);
    SDL_DestroyTexture(t_selector);
    SDL_DestroyTexture(t_selected);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void playerOneControls(SDL_Event e)
{

    if(e.type==SDL_KEYDOWN)
    {

        const Uint8 *keystate = SDL_GetKeyboardState(NULL);
                            if (keystate[SDL_SCANCODE_LEFT] )
                            {
                                selector_rect.x -= 80;
                            }
                            if (keystate[SDL_SCANCODE_RIGHT] )
                            {
                                selector_rect.x += 80;
                            }

                            if (keystate[SDL_SCANCODE_UP] )
                            {
                                selector_rect.y -= 80;
                            }
                            if (keystate[SDL_SCANCODE_DOWN] )
                            {
                                selector_rect.y += 80;
                            }

                            /* Pressing Enter */

                            if(keystate[SDL_SCANCODE_RETURN])
                            {
                            p=selector_rect.x;
                            q=selector_rect.y;
                                if(active=='y')
                                {
                                    if(logicP1(s, r, selector_rect.x, selector_rect.y))
                                      {
                                          del1(selector_rect.x, selector_rect.y);
                                          update1(s, r, selector_rect.x, selector_rect.y);
                                          player=2;
                                          active='n';
                                          cout<<active<<endl;
                                      }
                                }
                                else
                                {
                                    if(check1(p,q))

                                    {
                                        active='y';

                                    SDL_RenderCopy(renderer, t_selected, NULL, &selector_rect);
                                    SDL_RenderPresent(renderer);

                                    cout<<active<<endl;

                                    s=p;
                                    r=q;
                                    }
                                }
                            }

                            /* collide with edges of screen */
                            if ( selector_rect.x < 0 )
                            {
                                selector_rect.x = 560;
                            }
                            else if ( selector_rect.x > 640-75 )
                            {
                                selector_rect.x = 0;
                            }
                            if ( selector_rect.y < 0 )
                            {
                                selector_rect.y = 560;
                            }
                            else if ( selector_rect.y > 640-75 )
                            {
                                selector_rect.y = 0;
                            }


    }
}

void playerTwoControls(SDL_Event e)
{

    if(e.type==SDL_KEYDOWN)
    {

        const Uint8 *keystate = SDL_GetKeyboardState(NULL);
                            if (keystate[SDL_SCANCODE_A] )
                            {
                                selector_rect.x -= 80;
                            }
                            if (keystate[SDL_SCANCODE_D] )
                            {
                                selector_rect.x += 80;
                            }

                            if (keystate[SDL_SCANCODE_W] )
                            {
                                selector_rect.y -= 80;
                            }
                            if (keystate[SDL_SCANCODE_S] )
                            {
                                selector_rect.y += 80;
                            }

                            /* Pressing Enter */

                            if(keystate[SDL_SCANCODE_RETURN])
                            {
                            p=selector_rect.x;
                            q=selector_rect.y;

                                if(active=='y')
                                {
                                    if(logicP2(s, r, selector_rect.x, selector_rect.y))
                                      {
                                          del2(selector_rect.x, selector_rect.y);
                                          update2(s, r, selector_rect.x, selector_rect.y);
                                          player=1;
                                          active='n';
                                          cout<<active<<endl;
                                      }
                                }
                                else
                                {
                                    if(check2(p,q))
                                    {
                                        active='y';

                                    SDL_RenderCopy(renderer, t_selected, NULL, &selector_rect);
                                    SDL_RenderPresent(renderer);

                                    cout<<active<<endl;
                                    s=p;
                                    r=q;
                                    }
                                }
                            }

                            /* collide with edges of screen */
                            if ( selector_rect.x < 0 )
                            {
                                selector_rect.x = 560;
                            }
                            else if ( selector_rect.x > 640-75 )
                            {
                                selector_rect.x = 0;
                            }
                            if ( selector_rect.y < 0 )
                            {
                                selector_rect.y = 560;
                            }
                            else if ( selector_rect.y > 640-75 )
                            {
                                selector_rect.y = 0;
                            }

    }
}


bool logicP1(int a, int b, int c, int d)
{
    bool state=false;

    for(int i=0; i<8; i++)
    {
        if((block_rect[6][i].x==a&&block_rect[6][i].y==b))
            state=w_pawnlogic(a,b,c,d);
    }

    if((block_rect[7][2].x==a&&block_rect[7][2].y==b)||(block_rect[7][5].x==a&&block_rect[7][5].y==b))
    state=bishoplogic(a,b,c,d)&&permitBishop1(a,b,c,d);

    else if((block_rect[7][1].x==a&&block_rect[7][1].y==b)||(block_rect[7][6].x==a&&block_rect[7][6].y==b))
        state=knightlogic(a,b,c,d);

    else if((block_rect[7][3].x==a&&block_rect[7][3].y==b))
            state=true;

    else if((block_rect[7][4].x==a&&block_rect[7][4].y==b))
            state=kinglogic(a,b,c,d);

    else if((block_rect[7][0].x==a&&block_rect[7][0].y==b)||(block_rect[7][7].x==a&&block_rect[7][7].y==b))
        state=rooklogic(a,b,c,d);

    return state;
}

bool logicP2(int a, int b, int c, int d)
{
    bool state=false;

    for(int i=0; i<8; i++)
    {
        if((block_rect[1][i].x==a&&block_rect[1][i].y==b))
            state=b_pawnlogic(a,b,c,d);
    }

    if((block_rect[0][2].x==a&&block_rect[0][2].y==b)||(block_rect[0][5].x==a&&block_rect[0][5].y==b))
    state=bishoplogic(a,b,c,d)&&permitBishop1(a,b,c,d);

    else if((block_rect[0][6].x==a&&block_rect[0][6].y==b)||(block_rect[0][1].x==a&&block_rect[0][1].y==b))
        state=knightlogic(a,b,c,d);

    else if((block_rect[0][3].x==a&&block_rect[0][3].y==b))
            state=true;

    else if((block_rect[0][4].x==a&&block_rect[0][4].y==b))
            state=kinglogic(a,b,c,d);

    else if((block_rect[0][0].x==a&&block_rect[0][0].y==b)||(block_rect[0][7].x==a&&block_rect[0][7].y==b))
        state=rooklogic(a,b,c,d);

    return state;
}

void update1(int a, int b, int c, int d)
{

    for(int i=6; i<8; i++)
    {
        for(int j=0; j<8; j++)
            if(block_rect[i][j].x==a&&block_rect[i][j].y==b)
        {
                block_rect[i][j].x=c;
                block_rect[i][j].y=d;
                cout<<"Updated"<<endl;
        }
    }

}

void update2(int a, int b, int c, int d)
{

        for(int i=0; i<2; i++)
    {
        for(int j=0; j<8; j++)
            if(block_rect[i][j].x==a&&block_rect[i][j].y==b)
        {
                block_rect[i][j].x=c;
                block_rect[i][j].y=d;
                cout<<"Updated"<<endl;
        }
    }

}


bool b_pawnlogic(int a, int b, int c, int d)
{
    if(a-c==0&&d-b==80)
    return true;
    else
    return false;
}

bool w_pawnlogic(int a, int b, int c, int d)
{
    if(c-a==0&&b-d==80)
    return true;
    else
    return false;
}

bool bishoplogic(int a, int b, int c, int d)
{
    bool go;

    if(abs(a-c)==abs(b-d))
    go=true;
    else
    go= false;
    return go;
}

bool knightlogic(int a, int b, int c, int d)
{
    if((abs(a-c)==160 && abs(b-d)==80) || (abs(a-c)==80 && abs(b-d)==160))
        return true;
    else
        return false;
}

bool kinglogic(int a, int b, int c, int d)
{
    if((abs(a-c)==80&&abs(b-d)==80)||(abs(a-c)==0&&abs(b-d)==80)||(abs(a-c)==80&&abs(b-d)==0))
    return true;
    else
    return false;
}

bool rooklogic(int a, int b, int c, int d)
{
    if(abs(a-c)==0||abs(b-d)==0)
    return true;
    else
    return false;
}

bool check1(int a, int b)
{
    bool go=false;

    for(int i=6; i<8; i++)
    {
        for(int j=0; j<8; j++)
            if(block_rect[i][j].x==a&&block_rect[i][j].y==b)
        {
            go=true;
        }
    }

    return go;

}

bool check2(int a, int b)
{
    bool    go=false;

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<8; j++)
            if(block_rect[i][j].x==a&&block_rect[i][j].y==b)
        {
            go=true;
        }
    }

    return go;
}

bool permitBishop1(int a, int b, int c,int d)
{
    int i,j;
    bool go=true;
    if(a<c)
        for(i=a+80, j=b+80; i<c; i=i+80, j=j+80)
        {
            if(check2(i,j))
                go=false;
        }
    else
        for(i=c+80, j=d+80; i<a; i=i+80, j=j+80)
        {
            if(check2(i,j))
                go=false;
        }

    return go;
}

void del1(int a, int b)
{
    if(a==block_rect[0][0].x&&b==block_rect[0][0].y)
    {
    SDL_DestroyTexture(t_b_rook0);
    t_b_rook0=NULL;
    }
    if(a==block_rect[0][1].x&&b==block_rect[0][1].y)
    {
    SDL_DestroyTexture(t_b_knight0);
    t_b_knight0=NULL;
    }
    if(a==block_rect[0][2].x&&b==block_rect[0][2].y)
    {
    SDL_DestroyTexture(t_b_bishop0);
    t_b_bishop0=NULL;
    }
    if(a==block_rect[0][3].x&&b==block_rect[0][3].y)
    {
    SDL_DestroyTexture(t_b_queen0);
    t_b_queen0=NULL;
    }
    if(a==block_rect[0][4].x&&b==block_rect[0][4].y)
    {
    SDL_DestroyTexture(t_b_king0);
    t_b_king0=NULL;
    }
    if(a==block_rect[0][7].x&&b==block_rect[0][7].y)
    {
    SDL_DestroyTexture(t_b_rook1);
    t_b_rook1=NULL;
    }
    if(a==block_rect[0][6].x&&b==block_rect[0][6].y)
    {
    SDL_DestroyTexture(t_b_knight1);
    t_b_knight1=NULL;
    }
    if(a==block_rect[0][5].x&&b==block_rect[0][5].y)
    {
    SDL_DestroyTexture(t_b_bishop1);
    t_b_bishop1=NULL;
    }

    if(a==block_rect[1][0].x&&b==block_rect[1][0].y)
    {
    SDL_DestroyTexture(t_b_pawn0);
    t_b_pawn0=NULL;
    }
    if(a==block_rect[1][1].x&&b==block_rect[1][1].y)
    {
    SDL_DestroyTexture(t_b_pawn1);
    t_b_pawn1=NULL;
    }
    if(a==block_rect[1][2].x&&b==block_rect[1][2].y)
    {
    SDL_DestroyTexture(t_b_pawn2);
    t_b_pawn2=NULL;
    }
    if(a==block_rect[1][3].x&&b==block_rect[1][3].y)
    {
    SDL_DestroyTexture(t_b_pawn3);
    t_b_pawn3=NULL;
    }
    if(a==block_rect[1][4].x&&b==block_rect[1][4].y)
    {
    SDL_DestroyTexture(t_b_pawn4);
    t_b_pawn4=NULL;
    }
    if(a==block_rect[1][5].x&&b==block_rect[1][5].y)
    {
    SDL_DestroyTexture(t_b_pawn5);
    t_b_pawn5=NULL;
    }
    if(a==block_rect[1][6].x&&b==block_rect[1][6].y)
    {
    SDL_DestroyTexture(t_b_pawn6);
    t_b_pawn6=NULL;
    }
    if(a==block_rect[1][7].x&&b==block_rect[1][7].y)
    {
    SDL_DestroyTexture(t_b_pawn7);
    t_b_pawn7=NULL;
    }

}

void del2(int a,int b)
{
    if(a==block_rect[7][0].x&&b==block_rect[7][0].y)
    {
    SDL_DestroyTexture(t_w_rook0);
    t_w_rook0=NULL;
    }
    if(a==block_rect[7][1].x&&b==block_rect[7][1].y)
    {
    SDL_DestroyTexture(t_w_knight0);
    t_w_knight0=NULL;
    }
    if(a==block_rect[7][2].x&&b==block_rect[7][2].y)
    {
    SDL_DestroyTexture(t_w_bishop0);
    t_w_bishop0=NULL;
    }
    if(a==block_rect[7][3].x&&b==block_rect[7][3].y)
    {
    SDL_DestroyTexture(t_w_queen0);
    t_w_queen0=NULL;
    }
    if(a==block_rect[7][4].x&&b==block_rect[7][4].y)
    {
    SDL_DestroyTexture(t_w_king0);
    t_w_king0=NULL;
    }
    if(a==block_rect[7][7].x&&b==block_rect[7][7].y)
    {
    SDL_DestroyTexture(t_w_rook1);
    t_w_rook1=NULL;
    }
    if(a==block_rect[6][6].x&&b==block_rect[6][6].y)
    {
    SDL_DestroyTexture(t_w_knight1);
    t_w_knight1=NULL;
    }
    if(a==block_rect[6][5].x&&b==block_rect[6][5].y)
    {
    SDL_DestroyTexture(t_w_bishop1);
    t_w_bishop1=NULL;
    }

    if(a==block_rect[6][0].x&&b==block_rect[6][0].y)
    {
    SDL_DestroyTexture(t_w_pawn0);
    t_w_pawn0=NULL;
    }
    if(a==block_rect[6][1].x&&b==block_rect[6][1].y)
    {
    SDL_DestroyTexture(t_w_pawn1);
    t_w_pawn1=NULL;
    }
    if(a==block_rect[6][2].x&&b==block_rect[6][2].y)
    {
    SDL_DestroyTexture(t_w_pawn2);
    t_w_pawn2=NULL;
    }
    if(a==block_rect[6][3].x&&b==block_rect[6][3].y)
    {
    SDL_DestroyTexture(t_w_pawn3);
    t_w_pawn3=NULL;
    }
    if(a==block_rect[6][4].x&&b==block_rect[6][4].y)
    {
    SDL_DestroyTexture(t_w_pawn4);
    t_w_pawn4=NULL;
    }
    if(a==block_rect[6][5].x&&b==block_rect[6][5].y)
    {
    SDL_DestroyTexture(t_w_pawn5);
    t_w_pawn5=NULL;
    }
    if(a==block_rect[6][6].x&&b==block_rect[6][6].y)
    {
    SDL_DestroyTexture(t_w_pawn6);
    t_w_pawn6=NULL;
    }
    if(a==block_rect[6][7].x&&b==block_rect[6][7].y)
    {
    SDL_DestroyTexture(t_w_pawn7);
    t_w_pawn7=NULL;
    }
}
