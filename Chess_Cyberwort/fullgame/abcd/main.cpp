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
SDL_Surface* b_pawn=IMG_Load("PNG/b_pawn.png");
SDL_Surface* b_rook=IMG_Load("PNG/b_rook.png");
SDL_Surface* b_bishop=IMG_Load("PNG/b_bishop.png");
SDL_Surface* b_knight=IMG_Load("PNG/b_knight.png");
SDL_Surface* b_king=IMG_Load("PNG/b_king.png");
SDL_Surface* b_queen=IMG_Load("PNG/b_queen.png");
SDL_Surface* w_pawn=IMG_Load("PNG/w_pawn.png");
SDL_Surface* w_rook=IMG_Load("PNG/w_rook.png");
SDL_Surface* w_bishop=IMG_Load("PNG/w_bishop.png");
SDL_Surface* w_knight=IMG_Load("PNG/w_knight.png");
SDL_Surface* w_king=IMG_Load("PNG/w_king.png");
SDL_Surface* w_queen=IMG_Load("PNG/w_queen.png");
SDL_Surface* selector=IMG_Load("PNG/selector.png");
SDL_Surface* selected=IMG_Load("PNG/selected.png");

SDL_Renderer* renderer=NULL;

SDL_Rect block_rect[8][8];
SDL_Rect selector_rect;

SDL_Texture* t_fullBoard=NULL;
SDL_Texture* t_b_pawn=NULL;
SDL_Texture* t_b_rook=NULL;
SDL_Texture* t_b_bishop=NULL;
SDL_Texture* t_b_knight=NULL;
SDL_Texture* t_b_king=NULL;
SDL_Texture* t_b_queen=NULL;
SDL_Texture* t_w_pawn=NULL;
SDL_Texture* t_w_rook=NULL;
SDL_Texture* t_w_bishop=NULL;
SDL_Texture* t_w_knight=NULL;
SDL_Texture* t_w_king=NULL;
SDL_Texture* t_w_queen=NULL;
SDL_Texture* t_selector=NULL;
SDL_Texture* t_selected=NULL;


//USER DEFINED FUNCTIONS
void draw();
void close();
void playerOneControls(SDL_Event e);
void playerTwoControls(SDL_Event e);
void update_x(int a, int b, int c, int d);
bool logicP1(int a, int b, int c, int d);
bool logicP2(int a, int b, int c, int d);
bool b_pawnlogic(int a, int b, int c, int d);
bool w_pawnlogic(int a, int b, int c, int d);
bool bishoplogic(int a, int b, int c, int d);
bool knightlogic(int a, int b, int c, int d);
bool kinglogic(int a, int b, int c, int d);
bool rooklogic(int a, int b, int c, int d);


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
    //SDL_Texture*
     t_fullBoard=SDL_CreateTextureFromSurface(renderer,fullBoard);
    //SDL_Texture*
     t_b_pawn=SDL_CreateTextureFromSurface(renderer,b_pawn);
    //SDL_Texture*
     t_b_rook=SDL_CreateTextureFromSurface(renderer,b_rook);
    //SDL_Texture*
     t_b_bishop=SDL_CreateTextureFromSurface(renderer,b_bishop);
    //SDL_Texture*
     t_b_knight=SDL_CreateTextureFromSurface(renderer,b_knight);
    //SDL_Texture*
     t_b_king=SDL_CreateTextureFromSurface(renderer,b_king);
    //SDL_Texture*
     t_b_queen=SDL_CreateTextureFromSurface(renderer,b_queen);

    //SDL_Texture*
     t_w_pawn=SDL_CreateTextureFromSurface(renderer,w_pawn);
    //SDL_Texture*
     t_w_rook=SDL_CreateTextureFromSurface(renderer,w_rook);
    //SDL_Texture*
     t_w_bishop=SDL_CreateTextureFromSurface(renderer,w_bishop);
    //SDL_Texture*
     t_w_knight=SDL_CreateTextureFromSurface(renderer,w_knight);
    //SDL_Texture*
     t_w_king=SDL_CreateTextureFromSurface(renderer,w_king);
    //SDL_Texture*
     t_w_queen=SDL_CreateTextureFromSurface(renderer,w_queen);

    //SDL_Texture*
     t_selector=SDL_CreateTextureFromSurface(renderer,selector);
    //SDL_Texture*
     t_selected=SDL_CreateTextureFromSurface(renderer,selected);

    SDL_RenderCopy(renderer, t_fullBoard, NULL, NULL);


            for(int i=0; i<=7; i++)
                SDL_RenderCopy(renderer, t_b_pawn, NULL, &block_rect[1][i]);

            SDL_RenderCopy(renderer, t_b_bishop, NULL, &block_rect[0][2]);
            SDL_RenderCopy(renderer, t_b_bishop, NULL, &block_rect[0][5]);
            SDL_RenderCopy(renderer, t_b_king, NULL, &block_rect[0][4]);
            SDL_RenderCopy(renderer, t_b_knight, NULL, &block_rect[0][1]);
            SDL_RenderCopy(renderer, t_b_knight, NULL, &block_rect[0][6]);
            SDL_RenderCopy(renderer, t_b_queen, NULL, &block_rect[0][3]);
            SDL_RenderCopy(renderer, t_b_rook, NULL, &block_rect[0][0]);
            SDL_RenderCopy(renderer, t_b_rook, NULL, &block_rect[0][7]);

            for(int i=0; i<=7; i++)
                SDL_RenderCopy(renderer, t_w_pawn, NULL, &block_rect[6][i]);

            SDL_RenderCopy(renderer, t_w_bishop, NULL, &block_rect[7][2]);
            SDL_RenderCopy(renderer, t_w_bishop, NULL, &block_rect[7][5]);
            SDL_RenderCopy(renderer, t_w_king, NULL, &block_rect[7][4]);
            SDL_RenderCopy(renderer, t_w_knight, NULL, &block_rect[7][1]);
            SDL_RenderCopy(renderer, t_w_knight, NULL, &block_rect[7][6]);
            SDL_RenderCopy(renderer, t_w_queen, NULL, &block_rect[7][3]);
            SDL_RenderCopy(renderer, t_w_rook, NULL, &block_rect[7][0]);
            SDL_RenderCopy(renderer, t_w_rook, NULL, &block_rect[7][7]);

            SDL_RenderCopy(renderer, t_selector, NULL, &selector_rect);

            SDL_RenderPresent(renderer);

}

void close(){

    SDL_FreeSurface(fullBoard);
    SDL_FreeSurface(b_pawn);
    SDL_FreeSurface(b_rook);
    SDL_FreeSurface(b_bishop);
    SDL_FreeSurface(b_knight);
    SDL_FreeSurface(b_king);
    SDL_FreeSurface(b_queen);
    SDL_FreeSurface(w_pawn);
    SDL_FreeSurface(w_rook);
    SDL_FreeSurface(w_bishop);
    SDL_FreeSurface(w_knight);
    SDL_FreeSurface(w_king);
    SDL_FreeSurface(w_queen);
    SDL_DestroyTexture(t_w_bishop);
    SDL_DestroyTexture(t_w_king);
    SDL_DestroyTexture(t_w_knight);
    SDL_DestroyTexture(t_w_pawn);
    SDL_DestroyTexture(t_w_queen);
    SDL_DestroyTexture(t_w_rook);
    SDL_DestroyTexture(t_b_bishop);
    SDL_DestroyTexture(t_b_king);
    SDL_DestroyTexture(t_b_knight);
    SDL_DestroyTexture(t_b_pawn);
    SDL_DestroyTexture(t_b_queen);
    SDL_DestroyTexture(t_b_rook);
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
                                          update_x(s, r, selector_rect.x, selector_rect.y);
                                          player=2;
                                          active='n';
                                      }
                                }
                                else
                                {
                                    active='y';

//                                    SDL_RenderCopy(renderer, t_selected, NULL, &selector_rect);
//                                    SDL_RenderPresent(renderer);

                                    s=p;
                                    r=q;
                                }
                            }

                            /* collide with edges of screen */
                            if ( selector_rect.x < 0 )
                            {
                                selector_rect.x = 0;
                            }
                            else if ( selector_rect.x > 640-75 )
                            {
                                selector_rect.x -= 80;
                            }
                            if ( selector_rect.y < 0 )
                            {
                                selector_rect.y = 0;
                            }
                            else if ( selector_rect.y > 640-75 )
                            {
                                selector_rect.y -= 80;
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
                                          update_x(s, r, selector_rect.x, selector_rect.y);
                                          player=1;
                                          active='n';
                                      }
                                }
                                else
                                {
                                    active='y';

//                                    SDL_RenderCopy(renderer, t_selected, NULL, &selector_rect);
//                                    SDL_RenderPresent(renderer);

                                    s=p;
                                    r=q;
                                }
                            }

                            /* collide with edges of screen */
                            if ( selector_rect.x < 0 )
                            {
                                selector_rect.x = 0;
                            }
                            else if ( selector_rect.x > 640-75 )
                            {
                                selector_rect.x -= 80;
                            }
                            if ( selector_rect.y < 0 )
                            {
                                selector_rect.y = 0;
                            }
                            else if ( selector_rect.y > 640-75 )
                            {
                                selector_rect.y -= 80;
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
    state=bishoplogic(a,b,c,d);

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
    state=bishoplogic(a,b,c,d);

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

void update_x(int a, int b, int c, int d)
{
    int o=-1;
        for(int i=0; i<8; i++){
        for (int  j=0; j<8; j++){
            if(a==block_rect[i][j].x&&b==block_rect[i][j].y)
            {
                block_rect[i][j].x=c;
                block_rect[i][j].y=d;
                //eRect(c,d);
                o=1;
                break;
            }

        }

        if(o>0)
            break;
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
    if(abs(a-c)==abs(b-d))
    return true;
    else
    return false;
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
