#include<SDL2/SDL.h>
#include<SDL2/SDL_keyboard.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<cstdlib>
#define pos SDL_WINDOWPOS_CENTERED
#define BSIZE 80

using namespace std;

const int sw=640;
const int sh=640;


//user defined functions
void load();
void draw();
void destroy();

SDL_Window* window=NULL;
SDL_Surface* winSurface=NULL;
SDL_Renderer* renderer=NULL;

//declaring the textures;
SDL_Texture* winTexture=NULL;
SDL_Texture* selected=NULL;

    //initializing the black troops
    SDL_Texture* b_king=NULL;
    SDL_Texture* b_queen=NULL;
    SDL_Texture* b_knight=NULL;
    SDL_Texture* b_rook=NULL;
    SDL_Texture* b_bishop=NULL;
    SDL_Texture* b_pawn=NULL;

    //initializing the white troops
    SDL_Texture* w_king=NULL;
    SDL_Texture* w_queen=NULL;
    SDL_Texture* w_knight=NULL;
    SDL_Texture* w_rook=NULL;
    SDL_Texture* w_bishop=NULL;
    SDL_Texture* w_pawn=NULL;


// GLOBALLY DECLARES ALL THE BLOCKS
SDL_Rect block_rect[8][8];


int main(int  argc, char* argv[])
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

    SDL_Init( SDL_INIT_EVERYTHING );
    IMG_Init( IMG_INIT_PNG );
    window = SDL_CreateWindow("Super Chess", pos, pos, sw, sh, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    winSurface=SDL_GetWindowSurface(window);

    load();
    //draw();

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

//            if(player==1)
//                playerOneControls(event, selector);
//            else
//                playerTwoControls(event, selector);

            draw();
        }
    }

    destroy();
    SDL_Quit();
    IMG_Quit();

}

void load()
{
    winSurface=IMG_Load("icons/chessboard2.png");
    if(winSurface==NULL)
        cout<<"Error"<<endl;
    winTexture=SDL_CreateTextureFromSurface(renderer, winSurface);
    SDL_FreeSurface(winSurface);

    winSurface=IMG_Load("icons/b_pawn.png");
    if(winSurface==NULL)
        cout<<"Error"<<endl;
    b_king=SDL_CreateTextureFromSurface(renderer, winSurface);
    SDL_FreeSurface(winSurface);

    winSurface=IMG_Load("icons/b_rook.png");
    if(winSurface==NULL)
        cout<<"Error"<<endl;
    b_king=SDL_CreateTextureFromSurface(renderer, winSurface);
    SDL_FreeSurface(winSurface);

    winSurface=IMG_Load("icons/b_knight.png");
    if(winSurface==NULL)
        cout<<"Error"<<endl;
    b_king=SDL_CreateTextureFromSurface(renderer, winSurface);
    SDL_FreeSurface(winSurface);

    winSurface=IMG_Load("icons/b_bishop.png");
    if(winSurface==NULL)
        cout<<"Error"<<endl;
    b_king=SDL_CreateTextureFromSurface(renderer, winSurface);
    SDL_FreeSurface(winSurface);

    winSurface=IMG_Load("icons/b_queen.png");
    if(winSurface==NULL)
        cout<<"Error"<<endl;
    b_king=SDL_CreateTextureFromSurface(renderer, winSurface);
    SDL_FreeSurface(winSurface);

    winSurface=IMG_Load("icons/b_king.png");
    if(winSurface==NULL)
        cout<<"Error"<<endl;
    b_king=SDL_CreateTextureFromSurface(renderer, winSurface);
    SDL_FreeSurface(winSurface);

        winSurface=IMG_Load("icons/w_pawn.png");
    if(winSurface==NULL)
        cout<<"Error"<<endl;
    b_king=SDL_CreateTextureFromSurface(renderer, winSurface);
    SDL_FreeSurface(winSurface);

    winSurface=IMG_Load("icons/w_rook.png");
    if(winSurface==NULL)
        cout<<"Error"<<endl;
    b_king=SDL_CreateTextureFromSurface(renderer, winSurface);
    SDL_FreeSurface(winSurface);

    winSurface=IMG_Load("icons/w_knight.png");
    if(winSurface==NULL)
        cout<<"Error"<<endl;
    b_king=SDL_CreateTextureFromSurface(renderer, winSurface);
    SDL_FreeSurface(winSurface);

    winSurface=IMG_Load("icons/w_bishop.png");
    if(winSurface==NULL)
        cout<<"Error"<<endl;
    b_king=SDL_CreateTextureFromSurface(renderer, winSurface);
    SDL_FreeSurface(winSurface);

    winSurface=IMG_Load("icons/w_queen.png");
    if(winSurface==NULL)
        cout<<"Error"<<endl;
    b_king=SDL_CreateTextureFromSurface(renderer, winSurface);
    SDL_FreeSurface(winSurface);

    winSurface=IMG_Load("icons/w_king.png");
    if(winSurface==NULL)
        cout<<"Error"<<endl;
    b_king=SDL_CreateTextureFromSurface(renderer, winSurface);
    SDL_FreeSurface(winSurface);

}

void draw()
{
        SDL_RenderClear(renderer);

        //drawing the board
        if(!(winTexture==NULL))
        {
        SDL_RenderCopy(renderer, winTexture, NULL, NULL);
        SDL_RenderPresent(renderer);
        }

        for(int i=0; i<7; i++)
        {
            if(!(b_pawn==NULL))
            {
            SDL_RenderCopy(renderer, b_pawn, NULL, &block_rect[1][i]);
            SDL_RenderPresent(renderer);
            }
        }

        if(!(b_rook==NULL))
        {
        SDL_RenderCopy(renderer, b_rook, NULL, &block_rect[0][0]);
        SDL_RenderCopy(renderer, b_rook, NULL, &block_rect[0][7]);
        SDL_RenderPresent(renderer);
        }

        if(!(b_knight==NULL))
        {
        SDL_RenderCopy(renderer, b_knight, NULL, &block_rect[0][1]);
        SDL_RenderCopy(renderer, b_knight, NULL, &block_rect[0][6]);
        SDL_RenderPresent(renderer);
        }

        if(!(b_bishop==NULL))
        {
        SDL_RenderCopy(renderer, b_bishop, NULL, &block_rect[0][2]);
        SDL_RenderCopy(renderer, b_bishop, NULL, &block_rect[0][5]);
        SDL_RenderPresent(renderer);
        }

        if(!(b_queen==NULL))
        {
        SDL_RenderCopy(renderer, b_queen, NULL, &block_rect[0][3]);
        SDL_RenderPresent(renderer);
        }

        if(!(b_king==NULL))
        {
        SDL_RenderCopy(renderer, b_king, NULL, &block_rect[0][4]);
        SDL_RenderPresent(renderer);
        }

        for(int i=0; i<7; i++)
        {
            if(!(w_pawn==NULL))
            {
            SDL_RenderCopy(renderer, w_pawn, NULL, &block_rect[6][i]);
            SDL_RenderPresent(renderer);
            }
        }

        if(!(w_knight==NULL))
        {
        SDL_RenderCopy(renderer, w_knight, NULL, &block_rect[7][1]);
        SDL_RenderCopy(renderer, w_knight, NULL, &block_rect[7][6]);
        SDL_RenderPresent(renderer);
        }

        if(!(w_bishop==NULL))
        {
        SDL_RenderCopy(renderer, w_bishop, NULL, &block_rect[7][2]);
        SDL_RenderCopy(renderer, w_bishop, NULL, &block_rect[7][5]);
        SDL_RenderPresent(renderer);
        }

        if(!(w_queen==NULL))
        {
        SDL_RenderCopy(renderer, w_queen, NULL, &block_rect[7][3]);
        SDL_RenderPresent(renderer);
        }

        if(!(w_king==NULL))
        {
        SDL_RenderCopy(renderer, w_king, NULL, &block_rect[7][4]);
        SDL_RenderPresent(renderer);
        }

        //SDL_RenderPresent(renderer);
}

void destroy()
{
    SDL_DestroyTexture(winTexture);
    SDL_DestroyTexture(b_king);
    SDL_DestroyTexture(b_pawn);
    SDL_DestroyTexture(b_rook);
    SDL_DestroyTexture(b_knight);
    SDL_DestroyTexture(b_bishop);
    SDL_DestroyTexture(b_queen);
    SDL_DestroyTexture(w_king);
    SDL_DestroyTexture(w_pawn);
    SDL_DestroyTexture(w_rook);
    SDL_DestroyTexture(w_knight);
    SDL_DestroyTexture(w_bishop);
    SDL_DestroyTexture(w_queen);
    SDL_DestroyRenderer(renderer);

    SDL_DestroyWindow(window);
}
