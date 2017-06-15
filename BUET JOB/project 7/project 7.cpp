#include<cstdio>
#include<iostream>
#include<algorithm>
#define SIZE 7500

using namespace std;

int x[SIZE];
//int c[]={1,5,10,25,50};

void Changes(int c[], int n)
{
    x[0]=1;
    int coin;
    for(int i=0; i<n; i++)
    {
        coin=c[i];
        for(int j=0; j<SIZE; j++)
            {
                if(x[j])
                    x[j+coin]+=x[j];
            }
    }
}

int main()
{
    int n, c[1000];

    scanf("%d", &n);

    for(int i=0; i<n; i++)
        scanf("%d", &c[i]);

    sort(c,c+n);

    Changes(c,n);
    int l;

    while(scanf("%d", &l)==1)
        printf("%d\n", x[l]);

    return 0;
}
