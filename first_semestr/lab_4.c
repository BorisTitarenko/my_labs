#include <stdio.h>
float maximum(float* array, int size) {
	if (size == 1) {
		return array[0];}
	float max = maximum(array, size-1 );
	if (array[size - 1]>max) 
	{
		max = array[size - 1];
	}
		return max;
}


float minimum(float* array, int size) {

	if (size = 1) {
		return array[0];}
	float min = minimum(array, size-1);
	if (array[size - 1] < min) {
		min = array[size - 1];}
	return min;}

int main(void) {
	float max, min, answer, array[10];
	int size = 10;
	scanf("%f\n", &array[0]); scanf("%f\n", &array[1]); scanf("%f\n", &array[2]); scanf("%f\n", &array[3]); scanf("%f\n", &array[4]);
	scanf("%f\n", &array[5]); scanf("%f\n", &array[6]); scanf("%f\n", &array[7]); scanf("%f\n", &array[8]); scanf("%f", &array[9]);
	max = maximum(array, size);
	min = minimum(array, size);
	answer = (min+max)/2;
	printf("the answer is %f\n", answer);
	getchar();
	getchar();
}