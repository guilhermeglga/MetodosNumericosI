#include "../Newton.h"

class NewtonPadrao : public Newton {
    public:
        NewtonPadrao(Polinomio &f, double x0, double epsilon);
        void iterar() override;
};
