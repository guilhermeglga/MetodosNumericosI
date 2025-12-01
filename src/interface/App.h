#ifndef UI_APP_H
#define UI_APP_H

#include "./Pages/MainFrame/MainFrame.h"

// Classe Principal da UI(A main da UI basicamente)
class App{
    public:
        void start();

        App(int width_, int height_, vector<QuadroComparativo*>* quadro);

    private:
        int width, height;
        MainFrame main_frame;

        Font font;
        ControlFlow flow;
};

/* ToDo da UI:
    - Criar entradas:
        - Pra opção do Newton com ou sem FL
        - Pra derivada numérica ou feita na mão
        - Pras informações do polinômio:
            - Número de opções lambda
            - Coeficientes a3 e a2 pra cada lambda
            - Epsilon(pra cada lambda?)
    - Criar um elemento que mostre uma lista baseada nos quadros, depois:
        - Criar apresentação do quadro respostas
        - Criar apresentação do quadro comparativo

    - Padronizar a capitalização do nome das pastas
    - Falta programar um suporte decente pra Frames fixos, se precisar
    - Resolver como tudo isso vai ser apresentado
*/

#endif // UI_APP_H
