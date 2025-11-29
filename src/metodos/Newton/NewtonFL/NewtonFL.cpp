#include "NewtonFL.h"

NewtonFL::NewtonFL(Polinomio &f, double x0, double epsilon, int n_, std::vector<double> lambda)
: Newton(f, x0, epsilon), lambda(lambda), xw(x0) {
    n = n_;
}

iteracao NewtonFL::iterar() {
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
        it.derivadaDeFXw = xw;
        it.modif = false;

        return it;
    }
    double y = f.valor_funcao(xk);
    double df = derivada(xk);
    bool mudou = 0;
    for(int i = 0 ; i < n ; i++){
        if(std::abs(df) <= lambda[i]){
            df = xw;
            mudou = 1;
        }
    }
    xk = xk - y / df;
    if(!mudou) xw = df;
    iteracao_atual++;

    it.raiz = xk;
    it.funcaoNaRaiz = y;
    it.erroEmX = std::abs(xk - x_anterior);
    it.erroEmFX = std::abs(y - f_anterior);
    it.parada = false;
    if(it.raiz > 0.3) it.possivelRompimento = 0;
    else it.possivelRompimento = 0;
    it.derivadaDeFXw = xw;
    it.modif = mudou;

    return it;
}