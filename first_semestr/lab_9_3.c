#include <stdio.h>
#define ARIPHMETIK_PROGRESION(first, second, n) first+(second-first)*(n-1)
#define PRINT_ELEMENT(ARIPHMETIK_PROGRESION, n) printf("The %d element of progresion = %d",n,  ARIPHMETIK_PROGRESION)
int main(void){
	int first, second, n, element;
	scanf("%d", &first);
	scanf("%d", &second);
	scanf("%d", &n);
	element = ARIPHMETIK_PROGRESION(first, second, n);
	PRINT_ELEMENT(element, n);
	getchar();
	getchar();
	
}