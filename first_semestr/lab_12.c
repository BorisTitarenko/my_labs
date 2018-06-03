#include <stdio.h>
#include <stdlib.h>

void fill_arrays(int array1[], int array2[], int array3[], int n1, int n2, int n3);
void sum_of_elements(int* array_of_pointers[], int* sum1, int* sum2, int* sum3, int n1, int n2, int n3);

int main(void){
	int count1, count2, count3;
	printf("count 1 = ");
	scanf("%d", &count1);
	printf("count 2 = ");
	scanf("%d", &count2);
	printf("count 3 = ");
	scanf("%d", &count3);
	
	int* array1 = malloc(count1*sizeof(int));
	int* array2 = malloc(count2*sizeof(int));
	int* array3 = malloc(count3*sizeof(int));
	
	fill_arrays(array1, array2, array3, count1, count2, count3);
	array1[0] = count1; array2[0] = count2; array3[0] = count3;
	int* array_of_pointers[3] = {array1, array2, array3};
	
	int sum1 = 0, sum2 = 0, sum3 = 0;
	sum_of_elements(array_of_pointers, &sum1, &sum2, &sum3, count1, count2, count3);
	printf("sum1 = %d \nsum2 = %d  \nsum3 = %d", sum1, sum2, sum3);
	
	free(array1); free(array2); free(array3);
}

void fill_arrays(int array1[], int array2[], int array3[], int count1, int count2, int count3){
	printf("print elements of 1 array ");
	for (int i = 1; i < count1; i++){
		scanf("%d", (array1 + i)); 
	}
	printf("print elements of 2 array ");
	
	for(int i = 1; i < count2; i++){
		scanf("%d", (array2 + i));
	}
	printf("print elements of 3 array ");
	
	for (int i = 1; i < count3; i++){
		scanf("%d", (array3 + i));
	}
}

void sum_of_elements(int* array_of_pointers[], int* sum1, int* sum2, int* sum3, int count1, int count2, int count3){

	for (int i = 0; i < count1; i++){
		(*sum1) += *(array_of_pointers[0]+i);
	}
	
	for (int i = 0; i < count2; i++){
		(*sum2) += *(array_of_pointers[1]+i);
	}

	for (int i = 0; i < count3; i++){
		(*sum3) += *(array_of_pointers[2]+i);
	}
}