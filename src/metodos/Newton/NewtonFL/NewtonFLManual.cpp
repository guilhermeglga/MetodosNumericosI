#include "NewtonFLManual.h"

NewtonFLManual::NewtonFLManual(Polinomio &f, double x0, double epsilon, double lambda) :
NewtonFL(f, x0, epsilon, lambda) {}

double NewtonFLManual::derivada(double x) {
    return f.derivada_manual(x);
}