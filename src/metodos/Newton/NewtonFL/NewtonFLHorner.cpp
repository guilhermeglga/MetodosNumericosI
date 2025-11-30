#include "NewtonFLHorner.h"

NewtonFLHorner::NewtonFLHorner(Polinomio &f, double x0, double epsilon, double lambda) :
NewtonFL(f, x0, epsilon, lambda) {}

double NewtonFLHorner::derivada(double x) {
    return f.derivada_horner(x);
}
