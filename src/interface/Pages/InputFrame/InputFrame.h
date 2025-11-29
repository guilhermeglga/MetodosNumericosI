#ifndef UI_INPUTFRAME_H
#define UI_INPUTFRAME_H

#include "../Page/Page.h"

class InputFrame : public Page{
    public:
        void render() override;
        InputFrame(Rectangle bounds_, ControlFlow* flow_);

    private:
        // Uma struct com os inputs? ou o próprio quadro comparativo consegue manter os inputs?
        // Os inputs de fato(não sei quais e quantos ainda)
        // Botão de prosseguir[Não precisa ser atributo da classe]
};

#endif // UI_INPUTFRAME_H