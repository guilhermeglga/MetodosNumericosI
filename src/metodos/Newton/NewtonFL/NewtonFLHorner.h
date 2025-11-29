#ifndef NEWTONFLHORNER_H
#define NEWTONFLHORNER_H

#include "NewtonFL.h"

class NewtonFLHorner : public NewtonFL {
    public:
        NewtonFLHorner(Polinomio &f, double x0, double epsilon, int n, std::vector<double> lambda);
        double derivada(double x) override;
};

#endif // NEWTONFLHORNER_H