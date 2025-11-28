#include "NewtonFL.h"

NewtonFL::NewtonFL(Polinomio &f, double x0, double epsilon, int n, vector<double> lambda)
: f(f), xk(x0), xw(x0), epsilon(epsilon), iteracao_atual(0), n(n), lambda(lambda) {}

void Newton::iterar() {
    if(std::abs(f.valor_funcao(xk)) < epsilon)
        return;
    double y = f.valor_funcao(xk);
    double df = derivada(xk);
    bool val = 1;
    for(int i = 0 ; i < n ; i++){
        if(std::abs(df) <= lambda[i]){
            df = xw;
            val = 0;
        }
    }
    xk = xk - y / df;
    if(val) xw = df;
    iteracao_atual++;
}

int Newton::get_iteracao_atual() {
    return iteracao_atual;
}

double Newton::get_xk_atual() {
    return xk;
}
