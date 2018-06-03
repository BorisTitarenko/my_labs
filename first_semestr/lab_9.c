#include <stdio.h>
#include <stdarg.h>

unsigned int number(char *i, ...);
int main(void) {
	printf("\nnumber = %d", number("my numbers", 16, 1, 58, 89, 78, 8, -1));
	getchar();
	getchar();
}
unsigned int number(char *i, ...) {  /*it doesn't work*/
	int count = 0, sum = 0, next = 0;
	va_list element;
	va_start(element, *i);
	while (next != -1) {
		next = va_arg(element, int);
		count++;
	}
	va_end(element);
	printf("\ncount of numbers = %d", count);
	
	va_start(element, i);
	next = 0;
	while(next != -1) {      
        next = va_arg(element, int);
		for (int j = 1; j < next; j *= 10) {
			sum += (next % (j * 10) - next %j) / j;
		}
		if (sum == count) {
			return (next);
		}
		sum = 0;
		
	}
	return 0;}