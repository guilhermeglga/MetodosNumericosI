#ifndef UI_OUTPUTFRAME_H
#define UI_OUTPUTFRAME_H

// Dumb name i know
#include "../Page/Page.h"

class OutputFrame : public Page{
    public:
        void render() override;
        OutputFrame(Rectangle bounds_, ControlFlow* flow_);

    private:
        // Quadro comparativo aqui provavelmente
            // Incluindo o botão de iteração manual
        // Visualização da função se tiver pronta
        // Botão para voltar pra tela de inputs[Não precisa ser atributo da classe]
        // Acho que só esses três
};

#endif // UI_OUTPUTFRAME_H