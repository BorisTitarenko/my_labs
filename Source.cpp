#include <stdio.h>
#include <math.h>//бібліотека, необхідна для математичних розрахунків
int main()
{
	float x, y, z, result;
	scanf_s("%f", &x, "\n");// зчитую змінні по порядку
	scanf_s("%f", &y, "\n");
	scanf_s("%f", &z, "\n");
	result = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));//ось і сам вираз
	printf("%f", result);//вивожу на екран
	getchar();
	getchar();
}