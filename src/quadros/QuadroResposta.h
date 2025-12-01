#ifndef QUADRORESPOSTA_H
#define QUADRORESPOSTA_H

#include <vector>
#include <chrono>

#include "../iteracao/iteracao.h"
#include "../metodos/Newton/Newton.h"
#include "../metodos/Newton/NewtonPadrao/NewtonPadraoManual.h"
#include "../metodos/Newton/NewtonPadrao/NewtonPadraoHorner.h"
#include "../metodos/Newton/NewtonFL/NewtonFLManual.h"
#include "../metodos/Newton/NewtonFL/NewtonFLHorner.h"
#include "../metodos/Newton/Polinomio.h"
#include <cfloat>


enum NomeMetodo {
    NEWTON_PADRAO_DER_CALC,
    NEWTON_COM_FL_DER_CALC,
    NEWTON_PADRAO_DER_NCALC,
    NEWTON_COM_FL_DER_NCALC
};

class QuadroResposta{
    public:
        QuadroResposta(
            NomeMetodo metodo, 
            std::vector <double> coeficientes, 
            double epsilon,
            double lambda
        );

        void iterar_manual();
        void iterar_total(int limite);

        iteracao getIteracao(int indice);
        int getTamanho();
        long long getTempo();
        
    private:
        // Como newton é abstrato, esse atributo precisa ser um ponteiro
        Newton* metodo;
        Polinomio polinomio;
        std::vector <iteracao> quadro;

        int tamanho = 0;
        long long tempo = 0;

        Newton* CriarMetodo(NomeMetodo nome, Polinomio p, double epsilon, double lambda);
        
};

#endif // QUADRORESPOSTA_H
