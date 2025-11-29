
#include <string>
#include <map>
#include <vector>
#include "../iteracao/iteracao.h"

enum NomeMetodo {
    NEWTON_PADRAO_DER_CALC,
    NEWTON_COM_FL_DER_CALC,
    NEWTON_PADRAO_DER_NCALC,
    NEWTON_COM_FL_DER_NCALC
};

class QuadroResposta{
    public:
        QuadroResposta(NomeMetodo metodo);

        void iterar_manual();
        void iterar_total();

        iteracao getIteracao(int indice);
        double getTempo();
    private:
        std::vector <iteracao> quadro;
        // Metodo metodo;
        double tempo;
};
