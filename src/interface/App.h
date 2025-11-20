#ifndef UI_APP_H
#define UI_APP_H

#include "./Window/Window.h"
#include "./MainFrame/MainFrame.h"

// Classe Principal da UI(A main da UI basicamente)
class App{
    public:
        void start();

        App(int width_, int height_);

    private:
        Window window;
        MainFrame main_frame;
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

    - Resolver como tudo isso vai ser apresentado
*/

#endif // UI_APP_H