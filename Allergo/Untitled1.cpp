/*This is a C program which can take an integer number as an input and can print it
in a reversed form as an output...
Solved By : Farhana Ahmed Fima
Date : 04.07.16
*/

#include<stdio.h>
int main ()

{
    long long int a,b,r=0;
    printf("Enter any integer here:\n");
    scanf("%lld",&a);
    for(;a!=0;)
    {
        b=a%10;
        r=r*10+b;
        a=a/10;
    }
    printf("The reversed integer is: %lld\n",r);
    main();
    return 0;
}
