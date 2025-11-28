#include "NewtonPadraoHorner.h"

NewtonPadraoHorner::NewtonPadraoHorner(Polinomio &f, double x0, double epsilon) :
NewtonPadrao(f, x0, epsilon) {}

double NewtonPadraoHorner::derivada(double x) {
    return f.derivada_horner(x);
}
