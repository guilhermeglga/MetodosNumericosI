#ifndef UI_ITERLIST_H
#define UI_ITERLIST_H

#include "../Frames/ScrollableFrame.h"

#include <string>
#include <vector>

using namespace std;

// Copiei temporariamente as definições do quadro pra cá, só pra já definir o widget
struct iteracao{
    double raiz;
    double funcaoNaRaiz;
    double erroEmX;
    double erroEmFX;
    bool parada;

    double derivadaDeFXw; 
    bool possivelRompimento;
};
class QuadroResposta{
    public:
        QuadroResposta() {tempo = 0;}
        
        void adicionar(iteracao inter);

        iteracao retornarInteracao(int indice);
    private:
        vector <iteracao> quadro;
        double tempo;
};

class IterList : public ScrollableFrame{
    public:
        void render(Vector2 scrollOffset) override;

        IterList(Rectangle bounds_/*, QuadroResposta* board_*/);

        // Se o quadro se manter como um ponteiro, ver se a classe vai tratar de deletar ele
        ~IterList(){};

    private:
        // Assumindo por enquanto que essa classe já vai ser criada com um quadro definido
        // Se for necessário mudar a instancia de quadro, vou ter que mudar depois
        QuadroResposta* board;

};

#endif // UI_ITERLIST_H