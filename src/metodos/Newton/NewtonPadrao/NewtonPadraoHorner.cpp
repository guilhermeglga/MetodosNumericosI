#include "NewtonPadraoHorner.h"

NewtonPadraoHorner::NewtonPadraoHorner(Polinomio &pol, double x0, double epsilon)
    :NewtonPadrao(pol, x0, epsilon){
}

double NewtonPadraoHorner::derivada(double x)
{
    return f.derivada_horner(x);
}
