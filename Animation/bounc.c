#include <stdio.h>
#include <windows.h>
#include <math.h>

void h_newl(int h){
	while(h--){
		printf("\n");
	}
}
void stars(){
	printf("*\n");
}


int main(){
    int c;
    printf("Number of drops: ");
    scanf("%d",&c);
    while(c--){
	int x;
	float t;
	/* drop down */
	for ( x=1; x<=11; ++x){
		 t= 700*(sqrt (2*x/9.8) - sqrt (2*(x-1)/9.8));
		Sleep((int)t);
		system("cls");
		h_newl(x-1);
		stars();
	}
	/* drop up */
	for ( x=11; x>=1; --x){
		t= 700*(sqrt (2*x/9.8) - sqrt (2*(x-1)/9.8));
		if(x!=11)Sleep(t);
		system("cls");
		h_newl(x-1);
		stars();
	}
    }
	return 0;
}
