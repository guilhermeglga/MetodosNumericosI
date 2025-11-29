#include "NewtonFL.h"

class NewtonFLManual : public NewtonFL {
    public:
        NewtonFLManual(Polinomio &f, double x0, double epsilon, int n, std::vector<double> lambda);
        double derivada(double x) override;
};
