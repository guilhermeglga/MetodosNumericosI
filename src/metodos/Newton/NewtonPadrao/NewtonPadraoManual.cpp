#include "NewtonPadraoManual.h"

NewtonPadraoManual::NewtonPadraoManual(Polinomio &f, double x0, double epsilon) :
NewtonPadrao(f, x0, epsilon) {}

double NewtonPadraoManual::derivada(double x) {
    return f.derivada_manual(x);
}
