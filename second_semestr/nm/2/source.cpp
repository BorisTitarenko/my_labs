//
// Created by Borys on 15.02.2018.
//
#include <iostream>
#include <cmath>
#include <cstdio>
#define X0 b
using namespace std;

double f(double x){
    return pow(2, x) - pow(x, 2) - 1.2 + x/2;
}

int input(double & a, double & b, double & e){
    unsigned short  flag = 0;
    if(cin >> a >> b >> e)
        if(f(a)*f(b) < 0)
            flag = 1;
    if(!flag)cout << "Something entered incorectly. Let's try agayn !))" << endl;
    return flag;
}




double df(double x){
    return -2*x + pow(2, x) * log(2) + 1/2;
}


double ddf(double x){
    return pow(2, x)*pow(log(2), 2) - 2;
}

double o(double x){
    return //sqrt(pow(2,x) - 1.2 + x/2);
    x - (pow(2, x) - pow(x, 2) - 1.2 + x/2)/2;
    //-2 * pow(2,x) + 2 * pow(x, 2) + 2.4;
}

print(int i, double x, double b){
    printf("i = %-3d x = %-15lf x0 = %-15lf\n", i, x, b);
}

double Newton(double a, double b, double e){
    if (fabs(b-a) < e) return (b-a)/2.0;
    double temp_a = a, temp_b = b;
    if(f(b)*ddf(b) < 0){
        b = a;
    }
    double x0 = b;
    double x = x0;
    for (int i = 0; i < 1000; i++){
        x -= f(x0)/df(X0);
        print(i, x, X0);
        while(x < temp_a || x > temp_b){x = (x + x0)/2;}
        if (fabs(x0 - x) < e)
            break;
        x0 = x;
    }
    return x;
}


double iterations(double a, double b, double e){
    double x0 = (a + b)/2;
    double x = 0;
    double temp_a = a, temp_b = b;
    if (fabs(b-a) < e) return (b-a)/2.0;
    for(int i = 0; i < 1000; i++){
        x = o(x0);
        print(i, x, x0);
        while(x <= temp_a || x >= temp_b){x = (x + x0)/2;}

        if(fabs(x - x0) < e)
            break;
        x0 = x;
    }
    return x;
}


