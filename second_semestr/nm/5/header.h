//
// Created by Borys on 02.04.2018.
//

#ifndef LAB5_HEADER_H
#define LAB5_HEADER_H
void fill_matrix(int n, int m, double ** matrix);
void print(int n, int m, double ** matrix);
void LU(int n, int m, double ** matrix, double ** L, double ** U, double * solution);
void free_memory(double ** matrix, double ** L, double ** U, double * solution);

#endif //LAB5_HEADER_H
