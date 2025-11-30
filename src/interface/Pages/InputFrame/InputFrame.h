#ifndef UI_INPUTFRAME_H
#define UI_INPUTFRAME_H

#include "../Page/Page.h"
#include "AutoInput/AutoInput.h"
#include "IterInput/IterInput.h"

/*
    Primeira escolha: modo iterativo ou automatico

    iterativo -> cria um quadro resposta, recebe:
        n: numero de opções de lambda e coeficientes
        vetor de coeficientes pra cada n
        lambda pra cada n
        escolha entre um dos quatro métodos
        epsilon
    no fim dá output em uma tabela IterList pra cada n.

    automático -> cria um quadro comparativo, recebe:
        escolha do metodo1
        escolha do metodo2
        vetor de coeficientes
        epsilon
        lambda
    no fim dá output numa comparação entre os dois, acho que vai ser um widget novo
*/

class InputFrame : public Page{
    public:
        void render() override;
        InputFrame(Rectangle bounds_, ControlFlow* flow_);

    private:
        ControlFlow input_flow;

        AutoInput auto_input;
        IterInput iter_input;

        // Uma struct com os inputs? ou o próprio quadro comparativo consegue manter os inputs?
        // Os inputs de fato(não sei quais e quantos ainda)
        // Botão de prosseguir[Não precisa ser atributo da classe]
};

#endif // UI_INPUTFRAME_H