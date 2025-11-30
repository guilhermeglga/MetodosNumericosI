#ifndef NEWTONFLMANUAL_H
#define NEWTONFLMANUAL_H

#include "NewtonFL.h"

class NewtonFLManual : public NewtonFL {
    public:
        NewtonFLManual(Polinomio &f, double x0, double epsilon, double lambda);
        double derivada(double x) override;
};

#endif // NEWTONFLMANUAL_H