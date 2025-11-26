#include <vector>

#include "Polinomio.h"

class Newton {
    public:
    //x0 é o valor inicial do isolamento
    Newton(Polinomio f, double x0, double epsilon);

    void iterar();
    void iterar_horner();

    int get_iteracao_atual();
    double get_xk_atual();

    private:
    Polinomio f;
    double xk, epsilon;
    std::vector<float> iteracoes;
    int iteracao_atual;
};
