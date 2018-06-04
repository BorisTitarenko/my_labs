#include <iostream>
#include "header.h"
#include <cstdlib>
#include <cstdio>
using namespace std;
int main() {
    int n = 3, m = 4;
    double ** matrix = (double**)calloc(n, sizeof(double*));
    //double ** matrix_2 = (double**)calloc(n, sizeof(double*));

    for(int i = 0; i != n; ++i){
        matrix[i] = (double*)calloc(n, sizeof(double*));
       // matrix_2[i] = (double*)calloc(n, sizeof(double*));

    }
    double ** L = (double**)malloc(n*sizeof(double*));
    double ** U = (double**)malloc(n*sizeof(double*));
    for(int i = 0; i != n; ++i){
        L[i] = (double*)calloc(n, sizeof(double));
        U[i] = (double*)calloc(n, sizeof(double));
    }
    double * solution = (double*)calloc(n, sizeof(double));
    /*fill_matrix(n, m, matrix);
    print(n, m, matrix);
    Gausse_with_main_element(n, m, matrix, solution);*/
    fill_matrix(n, m, matrix);
    print(n, m, matrix);
    LU(n, m, matrix, L, U, solution);
    free_memory(n, matrix, L, U, solution);
    getchar();
    return 0;

}