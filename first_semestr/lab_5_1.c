#include <stdio.h>
#include <math.h>
int main(void){
	float fEps, fEnd, fStep, fX;
	fStep = 0.01;
	fEps = 0.001;
	printf("A = ");
	scanf("%f", &fX);
	printf("B = ");
	scanf("%f", &fEnd);
	if ((fabs(fX) <= 1.0) && (fabsf(fEnd) <= 1.0)) {
		for (fX; fX <= fEnd; fX += fStep) {
			float fSum = 1.0;
			float fNext = (1.0 / 3.0) * fX;

			for (int i = 1; fabsf(fNext) >= fEps; i++) {
				fSum += fNext;
				fNext *= (1.0 / 3.0 - i) * fX * 1 / (i + 1.0);
			}
			printf("_________________________\n");
			printf("|x = %0.2f     y = %0.4f|\n", fX, fSum);
		}}else { printf("try again"); }

	getchar();
	getchar();
}