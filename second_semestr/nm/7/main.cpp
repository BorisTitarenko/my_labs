#include <iostream>
#include "min_sq.h"

using namespace std;

int main() {
    const int n = 5, m = 3;
    double ** matrix = new double *[n];
    double ** matrix_norm = new double * [m];
    matrix[0] = new double[n*m];
    matrix_norm[0] = new double [m*m];

    for (int i = 1; i != n; ++i)
        matrix[i] = matrix[i-1] + m;
    for (int i = 1; i != m; ++i)
        matrix_norm[i] = matrix_norm[i-1] + m;

    double * b = new double[n];
    double * b_norm = new double[m];
    double * solution = new double [m];
    fill_matrix(n, m, matrix, b);
    print(n, m, matrix);
    min_sq(n, m, matrix, matrix_norm, b, b_norm,solution);
    sqrt_met(m, matrix_norm, b_norm, solution);
    free_memory(matrix, b);
    free_memory(matrix_norm, b_norm);
    return 0;
}