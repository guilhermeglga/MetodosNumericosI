#ifndef NEWTONFL_H
#define NEWTONFL_H

#include "../Newton.h"

class NewtonFL : public Newton {
    public:
        NewtonFL(Polinomio &f, double x0, double epsilon, double lambda);
        iteracao iterar() override;
    protected:
       double lambda, xw;
};

#endif // NEWTONFL_H