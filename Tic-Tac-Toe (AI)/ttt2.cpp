#include<stdio.h>


int main()
{
    for(int i=9; i>=0; i--)
        if(i)
    {
        continue;
    }
    else
        printf("%d", i);

    return 0;
}
