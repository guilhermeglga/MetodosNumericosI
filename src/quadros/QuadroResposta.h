#ifndef QUADRORESPOSTA_H
#define QUADRORESPOSTA_H

#include <vector>
#include <chrono>
#include <iostream>

#include "../iteracao/iteracao.h"
#include "../metodos/Newton/Newton.h"
#include "../metodos/Newton/NewtonPadrao/NewtonPadraoManual.h"
#include "../metodos/Newton/NewtonPadrao/NewtonPadraoHorner.h"
#include "../metodos/Newton/NewtonFL/NewtonFLManual.h"
#include "../metodos/Newton/NewtonFL/NewtonFLHorner.h"
#include "../metodos/Newton/Polinomio.h"


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
            std::vector<double> lambda = {},
            int lambda_size = 0
        );

        void iterar_manual();
        void iterar_total(int limite);

        iteracao getIteracao(int indice);
        long long getTempo();
    private:
        Newton metodo;
        Polinomio polinomio;
        std::vector <iteracao> quadro;

        int num_interacao = 0;
        long long tempo;
        
};

#endif // QUADRORESPOSTA_H
