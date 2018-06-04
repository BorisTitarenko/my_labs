#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <cmath>
#include "gause.h"
#define N 6
#define SIZE_X_TABLE 7
#define SIZE_Y_TABLE 4
using namespace std;

void fill(vector < pair <double, double>> & v)
{
    ifstream fin("your path");
    for(int i = 0; i != N; ++i)
    {
        double x, y;
        fin >> x >> y;
        v[i] = make_pair(x, y);
    }

    fin.close();
}


void search_coefs(vector <pair <double, double>> table, double x_coef_table [], double y_coef_table[])
{
    for(int i = 0; i != SIZE_X_TABLE; ++i) {
        for(int j = 0; j != N; ++j) {
            x_coef_table[i] += pow(table[j].first, i);
        }
    }

    for(int i = 0; i != SIZE_Y_TABLE; ++i) {
        for(int j = 0; j != N; ++j) {
            y_coef_table[i] += pow(table[j].first, i) * table[j].second;
        }
    }

}


void for_linean(double x_coef_table [], double y_coef_table [], double matrix [][3], double sol[])
{
    for(int i = 0; i != 2; ++i)
        for(int j = 0; j != 2; ++j)
            matrix[i][j] = x_coef_table[i+j];

    for(int i = 0; i != 2; ++i)
        matrix[i][2] = y_coef_table[i];

    Gause <double, 2, 3> g;
    g.Gausse_with_main_element(matrix, sol);

}

void for_pow_2(double x_coef_table [], double y_coef_table [], double matrix [][4], double sol[]){
    for(int i = 0; i != 3; ++i)
        for(int j = 0; j != 3; ++j)
            matrix[i][j] = x_coef_table[i+j];

    for(int i = 0; i != 3; ++i)
        matrix[i][3] = y_coef_table[i];

    Gause <double, 3, 4> g;
    g.Gausse_with_main_element(matrix, sol);
}

void for_pow_3(double x_coef_table [], double y_coef_table [], double matrix [][5], double sol[]){
    for(int i = 0; i != 4; ++i)
        for(int j = 0; j != 4; ++j)
            matrix[i][j] = x_coef_table[i+j];

    for(int i = 0; i != 4; ++i)
        matrix[i][4] = y_coef_table[i];

    Gause <double, 4, 5> g;
    g.Gausse_with_main_element(matrix, sol);
}

int main() {
    vector <pair <double, double>> table(N);
    double matrix_1 [2][3] = {0};
    double matrix_2 [3][4] = {0};
    double matrix_3 [4][5] = {0};
    double x_coef_table[SIZE_X_TABLE] = {0};
    double y_coef_table[SIZE_Y_TABLE] = {0};

    double linean_sol[2] = {0};
    double pow_2_sol[3] = {0};
    double pow_3_sol[4] = {0};

    fill(table);
    search_coefs(table, x_coef_table, y_coef_table);


    for_linean(x_coef_table, y_coef_table, matrix_1, linean_sol);
    for_pow_2(x_coef_table, y_coef_table, matrix_2, pow_2_sol);
    for_pow_3(x_coef_table, y_coef_table, matrix_3, pow_3_sol);

    cout << linean_sol[0] << " + " << linean_sol[1] << "x" << endl;
    cout << pow_2_sol[0] << " + " << pow_2_sol[1] << "x " << " + " << pow_2_sol[2] << "x^2" << endl;
    cout << pow_3_sol[0] << " + " << pow_3_sol[1] << "x " << " + " << pow_3_sol[2] << "x^2" << " + " \
    << pow_3_sol[3] << "x^3" << endl;


    return 0;
}