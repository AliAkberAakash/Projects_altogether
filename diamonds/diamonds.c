#include<stdio.h>
int diamond1(int n);
int diamond2(int n);

int diamond1(int n)
{
    int i,j,k,l;
    l=(n-n/2)-1;

    for(i=1; i<=n; i=i+2)
    {
        for(j=l; j>=1; j--)
            printf(" ");
        l--;
        for(k=1; k<=i; k++)
            printf("*");
        printf("\n");
    }
}

int diamond2(int n)
{
    int i,j,k,l,m;
    l=1;
    m=n-2;
    for(i=1; i<n; i=i+2)
    {
        for(j=1; j<=l; j++)
            printf(" ");
            l++;

        for(k=m; k>=1; k--)
            printf("*");
        m-=2;
        printf("\n");
    }
}

int main()
{
    int n,i;
    printf("Enter the number of grids (odd number):\n");
    scanf("%d", &n);

    diamond1(n);
    diamond2(n);
}
