#ifndef QUADROCOMPARATIVO_H
#define QUADROCOMPARATIVO_H

#include "QuadroResposta.h"
#include "../iteracao/iteracao.h"
#include <utility>

class QuadroComparativo {
    public:
        QuadroComparativo(NomeMetodo metodo1, NomeMetodo metodo2, std::vector<double> coeficientes, double epsilon, int n, std::vector<double> lambda);

        void executarComparacao(int interacao_max);
        std::pair<int,int> tamanhosQuadros();
        std::pair<iteracao*,iteracao*> getIteracoes(int i);
    
    private:
        QuadroResposta quadro1;
        QuadroResposta quadro2;
};

#endif // QUADROCOMPARATIVO_H
