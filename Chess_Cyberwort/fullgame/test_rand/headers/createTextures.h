#ifndef CREATETEXTURES_H_INCLUDED
#define CREATETEXTURES_H_INCLUDED
#include"initialize.h"
#include<iostream>

using namespace std;

    //initializing the window and selector texture;
    SDL_Texture* winTexture=NULL;
    SDL_Texture* selector=NULL;

    //initializing the renderer
    SDL_Renderer* renderer=NULL;

    //initializing the black troops
    SDL_Texture* b_king;
    SDL_Texture* b_queen;
    SDL_Texture* b_knight;
    SDL_Texture* b_rook;
    SDL_Texture* b_bishop;
    SDL_Texture* b_pawn;

    //initializing the white troops
    SDL_Texture* w_king;
    SDL_Texture* w_queen;
    SDL_Texture* w_knight;
    SDL_Texture* w_rook;
    SDL_Texture* w_bishop;
    SDL_Texture* w_pawn;

    void load(SDL_Surface* surface)
    {
    surface=IMG_Load("icons/chessboard2.png");
    if(surface==NULL)
        cout<<"Error"<<endl;
    winTexture=SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
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
    }

void destroy(SDL_Window* window)
{
    SDL_DestroyTexture(winTexture);
    SDL_DestroyRenderer(renderer);

    SDL_DestroyWindow(window);
}


#endif // CREATETEXTURES_H_INCLUDED
