#include "../quadros/QuadroResposta.h"


static Newton* CriarMetodo(NomeMetodo nome, Polinomio p, double epsilon, double lambda){
    double x0 = p.isolamento();

    switch (nome) {
        case NEWTON_PADRAO_DER_CALC : return new NewtonPadraoManual(p, x0, epsilon);
        case NEWTON_COM_FL_DER_CALC : return new NewtonFLManual(p, x0, epsilon, lambda);
        case NEWTON_PADRAO_DER_NCALC : return new NewtonPadraoHorner(p, x0, epsilon);
        case NEWTON_COM_FL_DER_NCALC : return new NewtonFLHorner(p, x0, epsilon, lambda);

        default: return new NewtonPadraoManual(p, x0, epsilon);
    }
}

QuadroResposta::QuadroResposta(
    NomeMetodo nome, 
    std::vector <double> coeficientes, 
    double epsilon,
    double lambda
) : polinomio(coeficientes)
{
    metodo = CriarMetodo(nome, polinomio, epsilon, lambda);
}

long long QuadroResposta::getTempo() {
    return tempo;
}

iteracao QuadroResposta::getIteracao(int indice){
    return quadro[indice];
}

int QuadroResposta::getTamanho(){
    return tamanho;
}

void QuadroResposta::iterar_manual(){
    auto ti = std::chrono::high_resolution_clock::now();

    quadro.push_back(metodo->iterar());
    tamanho += 1;
    
    auto tf = std::chrono::high_resolution_clock::now();
    tempo += std::chrono::duration_cast<std::chrono::milliseconds>(tf - ti).count();
}

void QuadroResposta::iterar_total(int limite){
    bool parar = false;

    auto ti = std::chrono::high_resolution_clock::now();
    while(!parar && tamanho < limite){
        iteracao iter = metodo->iterar();
        quadro.push_back(iter);
        parar = iter.parada;
        tamanho += 1;
    }

    for(size_t i = 0; i < quadro.size()-1; i++){
        if(quadro[i].possivelRompimento == true) quadro[i].possivelRompimento = false;
    }

    auto tf = std::chrono::high_resolution_clock::now();
    tempo += std::chrono::duration_cast<std::chrono::milliseconds>(tf - ti).count();
}
