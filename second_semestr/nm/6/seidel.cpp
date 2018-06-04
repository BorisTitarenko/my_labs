//
// Created by Borys on 08.04.2018.
//
#include <cmath>
#include <fstream>
#include <iostream>
#include <cstring>
#include "yakobi.h"
using namespace std;

void fill_matrix_seidel(int n, int m, double ** matrix){
    
    ifstream fin("your path");
    for(int i = 0; i != n; ++i){
        for(int j = 0; j != m; j++){
            fin >> matrix[i][j];
        }
    }
}
void prepare_seidel(int n, int m, double ** matrix, double * x){
    //print(n, m, matrix);
    //cout << n <<  "    "<<m << endl;
    for(int i =0; i != n; ++i){
        double temp = matrix[i][i]*(-1);
        for(int j = 0; j != m; ++j){
            matrix[i][j] /=  temp;
        }
    }
    //cout << "\n\n";
    //print(n, m, matrix);
    cout << "\n\n";
    for(int i = 0; i != n; ++i){
        matrix[i][m-1] = -matrix[i][m-1];
        x[i] = 0;
    }
}

void seidel(int n, int m, double ** matrix, double * x){
    //cout << n <<  "    "<<m << endl;
    double * x_p = new double[n];
    print_solution(n, x);
    double error = 0;
    int i = 0;
    do{
        memcpy(x_p, x, sizeof(double)*n);
        for(int i = 0; i != n; ++i){
            x[i] = 0;
            for(int j = 0; j != n; ++j){
                x[i] += matrix[i][j] * x[j];
            }
            x[i] += matrix[i][n];
            cout << x[i] << endl;
        }
        cout << "\niteration" << i << "\n";
        print_solution(n, x);
        cout << "\n";
        error = 0;
        for(int i = 0; i != n; ++i)
            error += fabs(x[i] - x_p[i]);
        ++i;
    }while(fabs(error) > E);

    print_solution(n, x);
    delete [] x_p;
}

