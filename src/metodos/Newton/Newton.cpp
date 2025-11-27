#include "Newton.h"

Newton::Newton(Polinomio &f, double x0, double epsilon)
: f(f), xk(x0), epsilon(epsilon), iteracao_atual(0) {}

int Newton::get_iteracao_atual() {
    return iteracao_atual;
}

double Newton::get_xk_atual() {
    return xk;
}
