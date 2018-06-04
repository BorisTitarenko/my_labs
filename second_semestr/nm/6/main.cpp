#include <iostream>
#include <cstdio>
#include "yakobi.h"
#include "seidel.h"
#include <cmath>
using namespace std;

int main() {
    const int n = 4, m = 5;
    double ** matrix = new double *[n];
    matrix[0] = new double[n*m];
    for (int i = 1; i != n; ++i)
        matrix[i] = matrix[i-1] + m;
    double * x = new double[n];

    fill_matrix(n, m, matrix);//yakobi
    cout << "\nthere must be more then " << iterations(n, m, matrix) << " iterations\n\n";
    print(n, m, matrix);
    prepare_jakobi_and_seidel(n, m, matrix, x);
    if(check_jakobi(n, m, matrix)){
        jakobi(n, m, matrix, x);
    }
    else{
        cout << "system can't be solved iteratively" << endl;
        return 0;
    } //yakobi


    getchar();
    getchar();
    const int n_2 = 3, m_2 = 4;
    delete [] x;
    x= 0;
    x = new double [n];

    fill_matrix_seidel(n_2, m_2, matrix);
    print(n_2, m_2, matrix);
    cout << "\n\n";
    prepare_seidel(n_2, m_2, matrix, x);
    print(n_2, m_2, matrix);
    prepare_jakobi_and_seidel(n_2, m_2, matrix, x);
    if(check_jakobi(n, m, matrix)){
        seidel(n_2, m_2, matrix, x);
    }
    else{
        cout << "system can't be solved iteratively" << endl;
        getchar();
        getchar();
        return 0;
    }
    seidel(n_2, m_2, matrix, x);

    getchar();
    getchar();
   return 0;
}