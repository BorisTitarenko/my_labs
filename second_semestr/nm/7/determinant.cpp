
#include <cmath>
using namespace std;

double determinant(double ** a, int n) {
    double det=0;
    double ** temp = new double * [n];
    temp[0] = new double [n*n];
    for(int i = 1; i != n; ++i)
        temp[i] = temp[i-1] + n;

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
            det += a[0][p] * pow(-1,p) * determinant(temp,n-1);
        }
        return det;
    }
}
