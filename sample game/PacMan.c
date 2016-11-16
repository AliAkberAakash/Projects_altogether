/*
*
* Program Name:
* Details:
* Solved By: Liverwort
* Date: 27.6.16 (modified)
* Version: 1.0.0
*
*/

#define WINVER 0x0500
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
void game_over();

void game_over()
{
    char c;
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n                      GAME OVER!!!\n");

    Sleep(1000);
    system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n\n\n            Press Any key to continue!\n");

    getch();

    //Sleep(10000);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n                    Play again?(y/n)\n");

    no:
    c=getchar();
    //getch();
    if(c=='y')
        main();
    if(c!='n'&&c!='y')
        goto no;


}


int main()
{

    int i,j,k=1,l=1,f=1,p,q;
    char c;

   system("cls");

   printf("************************************************************\n");
   printf("*o                                                         *\n");
    for(q=0; q<25-l; q++)
        printf("*                                                          *\n");

     printf("************************************************************");

    aakash:

    c=getch();
    system("cls");

    if(c=='d')
    {
        printf("************************************************************\n");
        k++;
        if(k>58||k<1)
            goto END;

        for(i=1; i<l; i++)
            printf("*                                                          *\n");
        printf("*");
        for(i=1; i<k; i++)
            printf(" ");
    }
    else if(c=='s')
    {
        printf("************************************************************\n");
        l++;
        if(l>25||l<1)
            goto END;

        for(i=1; i<l; i++)
            printf("*                                                          *\n");
        printf("*");
        for(i=1; i<k; i++)
            printf(" ");
    }

    else if(c=='w')
    {
        printf("************************************************************\n");
        l--;
        if(l>25||l<1)
            goto END;

        for(i=1; i<l; i++)
            printf("*                                                          *\n");
        printf("*");
        for(i=1; i<k; i++)
            printf(" ");
    }

    else if(c=='a')
    {
        printf("************************************************************\n");
        k--;
        if(k<1||k>58)
            goto END;

        for(i=1; i<l; i++)
            printf("*                                                          *\n");
        printf("*");
        for(i=1; i<k; i++)
            printf(" ");
    }

    else
        goto aakash;
    printf("o");

    for(p=0; p<58-k; p++)
        printf(" ");
    printf("*\n");
    for(q=0; q<25-l; q++)
        printf("*                                                          *\n");

     printf("************************************************************\n");

    goto aakash;

    END:
        game_over();
    return 0;
}

