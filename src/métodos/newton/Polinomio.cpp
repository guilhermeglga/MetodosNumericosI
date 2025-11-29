#include "Polinomio.h"

Polinomio::Polinomio(std::vector<double> a) //vetor com coeficientes
: a(a), n(a.size()) {
    b.resize(n);
    c.resize(n);
}

double Polinomio::valor_funcao(double x) {
    double val = 0;
    for (int i = n - 1 ; i >= 0; i--) {
        val *= x;
        val += a[i];
        b[i] = val;
    }
    return b[0];
}

double Polinomio::derivada_horner(double x) {
    if(n == 1) return 0;

    c[n-1] = b[n-1];
    for (int i = n-2; i >= 1; i--) {
        c[i] = b[i] + c[i+1] * x;
    }
    return c[1];
}
