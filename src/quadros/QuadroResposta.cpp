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
) 
{
    try{
        polinomio = new Polinomio(coeficientes);
    }catch(std::runtime_error &e){
        throw e;
    }
    metodo = CriarMetodo(nome, *polinomio, epsilon, lambda);
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
    bool continuar = true;

    auto ti = std::chrono::high_resolution_clock::now();
    while(continuar && tamanho < limite){
        quadro.push_back(metodo->iterar());
        continuar ^= quadro[tamanho].parada;
        tamanho += 1;
    }

    auto tf = std::chrono::high_resolution_clock::now();
    tempo += std::chrono::duration_cast<std::chrono::milliseconds>(tf - ti).count();
}
