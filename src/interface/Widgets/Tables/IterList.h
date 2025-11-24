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

    // Vou desconsiderar essas por enquanto
    //double derivadaDeFXw; 
    //bool possivelRompimento;
};
class QuadroResposta{
    public:
        QuadroResposta() {tempo = 0;}
        
        void adicionar(iteracao inter) { quadro.push_back(inter); };

        iteracao retornarInteracao(int indice){ return quadro.at(indice); };

        int tamanhoQuadro() { return quadro.size(); };
    private:
        vector <iteracao> quadro;
        double tempo;
};

#define UI_TABLE_CELL_HEIGHT 50
#define UI_TABLE_CELL_WIDTH 100

// Não existe uma função de tabela na raygui :(

// O tamanho disso aqui é dinâmico, ou seja, na inicialização só dá pra afirmar a origem
// Dito isso, ele devia herdar de outra coisa que não seja o scrollableFrame, mas isso já funciona

// Apenas o x e o y das bounds são levadas em consideração, width e height são dinâmicos
class IterList : public ScrollableFrame{
    public:
        void render(Vector2 scrollOffset) override;

        IterList(Rectangle bounds_, QuadroResposta* board_);

        // Se o quadro se manter como um ponteiro, ver se a classe vai tratar de deletar ele
        ~IterList(){};

        // Não basta dar update no quadro, pras mudanças aparecerem na tela precisa chamar essa função
        void updateBoard();


    private:
        // Assumindo por enquanto que essa classe já vai ser criada com um quadro definido
        // Se for necessário mudar a instancia de quadro, vou ter que mudar depois
        QuadroResposta* board;

        void drawCell(Vector2 pos, string text);
        void drawHeaders(Rectangle offsetBounds);

};

#endif // UI_ITERLIST_H