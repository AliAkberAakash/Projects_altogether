#include<SDL2/SDL.h>
#include<SDL2/SDL_keyboard.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<cstdlib>
#define pos SDL_WINDOWPOS_CENTERED
#define BSIZE 80
int presel_x,presel_y;
int postsel_x,postsel_y;
//CRERATING  GLOBAL  SURFACES
SDL_Surface* selectorSurface=IMG_Load("selector.png");
SDL_Surface* selectedSurface=IMG_Load("selected.png");
SDL_Surface* winSurface=NULL;
using namespace std;
//CRERATING  GLOBAL  RENDERER
SDL_Renderer* renderer=NULL;
// GLOBALLY DECLARES ALL THE BLOCKS
SDL_Rect block_rect[8][8];
//
// GLOBALLY DECLARES ALL THE TROOPS
SDL_Rect pawn_rect[2][8];
SDL_Rect rook_rect[2][2];
SDL_Rect knight_rect[2][2];
SDL_Rect bishop_rect[2][2];
SDL_Rect king_rect[2];
SDL_Rect queen_rect[2];
// SURFACES AND TEXTURES
SDL_Surface* fullBoard=NULL;
SDL_Surface* wbSurface=NULL;
SDL_Surface* bbSurface=NULL;
//
//    SDL_BlitSurface(fullBoard,NULL,winSurface,NULL);

SDL_Surface* b_pawn=NULL;
SDL_Surface* b_rook=NULL;
SDL_Surface* b_bishop=NULL;
SDL_Surface* b_knight=NULL;
SDL_Surface* b_king=NULL;
SDL_Surface* b_queen=NULL;

SDL_Surface* w_pawn=NULL;
SDL_Surface* w_rook=NULL;
SDL_Surface* w_bishop=NULL;
SDL_Surface* w_knight=NULL;
SDL_Surface* w_king=NULL;
SDL_Surface* w_queen=NULL;

// TEXTURE LOADING
SDL_Texture* t_fullBoard=NULL;
SDL_Texture* t_wbSurface=NULL;
SDL_Texture* t_bbSurface=NULL;

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

// USER DEFINED FUNCTIONS
void draw();
void load();
// ERASE A RECT
void eRect(int m, int n)
{
    SDL_Surface* wbSurface=IMG_Load("wb.png");
    SDL_Surface* bbSurface=IMG_Load("bb.png");
    if(m%2==0 && n%2==0)
        SDL_BlitSurface(wbSurface, NULL, winSurface, &block_rect[m][n]);
    else
        SDL_BlitSurface(bbSurface, NULL, winSurface, &block_rect[m][n]);
}
//


// DRAW SELECTOR

void Selector(int m=0, int n=0)
{
    SDL_BlitSurface(selectorSurface,NULL,winSurface,&block_rect[m][n]);
    presel_x=m;
    presel_y=n;
}


//DRAW SELECTED

void Selected(int m=0, int n=0)
{
    SDL_BlitSurface(selectedSurface,NULL,winSurface,&block_rect[m][n]);
}













// MAIN FUNCTION //


int main(int argc, char *argv[])
{

// INITIALIZATION OF BLOCKS

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


// //////

    SDL_Init( SDL_INIT_EVERYTHING );
    IMG_Init( IMG_INIT_PNG );
    SDL_Window* window;
    window = SDL_CreateWindow("Chess++", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640,640, SDL_WINDOW_SHOWN);
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    //SURFACE CREATION
    winSurface=SDL_GetWindowSurface(window);



    // DRAW ALL PAWNS(BOTH BLACK AND WHITE
//    for(int i=0; i<8; i++){
//        SDL_BlitSurface(w_pawn, NULL, winSurface, &block_rect[6][i]);
//        SDL_BlitSurface(b_pawn, NULL, winSurface, &block_rect[1][i]);
//    }
    // DRAW REST WHITE TROOPS
//        SDL_BlitSurface(w_king, NULL, winSurface, &block_rect[7][4]);
//        SDL_BlitSurface(w_queen, NULL, winSurface, &block_rect[7][3]);
//        SDL_BlitSurface(w_bishop, NULL, winSurface, &block_rect[7][2]);
//        SDL_BlitSurface(w_bishop, NULL, winSurface, &block_rect[7][5]);
//        SDL_BlitSurface(w_knight, NULL, winSurface, &block_rect[7][1]);
//        SDL_BlitSurface(w_knight, NULL, winSurface, &block_rect[7][6]);
//        SDL_BlitSurface(w_rook, NULL, winSurface, &block_rect[7][0]);
//        SDL_BlitSurface(w_rook, NULL, winSurface, &block_rect[7][7]);
    // DRAW REST BLACK TROOPS
//        SDL_BlitSurface(b_king, NULL, winSurface, &block_rect[0][4]);
//        SDL_BlitSurface(b_queen, NULL, winSurface, &block_rect[0][3]);
//        SDL_BlitSurface(b_bishop, NULL, winSurface, &block_rect[0][2]);
//        SDL_BlitSurface(b_bishop, NULL, winSurface, &block_rect[0][5]);
//        SDL_BlitSurface(b_knight, NULL, winSurface, &block_rect[0][1]);
//        SDL_BlitSurface(b_knight, NULL, winSurface, &block_rect[0][6]);
//        SDL_BlitSurface(b_rook, NULL, winSurface, &block_rect[0][0]);
//        SDL_BlitSurface(b_rook, NULL, winSurface, &block_rect[0][7]);

    //eRect(0,0);

    Selector(4,5);

    load();
    SDL_Event event;
    bool work=true;
    //SDL_RenderCopy(renderer, t_fullBoard, NULL, NULL);
    // copy_all()

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
//            else if (event.type==SDL_KEYDOWN)
            }
            draw();
            //SDL_UpdateWindowSurface(window);
        }
    }

    IMG_Quit();
    SDL_Quit();
    return 0;
}


void draw(){
//    SDL_Surface* fullBoard=IMG_Load("chessboard2.png");
//    SDL_Surface* wbSurface=IMG_Load("wb.png");
//    SDL_Surface* bbSurface=IMG_Load("bb.png");
////
////    SDL_BlitSurface(fullBoard,NULL,winSurface,NULL);
//
//    SDL_Surface* b_pawn=IMG_Load("b_pawn.png");
//    SDL_Surface* b_rook=IMG_Load("b_rook.png");
//    SDL_Surface* b_bishop=IMG_Load("b_bishop.png");
//    SDL_Surface* b_knight=IMG_Load("b_knight.png");
//    SDL_Surface* b_king=IMG_Load("b_king.png");
//    SDL_Surface* b_queen=IMG_Load("b_queen.png");
//
//    SDL_Surface* w_pawn=IMG_Load("w_pawn.png");
//    SDL_Surface* w_rook=IMG_Load("w_rook.png");
//    SDL_Surface* w_bishop=IMG_Load("w_bishop.png");
//    SDL_Surface* w_knight=IMG_Load("w_knight.png");
//    SDL_Surface* w_king=IMG_Load("w_king.png");
//    SDL_Surface* w_queen=IMG_Load("w_queen.png");

// TEXTURE LOADING
    SDL_Texture* t_fullBoard=SDL_CreateTextureFromSurface(renderer,fullBoard);
    SDL_Texture* t_wbSurface=SDL_CreateTextureFromSurface(renderer,wbSurface);
    SDL_Texture* t_bbSurface=SDL_CreateTextureFromSurface(renderer,bbSurface);

    SDL_Texture* t_b_pawn=SDL_CreateTextureFromSurface(renderer,b_pawn);
    SDL_Texture* t_b_rook=SDL_CreateTextureFromSurface(renderer,b_rook);
    SDL_Texture* t_b_bishop=SDL_CreateTextureFromSurface(renderer,b_bishop);
    SDL_Texture* t_b_knight=SDL_CreateTextureFromSurface(renderer,b_knight);
    SDL_Texture* t_b_king=SDL_CreateTextureFromSurface(renderer,b_king);
    SDL_Texture* t_b_queen=SDL_CreateTextureFromSurface(renderer,b_queen);

    SDL_Texture* t_w_pawn=SDL_CreateTextureFromSurface(renderer,w_pawn);
    SDL_Texture* t_w_rook=SDL_CreateTextureFromSurface(renderer,w_rook);
    SDL_Texture* t_w_bishop=SDL_CreateTextureFromSurface(renderer,w_bishop);
    SDL_Texture* t_w_knight=SDL_CreateTextureFromSurface(renderer,w_knight);
    SDL_Texture* t_w_king=SDL_CreateTextureFromSurface(renderer,w_king);
    SDL_Texture* t_w_queen=SDL_CreateTextureFromSurface(renderer,w_queen);
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
            SDL_RenderPresent(renderer);

}

void load()
{
    SDL_Surface* fullBoard=IMG_Load("chessboard2.png");
    SDL_Surface* wbSurface=IMG_Load("wb.png");
    SDL_Surface* bbSurface=IMG_Load("bb.png");
//
//    SDL_BlitSurface(fullBoard,NULL,winSurface,NULL);

    SDL_Surface* b_pawn=IMG_Load("b_pawn.png");
    SDL_Surface* b_rook=IMG_Load("b_rook.png");
    SDL_Surface* b_bishop=IMG_Load("b_bishop.png");
    SDL_Surface* b_knight=IMG_Load("b_knight.png");
    SDL_Surface* b_king=IMG_Load("b_king.png");
    SDL_Surface* b_queen=IMG_Load("b_queen.png");

    SDL_Surface* w_pawn=IMG_Load("w_pawn.png");
    SDL_Surface* w_rook=IMG_Load("w_rook.png");
    SDL_Surface* w_bishop=IMG_Load("w_bishop.png");
    SDL_Surface* w_knight=IMG_Load("w_knight.png");
    SDL_Surface* w_king=IMG_Load("w_king.png");
    SDL_Surface* w_queen=IMG_Load("w_queen.png");
}
