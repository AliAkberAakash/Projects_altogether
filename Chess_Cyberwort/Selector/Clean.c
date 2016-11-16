#include<SDL2/SDL.h>
#include<SDL2/SDL_keyboard.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<cstdlib>
//window position
#define pos SDL_WINDOWPOS_CENTERED
#define BSIZE 80

//declaration of surfaces
SDL_Surface* winSurface=NULL;
SDL_Surface* selector=NULL;
SDL_Surface* fullBoard=NULL;

//function prototypes
void surfaceCreator(SDL_Window* a);

using namespace std;

//window size
const int sw=640;
const int sh=640;

// GLOBALLY DECLARES ALL THE BLOCKS
SDL_Rect block_rect[8][8];

// GLOBALLY DECLARES ALL THE TROOPS
SDL_Rect pawn_rect[2][8];
SDL_Rect rook_rect[2][2];
SDL_Rect knight_rect[2][2];
SDL_Rect bishop_rect[2][2];
SDL_Rect king_rect[2];
SDL_Rect queen_rect[2];
SDL_Rect selector_rect;

//event handlinh function

void event()
{
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

            SDL_UpdateWindowSurface(window);
        }
    }
}


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


// //////

    SDL_Init( SDL_INIT_EVERYTHING );
    IMG_Init( IMG_INIT_PNG );
    SDL_Window* widow=NULL;
    window = SDL_CreateWindow("Chess++", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640,640, SDL_WINDOW_SHOWN);

    surfaceCreator(window);
    event();

    IMG_Quit();
    SDL_Quit();
    return 0;


}


void surfaceCreator(SDL_Window* a)
{
        //SURFACE CREATION
    winSurface=SDL_GetWindowSurface(a);
    fullBoard=IMG_Load("chessboard2.png");
    SDL_Surface* wbSurface=IMG_Load("wb.png");
    SDL_Surface* bbSurface=IMG_Load("bb.png");

    SDL_BlitSurface(fullBoard,NULL,winSurface,NULL);

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

    //selector surface
    selector=IMG_Load("selector.png");

    //DRAW SELECTOR
        SDL_BlitSurface(selector, NULL, winSurface, &block_rect[7][0]);

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
}
