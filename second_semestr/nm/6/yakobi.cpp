//
// Created by Borys on 07.04.2018.
//
#include <cmath>
#include <fstream>
#include <iostream>
#include <cstring>
#include "yakobi.h"
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


bool check_jakobi(int n, int m, double ** matrix){
    double sum = 0;
    for(int i = 0; i != n; ++i){
        for(int j = 0; j != n; ++j)
            sum += fabs(matrix[i][j]);
        if(sum > 1){
            cout << sum << endl;
            return false;}
        sum = 0;
    }
    /*sum = 0;
    for(int i = 0; i != n; ++i){
        for(int j = 0; j != n; ++j)
            sum += fabs(matrix[j][i]);
        if(sum > 1)
            return false;
        sum = 0;
    }*/
    return true;
}


void prepare_jakobi_and_seidel(int n, int m, double ** matrix, double * x){
    for (int i = 0; i != n; ++i){
        double temp = matrix[i][i];
        matrix[i][i] = 0;
    }

    for(int i = 0; i != n; ++i){
        x[i] = matrix[i][n];
    }
    cout << "\n\n";
    print(n, m, matrix);
}


double iterations(int n, int m, double ** matrix){
    double a = 0, b = 0;
    for(int i = 0; i != n; ++i){
        b += fabs(matrix[i][n]);
        for(int j = 0; j != n; ++j)
            a += fabs(matrix[i][j]);
    }
    return fabs(log(fabs(E * (1 - a) /b )/log(a)) - 1);

}


void jakobi(int n, int m, double ** matrix, double * x){
    double * x_p = new double[n];
    double error = 0;
    int i = 0;
    do{
        memcpy(x_p, x, sizeof(double)*n);
        for(int i = 0; i != n; ++i){
            x[i] = 0;
            for(int j = 0; j != m; ++j){
               x[i] += matrix[i][j] * x_p[j];
            }
            x[i] += matrix[i][n];
            //cout << x[i] << endl;
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



