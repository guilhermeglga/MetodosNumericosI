#include "NewtonPadrao.h"

iteracao NewtonPadrao::iterar() {
    iteracao it{};

    double x_anterior = xk;
    double f_anterior = f.valor_funcao(xk);

    if(std::abs(f_anterior < epsilon)){
        it.raiz = x_anterior;
        it.funcaoNaRaiz = f_anterior;
        it.erroEmX = 0;
        it.erroEmFX = 0;
        it.parada = true;
        if(it.raiz > 0.3) it.possivelRompimento = 0;
        else it.possivelRompimento = 0;

        return it;
    }
    double y = f.valor_funcao(xk);
    double df = derivada(xk);
    xk = xk - y / df;
    iteracao_atual++;

    it.raiz = xk;
    it.funcaoNaRaiz = y;
    it.erroEmX = std::abs(xk - x_anterior);
    it.erroEmFX = std::abs(y - f_anterior);
    it.parada = false;
    if(it.raiz > 0.3) it.possivelRompimento = 0;
    else it.possivelRompimento = 0;
    
    return it;
}

NewtonPadrao::NewtonPadrao(Polinomio &f, double x0, double epsilon)
    :Newton(f, x0, epsilon){
}
