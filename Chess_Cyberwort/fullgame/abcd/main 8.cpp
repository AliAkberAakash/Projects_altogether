/** Pending Works:
1. King-Rook castling
2. King Check and Unchecked
3. Winner Declaration
4. Mouse control support
5. Menu with proper functionalities
*/

/** Current Activity:
1. Watching some videos about chess game play
    to be sure about all the rules and special moves.
*/


#include<SDL2/SDL.h>
#include<SDL2/SDL_keyboard.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<cstdlib>
#define pos SDL_WINDOWPOS_CENTERED
#define BSIZE 80
#define blank 0
#define bpawn 1
#define bking 2
#define bqueen 3
#define bbishop 4
#define bknight 5
#define brook 6
#define wpawn 7
#define wking 8
#define wqueen 9
#define wbishop 10
#define wknight 11
#define wrook 12
bool killing=false;
bool castling=true;

char current_turn='w';

int killed[13];        /**GameSaverArrays**/
int troops[64];        /***/

bool moved=false;
bool select=false;
bool jump_over=true;
using namespace std;
int selected_pos=0;
int selected_troop_type=0;
int present_selector_pos=0;
int movetype=0;
int movefrom;
int moveto;

int presel_x,presel_y;
int postsel_x,postsel_y;

SDL_Window* window=NULL;
SDL_Surface* winsurface=NULL;
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
SDL_Surface* sbb=IMG_Load("PNG/bb.png");
SDL_Surface* swb=IMG_Load("PNG/wb.png");

SDL_Renderer* renderer=NULL;

SDL_Rect block_rect[8][8];
SDL_Rect pawn_rect[2][8];
SDL_Rect rook_rect[2][2];
SDL_Rect knight_rect[2][2];
SDL_Rect bishop_rect[2][2];
SDL_Rect king_rect[2];
SDL_Rect queen_rect[2];

SDL_Rect selector_rect;
SDL_Rect selected_rect;

SDL_Rect rfullboard;

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
SDL_Texture* t_sbb=NULL;
SDL_Texture* t_swb=NULL;






//void POS_Init();
bool logical_move(int trooptype, int troopos, int despos);
void logical_kill(int trooptype1, int troopos1, int despos1, int killedtype1);
void TROOPS_Init();
void draw();
void close();
bool troop_logic(int ttype, int srce, int dest);



int main(int argc, char *argv[])
{

    rfullboard.h=640;
    rfullboard.w=640;
    rfullboard.x=0;
    rfullboard.y=0;
    selector_rect.h=BSIZE;
    selector_rect.w=BSIZE;
    selector_rect.x=BSIZE*3;
    selector_rect.y=BSIZE*4;

    selected_rect.h=BSIZE;
    selected_rect.w=BSIZE;
    selected_rect.x=BSIZE*7;
    selected_rect.y=BSIZE*0;

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

    TROOPS_Init();
   // POS_Init();
    SDL_Init( SDL_INIT_EVERYTHING );
    IMG_Init( IMG_INIT_PNG );
    window = SDL_CreateWindow("Chess", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640,640, SDL_WINDOW_SHOWN);

    winsurface=SDL_GetWindowSurface(window);
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    SDL_Event event;
    bool work=true;

    t_selected=SDL_CreateTextureFromSurface(renderer,selected);
    t_selector=SDL_CreateTextureFromSurface(renderer,selector);

    t_fullBoard=SDL_CreateTextureFromSurface(renderer,fullBoard);

    t_b_pawn=SDL_CreateTextureFromSurface(renderer,b_pawn);
    t_b_rook=SDL_CreateTextureFromSurface(renderer,b_rook);
    t_b_bishop=SDL_CreateTextureFromSurface(renderer,b_bishop);
    t_b_knight=SDL_CreateTextureFromSurface(renderer,b_knight);
    t_b_king=SDL_CreateTextureFromSurface(renderer,b_king);
    t_b_queen=SDL_CreateTextureFromSurface(renderer,b_queen);

    t_w_pawn=SDL_CreateTextureFromSurface(renderer,w_pawn);
    t_w_rook=SDL_CreateTextureFromSurface(renderer,w_rook);
    t_w_bishop=SDL_CreateTextureFromSurface(renderer,w_bishop);
    t_w_knight=SDL_CreateTextureFromSurface(renderer,w_knight);
    t_w_king=SDL_CreateTextureFromSurface(renderer,w_king);
    t_w_queen=SDL_CreateTextureFromSurface(renderer,w_queen);
    t_sbb=SDL_CreateTextureFromSurface(renderer,sbb);
    t_swb=SDL_CreateTextureFromSurface(renderer,swb);

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
    SDL_FreeSurface(selected);
    SDL_FreeSurface(selector);
    SDL_FreeSurface(sbb);
    SDL_FreeSurface(swb);

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
            else if(event.type==SDL_MOUSEBUTTONDOWN)
            {
//                const Uint8 *keystate = SDL_GetKeyboardState(NULL);
//                if (keystate[SDL_SCANCODE_LEFT] )
//                    selector_rect.x -=(selector_rect.x-80<0)? 0: 80;
//                if (keystate[SDL_SCANCODE_RIGHT] )
//                    selector_rect.x += (selector_rect.x+80 > 630) ? 0:80;
//                if (keystate[SDL_SCANCODE_UP] )
//                    selector_rect.y -= (selector_rect.y-80<0)? 0: 80;
//                if (keystate[SDL_SCANCODE_DOWN] )
//                    selector_rect.y += (selector_rect.y+80 > 630) ? 0:80;
                if(event.button.button==SDL_BUTTON_LEFT)
                {
                    present_selector_pos=( ((int)( ((int)selector_rect.y)/BSIZE ))*8 )+((int)((selector_rect.x)/BSIZE));
                    if(((troops[present_selector_pos]>=1 && troops[present_selector_pos]<=6) && !select && current_turn=='b') || ((troops[present_selector_pos]>=7 && troops[present_selector_pos]<=12) && !select && current_turn=='w'))
                    {
                        selected_rect.x=selector_rect.x;
                        selected_rect.y=selector_rect.y;
                        selected_troop_type=troops[present_selector_pos];
                        selected_pos=present_selector_pos;
                        select=true;
                    }
                    else if(selected_rect.y==selector_rect.y && selected_rect.x==selector_rect.x)
                    {
                        select=false;
                    }
                    else if(select && troops[present_selector_pos]==0)
                    {
                        logical_move(selected_troop_type,selected_pos,present_selector_pos);
                    }
                    else if(select && (((troops[selected_pos]>=1 && troops[selected_pos]<=6) && (troops[present_selector_pos]>=7 &&troops[present_selector_pos]<=12)) || ((troops[selected_pos]>=7 && troops[selected_pos]<=12) && (troops[present_selector_pos]>=1 &&troops[present_selector_pos]<=6))))
                    {
                        killing=true;
                        logical_kill(selected_troop_type,selected_pos,present_selector_pos,troops[present_selector_pos]);
                        killing=false;
                    }

                }
            }
            draw();
        }
    }


    close();
    IMG_Quit();
    SDL_Quit();
    return 0;
}
void draw()
{

    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, t_fullBoard, NULL, &rfullboard);
for (int i=0; i<=63; i++){
    if(troops[i]!=blank){
        switch(troops[i]){
        case bpawn: SDL_RenderCopy(renderer, t_b_pawn, NULL, &block_rect[(int)(i/8)][i%8]); break;
        case bking: SDL_RenderCopy(renderer, t_b_king, NULL, &block_rect[(int)(i/8)][i%8]); break;
        case bqueen: SDL_RenderCopy(renderer, t_b_queen, NULL, &block_rect[(int)(i/8)][i%8]); break;
        case bbishop: SDL_RenderCopy(renderer, t_b_bishop, NULL, &block_rect[(int)(i/8)][i%8]); break;
        case bknight: SDL_RenderCopy(renderer, t_b_knight, NULL, &block_rect[(int)(i/8)][i%8]); break;
        case brook: SDL_RenderCopy(renderer, t_b_rook, NULL, &block_rect[(int)(i/8)][i%8]); break;
        case wpawn: SDL_RenderCopy(renderer, t_w_pawn, NULL, &block_rect[(int)(i/8)][i%8]); break;
        case wking: SDL_RenderCopy(renderer, t_w_king, NULL, &block_rect[(int)(i/8)][i%8]); break;
        case wqueen: SDL_RenderCopy(renderer, t_w_queen, NULL, &block_rect[(int)(i/8)][i%8]); break;
        case wbishop: SDL_RenderCopy(renderer, t_w_bishop, NULL, &block_rect[(int)(i/8)][i%8]); break;
        case wknight: SDL_RenderCopy(renderer, t_w_knight, NULL, &block_rect[(int)(i/8)][i%8]); break;
        case wrook: SDL_RenderCopy(renderer, t_w_rook, NULL, &block_rect[(int)(i/8)][i%8]); break;
        default: int e=404; //Does nothing
        }
    }
}

    SDL_RenderCopy(renderer, t_selector, NULL, &selector_rect);
    if(select)
    {
        SDL_RenderCopy(renderer, t_selected, NULL, &selected_rect);
    }

    SDL_RenderPresent(renderer);

}
void close()
{
    SDL_FreeSurface(winsurface);
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
    SDL_DestroyTexture(t_selected);
    SDL_DestroyTexture(t_selector);
    SDL_DestroyTexture(t_sbb);
    SDL_DestroyTexture(t_swb);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
void TROOPS_Init()
{

    for (int i=0; i<=64; i++)
        troops[i]=0;
    //init black troops
    for (int i = 8; i<=15; i++)
        troops[i]=bpawn;
    troops[0]=troops[7]=brook;
    troops[1]=troops[6]=bknight;
    troops[2]=troops[5]=bbishop;
    troops[3]=bqueen;
    troops[4]=bking;
    //init white troops;
    for (int i = 48; i<=55; i++)
        troops[i]=wpawn;
    troops[56]=troops[63]=wrook;
    troops[57]=troops[62]=wknight;
    troops[58]=troops[61]=wbishop;
    troops[59]=wqueen;
    troops[60]=wking;
}
bool logical_move(int trooptype, int troopos, int despos)
{
    moved=false;
    if(troop_logic(trooptype,troopos,despos))
    {
                select=false;
                troops[troopos]=blank;
                troops[despos]=trooptype;
                moved=true;

    }
    if(moved)
    {
        if (current_turn=='w')
            current_turn='b';
        else
            current_turn='w';
    }
    return moved;

}
void logical_kill(int trooptype1, int troopos1, int despos1, int killedtype1)
{
    if(killedtype1!=2 && killedtype1!=8)
    {
        troops[despos1]=0;

        if(logical_move(trooptype1,troopos1,despos1))
            killed[killedtype1]++;
        else
            troops[despos1]=killedtype1;
    }
}
bool troop_logic(int ttype, int srce, int dest)
{
    int i;
    jump_over=true;


    if(ttype==3 || ttype==9 || ttype==4 || ttype==10)
    {
        if(srce>dest)
        {
            if((srce-dest)%7==0 && dest%8!=srce%8 && (int)(dest/8)!=(int)(srce/8))
            {
                for ( i=srce-7; i<dest ; i-=7)
                {
                    if(troops[i]!=0)
                    {
                        if(!(killing && i==dest))
                        {
                            jump_over=false;
                            break;
                        }
                    }
                }
            }
            else if((srce-dest)%9==0 && dest%8!=srce%8 && (int)(dest/8)!=(int)(srce/8))
            {
                for ( i=srce-9; i>dest; i-=9)
                {
                    if(troops[i]!=0)
                    {
                        if(!(killing && i==dest))
                        {
                            jump_over=false;
                            break;
                        }
                    }
                }
            }
        }
        if(srce<dest)
        {
            if((dest-srce)%7==0 && dest%8!=srce%8 && (int)(dest/8)!=(int)(srce/8))
            {
                for (int i=srce+7; i<dest ; i+=7)
                {
                    if(troops[i]!=0)
                    {
                        if(!(killing && i==dest))
                        {
                            jump_over=false;
                            break;
                        }
                    }
                }
            }
            else if((dest-srce)%9==0 && dest%8!=srce%8 && (int)(dest/8)!=(int)(srce/8))
            {
                for ( i=srce+9; i<dest; i+=9)
                {
                    if(troops[i]!=0)
                    {
                        if(!(killing && i==dest))
                        {
                            jump_over=false;
                            break;
                        }
                    }
                }
            }
        }

    }
    if(ttype==3 || ttype==9 || ttype==6 || ttype==12)
    {
        if(srce>dest)
        {
            if((int)(srce/8)==(int)(dest/8))
            {
                for ( i=srce+1; i>dest ; i--)
                {
                    if(troops[i]!=0)
                    {
                        if(!(killing && i==dest))
                        {
                            jump_over=false;
                            break;
                        }
                    }
                }
            }
            else if((int)(srce%8)==(int)(dest%8))
            {
                for ( i=srce-8; i>dest; i-=8)
                {
                    if(troops[i]!=0)
                    {
                        if(!(killing && i==dest))
                        {
                            jump_over=false;
                            break;
                        }
                    }
                }
            }
        }
        if(srce<dest)
        {
            if((int)(srce/8)==(int)(dest/8))
            {
                for ( i=srce+1; i<dest ; i++)
                {
                    if(troops[i]!=0)
                    {
                        if(!(killing && i==dest))
                        {
                            jump_over=false;
                            break;
                        }
                    }
                }
            }
            else if((int)(srce%8)==(int)(dest%8))
            {
                for ( i=srce+8; i<dest; i+=8)
                {
                    if(troops[i]!=0)
                    {
                        if(!(killing && i==dest))
                        {
                            jump_over=false;
                            break;
                        }
                    }
                }
            }
        }
    }

    switch(ttype)
    {
    case 1:

        if (!killing && ((dest-srce == 8) || ( (srce>=8 && srce<=15) && dest-srce==16 && troops[dest-8]==0)))
            return true;
        else if(killing && (dest-srce==7 || dest-srce==9))
            return true;
        else
            return false;
        break;
    case 2:
        if(abs(dest-srce)==8 || abs(dest-srce)==9 || abs(dest-srce)==7 || abs(dest-srce)==1)
            return true;
        else
            return false;
        break;
    case 3:
        if((abs(dest%8-srce%8)==(int)abs(dest/8-srce/8) || (int)(dest/8)==(int)(srce/8) || (int)(dest%8)==(int)(srce%8)) && jump_over)
            return true;
        else
            return false;
        break;
    case 4:
        if((abs(dest%8-srce%8)==(int)abs(dest/8-srce/8)) && jump_over)
            return true;
        else
            return false;
        break;
    case 5:
        if( ( abs(((int)(dest/8))-((int)(srce/8)))==2 && abs( ((int)(dest%8))-((int)(srce%8)) )==1 ) || ( abs(((int)(dest/8))-((int)(srce/8)))==1 && abs( ((int)(dest%8))-((int)(srce%8)) )==2 ))
            return true;
        else
            return false;
        break;
    case 6:
        if((dest%8==srce%8 || (int)(dest/8)==(int)(srce/8)) && jump_over)
            return true;
        else
            return false;
        break;
    case 7:
        if (!killing && ((srce-dest == 8)  || ( (srce>=48 && srce<=55) && srce-dest==16 && troops[dest+8]==0)))
            return true;
        else if(killing && (srce-dest==7 || srce-dest==9))
            return true;
        else
            return false;
        break;
        break;
    case 8:
        if(abs(dest-srce)==8 || abs(dest-srce)==9 || abs(dest-srce)==7 || abs(dest-srce)==1)
            return true;
        else
            return false;
        break;
    case 9:
        if((abs(dest%8-srce%8)==(int)abs(dest/8-srce/8) || (int)(dest/8)==(int)(srce/8) || (int)(dest%8)==(int)(srce%8)) && jump_over)
            return true;
        else
            return false;
        break;
    case 10:
        if((abs(dest%8-srce%8)==(int)abs(dest/8-srce/8)) && jump_over)
            return true;
        else
            return false;
        break;
    case 11:
        if( ( abs(((int)(dest/8))-((int)(srce/8)))==2 && abs( ((int)(dest%8))-((int)(srce%8)) )==1 ) || ( abs(((int)(dest/8))-((int)(srce/8)))==1 && abs( ((int)(dest%8))-((int)(srce%8)) )==2 ))
            return true;
        else
            return false;
        break;
    case 12:
        if((dest%8==srce%8 || (int)(dest/8)==(int)(srce/8)) && jump_over)
            return true;
        else
            return false;
        break;
    default:
        return false;
    }
}
