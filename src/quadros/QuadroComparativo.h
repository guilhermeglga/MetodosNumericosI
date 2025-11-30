#ifndef QUADROCOMPARATIVO_H
#define QUADROCOMPARATIVO_H

#include "QuadroResposta.h"
#include "../iteracao/iteracao.h"
#include <utility>
#include <map>

class QuadroComparativo {
    public:
        QuadroComparativo(std::vector<double> coeficientes, double epsilon, double lambda, int interacao_max);
    
        QuadroResposta QPadrao_M; // manual
        QuadroResposta QPadrao_H; // horner
        QuadroResposta QFL_M;
        QuadroResposta QFL_H;
};

#endif // QUADROCOMPARATIVO_H
