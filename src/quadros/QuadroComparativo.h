#ifndef QUADROCOMPARATIVO_H
#define QUADROCOMPARATIVO_H

#include "QuadroResposta.h"
#include "../iteracao/iteracao.h"

class QuadroComparativo {
    public:
        QuadroComparativo(NomeMetodo metodo1, NomeMetodo metodo2, Polinomio &p, double x0, double epsilon, int n, std::vector<double> lambda);

        void executarcomparacao();
        void preencherHistorico();
    private:
        QuadroResposta quadro1;
        QuadroResposta quadro2;
        std::vector<iteracao> historico_newton_padrao;
        std::vector<iteracao> historico_newton_fl;
        Polinomio polinomio;
        double x0;
        double epsilon;
        int n;
        std::vector<double> lambda;
};
#endif
