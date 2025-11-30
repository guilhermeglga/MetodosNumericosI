#ifndef UI_ITERINPUT_H
#define UI_ITERINPUT_H

#include "../../Page/Page.h"
#include "../../../../quadros/QuadroResposta.h"

using namespace std;

struct IterEntries{
    int n; // Número de opções
    vector<vector<double>> a; // Coeficientes do polinomio
    vector<double> lambdas;
    NomeMetodo metodo;
    double epsilon;
};

class IterInput : public Page{
    public:
        void render() override;
        IterInput(Rectangle bounds_, ControlFlow* flow_);

        IterEntries get_entries();
    private:
        IterEntries entries;
};

#endif // UI_ITERINPUT_H