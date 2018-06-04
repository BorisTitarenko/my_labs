//
// Created by Borys on 06.05.2018.
//

#ifndef CODE_GAUSE_H
#define CODE_GAUSE_H
#include <cstring>
#include <iostream>

using namespace std;

template <class TYPE, size_t colums, size_t rows>
class Gause{
    size_t n;
    size_t m;
public:

    Gause() : n(colums), m(rows) {}

    void flesh_back(TYPE matrix[][rows], TYPE solution[]){
        for (int i = n-1; i>=0; i--) {
            solution[i] = matrix[i][n]/matrix[i][i];
            for (int k=i-1;k>=0; k--) {
                matrix[k][n] -= matrix[k][i] * solution[i];
            }
        }
    }

    void Gausse_with_main_element(TYPE matrix[][rows], TYPE solution[]) {
        cout << "\n";
        for(int i = 0; i != n; ++i){
            TYPE max_el = matrix[i][i];
            int  max_el_index = i;
            for(int k = i+1; k != n; ++k){
                if(fabs(matrix[k][i]) > max_el){
                    max_el = matrix[k][i];
                    max_el_index = k;
                }
            }
            if(max_el == 0){
                cout << "System doesn't have solution";
                return;
            }
            if(max_el_index != i) {
                TYPE temp[n];
                memcpy(temp, matrix[i], sizeof(TYPE)*(m));
                memcpy(matrix[i], matrix[max_el_index], sizeof(TYPE)*(m));
                memcpy(matrix[max_el_index], temp, sizeof(TYPE)*(m));

            }


            for (int k=i+1; k != n; ++k) {
                TYPE c = -matrix[k][i]/matrix[i][i];
                for (int j=i; j != m; ++j) {
                    if (i==j)
                        matrix[k][j] = 0;
                    else
                        matrix[k][j] += c * matrix[i][j];
                }
            }
        }
        flesh_back(matrix, solution);
    }
};
#endif //CODE_GAUSE_H
