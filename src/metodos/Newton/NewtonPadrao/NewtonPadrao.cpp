#include "NewtonPadrao.h"

NewtonPadrao::NewtonPadrao(Polinomio &f, double x0, double epsilon) :
Newton(f, x0, epsilon) {}

void NewtonPadrao::iterar() {
    if(std::abs(f.valor_funcao(xk)) < epsilon)
        return;
    double y = f.valor_funcao(xk);
    double df = derivada(xk);
    xk = xk - y / df;
    iteracao_atual++;
}
