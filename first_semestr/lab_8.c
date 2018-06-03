#include <stdio.h>
#include <math.h>
#define PI 3.14159265

double integral_rectangle(double a, double b);
double integral_trapeze(double a, double b);
double integral_simpson(double a, double b);


int main(void){
	double a = 0, b = PI;
	
	printf("%lf\n", integral_rectangle(a, b));
	printf("%lf\n", integral_trapeze(a, b));
	printf("%lf", integral_simpson(a, b));
	getchar();
	getchar();
}
double integral_rectangle(double a, double b){
	double square = 0, eps = (b - a) / 100000;
	for(a; a < b; a += eps){
		square += exp(a)*cos(a)*cos(a)*eps;
	}
	return square;
}

double integral_trapeze(double a, double b){
	double square = 0, eps = (b - a) / 100000, x1 = 0.0;
	double x2 = exp(a)*cos(a)*cos(a)*eps;
	for(a; a < b; a += eps){
		x1 = x2;
		x2 = exp(a)*cos(a)*cos(a)*eps;
		square += (x1 + x2)/2;
		
	}
	return square;
}
double integral_simpson(double a, double b){
	double square = 0, eps = (b - a) / 100000;
	double a_next = a + eps;
	for (a; a < b - eps; a += eps, a_next += eps){
		square += exp(a)*cos(a)*cos(a)*eps;
		square += 4*exp(a + eps/2)*cos(a + eps/2)*cos(a + eps/2)*eps;
		square += exp(a_next)*cos(a_next)*cos(a_next)*eps;
	}
	return square/6;
}