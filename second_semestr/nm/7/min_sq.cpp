//
// Created by Borys on 08.04.2018.
//
#include <cmath>
#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "determinant.h"
using namespace std;

void print_solution(int n, double * solution){
    for(int i = 0; i != n; ++i){
        cout << "x" << i+1 << " = " << solution[i] << endl;
    }
}
void fill_matrix(int n, int m, double ** matrix, double * x){
    ifstream fin("your path");
    for(int i = 0; i != n; ++i){
        for(int j = 0; j != m; j++){
            fin >> matrix[i][j];
        }
        fin >> x[i];
    }

}

void print(int n, int m, double ** matrix){
    for(int i = 0; i != n; ++i){
        for(int j = 0; j != m; ++j){
            printf("%-10lf  ", matrix[i][j]);
        }
        printf("\n");
    }
}

void free_memory(double ** matrix, double * x){
    delete [] matrix[0];
    delete [] matrix;
    delete [] x;
}


void trans(int n, int m, double ** matrix, double ** matrix_trans){
    for(int i = 0; i != n; ++i)
        for(int j = 0; j != m; ++j)
            matrix_trans[j][i] = matrix[i][j];
}

void dot(int n, int m, double ** matrix, double ** matrix_trans, double ** matrix_norm){

    for(int i = 0; i != m; ++i) {
        for (int j = 0; j != m; ++j) {
            matrix_norm[i][j] = 0;
            for (int k = 0; k != n; ++k)
                matrix_norm[i][j] += matrix_trans[i][k] * matrix[k][j];
        }
    }
}

void dot_x(int n, int m, double ** matrix_trans, double * b, double * b_norm){
    for(int i = 0; i != m; ++i){
        b_norm[i] = 0;
        for(int j = 0; j != n; ++j )
            b_norm[i] += matrix_trans[i][j] * b[j];
    }

}


void min_sq(int n, int m, double **matrix, double **matrix_norm, double *b, double *b_norm, double *solution) {
    double **matrix_trans = new double *[m];
    matrix_trans[0] = new double[m * n];
    for (int i = 1; i != m; ++i)
        matrix_trans[i] = matrix_trans[i - 1] + n;

    trans(n, m, matrix, matrix_trans);
    dot(n, m, matrix, matrix_trans, matrix_norm);
    dot_x(n, m, matrix_trans, b, b_norm);
    cout << "\n\nNormal matrix\n";
    print(m, m, matrix_norm);
}


void sqrt_met(int m, double ** matrix_norm, double * b_norm, double * solution){
    double det = determinant(matrix_norm, m);
    cout << "\ndeterminant = " << det << endl;

    if(!det)
        return;

    double ** L, ** L_trans;
    L = new double * [m];
    L_trans = new double * [m];
    L[0] = new double [m*m];
    L_trans[0] = new double [m*m];

    for(int i = 1; i != m; ++i){
        L[i] = L[i-1] + m;
        L_trans[i] = L_trans[i-1] + m;
    }


    L[0][0] = sqrt(matrix_norm[0][0]);
    for(int i = 1; i != m; ++i)
        L[i][0] = matrix_norm[i][0] / L[0][0];

    for(int i = 0; i != m; ++i){
        double element;
        for(int j = 0; j != i; ++j){
            element = 0;
            for (int k = 0; k < j; k++)
                element += L[i][k] * L[j][k];

            L[i][j] = (matrix_norm[i][j] - element) / L[j][j];
        }
        element = matrix_norm[i][i];
        for (int k = 0; k < i; k++) {
            element -= L[i][k] * L[i][k];
        }
        L[i][i] = sqrt(element);
    }


    cout << "\nL matrix\n";
    trans(m, m, L, L_trans);
    print(m, m, L);
    cout << "\n\n";


    double sum=0;
    double * y = (double *)calloc(m, sizeof(double));
    for (int i = 0; i != m; ++i) {
        y[i] = b_norm[i] / L[i][i];
        for (int j=i+1; j != m; ++j)
            b_norm[j] -= L[j][i] * y[i];
    }


    for (int i = m-1; i>=0; i--) {
        solution[i] = y[i]/L_trans[i][i];
        for (int k=i-1;k>=0; k--)
            y[k] -= L_trans[k][i] * solution[i];
    }
    delete [] L[0];
    delete [] L;
    delete [] L_trans[0];
    delete [] L_trans;
    free(y);
    print_solution(m, solution);


}

