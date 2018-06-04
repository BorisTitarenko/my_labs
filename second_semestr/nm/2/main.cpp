#include <iostream>
#include "header.h"
using namespace std;


int main() {
    double left, right, eps;
    double & a = left;
    double & b = right;
    double & e = eps;
    while(!input(a, b, e));
    cout << "\nThe result of Newton method is  " << Newton(a, b, e) << "\n" << endl;
    cout << "\nThe result of iteration method is  " << iterations(a, b, e) << "\n" << endl;
    return 0;
}