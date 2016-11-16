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

SDL_Window* window=NULL;
//SDL_Surface* winSurface=NULL;
SDL_Surface* board=NULL;
SDL_Surface* sprite=NULL;
SDL_Texture* boardT=NULL;
SDL_Texture* spriteT=NULL;
SDL_Renderer* renderer1=NULL;
SDL_Renderer* renderer=NULL;

SDL_Rect sprite_rect;

int main(int argc, char* argv[])
{
//             SDL_Rect topLeftViewport;
//                topLeftViewport.x = 0;
//                topLeftViewport.y = 0;
//                topLeftViewport.w = 80;
//                topLeftViewport.h = 80;
//                SDL_RenderSetViewport( renderer1, &topLeftViewport );


    sprite_rect.x=0;
    sprite_rect.y=0;
    sprite_rect.h=80;
    sprite_rect.w=80;

    SDL_Init( SDL_INIT_EVERYTHING );
    IMG_Init( IMG_INIT_PNG );

    window=SDL_CreateWindow("window", pos, pos, sw, sh, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    board=IMG_Load("icons/chessboard2.png");
    sprite=IMG_Load("icons/b_bishop.png");
    if(sprite==NULL)
        cout<<"Error!!"<<endl;

    boardT=SDL_CreateTextureFromSurface(renderer, board);
    SDL_FreeSurface(board);

    spriteT=SDL_CreateTextureFromSurface(renderer1, sprite);
    SDL_FreeSurface(sprite);

    while (1) {
        SDL_Event e;
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                break;
            }

            else if(e.type==SDL_KEYDOWN)
            {

        const Uint8 *keystate = SDL_GetKeyboardState(NULL);
                            if (keystate[SDL_SCANCODE_RETURN] )
                            {
                                SDL_DestroyTexture(boardT);
                                //SDL_DestroyRenderer(renderer);
                            }

        }

        SDL_RenderClear(renderer);
        SDL_RenderClear(renderer1);
        SDL_RenderCopy(renderer, boardT, NULL, NULL);
        SDL_RenderCopy(renderer1, spriteT, NULL, &sprite_rect);
        SDL_RenderPresent(renderer);
        SDL_RenderPresent(renderer1);
        }

    }

    SDL_DestroyTexture(boardT);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(spriteT);
    SDL_DestroyRenderer(renderer1);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}
