#ifndef NEWTONPADRAO_H
#define NEWTONPADRAO_H

#include "../Newton.h"

class NewtonPadrao : public Newton {
    public:
        iteracao iterar() override;

        NewtonPadrao(Polinomio &f, double x0, double epsilon);
};

#endif // NEWTONPADRAO_H