#include <stdio.h>
int main(void) {
    int iLines, iColons;
	printf("Number of lines: ");
	scanf("%d", &iLines);
	printf("Number of colums: ");
	scanf("%d", &iColons);
	float fMatrix[iLines][iColons];
	
	for (int i = 0; i < iLines; i++){
		for (int j = 0; j < iColons; j++){
			printf("[%d][%d] = ", i, j); 
			scanf("%f", &fMatrix[i][j]);
		}
	}
	float fMax = 1.0, fTotal = 1.0; 
	int iIndex = 0;
	
	for (int i = 0; i < iLines; i++){
		fTotal = 1.0;
		for (int j = 0; j < iLines; j++){
			fTotal *= fMatrix[i][j];
		}
		if (i == 0 || fTotal > fMax){
			iIndex = i;
			fMax = fTotal;}
	}
	printf("%d", iIndex);
	float fMatrix2[iLines-1][iColons];
	for (int i = 0; i < iLines; i++){
		for (int j = 0; j < iColons; j++){
			if (i >= iIndex){ 
				fMatrix2[i][j] = fMatrix[i+1][j];}
			
			else{
				fMatrix2[i][j] = fMatrix[i][j];
			}
		
		}
	}
	for (int i = 0; i < iLines-1; i++){
		printf("\n");
		for (int j = 0; j < iColons; j++){
			printf("[%d][%d] = %f  ", i, j, fMatrix2[i][j]);
		}
	}
	getchar();
	getchar();
}

