#include<cstdio>
#include<windows.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_keyboard.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<cstdlib>
#define pos SDL_WINDOWPOS_CENTERED

int newbuttonx(int x);
int newbuttony(int y);

int main(int argc, char *argv[])
{
    SDL_Window* window=NULL;

    SDL_Surface* board=IMG_Load("images/board.png");
    SDL_Surface* cross=IMG_Load("images/cross.png");
    SDL_Surface* circle=IMG_Load("images/circle.png");

    SDL_Renderer* renderer=NULL;

    SDL_Rect block_rect[3][3];
    SDL_Rect window_rect;

    SDL_Texture* t_board=NULL;

    SDL_Texture* t_cross=NULL;
    SDL_Texture* t_circle=NULL;

    SDL_FreeSurface(board);
    board=NULL;
    SDL_FreeSurface(cross);
    cross=NULL;

    SDL_FreeSurface(circle);
    circle=NULL;

    int a[10],temp,i,j,f,rnd=0;

    for(int i=0; i<3; i++)
    {
        for (int  j=0; j<3; j++)
        {
            block_rect[i][j].x=j*80;
            block_rect[i][j].y=i*80;
            block_rect[i][j].h=80;
            block_rect[i][j].w=80;
        }
    }

    SDL_Init( SDL_INIT_EVERYTHING );
    IMG_Init( IMG_INIT_PNG );
    window = SDL_CreateWindow("TTT", pos, pos, 240,240, SDL_WINDOW_SHOWN);
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    t_board=SDL_CreateTextureFromSurface(renderer,board);

    window_rect.h=240;
    window_rect.w=240;


    int z,o;

    bool p=true, brk=false, nothing=true, player=false, computer=false;

    for(i=0; i<10; i++)
        a[i]=0;


    start:

    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, t_board, NULL, &window_rect);
    SDL_RenderPresent(renderer);


    int k=0;
    for(i=0;i<3;i++)
    {
        for(j=0; j<3; j++)
        {
            if(a[k+j+1]==1)
            SDL_RenderCopy(renderer, t_circle, NULL, &block_rect[i][j]);
            else if(a[k+j+1]==2)
            SDL_RenderCopy(renderer, t_cross, NULL, &block_rect[i][j]);

        }
    }

        if(player)
        {
            printf("Player wins\n");
            goto finish;
        }

    system("cls");



    /**first row**/
    printf("..................................\n");
    printf(".          .          .          .\n");
    printf(".          .          .          .\n");
    if(a[1]==1)
        printf(".  Player  ");
    else if(a[1]==2)
        printf(". Computer ");
    else
        printf(".1         ");

    if(a[2]==1)
        printf(".  Player  .");
    else if(a[2]==2)
        printf(". Computer .");
    else
        printf(".2         .");

    if(a[3]==1)
        printf("  Player  .\n");
    else if(a[3]==2)
        printf(" Computer .\n");
    else
        printf("3         .\n");

    printf(".          .          .          .\n");
    printf(".          .          .          .\n");

    /**second row**/

    printf("..................................\n");
    printf(".          .          .          .\n");
    printf(".          .          .          .\n");
    if(a[4]==1)
        printf(".  Player  ");
    else if(a[4]==2)
        printf(". Computer ");
    else
        printf(".4         ");

    if(a[5]==1)
        printf(".  Player  .");
    else if(a[5]==2)
        printf(". Computer .");
    else
        printf(".5         .");

    if(a[6]==1)
        printf("  Player  .\n");
    else if(a[6]==2)
        printf(" Computer .\n");
    else
        printf("6         .\n");

    printf(".          .          .          .\n");
    printf(".          .          .          .\n");

    /**third row**/

    printf("..................................\n");
    printf(".          .          .          .\n");
    printf(".          .          .          .\n");
    if(a[7]==1)
        printf(".  Player  ");
    else if(a[7]==2)
        printf(". Computer ");
    else
        printf(".7         ");

    if(a[8]==1)
        printf(".  Player  .");
    else if(a[8]==2)
        printf(". Computer .");
    else
        printf(".8         .");

    if(a[9]==1)
        printf("  Player  .\n");
    else if(a[9]==2)
        printf(" Computer .\n");
    else
        printf("9         .\n");

    printf(".          .          .          .\n");
    printf(".          .          .          .\n");
    printf("..................................\n\n\n");

    /**check if draw**/

    f=0;

    for(i=1; i<9; i++)
    {
        if(a[i]==0)
            f=1;
    }

    if(!f)
    {
        printf("Match draw!\n");
        goto finish;
    }


    if(p)
    {
        SDL_Event e;
        bool work=true;

        while(work)
        {
            SDL_Delay(16);
            while(SDL_PollEvent(&e))
            {
                SDL_Delay(16);
                if(e.type==SDL_QUIT)
                {
                    work=false;
                    p=false;
                    break;
                }

                if(e.type==SDL_MOUSEBUTTONDOWN)
                {
                    if(e.button.button==SDL_BUTTON_LEFT)
                    z=newbuttonx(e.button.x);
                    o=newbuttony(e.button.y);
                }

                k=0;
                for(i=0;i<3; i++)
                {
                    for(j=0; j<3;j++)
                    {
                        if(block_rect[i][j].x==z&&block_rect[i][j].y==o)
                        {
                            a[j+k+1]==1;
                        }
                    }
                }
            }


        }
        int x;
        printf("Enter your position\n");

        scanf("%d", &x);

        if(a[x]==0&&x>=1&&x<=9)
        {
            a[x]=1;
            p=false;
            nothing=true;
        }

        goto start;

    }
    else
    {
        for(i=1; i<=9; i++)
        {
            if(a[i]==1)
            {
                if(i==1)
                {
                    if(a[2]==1)
                    {
                        if(a[3]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            if(a[3]==0)
                            {
                                a[3]=2;
                                p=true;
                                nothing=false;
                                break;
                            }
                        }
                    }
                    if(a[3]==1)
                    {
                        if(a[2]==0)
                        {
                            a[2]=2;
                            p=true;
                            nothing=false;
                            break;
                        }
                    }
                    if(a[4]==1)
                    {
                        if(a[7]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            if(a[7]==0)
                            {
                            a[7]=2;
                            p=true;
                            nothing=false;
                            break;
                            }
                        }
                    }
                    if(a[7]==1)
                    {
                        if(a[4]==0)
                        {
                            a[4]=2;
                            p=true;
                            nothing=false;
                            break;
                        }
                    }
                    if(a[5]==1)
                    {
                        if(a[9]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            if(a[9]==0)
                            {
                            a[9]=2;
                            p=true;
                            nothing=false;
                            break;
                            }
                        }
                    }
                    if(a[9]==1)
                    {
                        if(a[5]==0)
                        {
                            a[5]=2;
                            p=true;
                            nothing=false;
                            break;
                        }
                    }
                }
                if (i==2)
                {
                    if(a[3]==1)
                    {
                        if(a[1]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            if(a[1]==0)
                            {
                                a[1]=2;
                                p=true;
                                nothing=false;
                                break;
                            }
                        }
                    }
                    if(a[1]==1)
                    {
                        if(a[3]==0)
                        {
                            a[3]=2;
                            p=true;
                            nothing=false;
                            break;
                        }
                    }
                   if(a[5]==1)
                    {
                        if(a[8]==1)
                        {
                            player=true;
                            break;
                        }
                        else if(a[8]==0)
                        {
                            a[8]=2;
                            p=true;
                            nothing=false;
                            break;
                        }
                    }
                   if(a[8]==1)
                    {
                        if(a[5]==0)
                        {
                            a[5]=2;
                            p=true;
                            nothing=false;
                            break;
                        }
                    }

                }
                if(i==3)
                {
                    if(a[2]==1)
                    {
                        if(a[1]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            if(a[1]==0)
                            {
                            a[1]=2;
                            p=true;
                            nothing=false;
                            break;
                            }
                        }
                    }
                    if(a[1]==1)
                    {
                        if(a[2]==0)
                        {
                            a[2]=2;
                            p=true;
                            nothing=false;
                            break;
                        }
                    }
                    if(a[6]==1)
                    {
                        if(a[9]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            if(a[9]==0)
                            {
                            a[9]=2;
                            p=true;
                            nothing=false;
                            break;
                            }
                        }
                    }
                    if(a[9]==1)
                    {
                        if(a[6]==0)
                        {
                            a[6]=2;
                            p=true;
                            nothing=false;
                            break;
                        }
                    }
                    if(a[5]==1)
                    {
                        if(a[7]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            if(a[7]==0)
                            {
                            a[7]=2;
                            p=true;
                            nothing=false;
                            break;
                            }
                        }
                    }
                    if(a[7]==1)
                    {
                        if(a[5]==0)
                        {
                            a[5]=2;
                            p=true;
                            nothing=false;
                            break;
                        }
                    }
                }
                else if(i==4)
                {
                    if(a[5]==1)
                    {
                        if(a[6]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            if(a[6]==0)
                            {
                            a[6]=2;
                            p=true;
                            nothing=false;
                            break;
                            }
                        }
                    }
                    if(a[6]==1)
                    {
                        if(a[5]==0)
                            {
                            a[5]=2;
                            p=true;
                            nothing=false;
                            break;
                            }
                    }
                    if(a[1]==1)
                    {
                        if(a[7]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            if(a[7]==0)
                            {
                                a[7]==2;
                                p=true;
                                nothing=false;
                                break;
                            }
                        }
                    }
                    if(a[7]==1)
                    {
                        if(a[1]==0)
                            {
                            a[1]=2;
                            p=true;
                            nothing=false;
                            break;
                            }
                    }

                }

                else if(i==5)
                {
                    if(a[6]==1)
                    {
                        if(a[4]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            if(a[4]==0)
                            {
                            a[4]=2;
                            p=true;
                            nothing=false;
                            break;
                            }
                        }
                    }
                    if(a[9]==1)
                    {
                        if(a[1]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            if(a[1]==0)
                            {
                            a[1]=2;
                            p=true;
                            nothing=false;
                            break;
                            }
                        }
                    }
                    if(a[7]==1)
                    {
                        if(a[3]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            if(a[3]==0)
                            {
                            a[3]=2;
                            p=true;
                            nothing=false;
                            break;
                            }
                        }
                    }
                    if(a[8]==1)
                    {
                        if(a[2]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            if(a[2]==0)
                            {
                            a[2]=2;
                            p=true;
                            nothing=false;
                            break;
                            }
                        }
                    }
                }
                if(i==7)
                {
                    if(a[8]==1)
                    {
                        if(a[9]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            if(a[9]==0)
                            {
                            a[9]=2;
                            p=true;
                            nothing=false;
                            break;
                            }
                        }
                    }
                    if(a[9]==1)
                    {
                        if(a[8]==0)
                            {
                            a[8]=2;
                            p=true;
                            nothing=false;
                            break;
                            }
                    }
                }
                if(i==8)
                {
                    if(a[9]==1)
                    {
                        if(a[7]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            if(a[7]==0)
                            {
                            a[7]=2;
                            p=true;
                            nothing=false;
                            break;
                            }
                        }
                    }
                }
            }

        }

        if(nothing)
        {
            for(i=1; i<10;i++)
            {
                if(a[i]==0)
                {
                    a[i]=2;
                    p=true;
                    nothing=false;
                    break;
                }
            }

        }
    }

    Sleep(100);

    goto start;

    finish:

        Sleep(100);

    return 0;
}

newbuttonx(int a)
{
    int x=0;
        if(a>0&&a<79)
        x=0;
    else if(a>80&&a<160)
        x=80;
    else if(a>160&&a<240)
        x=160;
    else if(a>240&&a<320)
        x=240;

    return x;
}

newbuttony(int b)
{
    int y=0;
        if(b>0&&b<79)
        y=0;
    else if(b>80&&b<160)
        y=80;
    else if(b>160&&b<240)
        y=160;
    else if(b>240&&b<320)
        y=240;

    return y;
}
