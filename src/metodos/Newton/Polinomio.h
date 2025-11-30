#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <vector>
#include <cmath>
#include <stdexcept>

class Polinomio {
    public:
        Polinomio(std::vector<double> a);

        double valor_funcao(double x);
        double derivada_manual(double x);
        double derivada_horner(double x);
        
        bool raiz_real();
        double isolamento();

    private:
        //vetor com coeficientes
        std::vector<double> a;
        std::vector<double> b;
        std::vector<double> c;
        int n;
};

#endif // POLINOMIO_H