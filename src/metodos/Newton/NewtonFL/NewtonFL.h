#include <vector>
#include <cmath>
#include "Polinomio.h"

class NewtonFL {
    public:
        //x0 é o valor inicial do isolamento
        NewtonFL(Polinomio &f, double x0, double epsilon, int n, std::vector<double> lambda);

        virtual void iterar();
        virtual double derivada(double x);

        int get_iteracao_atual();
        double get_xk_atual();

    protected:
        Polinomio f;
        double xk, xw, epsilon; //xw guarda o valor da ultima derivada de xk valida
        std::vector<double> iteracoes, lambda;
        int iteracao_atual, n;
};
