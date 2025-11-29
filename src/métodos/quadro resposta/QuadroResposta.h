#include <string>
#include <map>
#include <vector>


// ToDo: passar para um arquivo proprio
struct iteracao{
    // informações para ambos os métodos
    double raiz;
    double funcaoNaRaiz;
    double erroEmX;
    double erroEmFX;
    bool parada;

    // informações para o newtom com FL
    double derivadaDeFXw;
    bool possivelRompimento;
};



class QuadroResposta{
    public:
    // ToDo: enum para qual metodo
    QuadroResposta(std::string metodo);

    // ToDo: alterar para pegar informação do metodo direto
    void adicionar(iteracao inter);

    // ToDo: metodos complementares de retorno
    iteracao retornarInteracao(int indice);
    private:
    std::vector <iteracao> quadro;
    // Metodo metodo;
    double tempo;
};
