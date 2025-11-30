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

bool Polinomio::raiz_real(){ //verifica se possui raizes reais
    double eps = 1e-12;
    if(fabs(a[3]) > 0) return true; //funcoes de grau impar sempre tem raiz
    else if(fabs(a[2]) <= eps && fabs(a[1]) > eps) return true;
    else if(fabs(a[3]) <= eps && fabs(a[2]) <= eps && fabs(a[1]) <= eps && fabs(a[0]) > eps) return false;

    //se nao entrou em nenhum if, é uma função do segundo grau
    //basta calcular o discriminante (delta)
    double d = a[1]*a[1] - 4*a[2]*a[0];
    if(d < 0) return false;
    else return true;
}

double Polinomio::isolamento() {
    double eps = 1e-12;
    if(fabs(a[3]) <= eps && fabs(a[2]) <= eps && fabs(a[1]) <= eps && fabs(a[0]) <= eps) return 0;
    if(raiz_real() == false) throw std::runtime_error("Sem raizes reais");

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
