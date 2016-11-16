#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,k=0,d;
    int carry=0;
    char a[50];
    char b[50];
    int c[80];
printf("Enter two numbers.\n");
    gets(a);
    i=strlen(a)-1;
    gets(b);
    j=strlen(b)-1;
 if (i>j)
 {
     while(i>=0)
    {
        if(j>=0)
      {
      d=(a[i]+b[j]-96);
      c[k]=(d+carry)%10;
      carry=(d+carry)/10;
      i--;
      k++;
      j--;
      }
      else
        {
      d=(a[i]-48);
      c[k]=(d+carry)%10;
      carry=(d+carry)/10;
      i--;
      k++;
        }
    }
 }
 else
 {
     while(j>=0)
    {
        if(i>=0)
      {
      d=(a[i]+b[j]-96);
      c[k]=(d+carry)%10;
      carry=(d+carry)/10;
      i--;
      k++;
      j--;
      }
      else
        {
      d=(b[j]-48);
      c[k]=(d+carry)%10;
      carry=(d+carry)/10;
      j--;
      k++;
        }
    }
 }
    if (carry!=0)
    printf("%d", carry);
    k--;
    while(k>=0)
    {
        printf("%d", c[k]);
        k--;
    }
    printf("\n\n");
    main();
}
