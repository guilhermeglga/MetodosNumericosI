#include "QuadroComparativo.h"
#include <Polinomio.h>

static Newton CriarMetodo(NomeMetodo nome, Polinomio p, double x0, double epsilon, int n, std::vector<double> lambda = std::vector<double>()){
    switch (nome) {
        case NEWTON_PADRAO_DER_CALC : return NewtonPadraoManual(p, x0, epsilon);
        case NEWTON_COM_FL_DER_CALC : return NewtonFLManual(p, x0, epsilon, lambda);
        case NEWTON_PADRAO_DER_NCALC : return NewtonPadraoHorner(p, x0, epsilon);
        case NEWTON_COM_FL_DER_NCALC : return NewtonFLHorner(p, x0, epsilon, lambda);

        default: return Newton(p, x0, epsilon);
    }
}

QuadroComparativo::QuadroComparativo(NomeMetodo metodo1, NomeMetodo metodo2,Polinomio &p, double x0, double epsilon, int n, std::vector<double> lambda)
    : polinomio(p), x0(x0), epsilon(epsilon), n(n), lambda(lambda),
    quadro1(metodo1, p, lambda),
    quadro2(metodo2, p, lambda) {}

void QuadroComparativo::preencherHistorico(QuadroResposta &quadro, std::vector<iteracao> &historico) {
    quadro.iterar_manual();
    iteracao it = quadro.getIteracao(0);
    historico.push_back(it);
    int i = 1;
    while (!it.parada){
        i += 1;
        quadro.iterar_manual();
        iteracao it = quadro.getIteracao(i);
        historico.push_back(it);
     }
}

void QuadroComparativo::executarcomparacao() {
    historico_newton_padrao.clear();
    historico_newton_fl.clear();

    auto start_newton = std::chrono::high_resolution_clock::now();
    preencherHistorico(quadro_newton_padrao, historico_newton_padrao);
    auto end_newton = std::chrono::high_resolution_clock::now();
    auto duration_newton = std::chrono::duration_cast<std::chrono::microseconds>(end_newton - start_newton);

    auto start_fl = std::chrono::high_resolution_clock::now();
    preencherHistorico(quadro_newton_fl, historico_newton_fl);
    auto end_fl = std::chrono::high_resolution_clock::now();
    auto duration_fl = std::chrono::duration_cast<std::chrono::microseconds>(end_fl - start_fl);
}
