#include "NewtonPadrao.h"

void Newton::iterar() {
    if(std::abs(f.valor_funcao(xk)) < epsilon)
        return;
    double y = f.valor_funcao(xk);
    double df = derivada(xk);
    xk = xk - y / df;
    iteracao_atual++;
}
