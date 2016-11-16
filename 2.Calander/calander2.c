#include<stdio.h>
#include<conio.h>
#include<string.h>

int main()
{
    int i,j,k=32;
    char m[12][10]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    for(i=0;i<12;i++)
    {
        printf("\n%s\n\n", m[i]);
        printf("SAT   SUN   MON   TUE   WED   THU   FRI\n\n");
        for(j=1; j<k; j++)
        {
            printf("%3d   ", j);
            if(j%7==0) printf("\n\n");
            if(i==1&&j==29) break;
            else if((i==3||i==5||i==8||i==10)&&(j==30)) break;
        }
        printf("\n\n");
    }
    return 0;
}
