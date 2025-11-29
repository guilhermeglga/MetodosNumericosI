#include "NewtonFLManual.h"

NewtonFLManual::NewtonFLManual(Polinomio &f, double x0, double epsilon, int n, std::vector<double> lambda) :
NewtonFL(f, x0, epsilon, n, lambda) {}

double NewtonFLManual::derivada(double x) {
    return f.derivada_manual(x);
}