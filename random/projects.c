/* Write a C program to convert any integer to its hexadecimal equivalent.
Programmer: Aakash
Date:2.3.16 */
#include<stdio.h>
#include<conio.h>
#include<math.h>

int main()
{
    int x,i=0,a[20],j;
    printf("Enter the Integer number\n");
    scanf("%d", &x);
    if(x==0)
        printf("The Hexadecimal equivalent is:\n 0\n");
    while(x!=0)
    {
        a[i]=x%16;
        x=x/16;
        i++;
    }
    printf("The hexadecimal equivalent is\n");
    for (j=i-1; j>=0; j--) /*The first value of j is i-1, which means it will be the last element of a[i],
        so we are reversing the values of a[i] to get the Hexadecimal value */
    {
       switch (a[j])
       {
   case 10:
    printf("A");
    break;
   case 11:
    printf("B");
    break;
   case 12:
    printf("C");
    break;
   case 13:
    printf("D");
    break;
   case 14:
    printf("E");
    break;
   case 15:
    printf("F");
    break;
   default:
    printf("%d", a[j]);
    break;
      }
    }
    getch();
}
