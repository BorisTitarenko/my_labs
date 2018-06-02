#include <stdio.h>
#include <math.h>
int main()
{
	float x, y, z, result;
	scanf_s("%f", &x, "\n");
	scanf_s("%f", &y, "\n");
	scanf_s("%f", &z, "\n");
	result = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	printf("%f", result);
	getchar();
	getchar();
}