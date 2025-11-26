#include <iostream>
#include <cmath>

#include "./métodos/newton/Polinomio.h"
#include "./métodos/newton/Newton.h"

using namespace std;

double f(double x, double a3, double a2){
    return a3 * pow(x, 3) - 9 * a2 * x + 3;
}

double isolamento(double a3, double a2) {
    double xa = 0, xb = 0;
    while(true){
        double a = f(xa, a3, a2);
        double b = f(xb, a3, a2);

        if(a * b < 0) {
            //a mudou ou b mudou
            if(a * f(xa + 0.5, a3, a2) < 0) return (xa + 0.25);
            return (xb - 0.25);
        }

        xa -= 0.5;
        xb += 0.5;
    }
}

double derivada(double x, double a3, double a2) {
    return a3 * 3 * pow(x, 2) - 9 * a2;
}

double iter_newton(double xk, double a3, double a2, double epsilon) {
    double f_xk = f(xk, a3, a2);
    double df = derivada(xk, a3, a2);
    xk = xk - f_xk / df;
    return xk;
}

double iter_newton_horner(double xk, double a3, double a2, double epsilon) {
    double f_xk = f(xk, a3, a2);
    double df = derivada_metodo_horner(xk, {3, -9 * a2, 0, a3});
    xk = xk - f_xk / df;
    return xk;
}

double newton(double x0, double a3, double a2, double epsilon){
    int k = 1;
    double xk = iter_newton(x0, a3, a2, epsilon);
    double f_xk = f(xk, a3, a2);

    while (abs(f_xk) >= epsilon){
        xk = iter_newton(xk, a3, a2, epsilon);
        f_xk = f(xk, a3, a2);
        k++;
    }

    return xk;
}

int main() {
    int n;
    double lambda, a3, a2, epsilon;
    cin >> n >> lambda >> a3 >> a2 >> epsilon;
    double x0 = isolamento(a3, a2);
    cout << newton(x0, a3, a2, epsilon) << endl;
    return 0;
}
