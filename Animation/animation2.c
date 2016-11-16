#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <windows.h>



int main()
{
    int i,j,k=0,m;

    char *c="  My name is Aakash";

    for(i=0; i<5; i++)
    {

       // for(m=0; m<i; m++)
        //{
            //printf("\n");
        //}

        for(j=0; j<i; j++)
        {
            printf(" ");
        }

       // for(j=0; j<i; j++)
        //{
            printf("*\*\n**");
        //}


        Sleep(100);
        k++;

       // if(k!=30)
//        system("cls");

        //main();


    }

}
