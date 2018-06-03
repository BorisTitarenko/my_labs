#include <stdio.h>
#include <stdlib.h>
int main(void){
	int iNumber;
	printf("Enter number of numbers ");
	scanf("%d", &iNumber);
	/*int * iVector;
	iVector = (int *)malloc(iNumber * sizeof(int[iNumber]));*/
	int iVector[iNumber];
	int iSum = 0, iMultiple = 1;
	for (int j = 0; j < sizeof(iVector)/sizeof(int); j++){
		int i;
		printf("[%d] = ", j);
		scanf("%d", &i);
		*(iVector+j) = i;
	}
	for (int j = 0; j < sizeof(iVector)/sizeof(int); j++){
		if (iVector[j]%2 == 0){
			iSum += *(iVector+j); 
		}
		else if(*(iVector + j) % 2 == 1){
			iMultiple *= *(iVector + j); 
		}	
	}
	printf("sum of even numbers = %d\nproduct of odd numbers = %d", iSum, iMultiple);
	/*free(iVector);*/
	getchar();
	getchar();
}