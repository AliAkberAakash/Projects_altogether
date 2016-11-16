#ifndef PACMANHEADER_H_INCLUDED
#define PACMANHEADER_H_INCLUDED



#endif // PACMANHEADER_H_INCLUDED


/*
*
* Program Name: Pac Man
* Details: Its a Classinc game
* Solved By: Liverwort
* Date: 24.6.16
*
*/

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>


int pac()
{

    int i,j,k=0,l=0;
    char c;

   printf("*");

    aakash:

    c=getch();
    system("cls");

    if(c=='d')
    {
        k++;
        for(i=0; i<l; i++)
            printf("\n");
        for(i=0; i<k; i++)
            printf(" ");
    }
    else if(c=='s')
    {
        l++;

        for(i=0; i<l; i++)
            printf("\n");
        for(i=0; i<k; i++)
            printf(" ");
    }

    else if(c=='w')
    {
        l--;

        for(i=0; i<l; i++)
            printf("\n");
        for(i=0; i<k; i++)
            printf(" ");
    }

    else if(c=='a')
    {
        k--;

        for(i=0; i<l; i++)
            printf("\n");
        for(i=0; i<k; i++)
            printf(" ");
    }

    printf("*");
    //Sleep(100);
    goto aakash;

    return 0;
}

