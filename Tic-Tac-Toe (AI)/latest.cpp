
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>



int main()
{
    int a[10],temp,i,j,rnd=0;

    bool p=true, brk=false, nothing=true, player=false, computer=false;

    for(i=0; i<10; i++)
        a[i]=0;


    start:

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

    if(p)
    {
        int temp;

        printf("Enter your number:\n");

        scanf("%d", &temp);

         if(temp<1||temp>9||a[temp]!=0)
            goto start;
        else
        {
            a[temp]=1;
            nothing=true;
            p=false;
        }


    }
    else
    {
        for(i=1; i<9; i++)
        {
            if(i==1)
            {
                if(a[1]==1)
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
                            a[3]=2;
                            p=true;
                            nothing=false;
                            break;
                        }
                    }
                    else if(a[3]==1)
                    {
                        if(a[2]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            a[2]==2;
                            nothing=false;
                            p=true;
                            break;
                        }
                    }
                    else if(a[4]==1)
                    {
                        if(a[7]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            a[7]=2;
                            p=true;
                            nothing=false;
                            break;
                        }

                    }
                    else if(a[7]==1)
                    {
                        if(a[4]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            a[4]=2;
                            p=true;
                            nothing=false;
                            break;
                        }

                    }
                    else if(a[5]==1)
                    {
                        if(a[9]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            a[9]=2;
                            p=true;
                            nothing=false;
                            break;
                        }

                    }
                    else if(a[9]==1)
                    {
                        if(a[5]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            a[5]=2;
                            p=true;
                            nothing=false;
                            break;
                        }

                    }
                }
            }

            if(i==2)
            {
                if(a[2]==1)
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
                            a[1]=2;
                            p=true;
                            nothing=false;
                            break;
                        }
                    }
                    else if(a[1]==1)
                    {
                        if(a[3]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            a[3]=2;
                            p=true;
                            nothing=false;
                            break;
                        }

                    }
                    else if(a[5]==1)
                    {
                        if(a[8]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            a[8]=2;
                            p=true;
                            nothing=false;
                            break;
                        }

                    }
                    else if(a[8]==1)
                    {
                        if(a[5]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            a[5]=2;
                            p=true;
                            nothing=false;
                            break;
                        }

                    }

                }
            }

            if(i==3)
            {
                if(a[3]==1)
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
                            a[1]=2;
                            p=true;
                            nothing=false;
                            break;
                        }
                    }
                    else if(a[1]==1)
                    {
                        if(a[2]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            a[2]=2;
                            p=true;
                            nothing=false;
                            break;
                        }

                    }
                    else if(a[5]==1)
                    {
                        if(a[7]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            a[7]=2;
                            p=true;
                            nothing=false;
                            break;
                        }

                    }
                    else if(a[7]==1)
                    {
                        if(a[5]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            a[5]=2;
                            p=true;
                            nothing=false;
                            break;
                        }

                    }

                    else if(a[6]==1)
                    {
                        if(a[9]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            a[9]=2;
                            p=true;
                            nothing=false;
                            break;
                        }

                    }
                    else if(a[9]==1)
                    {
                        if(a[6]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            a[6]=2;
                            p=true;
                            nothing=false;
                            break;
                        }

                    }

                }
            }

            if(i==4)
            {
                if(a[4]==1)
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
                            a[6]=2;
                            nothing=false;
                            p=true;
                            break;
                        }
                    }
                    else if(a[6]==1)
                    {
                        if(a[5]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            a[5]=2;
                            p=true;
                            nothing=false;
                            break;
                        }

                    }
                    else if(a[7]==1)
                    {
                        if(a[1]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            a[1]=2;
                            nothing=false;
                            p=true;
                            break;

                        }
                    }
                    else if(a[1]==1)
                    {
                        if(a[7]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            a[7]=2;
                            nothing=false;
                            p=true;
                            break;
                        }
                    }

                }
            }

            if(i==5)
            {
                if(a[5]==1)
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
                            a[4]==2;
                            nothing=false;
                            p=true;
                            break;
                        }
                    }
                    else if(a[4]==1)
                    {
                        if(a[6]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            a[6]==2;
                            nothing=false;
                            p=true;
                            break;
                        }
                    }
                    else if(a[2]==1)
                    {
                        if(a[8]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            a[8]==2;
                            nothing=false;
                            p=true;
                            break;
                        }
                    }
                    else if(a[8]==1)
                    {
                        if(a[2]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            a[2]==2;
                            nothing=false;
                            p=true;
                            break;
                        }
                    }
                    else if(a[9]==1)
                    {
                        if(a[1]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            a[1]==2;
                            nothing=false;
                            p=true;
                            break;
                        }
                    }
                    else if(a[1]==1)
                    {
                        if(a[9]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            a[9]==2;
                            nothing=false;
                            p=true;
                            break;
                        }
                    }
                }
                else if(a[3]==1)
                    {
                        if(a[7]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            a[7]=2;
                            p=true;
                            nothing=false;
                            break;
                        }

                    }
                    else if(a[7]==1)
                    {
                        if(a[3]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            a[3]=2;
                            p=true;
                            nothing=false;
                            break;
                        }

                    }
            }
            else if(i==6)
            {
                    if(a[3]==1)
                    {
                        if(a[9]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            a[9]==2;
                            nothing=false;
                            p=true;
                            break;
                        }
                    }
                    else if(a[9]==1)
                    {
                        if(a[3]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            a[3]==2;
                            nothing=false;
                            p=true;
                            break;
                        }
                    }
                    else if(a[5]==1)
                    {
                        if(a[4]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            a[4]==2;
                            nothing=false;
                            p=true;
                            break;
                        }
                    }
                    else if(a[4]==1)
                    {
                        if(a[5]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            a[5]==2;
                            nothing=false;
                            p=true;
                            break;
                        }
                    }
            }
            if(i==7)
            {
                if(a[7]==1)
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
                            a[9]=2;
                            p=true;
                            nothing=false;
                            break;
                        }

                    }
                    else if(a[9]==1)
                    {
                        if(a[8]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            a[8]=2;
                            p=true;
                            nothing=false;
                            break;
                        }

                    }
                    else if(a[4]==1)
                    {
                        if(a[1]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            a[1]=2;
                            p=true;
                            nothing=false;
                            break;
                        }

                    }
                    else if(a[1]==1)
                    {
                        if(a[4]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            a[4]=2;
                            p=true;
                            nothing=false;
                            break;
                        }

                    }
                    else if(a[5]==1)
                    {
                        if(a[3]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            a[3]=2;
                            p=true;
                            nothing=false;
                        }

                    }
                    else if(a[3]==1)
                    {
                        if(a[5]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            a[5]=2;
                            p=true;
                            nothing=false;
                            break;
                        }

                    }
                }
            }
        }

        if(nothing)
        {
            for(i=1; i<9; i++)
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
