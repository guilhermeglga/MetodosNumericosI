#include "NewtonPadrao.h"

class NewtonPadraoHorner : public NewtonPadrao {
    public:
        NewtonPadraoHorner(Polinomio& pol, double x0, double epsilon);
        double derivada(double x) override;
};
