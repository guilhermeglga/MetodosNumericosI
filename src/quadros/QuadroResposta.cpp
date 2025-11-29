#include "../quadros/QuadroResposta.h"


static Newton CriarMetodo(NomeMetodo nome, Polinomio p, double epsilon, std::vector<double> lambda, int lambda_size){
    double x0 = p.isolamento();

    switch (nome) {
        case NEWTON_PADRAO_DER_CALC : return NewtonPadraoManual(p, x0, epsilon);
        case NEWTON_COM_FL_DER_CALC : return NewtonFLManual(p, x0, epsilon, lambda_size, lambda);
        case NEWTON_PADRAO_DER_NCALC : return NewtonPadraoHorner(p, x0, epsilon);
        case NEWTON_COM_FL_DER_NCALC : return NewtonFLHorner(p, x0, epsilon, lambda_size, lambda);

        default: return Newton(p, 0.0, 0.0);
    }
}

QuadroResposta::QuadroResposta(
    NomeMetodo nome, 
    std::vector <double> coeficientes, 
    double epsilon,
    std::vector<double> lambda,
    int lambda_size
) : polinomio(coeficientes), metodo(CriarMetodo(nome, polinomio, epsilon, lambda, lambda_size)) {}

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

    quadro.push_back(metodo.iterar());
    tamanho += 1;
    
    auto tf = std::chrono::high_resolution_clock::now();
    tempo += std::chrono::duration_cast<std::chrono::milliseconds>(tf - ti).count();
}

void QuadroResposta::iterar_total(int limite){
    bool continuar = true;

    auto ti = std::chrono::high_resolution_clock::now();
    while(continuar && tamanho < limite){
        quadro.push_back(metodo.iterar());
        continuar ^= quadro[tamanho].parada;
        tamanho += 1;
    }

    auto tf = std::chrono::high_resolution_clock::now();
    tempo += std::chrono::duration_cast<std::chrono::milliseconds>(tf - ti).count();
}
