#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    int i,j,n;
    char a[30][10];
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        scanf("%s", a[i]);

    }

    for(i=0; i<100; i++)
    {
        for(j=0; j<100; j++)
        {
            if (a[j]==i)
                printf("%s", a[i]);
        }
    }
}
