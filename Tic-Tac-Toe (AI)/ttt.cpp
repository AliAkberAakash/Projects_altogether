#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int main()
{
    int a[10],temp,i,j,rnd=0;

    bool p=true, brk=false, nothing=true;

    for(i=0; i<10; i++)
        a[i]=0;

start:

    for(i=1; i<10; i++)
    {
        if(i+(i+1)+(i+2)<=1)
        {
            if(a[i]==1&&a[i+1]==1&&a[i+2]==1)
            {
                printf("You Win!!!\n");

                goto finish;
            }
            else if(a[i]==2&&a[i+1]==2&&a[i+2]==2)
            {
                printf("I Win!!!\n");

                goto finish;
            }
        }
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
        printf("Enter your position\n");
        scanf("%d",&temp);

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
            for(j=1; j<5; j++)
            {
                if(a[i]==1)
                {
                    if(i+j<=9)
                    {
                        if(a[i+j]==1)
                        {
                            if(i+(j*2)<=9)
                            {
                                if(a[i+(j*2)])
                                   {
                                       continue;
                                   }
                                else
                                    {
                                        if(a[i+(j*2)]==0)
                                        {
                                            a[i+(j*2)]=2;
                                            brk=true;
                                            p=true;
                                            break;
                                        }
                                    }
                            }
                            else
                            {
                                if(i-j>=1)
                                {
                                    if(a[i-j]==1)
                                    {
                                        continue;
                                    }
                                    else
                                    {
                                        if(a[i-j]==0)
                                        {
                                            a[i-j]=2;
                                            brk=true;
                                            p=true;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        else
                        {
                            if(i-j>=1)
                            {
                                if(a[i-j]==1)
                                {
                                    if(i-(j*2)>=1)
                                    {
                                        if(a[i-(j*2)]==1)
                                        {
                                            continue;
                                        }
                                        else
                                        {
                                            if(a[i-j*2]==0)
                                            {
                                                a[i-j*2]==1;
                                                p=true;
                                                brk=true;
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        if(i-j>=1)
                        {
                            if(a[i-j]==1)
                            {
                                if(i-(j*2)>=1)
                                {
                                    if(a[i-(j*2)]==1)
                                    {
                                        continue;
                                    }
                                    else
                                    {
                                        a[i-(j*2)]==2;
                                        p=true;
                                        brk=true;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if(brk)
            {
                nothing=false;
                break;
            }

        }

        if(nothing)
        {
            for(i=1; i<10; i++)
            {
                if(a[i]==0)
                {
                    a[i]=2;
                    p=true;
                    break;
                }

            }

        }

    }

    Sleep(1000);

    goto start;


    finish:

        Sleep(500);

        return 0;
    }
