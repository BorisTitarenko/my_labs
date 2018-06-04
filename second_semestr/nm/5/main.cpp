#include <iostream>
#include "header.h"
#include <cstring>
using namespace std;
int main() {
    int n = 3, m = 4;
    double ** matrix = new double * [n];
    matrix[0] = new double[n*m];
    for(int i = 1; i != n; ++i)
        matrix[i] = matrix[i-1] + m;
    double ** L = new double *[n*m];
    double ** U = new double *[n*m];
    L[0] = new double [n*m];
    U[0] = new double [n*m];
    for(int i = 1; i != n; ++i){
        L[i] = L[i-1] + m;
        U[i] = U[i-1] + m;
    }
    double * solution = new double [n];
    memset(L[0], 0, n*m); L[0][1] = 0;
    memset(U[0], 0, n*m);
    //print(n, n, L);
    //print(n, n, U);
    fill_matrix(n, m, matrix);
    print(n, m, matrix);
    LU(n, m, matrix, L, U, solution);
    free_memory(matrix, L, U, solution);
    return 0;

}