#include <iostream>
#include <iomanip>
#include <conio.h>
#include <math.h>

using namespace std;

const int SIZE = 2;

double function_1 (double x, double y) {
    return tan(x*y) - pow(x, 2);
}

double function_2 (double x, double y) {
    return 0.7 * pow(x, 2) + 2*pow(y, 3) - 1;
}

double function_1_1 (double x, double y) {
    return y / pow(cos(x*y), 2) - 2*x;
}

double function_1_2(double x, double y){
    return x / pow(cos(x*y), 2);
}

double function_2_1(double x, double y){
    return 1.4 * x;
}

double function_2_2 (double x, double y) {
    return 6 * pow(y, 2);
}

int  main()
{
    double eps = 0.001;
    double x, y;
    double temp_x = 1, temp_y = 1;
    int counter = 0;
    double W[SIZE][SIZE] = {1, 1, 1, 1};
    double W_[SIZE][SIZE];
    int i, j;
    double det_W;

    while (1)
    {
        W[0][0] = function_1_1(temp_x, temp_y);
        W[0][1] = function_1_2(temp_x, temp_y);
        W[1][0] = function_2_1(temp_x, temp_y);
        W[1][1] = function_2_2(temp_x, temp_y);

        det_W = W[0][0]*W[1][1] - W[0][1]*W[1][0];

        if (det_W == 0)
            break;
        W_[0][0] = W[1][1]/det_W;
        W_[0][1] = - W[1][0]/det_W;
        W_[1][0] = - W[0][1]/det_W;
        W_[1][1] = W[0][0]/det_W;
        x = temp_x - W_[0][0]*function_1 (temp_x, temp_y) - W_[0][1]*function_2 (temp_x, temp_y);
        y = temp_y - W_[1][0]*function_1 (temp_x, temp_y) - W_[1][1]*function_2 (temp_x, temp_y);

        cout << "Count = " << counter << setw(10) << "X = " << x << setw(10) << "Y = " << y << endl;
        ++counter;
        if (fabs(x - temp_x) < eps && fabs(y - temp_y) < eps) break;
        temp_x = x;
        temp_y = y;
    }
    cout << "\nAnswer:   " << "X = " << x << setw(10) << "Y = " << y << endl;

    getch(); getch();
    return 0;
}
