#include <iostream>
#include <cmath>

#define E 0.0001//змінити
#define N1 6
#define N2 8

using namespace std;

double f(double x){
    return 1/(sqrt(12 * x*x + 0.5));
}

double f_2(double x){
    return log10(1 + x*x)/(2*x - 1);
}

double trap(double a, double b){
    double result = 0;
    double h = (b-a)/N1;
    for(a; a < b; a += h){
        result += ((f(a) + f(a+h))/2)*h;
        cout << result << endl;
    }
    return result;
}

double Simpson(double a, double b){
    double result = 0;
    double e = (a + b)/(N2*2);
    for(a; a < b; a += 2*e){
        result += (f_2(a) + 4*f_2(a+e/2) + f_2(a+e))*e/3;
        cout << result << endl;
    }
    return result;
}

int main() {
    double a = 0.6;
    double b = 1.4;
    double a_2 = 1.2;
    double b_2 = 2.8;
    cout << "\nintegral = " << trap(a, b) << endl;
    cout << "\nintegral = " << Simpson(a, b) << endl;
    getchar();
    return 0;
}