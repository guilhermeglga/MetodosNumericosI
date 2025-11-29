#ifndef QUADROCOMPARATIVO_H
#define QUADROCOMPARATIVO_H

#include "QuadroResposta.h"
#include "../iteracao/iteracao.h"

class QuadroComparativo {
    public:
        QuadroComparativo(NomeMetodo metodo1, NomeMetodo metodo2, Polinomio &p, double x0, double epsilon, int n, std::vector<double> lambda);

        void executarcomparacao(int interacao_max);
        void preencherHistorico();
    private:
        QuadroResposta quadro1;
        QuadroResposta quadro2;
        std::vector<iteracao> historico1;
        std::vector<iteracao> historico2;
        long long tempo1;
        long long tempo2;
        Polinomio polinomio;
        double x0;
        double epsilon;
        int n;
        std::vector<double> lambda;
        int interacao_max;
};

#endif // QUADROCOMPARATIVO_H