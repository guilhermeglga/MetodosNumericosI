#include "Newton.h"

Newton::Newton(Polinomio f, double x0, double epsilon)
: f(f), xk(x0), epsilon(epsilon), iteracao_atual(0) {}

void Newton::iterar() {
    double y = f.valor_funcao(xk);
    double df = f.derivada_horner(xk);
    xk = xk - y /  df;
    iteracao_atual++;
}

void Newton::iterar_horner() {
    double y = f.valor_funcao(xk);
    double df = f.derivada_horner(xk);
    xk = xk - y / df;
    iteracao_atual++;
}

int Newton::get_iteracao_atual() {
    return iteracao_atual;
}

double Newton::get_xk_atual() {
    return xk;
}
