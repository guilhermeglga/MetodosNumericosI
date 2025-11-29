#include "QuadroComparativo.h"
#include <Polinomio.h>

static Newton CriarMetodo(NomeMetodo nome, Polinomio p, std::vector<double> lambda = std::vector<double> ()){
    switch (nome) {
        case NEWTON_PADRAO_DER_CALC : return NewtonPadraoManual(p, 0.0, 0.0);
        case NEWTON_COM_FL_DER_CALC : return NewtonFLManual(p, 0.0, 0.0, 0, lambda);
        case NEWTON_PADRAO_DER_NCALC : return NewtonPadraoHorner(p, 0.0, 0.0);
        case NEWTON_COM_FL_DER_NCALC : return NewtonFLHorner(p, 0.0, 0.0, 0, lambda);
            
        default: return Newton(p, 0.0, 0.0);
    }
}

QuadroComparativo::QuadroComparativo(NomeMetodo metodo1, NomeMetodo metodo2,Polinomio &p, double x0, double epsilon, int n, std::vector<double> lambda)
    : polinomio(p), x0(x0), epsilon(epsilon), n(n), lambda(lambda), 
    CriarMetodo(NEWTON_PADRAO_DER_CALC, p, std::vector<double>()),
    quadro_newton_fl(NEWTON_COM_FL_DER_CALC, p, lambda) {}

void QuadroComparacao::preencherHistorico(QuadroResposta &quadro, std::vector<iteracao> &historico) {
    for (int i = 0; i < iteracoes_max; i++) {
        quadro.iterar_manual();
        iteracao it = quadro.iterar(i);
        historico.push_back(it);

        if (it.parada) {
            std::cout << "Metodo convergiu na iteracao " << i + 1 << std::endl;
            break;
        }
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