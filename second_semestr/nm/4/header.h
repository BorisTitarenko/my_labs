//
// Created by Borys on 25.03.2018.
//

#ifndef CODE_HEADER_H
#define CODE_HEADER_H

void fill_matrix(int n, int m, double ** matrix);
void print(int n, int m, double ** matrix);
void Gausse_with_main_element(int n, int m, double **matrix, double * solution);
void LU(int n, int m, double ** matrix, double ** L, double ** U, double * solution);
void free_memory(int n, double ** matrix, double ** L, double ** U, double * solution);
#endif //CODE_HEADER_H
