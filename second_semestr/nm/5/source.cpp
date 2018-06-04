//
// Created by Borys on 02.04.2018.
//
#include <iostream>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <cstring>
using namespace std;

void print_solution(int n, double * solution){
    for(int i = 0; i != n; ++i){
        cout << "x" << i+1 << " = " << solution[i] << endl;
    }
}
void fill_matrix(int n, int m, double ** matrix){
    ifstream fin("your path");
    for(int i = 0; i != n; ++i){
        for(int j = 0; j != m; j++){
            fin >> matrix[i][j];
        }
    }
}

void print(int n, int m, double ** matrix){
    for(int i = 0; i != n; ++i){
        for(int j = 0; j != m; ++j){
            printf("%-10.4lf  ", matrix[i][j]);
        }
        printf("\n");
    }
}
void LU(int n, int m, double ** matrix, double ** L, double ** U, double * solution){
    for(int i = 0; i != n; ++i){
        for(int j = i; j != n; ++j){

            L[j][i] = matrix[j][i];
            for(int k = 0; k != i; ++k)
                L[j][i] -= L[j][k] * U[k][i];

        }
        for(int j = 0; j != n; ++j){
            if(i == j)
                U[i][j] = 1;
            else {
                U[i][j] = matrix[i][j] / L[i][i];
                for (int k = 0; k < i; k++) {
                    U[i][j] -= ((L[i][k] * U[k][j]) / L[i][i]);
                }
            }
        }
    }
    cout << "\n";
    print(3, 3, L);
    cout << "\n";
    print(3, 3, U);
    double sum=0;
    double * y = (double *)calloc(n, sizeof(double));
    for (int i = 0; i != n; ++i) {
        y[i] = matrix[i][n]/L[i][i];
        for (int j=i+1; j != n; ++j)
            matrix[j][n] -= L[j][i] * y[i];
    }
    //print_solution(n, y);
    for (int i = n-1; i>=0; i--) {
        solution[i] = y[i]/U[i][i];
        for (int k=i-1;k>=0; k--)
            y[k] -= U[k][i] * solution[i];
    }
    free(y);
    print_solution(n, solution);

}
void free_memory( double ** matrix, double ** L, double ** U, double * solution){
    delete matrix[0];
    delete matrix;
    delete L[0];
    delete L;
    delete U[0];
    delete U;
    delete solution;
}

