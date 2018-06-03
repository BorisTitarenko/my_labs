#include <stdio.h>
int main(void){
	int i = 1000;
	int flag = 0;
	for(i; i < 10000; i++){
		flag = 1;
		for (int j = 1; j <= 1000; j *= 10 ){
			if ((i/j - 7) % 10 == 0)
			{
				flag = 0;
				break;
			}		
		}
		if ( flag )
			printf("%d ", i);
	}
	getchar();
	getchar();
}