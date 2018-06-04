#include <iostream>
#include "iterations.h"

#include <vector>
using namespace std;

int main() {
    vector <double> x(N);
    vector <double> x0(N);

    x0[0] = (0.655131, 1);
    x0[1] = (-0.285152, 1);
    x = x0;

    double (*f[N])(double);
    f[0] = o1;
    f[1] = o2;

    iterations(x, x0, f);

    getchar();
    getchar();
    return 0;
}