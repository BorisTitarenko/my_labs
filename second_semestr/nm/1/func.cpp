//
// Created by Borys on 13.02.2018.
//
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double f(double x){//сама функція
    return pow(2, x) - pow(x, 2) - 1.2 + x/2;
}
double ddf(double x){// друга похідна функції
    return pow(2, x)*pow(log(2), 2) - 2;
}



int input(double & a, double & b, double & e){//функція вводу значень
    unsigned short  flag = 0;
    if(cin >> a >> b >> e);
        if(f(a)*f(b) < 0)
            flag = 1;
    if(!flag)(cout << "Something entered incorectly. Lets try again !))\n");
    return flag;
}

void print(int i, double x, double a){// функція виводу
    printf("n = %-3d x = %-10lf a = %-10lf\n", i, x, a);
}

double dihom(double a, double b, double e){//функція пошуку коренів рівняння методом поділу відрізка пополам
    double x = (b+a)/2;
    for (int i = 0; (fabs(b-a) > e) && f((x) != 0) && i < 1000; i++){
        x = (b+a)/2.0;
        if(f(a)*f(x) < 0){
            b = x;
            print(i, x, a);}
        else{
            a = x;
            print(i, x, a);}
    }
    return x;
}



double hord(double a, double b, double e){//функція пошуку коренів рівняння методом хорд
    double x =( a + b)/2;
    if (fabs(b-a) < e) return (b-a)/2.0;

    if(f(b)*ddf(b) <= 0){
        double temp = a;
        a = b;
        b = temp;
    }
    for (int i = 0; i < 1000; i++){
        x = a - (f(a)*(b-a))/(f(b) - f(a));
        print(i, x, a);
        if(fabs(a - x) < e){
            break;}
        a = x;
    }
    return x;

}
