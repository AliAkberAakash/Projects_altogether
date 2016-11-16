#include <stdio.h>

int main() {

    int N,hundred,fifty,twenty,ten,five,two,one,temp;

    scanf("%d", &N);

    hundred=N/100;
    temp=N%100;
    fifty=temp/50;
    temp=temp%50;
    twenty=temp/20;
    temp=temp%20;
    ten=temp/10;
    temp=temp%10;
    five=temp/5;
    temp=temp%5;
    two=temp/2;
    temp=temp%2;
    one=temp/1;

    printf("\n\n%d\n\n",N);
    printf("%8d nota(s) de R$ 100,00\n", hundred);
    printf("%8d nota(s) de R$  50,00\n", fifty);
    printf("%8d nota(s) de R$  20,00\n", twenty);
    printf("%8d nota(s) de R$  10,00\n", ten);
    printf("%8d nota(s) de R$   5,00\n", five);
    printf("%8d nota(s) de R$   2,00\n", two);
    printf("%8d nota(s) de R$   1,00\n", one);

    return 0;
}
