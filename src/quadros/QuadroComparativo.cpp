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

void QuadroComparativo::executarcomparacao(int interacao_max) {
    this->interacao_max = interacao_max;
    historico1.clear();
    historico2.clear();

    auto comeco_met1 = std::chrono::high_resolution_clock::now();
    preencherHistorico(quadro1, historico1);
    auto fim_met1 = std::chrono::high_resolution_clock::now();
    auto duracao_met1 = std::chrono::duration_cast<std::chrono::microseconds>(fim_met1 - comeco_met1);

    auto comeco_met2 = std::chrono::high_resolution_clock::now();
    preencherHistorico(quadro2, historico2);
    auto fim_met2 = std::chrono::high_resolution_clock::now();
    auto duracao_met2 = std::chrono::duration_cast<std::chrono::microseconds>(fim_met2 - comeco_met2);
}
