//
// Created by Borys on 22.04.2018.
//
#include "iterations.h"
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void print_x(vector <double> x){
    for (size_t i = 0; i != x.size(); ++i) {
        cout << "x" << i+1 << "= " << x[i] << endl;
    }
}

double o1(double y){
    return (sin(y) - 1.5)/2;
}

double o2(double x){

    return cos(x + 0.5) - 2;
}

bool end_of_iterations(vector <double> x, vector <double> x0) {
    double sum = 0;
   for(size_t i = 0; i != x.size(); ++i){
        sum += fabs(x[i] - x0[i]);
    }
    return (sum < E);
}

int iterations(vector <double> x, vector <double> x0, double (*f[N])(double)){
    int i = 0;
    do{

        x0 = x;
        x[0] = f[0](x0[1]);
        x[1] = f[1](x0[0]);
        cout << "\n\n" << "iteration " << i << "\n";
        print_x(x);
        ++i;
    }while(!end_of_iterations(x, x0));
}
