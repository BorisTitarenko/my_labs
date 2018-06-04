//
// Created by Borys on 07.04.2018.
//

#ifndef PROG_YAKOBI_H
#define PROG_YAKOBI_H

#define E 0.001

void fill_matrix(int n, int m, double ** matrix);
void print(int n, int m, double ** matrix);
void prepare_jakobi_and_seidel(int n, int m, double ** matrix, double * x);
bool check_jakobi(int n, int m, double ** matrix);
void jakobi(int n, int m, double ** matrix, double * x);
double iterations(int n, int m, double ** matrix);
void print_solution(int n, double * solution);
#endif //PROG_YAKOBI_H
