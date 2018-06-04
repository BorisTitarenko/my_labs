#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

#define N 10
using namespace std;


void fill(vector < pair <double, double>> & v, double & first_x, double & second_x){
    ifstream fin("E:\\NULP\\2\\NM\\lab9\\test.txt");
    for(int i = 0; i != N; ++i){
        double x, y;
        fin >> x >> y;
        //cout << x << "  " <<  y << endl;
        v[i] = make_pair(x, y);
        //cout << v[i].first << "   " << v[i].second << endl;
    }
    fin >> first_x >> second_x;
    fin.close();
}

double Lagrange(vector < pair <double, double>>  v , double  x){
    double answer = 0;
    for(int i = 0; i != N; ++i){
        double p = 1;
        for(int j = 0; j != N; ++j){
            if(i != j)
                p *= (x - v[j].first)/(v[i].first - v[j].first);
        }
        answer += p * v[i].second;
    }
    return answer;

}
void prepare_newton(vector <double> & x_newton, vector<vector <double>> & y_newton, vector <pair <double, double>> & v){
    for(int i = 0; i != N; ++i){
        x_newton[i] = v[i].first;
        y_newton[i][0] = v[i].second;
    }
}

int factorial(int i){
    int factor = 1;
    for(int j = 1; j <= i; j++)
        factor *= j;
    return factor;
}
float u_cal(float u, int n)
{
    float temp = u;
    for (int i = 1; i < n; i++)
        temp = temp * (u - i);
    return temp;
}

double Newton(vector <double> & x_newton, vector <vector <double>> & y_newton, double x){
    //cout << "lol" << endl;
    for (int i = 1; i != N; ++i) {
        for (int j = 0; j != N - i; ++j)
            y_newton[j][i] = y_newton[j + 1][i - 1] - y_newton[j][i - 1];
    }
    //cout << "kek" << endl;
    float sum = y_newton[0][0];
    float u = (x - x_newton[0]) / (x_newton[1] - x_newton[0]);
    for (int i = 1; i != N; ++i) {
        sum = sum + (u_cal(u, i) * y_newton[0][i]) /
                    factorial(i);
    }
    return sum;
}


int main() {
    vector< pair <double, double>> v(N);
    double x_first = 0, x_second = 0;

    fill(v, x_first, x_second);
    cout << "\n\ny1 = " << Lagrange(v, x_first) << endl;

    vector <double> x_newton (N);
    vector <vector <double>> y_newton(N);
    for(int i = 0; i != N; ++i)
        y_newton[i].resize(N);
    prepare_newton(x_newton, y_newton, v);
    cout << "\n\ny2 = " <<Newton(x_newton, y_newton, x_second) << endl;
    return 0;
}