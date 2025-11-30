#ifndef QUADROCOMPARATIVO_H
#define QUADROCOMPARATIVO_H

#include "QuadroResposta.h"
#include "../iteracao/iteracao.h"
#include <string>

class QuadroComparativo {
    public:
        QuadroComparativo(std::vector<double> coeficientes, double epsilon, double lambda, int interacao_max);
    
        int tam_max();

        std::string get_nome_prop(int i);

        QuadroResposta QPadrao_M; // manual
        QuadroResposta QPadrao_H; // horner
        QuadroResposta QFL_M;
        QuadroResposta QFL_H;

    private:
        std::vector<std::string> nomes_prop;
};

#endif // QUADROCOMPARATIVO_H
