//
// Created by Borys on 08.04.2018.
//

#ifndef PROG_SEIDEL_H
#define PROG_SEIDEL_H

void fill_matrix_seidel(int n, int m, double ** matrix);
void prepare_seidel(int n, int m, double ** matrix, double * x);
void seidel(int n, int m, double ** matrix, double * x);

#endif //PROG_SEIDEL_H
