//
// Created by Borys on 03.03.2018.
//
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#define MAX 3

using namespace std;

void show(double temp[MAX][MAX]){
    for (int i = 0; i < MAX; i++){
        cout << endl;
        for (int j = 0; j < MAX; j++){
            cout << temp[i][j] << "  ";
        }
    }
}
void fill(double a[MAX][MAX], double sol[MAX]){
    for (int i = 0; i != MAX; ++i){
        for (int j = 0; j != MAX; ++j){
            cin >> a[i][j];
        }
    }
    for (int i = 0; i != MAX; ++i){
        cin >> sol[i];
    }
}
void print(double res[MAX]){
    for (int i = 0; i != MAX; ++i){
        cout << "x" << i+1 << " = " << res[i] << endl;
    }
}
void trans(double temp[MAX][MAX]){
    for (int i = 0; i != MAX; ++i){
        for (int j = i; j != MAX; ++j){
            double t = temp[j][i];
            temp[j][i] = temp[i][j];
            temp[i][j] = t;
        }
    }
}


double determinant(double a[MAX][MAX], int n) {
    double det=0, temp[MAX][MAX];
    int p, h, k, i, j;
    if(n==1) {
        return a[0][0];
    } else if(n==2) {
        det=(a[0][0]*a[1][1]-a[0][1]*a[1][0]);
        return det;
    } else {
        for(p=0;p<n;p++) {
            h = 0;
            k = 0;
            for(i=1;i<n;i++) {
                for( j=0;j<n;j++) {
                    if(j==p) {
                        continue;
                    }
                    temp[h][k] = a[i][j];
                    k++;
                    if(k==n-1) {
                        h++;
                        k = 0;
                    }
                }
            }
            det += a[0][p]*pow(-1,p)*determinant(temp,n-1);
        }
        return det;
    }
}

int Cramer(double a[MAX][MAX], double sol[MAX], double res[MAX]){
    //show(a);
    double temp_at [MAX][MAX];
    double temp [MAX][MAX];
    memcpy(temp_at, a, MAX*MAX*sizeof(double));

    trans(temp_at);

    for (int i = 1; i != MAX; ++i){
        memcpy(temp[i-1], temp_at[i], MAX*sizeof(double));
    }
    memcpy(temp[MAX-1], sol, MAX*sizeof(double));


    double det = determinant(a, MAX);
    cout << "Determinant = " << det << endl;
    double dett = determinant(temp, MAX);
    if(!det){cout << "lol"; return 1;}
    if(!dett){cout << "kek"; return 1;}



    for(int i = 0; i != MAX; ++i){
        memcpy(temp, temp_at, MAX*MAX*sizeof(double));
        memcpy(temp[i], sol, MAX*sizeof(double));

        res[i] = determinant(temp, MAX)/det;

    }
    return 0;

}

double alg(double a[MAX][MAX], int i, int j){
    double temp[MAX][MAX];
    for(int m = 0; m != MAX; ++m) {
        memcpy(temp, a, MAX * MAX * sizeof(double));
        for (int k = 0; k != MAX; ++k) {
            if (k == j)
                continue;
            temp[i][k] = 0;
        }
    }
    double res = determinant(temp, MAX) / a[i][j];
    return res;
}

void Inv(double a[MAX][MAX], double sol[MAX], double res[MAX]){
    double main_det = determinant(a, MAX);

    double inv[MAX][MAX];
    for(int i = 0; i != MAX; ++i){
        for(int j = 0; j != MAX; ++j){
            inv[i][j] = alg(a, i, j);
        }
    }
	
    trans(inv);
    cout << endl;
    for(int i = 0; i != MAX; ++i){
        double mul = 0;
        for(int j = 0; j != MAX; ++j){
            mul += inv[i][j]*sol[j];
        }
        res[i] = mul/main_det;
    }

}




