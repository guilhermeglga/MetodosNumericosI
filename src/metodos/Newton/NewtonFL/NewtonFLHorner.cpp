#include "NewtonFLHorner.h"

NewtonFLHorner::NewtonFLHorner(Polinomio &f, double x0, double epsilon, int n, std::vector<double> lambda) :
NewtonFL(f, x0, epsilon, n, lambda) {}

double NewtonFLHorner::derivada(double x) {
    return f.derivada_horner(x);
}
