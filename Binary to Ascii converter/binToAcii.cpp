/*
Program Name : Binary to ASCII Converter
Details      : This program can take any binary number as input and output its equivalent ASCII code.
               It also has an additional "Decimal to Binary converter" sub program.
Solved By    : Liverwort
Date         : 13.6.16
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>

int decimalToBin(int decimal);
int binToDecimal(int bin);
char menu();

int decimalToBin(int decimal)
{
    int i=0,bin[100000];

    while(decimal)
    {
        bin[i]=decimal%2;
        decimal=decimal/2;

        i++;
    }

        while(i--)
        printf("%d", bin[i]);

    printf("\n");
}

int binToDecimal(int bin)
{
    int i=0, decimal=0,v;

    while(bin)
    {
        v=bin%10;
        decimal+=pow(2,i)*v;
        bin=bin/10;
        i++;
    }

    return decimal;

}

int main()
{
    int decimal,binary,v;
    char c;

    system("Color 1A");
    printf("Chose your option from the menu:\n\n");
    printf("1. Binary to ASCII converter (b)\n");
    printf("2. Use the Decimal to binary converter (d)\n\n");

    scanf("%c", &c);

    if(c=='d')
        {
            fflush(stdout);
            fflush(stdin);
            system("cls");
            system("Color 2B");
            printf("Enter the decimal number:\n\n");

            scanf("%d", &decimal);

            printf("The equivalent binary is:\n");
            decimalToBin(decimal);

            again2:
            printf("\n\nEnter m to go to main menu or e to exit\n\n");
            getchar();
            scanf("%c", &c);

            if(c=='m')
            {
               fflush(stdout);
               fflush(stdin);
               system("cls");
                main();
            }

            else if(c=='e')
                goto exit;

            else
            {
                printf("Not a valid choice.\n\nChoose again:\n\n");
                goto again2;
            }
        }

    else if(c=='b')
    {
        fflush(stdout);
        fflush(stdin);
        system("cls");
        system("Color 3E");
        printf("Enter the binary number:\n\n");

            scanf("%d", &binary);

            v=binToDecimal(binary);

            if((v<0)||(v>128))
                printf("\n\n\nSorry no such ASCII character exists!\n\n");
            else
            printf("\n\n\nThe requested ASCII value is: %c\n",v);

            again1:
            printf("\n\nEnter m to go to main menu or e to exit\n\n");

            getchar();
            scanf("%c", &c);

            if(c=='m')
            {
              fflush(stdout);
              fflush(stdin);
              system("cls");
              main();
            }
            else if(c=='e')
                goto exit;

            else
            {
                printf("Not a valid choice.\n\nChoose again:\n\n");
                goto again1;
            }
    }

    else
    {
        printf("Not a valid choice.\n\nChoose again:\n\n");
        getchar();
        main();
    }

    exit:

    fflush(stdout);
    fflush(stdin);
    system("cls");

    printf("Thanks for Using Our Program ^_^\n\n");
    printf("Powered By Liverwort Softwares LTD.\n");

    return 0;
}

