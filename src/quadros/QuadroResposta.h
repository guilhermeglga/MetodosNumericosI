
#include <string>
#include <map>
#include <vector>
#include "../iteracao/iteracao.h"
#include "../metodos/Newton/Newton.h"
#include "../metodos/Newton/NewtonPadrao/NewtonPadraoManual.h";
#include "../metodos/Newton/NewtonPadrao/NewtonPadraoHorner.h";
#include "../metodos/Newton/NewtonFL/NewtonFLManual.h";
#include "../metodos/Newton/NewtonFL/NewtonFLHorner.h";
#include "../metodos/Newton/Polinomio.h"


enum NomeMetodo {
    NEWTON_PADRAO_DER_CALC,
    NEWTON_COM_FL_DER_CALC,
    NEWTON_PADRAO_DER_NCALC,
    NEWTON_COM_FL_DER_NCALC 
};

class QuadroResposta{
    public:
        QuadroResposta(NomeMetodo metodo, Polinomio p, std::vector<double> lambda);

        void iterar_manual();
        void iterar_total();

        iteracao getIteracao(int indice);
        double getTempo();
    private:
        std::vector <iteracao> quadro;
        Newton metodo;
        double tempo;
};


