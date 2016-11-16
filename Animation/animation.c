#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <windows.h>



int main()
{
    int i,j,k=0;

    char *c="  My name is Aakash";

    for(i=0; i<strlen(c); i++)
    {

        for(j=i+1; j<=strlen(c); j++)
        {
            printf("%c", c[j]);
        }
        Sleep(100);
        k++;

        if(k!=strlen(c))
        system("cls");


    }

}
