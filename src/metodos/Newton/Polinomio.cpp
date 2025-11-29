#include "Polinomio.h"

Polinomio::Polinomio(std::vector<double> a) //vetor com coeficientes
: a(a), n(a.size()) {
    b.resize(n);
    c.resize(n);
}

double Polinomio::valor_funcao(double x) {
    double val = 0;
    for (int i = n - 1; i >= 0; i--) {
        val *= x;
        val += a[i];
        b[i] = val;
    }
    return b[0];
}

double Polinomio::derivada_manual(double x) {
    double val = 0;
    for (int i = 1 ; i < n ; i++) {
        val += a[i] * i * pow(x, i - 1);
    }
    return val;
}

double Polinomio::derivada_horner(double x) {
    if(n == 1) return 0;

    c[n-1] = b[n-1];
    for (int i = n-2; i >= 1; i--) {
        c[i] = b[i] + c[i+1] * x;
    }
    return c[1];
}

double Polinomio::isolamento() {
    double xa = 0, xb = 0;
    while(true){
        double a = valor_funcao(xa);
        double b = valor_funcao(xb);

        if(a * b < 0) {
            //a mudou ou b mudou
            if(a * valor_funcao(xa + 0.5) < 0) return (xa + 0.25);
            return (xb - 0.25);
        }

        xa -= 0.5;
        xb += 0.5;
    }
}
