#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include <windows.h>

int main()
{
    start1:

    int i, a[10000],n,p=0;

    int k=0;

    n=0;

    start2:

    system("cls");

    printf("**************\n");
    for(i=0; i<p; i++)
        printf("*            *\n");
    printf("*");
    for(int j=1; j<=n; j++)
        printf(" ");
    printf("*");
    for(int j=1; j<=(11-n); j++)
        printf(" ");
    printf("*\n");
    printf("*");
    for(int j=1; j<=n+1; j++)
        printf(" ");
    printf("*");
    for(int j=1; j<=(10-n); j++)
        printf(" ");
    printf("*\n");
    for(i=0; i<15-p; i++)
        printf("*            *\n");
    printf("**************\n");

    p++;

    Sleep(500);

    k++;

    if(k==16)
        goto start1;
    else
        goto start2;

    return 0;
}
