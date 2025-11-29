#include "../quadros/QuadroResposta.h"


static Newton CriarMetodo(NomeMetodo nome, Polinomio p, std::vector<double> lambda = std::vector<double> ()){
    switch (nome) {
        case NEWTON_PADRAO_DER_CALC : return NewtonPadraoManual(p, 0.0, 0.0);
        case NEWTON_COM_FL_DER_CALC : return NewtonFLManual(p, 0.0, 0.0, 0, lambda);
        case NEWTON_PADRAO_DER_NCALC : return NewtonPadraoHorner(p, 0.0, 0.0);
        case NEWTON_COM_FL_DER_NCALC : return NewtonFLHorner(p, 0.0, 0.0, 0, lambda);
            
        default: return Newton(p, 0.0, 0.0);
    }
}

QuadroResposta::QuadroResposta(NomeMetodo nome, Polinomio p, std::vector<double> lambda) : metodo(CriarMetodo(nome, p, lambda)) {}

double QuadroResposta::getTempo() {
    return tempo;
}

iteracao QuadroResposta::getIteracao(int indice){
    return quadro[indice];
}

void QuadroResposta::iterar_manual(){
    metodo.iterar();
    //ToDo: terminar
}

void QuadroResposta::iterar_total(){
    bool continuar = true;
    while(continuar){
        metodo.iterar();
        //ToDo: terminar
    }
}