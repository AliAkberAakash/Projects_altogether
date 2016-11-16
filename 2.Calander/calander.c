#include<stdio.h>
#include<conio.h>
#include<string.h>

int main()
{
    int i,j,k=32;
    char m[12][10]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    for(i=0;i<12;i++)
    {
        for(j=1; j<k; j++)
        {
            printf("%s\n\n", m[i]);
            printf("SAT   SUN   MON   TUE   WED  THU  FRI\n\n");
            printf("%3d   ", j);
            if(j%7==0) printf("\n\n");
            if(i==2&&j==29) break;
            else if((i==4||i==6||i==9||i==11)&&(j==30)) break;
        }
    }
    return 0;
}
