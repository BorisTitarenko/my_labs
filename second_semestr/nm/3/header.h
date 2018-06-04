//
// Created by Borys on 03.03.2018.
//

#ifndef LAB3_HEADER_H
#define LAB3_HEADER_H
#define MAX 3

double determinant(double a[MAX][MAX], int n);
void fill(double a[MAX][MAX], double sol[MAX]);
void print(double a[MAX]);
int Cramer(double a[MAX][MAX], double sol[MAX], double res[MAX]);
void trans(double temp[MAX][MAX]);
void Inv(double a[MAX][MAX], double sol[MAX], double res[MAX]);

#endif //LAB3_HEADER_H
