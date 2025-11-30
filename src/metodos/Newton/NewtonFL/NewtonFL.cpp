#include "NewtonFL.h"

NewtonFL::NewtonFL(Polinomio &f, double x0, double epsilon, double lambda)
: Newton(f, x0, epsilon), lambda(lambda), xw(x0) {}

iteracao NewtonFL::iterar() {
    iteracao it{};

    double x_anterior = xk;
    double f_anterior = f.valor_funcao(xk);

    double df = derivada(xk);
    xk = xk - f_anterior / df;
    double y = f.valor_funcao(xk);

    it.raiz = xk;
    it.funcaoNaRaiz = y;
    it.erroEmX = std::abs(xk - x_anterior);
    it.erroEmFX = std::abs(y - f_anterior);

    if(std::abs(y) < epsilon || std::abs(xk - x_anterior) < epsilon)
        it.parada = true;
    else
        it.parada = false;

    if(it.raiz > 0.3)
        it.possivelRompimento = 1;
    else
        it.possivelRompimento = 0;

    bool mudou = 0;
    if(std::abs(df) <= lambda){
        df = xw;
        mudou = 1;
    }
    if(!mudou) xw = df;

    it.derivadaDeFXw = xw;
    it.modif = mudou;

    iteracao_atual++;

    return it;
}
