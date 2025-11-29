#ifndef NEWTONFL_H
#define NEWTONFL_H

#include "../Newton.h"

class NewtonFL : public Newton {
    public:
        NewtonFL(Polinomio &f, double x0, double epsilon, int n, std::vector<double> lambda);
        iteracao iterar() override;
    protected:
       std::vector<double> lambda;
       int n;
       double xw;
};

#endif // NEWTONFL_H