#include <stdio.h>
void reverse(void);
int factorial(int );
void reverse_and_index(int );
float fraction(int );

int main (void){
	int n;
	printf("input a numbers for reverse ");
	reverse();
	printf("\n");
	while(n != 0){
		printf("input a number for give factorial ");
		scanf("%d", &n); 
		printf("factorial = %d\n", factorial(n));}
	
	printf("input a numbers for give reverse numbers ");
	reverse_and_index(1);
	
	printf("\ninput a level of fraction ");
	scanf("%d", &n);
	float answer = 1.0 / fraction(n);
	printf("\nfraction = %f", answer);
}
void reverse(void){
	int n;
	scanf("%d", &n);
	if (n != 0){
		reverse();
		printf("%d ", n);
	}
}
int factorial(int n){
	
	if(n == 0){
		return 1;}
	else {
		return factorial(n-1)*n;}
}
void reverse_and_index(int i){
	int n;
	scanf("%d", &n);
	if (n != 0){
		reverse_and_index(i+1);
		printf("value of %d element = %d\n", i, n);
    }}
	
float fraction(int n){
	if (n < 1){
		return 1.0;}
	else{
		return (2.0 + 1.0/fraction(n - 2));}}

