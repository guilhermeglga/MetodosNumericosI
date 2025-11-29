#include "NewtonPadraoHorner.h"

double NewtonPadraoHorner::derivada(double x) {
    return f.derivada_horner(x);
}
