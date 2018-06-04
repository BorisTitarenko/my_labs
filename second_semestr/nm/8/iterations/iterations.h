//
// Created by Borys on 22.04.2018.
//

#ifndef CODE_ITERATIONS_H
#define CODE_ITERATIONS_H

#include <vector>

#define E 0.001
#define N 2
using namespace std;

double o1(double x);
double o2(double x);
void print_x(vector <double> x);
int iterations(vector <double> x, vector <double> x0, double (*f[N])(double));

#endif //CODE_ITERATIONS_H
