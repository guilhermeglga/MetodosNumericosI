#include "NewtonPadrao.h"

class NewtonPadraoManual : public NewtonPadrao {
    public:
        NewtonPadraoManual(Polinomio& pol, double x0, double epsilon);
        double derivada(double x) override;
};
