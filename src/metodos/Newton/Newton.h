#ifndef NEWTON_H
#define NEWTON_H

#include <vector>
#include <cmath>
#include "Polinomio.h"
#include "../../iteracao/iteracao.h"

class Newton {
    public:
        //x0 é o valor inicial do isolamento
        Newton(Polinomio &f, double x0, double epsilon);

        virtual iteracao iterar();
        virtual double derivada(double x);

        int get_iteracao_atual();
        double get_xk_atual();

    protected:
        Polinomio f;
        double xk, epsilon;
        std::vector<float> iteracoes;
        int iteracao_atual;
};

#endif // NEWTON_H