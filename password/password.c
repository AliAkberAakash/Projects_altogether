#include<stdio.h>
#include<string.h>

int main()
{
    char a[]="AAKASH";
    char b[8];
    char c;
    int i,pw;
    printf("Enter your 6 character password:\n");
    for(i=0; i<6; i++)
    {
        b[i]=getch();
        printf("*");
    }

    printf("\nPress Enter!!");
    getch();

    pw=strcmp(a,b);

    if(pw==0)
        printf("\nCorrect Password!\n");
    else
        printf("\nWrong password.\nTry again!\n");
    return 0;
}
