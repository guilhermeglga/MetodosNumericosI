#include <vector>
#include <cmath>
#include "Polinomio.h"

class Newton {
    public:
        //x0 é o valor inicial do isolamento
        Newton(Polinomio &f, double x0, double epsilon);

        virtual void iterar() = 0;
        virtual double derivada(double x) = 0;

        int get_iteracao_atual();
        double get_xk_atual();

    protected:
        Polinomio f;
        double xk, epsilon;
        std::vector<float> iteracoes;
        int iteracao_atual;
};
