#include <vector>

class Polinomio {
    public:
    Polinomio(std::vector<double> a);

    double valor_funcao(double x);
    double derivada_horner(double x);

    private:
    //vetor com coeficientes
    std::vector<double> a;
    std::vector<double> b;
    std::vector<double> c;
    int n;
};
