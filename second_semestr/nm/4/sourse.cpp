//
// Created by Borys on 25.03.2018.
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
    ifstream fin("you path");
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
void flesh_back(int n, double ** matrix, double * solution){
    for (int i = n-1; i>=0; i--) {
        solution[i] = matrix[i][n]/matrix[i][i];
        for (int k=i-1;k>=0; k--) {
            matrix[k][n] -= matrix[k][i] * solution[i];
        }
    }
}
void Gausse_with_main_element(int n, int m, double **matrix, double * solution){
    cout << "\n";
    solution = new double [n];
    for(int i = 0; i != n; ++i){
        double max_el = matrix[i][i];
        int  max_el_index = i;
        for(int k = i+1; k != n; ++k){
            if(fabs(matrix[k][i]) > max_el){
                max_el = matrix[k][i];
                max_el_index = k;
            }
        }
        if(max_el == 0){
            cout << "System doesn't have solution";
            return;
        }
        if(max_el_index != i){
            double temp[n];
            memcpy(temp, matrix[i], sizeof(double)*(m));
            memcpy(matrix[i], matrix[max_el_index], sizeof(double)*(m));
            memcpy(matrix[max_el_index], temp, sizeof(double)*(m));

        }


        for (int k=i+1; k != n; ++k) {
            double c = -matrix[k][i]/matrix[i][i];
            for (int j=i; j != m; ++j) {
                if (i==j)
                    matrix[k][j] = 0;

                else
                    matrix[k][j] += c * matrix[i][j];
            }
        }
        print(n, m, matrix);
        cout << "\n";

    }
    flesh_back(n, matrix, solution);
    print_solution(n, solution);
}

void LU(int n, int m, double ** matrix, double ** L, double ** U, double * solution){
   for(int i = 0; i != n; ++i){
       for(int j = i; j != n; ++j){

               L[j][i] = matrix[j][i];
               for(int k = 0; k != i; ++k)
                   L[j][i] -= L[j][k] * U[k][i];

       }
       for(int j = 0; j != n; ++j){
           /*if (j < i)
               U[i][j] = 0;
           else*/ if(i == j)
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
void free_memory(int n, double ** matrix, double ** L, double ** U, double * solution){
    for(int i = 0; i != n; ++i){
        free(matrix[i]);
        free(L[i]);
        free(U[i]);
    }
    free(matrix);
    free(L);
    free(U);
    free(solution);
}


