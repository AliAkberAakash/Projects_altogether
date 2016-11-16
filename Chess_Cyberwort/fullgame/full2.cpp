#include<SDL2/SDL.h>
#include<SDL2/SDL_keyboard.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<cstdlib>
#define pos SDL_WINDOWPOS_CENTERED
#define BSIZE 80

const int sw=640;
const int sh=640;
char active='n';
int p=0,q=0,s=-1,r=-1;

SDL_Surface* winSurface=NULL;
SDL_Window* window=NULL;
SDL_Surface* selector=NULL;
SDL_Surface* selected=NULL;
using namespace std;
// GLOBALLY DECLARES ALL THE BLOCKS
SDL_Rect block_rect[8][8];

//PLAYER SELECTOR
int player=1;


// GLOBALLY DECLARES ALL THE TROOPS
SDL_Rect selector_rect;

// USER DEFINED FUNCTIONS
void playerOneControls(SDL_Event e, SDL_Surface* selector);
void playerTwoControls(SDL_Event e, SDL_Surface* selector);
void draw();
void update_x(int a, int b, int c, int d);
bool logicP1(int a, int b, int c, int d);
bool logicP2(int a, int b, int c, int d);
bool b_pawnlogic(int a, int b, int c, int d);
bool w_pawnlogic(int a, int b, int c, int d);
bool bishoplogic(int a, int b, int c, int d);
bool knightlogic(int a, int b, int c, int d);
bool kinglogic(int a, int b, int c, int d);
bool rooklogic(int a, int b, int c, int d);


// ERASE A RECT
        void eRect(int m, int n){
            SDL_Surface* wbSurface=IMG_Load("icons/wb.png");
            SDL_Surface* bbSurface=IMG_Load("icons/bb.png");
            if(m%2==0 && n%2==0)
                SDL_BlitSurface(wbSurface, NULL, winSurface, &block_rect[m][n]);
            else
                SDL_BlitSurface(bbSurface, NULL, winSurface, &block_rect[m][n]);
        }
    //


// MAIN FUNCTION //


int main(int argc, char *argv[])
{

// INITIALIZATION OF BLOCKS

    for(int i=0; i<8; i++){
        for (int  j=0; j<8; j++){
            block_rect[i][j].x=j*BSIZE;
            block_rect[i][j].y=i*BSIZE;
            block_rect[i][j].h=BSIZE;
            block_rect[i][j].w=BSIZE;
        }
    }


            //selector properties
            selector_rect.x=0;
            selector_rect.y=560;
            selector_rect.h=80;
            selector_rect.w=80;




    SDL_Init( SDL_INIT_EVERYTHING );
    IMG_Init( IMG_INIT_PNG );
    window = SDL_CreateWindow("Chess++", pos, pos, sw, sh, SDL_WINDOW_SHOWN);
    selected=IMG_Load("icons/selected.png");

    draw();
    // DRAW THE SELECTOR
    SDL_BlitSurface(selector, NULL, winSurface, &selector_rect);

    SDL_Event event;
    bool work=true;
    while(work){
            SDL_Delay(16);
        while(SDL_PollEvent(&event)){
                SDL_Delay(16);
            if(event.type==SDL_QUIT){
                work=false;
                break;
            }

            if(player==1)
                playerOneControls(event, selector);
            else
                playerTwoControls(event, selector);

            SDL_UpdateWindowSurface(window);
        }
    }

    IMG_Quit();
    SDL_Quit();
    return 0;
}

void playerOneControls(SDL_Event e, SDL_Surface* selector)
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
                                      }
                                   //update_y(r, r, selector_rect.y);

                                    active='n';

                                    cout<<active<<endl;
                                }
                                else
                                {
                                    //cout<<p<<" "<<q<<endl;
                                    active='y';

                                    SDL_BlitSurface(selected, NULL, selector, NULL);
                                    s=p;
                                    r=q;
                                    cout<<active<<endl;
                                }
                                //cout<<active<<endl;
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

                            //cout<<block_rect[0][0].x<<endl;
                            draw();
                            SDL_BlitSurface(selector, NULL, winSurface, &selector_rect);
                            SDL_UpdateWindowSurface(window);


    }
}

void playerTwoControls(SDL_Event e, SDL_Surface* selector)
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
                            cout<<p<<" "<<q<<endl;
                                if(active=='y')
                                {
                                    if(logicP2(s, r, selector_rect.x, selector_rect.y))
                                      {
                                          update_x(s, r, selector_rect.x, selector_rect.y);
                                          player=1;
                                      }
                                   //update_y(r, r, selector_rect.y);

                                    active='n';

                                    cout<<active<<endl;
                                }
                                else
                                {
                                    //cout<<p<<" "<<q<<endl;
                                    active='y';

                                    SDL_BlitSurface(selected, NULL, selector, NULL);
                                    s=p;
                                    r=q;
                                    cout<<active<<endl;
                                }
                                //cout<<active<<endl;
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

                            //cout<<block_rect[0][0].x<<endl;
                            draw();
                            //eRect(s,r);
                            SDL_BlitSurface(selector, NULL, winSurface, &selector_rect);
                            SDL_UpdateWindowSurface(window);


    }
}


void draw()
 {
   //SURFACE CREATION
    winSurface=SDL_GetWindowSurface(window);
    SDL_Surface* fullBoard=IMG_Load("icons/chessboard2.png");
    SDL_Surface* wbSurface=IMG_Load("icons/wb.png");
    SDL_Surface* bbSurface=IMG_Load("icons/bb.png");
    selector=IMG_Load("icons/selector.png");

    SDL_BlitSurface(fullBoard,NULL,winSurface,NULL);

    SDL_Surface* b_pawn=IMG_Load("icons/b_pawn.png");
    SDL_Surface* b_rook=IMG_Load("icons/b_rook.png");
    SDL_Surface* b_bishop=IMG_Load("icons/b_bishop.png");
    SDL_Surface* b_knight=IMG_Load("icons/b_knight.png");
    SDL_Surface* b_king=IMG_Load("icons/b_king.png");
    SDL_Surface* b_queen=IMG_Load("icons/b_queen.png");

    SDL_Surface* w_pawn=IMG_Load("icons/w_pawn.png");
    SDL_Surface* w_rook=IMG_Load("icons/w_rook.png");
    SDL_Surface* w_bishop=IMG_Load("icons/w_bishop.png");
    SDL_Surface* w_knight=IMG_Load("icons/w_knight.png");
    SDL_Surface* w_king=IMG_Load("icons/w_king.png");
    SDL_Surface* w_queen=IMG_Load("icons/w_queen.png");



    // DRAW ALL PAWNS(BOTH BLACK AND WHITE
    for(int i=0; i<8; i++){
        SDL_BlitSurface(w_pawn, NULL, winSurface, &block_rect[6][i]);
        SDL_BlitSurface(b_pawn, NULL, winSurface, &block_rect[1][i]);
    }
    // DRAW REST WHITE TROOPS
        SDL_BlitSurface(w_king, NULL, winSurface, &block_rect[7][4]);
        SDL_BlitSurface(w_queen, NULL, winSurface, &block_rect[7][3]);
        SDL_BlitSurface(w_bishop, NULL, winSurface, &block_rect[7][2]);
        SDL_BlitSurface(w_bishop, NULL, winSurface, &block_rect[7][5]);
        SDL_BlitSurface(w_knight, NULL, winSurface, &block_rect[7][1]);
        SDL_BlitSurface(w_knight, NULL, winSurface, &block_rect[7][6]);
        SDL_BlitSurface(w_rook, NULL, winSurface, &block_rect[7][0]);
        SDL_BlitSurface(w_rook, NULL, winSurface, &block_rect[7][7]);
   // DRAW REST BLACK TROOPS
        SDL_BlitSurface(b_king, NULL, winSurface, &block_rect[0][4]);
        SDL_BlitSurface(b_queen, NULL, winSurface, &block_rect[0][3]);
        SDL_BlitSurface(b_bishop, NULL, winSurface, &block_rect[0][2]);
        SDL_BlitSurface(b_bishop, NULL, winSurface, &block_rect[0][5]);
        SDL_BlitSurface(b_knight, NULL, winSurface, &block_rect[0][1]);
        SDL_BlitSurface(b_knight, NULL, winSurface, &block_rect[0][6]);
        SDL_BlitSurface(b_rook, NULL, winSurface, &block_rect[0][0]);
        SDL_BlitSurface(b_rook, NULL, winSurface, &block_rect[0][7]);

    // killing a troop
    //kill(a,b,c);

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

