#include "header.h"
#include <iostream>
using namespace std;

int main() {
    double left, right, eps;
    double &a = left;
    double &b = right;
    double &e = eps;
    while(!(input(a, b, e)));
    cout << "\n" << "The result of bisection method is  " << dihom(a, b, e) << "\n" << endl;
    cout << "\n" << "The result of secand method is  " << hord(a, b, e) << "\n" << endl;
    //виклик функцій
    return 0;
}