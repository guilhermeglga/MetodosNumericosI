#include "NewtonPadraoHorner.h"

double Newton::derivada(double x) {
    return f.derivada_horner(x);
}