#include <stdio.h>
#define n 4
void exchange(int matrix[][n]);
int main (void){
	int matrix[n][n] = {1, 2, 3, 4, 4, 100, 458, 965, 2, 878, 546, 145, 8, 5, 6, 2};
	for (int i = 0; i < n; i++){
		printf("\n");
		for (int j = 0; j < n; j++){
			printf("%3d ", matrix[i][j]);
		}
	}
	printf("\n");
	exchange(matrix);
	
	getchar();
	getchar();
	
}
void exchange(int matrix[][n]){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (matrix[i][0] == matrix[0][j]){
				for (int k = 0; k < n; k++){
					int temp = matrix[i][k];
					matrix[i][k] = matrix[k][j];
					matrix[k][j] = temp;
				}
			}
		}
	}
	for (int i = 0; i < n; i++){
		printf("\n");
		for (int j = 0; j < n; j++){
			printf("%3d ", matrix[i][j]);
		}
	}
}