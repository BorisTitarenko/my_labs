//
// Created by Borys on 08.04.2018.
//

#ifndef PROG_MIN_SQ_H
#define PROG_MIN_SQ_H

void fill_matrix(int n, int m, double ** matrix, double * x);
void print(int n, int m, double ** matrix);
void free_memory(double ** matrix, double * x);
void min_sq(int n, int m, double **matrix, double **matrix_norm, double *b, double *b_norm, double *solution);
void sqrt_met(int m, double ** matrix_norm, double * b_norm, double * solution);
#endif //PROG_MIN_SQ_H
