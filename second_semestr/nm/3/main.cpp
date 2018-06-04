#include <iostream>
#include "header.h"
using namespace std;
int main() {
    double a[MAX][MAX];
    double sol[MAX];
    double res1[MAX];
    double res2[MAX];
    fill(a, sol);
    if(Cramer(a, sol, res1))
        return 1;
    cout << "Root equations found by the Cramer method" << endl;
    print(res1);
    Inv(a, sol, res2);
    cout << "Root equations found by the matrix method" << endl;
    print(res2);
    return 0;
}
