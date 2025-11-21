
#include <string>
#include <map>
#include <vector> 

struct interacao{
    // informações para ambos os métodos
    double raiz;
    double fRaiz;
    double erroEmX;
    double erroEmFx;
    bool possivelRompimento;

    // informações para o newtom com FL
    double fDerXw; 
};

typedef std::map <std::string, double> interacao2;

class QuadroResposta{
    public:
        QuadroResposta(std::string metodo);

        void adicionar(interacao inter);
        void adicionar2(interacao2 inter);

        interacao retornarInteracao(int indice);
    private:
        std::vector <interacao> quadro;
        std::vector <interacao2> quadro2;
};