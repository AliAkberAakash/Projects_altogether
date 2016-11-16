#include<SDL2/SDL.h>
#include<SDL2/SDL_keyboard.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<cstdlib>
#define pos SDL_WINDOWPOS_CENTERED

using namespace std;

const int sw=640;
const int sh=640;

SDL_Window* window=NULL;

SDL_Surface* board=NULL;

SDL_Texture* boardT=NULL;
SDL_Texture* spriteT=NULL;
SDL_Texture* sprite2=NULL;

SDL_Renderer* renderer=NULL;
SDL_Renderer* renderer1=NULL;

SDL_Rect sprite_rect;
SDL_Rect rect2;

int main(int argc, char* argv[])
{

    sprite_rect.x=80;
    sprite_rect.y=0;
    sprite_rect.h=80;
    sprite_rect.w=80;

    rect2.x=80;
    rect2.y=80;
    rect2.h=80;
    rect2.w=80;

    SDL_Init( SDL_INIT_EVERYTHING );
    IMG_Init( IMG_INIT_PNG );

    window=SDL_CreateWindow("window", pos, pos, sw, sh, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    board=IMG_Load("icons/chessboard2.png");

    boardT=SDL_CreateTextureFromSurface(renderer, board);
    SDL_FreeSurface(board);

    board=IMG_Load("icons/b_bishop.png");
    if(board==NULL)
        cout<<"Error!!"<<endl;

    spriteT=SDL_CreateTextureFromSurface(renderer, board);
    SDL_FreeSurface(board);

        board=IMG_Load("icons/b_pawn.png");
    if(board==NULL)
        cout<<"Error!!"<<endl;

    spriteT=SDL_CreateTextureFromSurface(renderer, board);
    SDL_FreeSurface(board);

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
                                SDL_DestroyTexture(spriteT);
                                //SDL_DestroyRenderer(renderer);
                            }
                            if (keystate[SDL_SCANCODE_DOWN] )
                            {
                                sprite_rect.y+=80;
                            }

        }

        SDL_RenderClear(renderer);
        //SDL_RenderClear(renderer1);
        SDL_RenderCopy(renderer, boardT, NULL, NULL);
        SDL_RenderCopy(renderer, spriteT, NULL, &sprite_rect);
        SDL_RenderCopy(renderer, sprite2, NULL, &rect2);
        SDL_RenderPresent(renderer);
        //SDL_RenderPresent(renderer1);
        }

    }

    SDL_DestroyTexture(boardT);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(spriteT);

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}
