#include<stdio.h>
#include<conio.h>
int main()
{
    int i,j,a;
    for(i=1; i<=12; i++)
    {
        for(j=1; j<=12; j++)
        {
            a=i*j;
            printf("%3d   ", a);
        }
        printf("\n");
    }
}
