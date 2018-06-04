 #include <iostream>
#include<iomanip>
#include <cmath>
using namespace std;

//Задана функція
double F(double x, double y) {
    return cos(y)/(1.25 + x) - 0.5*y*y;
}

//Обчислення значень у1 та у2 методом Рунге-Кутти
void Runge_Kutt(double *X, double *Y, int n, double h) {
    cout << "---<< Runge-Kutt method >>---";
    for (int i = 1; i <= n; ++i) {
        X[i] = X[0] + i*h;
        double k1 = h*F(X[i - 1], Y[i - 1]); cout << "\nk1 for y" << i << " = " << k1;
        double k2 = h*F(X[i - 1] + h / 2, Y[i - 1] + k1 / 2); cout << "\nk2 for y" << i << " = " << k2;
        double k3 = h*F(X[i - 1] + h / 2, Y[i - 1] + k2 / 2); cout << "\nk3 for y" << i << " = " << k3;
        double k4 = h*F(X[i - 1] + h, Y[i - 1] + k3); cout << "\nk4 for y" << i << " = " << k4;
        Y[i] = Y[i - 1] + (k1 + 2 * k2 + 2 * k3 + k4) / 6; cout << "\ny" << i << " = " << Y[i] << endl;
    }
}

//Метод Адамса
void Adams(double *X, double *Y, double Y0, double a, double b, double h) {
    X[0] = a; Y[0] = Y0;
    double q[10], delta_q[10], delta2_q[10];
    Runge_Kutt(X, Y, 2, 0.1);
    q[0] = h*F(X[0], Y[0]);
    q[1] = h*F(X[1], Y[1]);

    for (int i = 2; i < 10; ++i) {
        q[i] = h*F(X[i], Y[i]);
        delta_q[i - 1] = q[i] - q[i - 1];
        delta_q[i - 2] = q[i - 1] - q[i - 2];
        delta2_q[i - 2] = delta_q[i - 1] - delta_q[i - 2];

        Y[i + 1] = Y[i] + q[i] + 0.5*delta_q[i - 1] + (5.0 / 12)*delta2_q[i - 2];
        X[i + 1] = X[0] + (i + 1)*h;
    }

    cout << "\n\n---<< Adams method >>---\n";
    cout << " i\t X\t  Y\n=======================\n";
    for (int i = 0; i < 11; ++i) {
        cout << i << "\t" << fixed << setprecision(1) << X[i] << "\t" << setprecision(4) << Y[i] << "\n";
    }
}

int main() {
    cout << "y'= 1-0.8y*sin(x)-2y^2\ty(0)=0\t[0; 1]\n\n";
    double a = 0, b = 1, h = 0.1;
    double *X, *Y;
    X = new double[11];
    Y = new double[11];
    Adams(X, Y, 0, a, b, h);
    getchar(); getchar();
    return 0;
}