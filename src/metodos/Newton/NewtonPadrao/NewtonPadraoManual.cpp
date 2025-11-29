#include "NewtonPadraoManual.h"

NewtonPadraoManual::NewtonPadraoManual(Polinomio &pol, double x0, double epsilon)
    :NewtonPadrao(pol, x0, epsilon){
}

double NewtonPadraoManual::derivada(double x)
{
    return f.derivada_manual(x);
}
