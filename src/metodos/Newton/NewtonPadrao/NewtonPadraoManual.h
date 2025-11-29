#ifndef NEWTONPADRAOMANUAL_H
#define NEWTONPADRAOMANUAL_H

#include "NewtonPadrao.h"

class NewtonPadraoManual : public NewtonPadrao {
    public:
        NewtonPadraoManual(Polinomio& pol, double x0, double epsilon);
        double derivada(double x) override;
};

#endif // NEWTONPADRAOMANUAL_H