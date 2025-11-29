#include "QuadroComparativo.h"
#include <Polinomio.h>

QuadroComparativo::QuadroComparativo(NomeMetodo metodo1, NomeMetodo metodo2, std::vector<double> coeficientes, double epsilon, int n, std::vector<double> lambda): 
    quadro1(metodo1, coeficientes, epsilon, lambda, n),
    quadro2(metodo2, coeficientes, epsilon, lambda, n) {}

void QuadroComparativo::executarComparacao(int interacao_max) {
    quadro1.iterar_total(interacao_max);
    quadro2.iterar_total(interacao_max);
}

std::pair<int,int> QuadroComparativo::tamanhosQuadros(){
    std::pair<int,int> tamanhos(quadro1.getTamanho(),quadro2.getTamanho());
    return tamanhos;
}

std::pair<iteracao*,iteracao*> QuadroComparativo::getIteracoes(int i){
    std::pair<iteracao*,iteracao*> iteracoes;
    int tamanho1 = tamanhosQuadros().first;
    int tamanho2 = tamanhosQuadros().second;
    if (i > tamanho1){
        iteracoes.first = &quadro1.getIteracao(i);
    }else{
        iteracoes.first = nullptr;
    }if (i > tamanho2){
        iteracoes.second = &quadro2.getIteracao(i);
    }else{
        iteracoes.second = nullptr;
    }
    return iteracoes;
}