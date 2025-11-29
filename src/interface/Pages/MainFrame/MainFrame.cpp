#include "MainFrame.h"

/*#include "../Widgets/Gradient.h"
#include "../Widgets/Inputs/NumberEntry.h"
#include "../Widgets/Inputs/Button.h"
#include "../Widgets/Label.h"
#include "../Widgets/Inputs/CheckBox.h"
#include "../Widgets/Tables/IterList.h"

#include <string>*/

MainFrame::MainFrame(Rectangle bounds_, ControlFlow* flow_)
    : Page(bounds_, flow_),
    in_frame(bounds_, flow_),
    out_frame(bounds_, flow_)
{
    /*
    // Quadro temporario, só pra testar
    iteracao iter1;
    iteracao iter2;
    iteracao iter3;

    iter1.raiz = 2.0f;
    iter2.raiz = 2.352f;
    iter3.raiz = 2.4024f;

    iter1.funcaoNaRaiz = iter1.raiz*2;
    iter2.funcaoNaRaiz = iter2.raiz*2;
    iter3.funcaoNaRaiz = iter3.raiz*2;

    iter1.erroEmX = 23.055f;
    iter2.erroEmX = 3.521f;
    iter3.erroEmX = 0.155f;

    iter1.erroEmFX = 1.525f;
    iter2.erroEmFX = 0.752f;
    iter3.erroEmFX = 0.091f;

    iter1.parada = false;
    iter2.parada = false;
    iter3.parada = true;

    QuadroResposta* board_ = new QuadroResposta();
    board_->adicionar(iter1);
    board_->adicionar(iter2);

    IterList* iterList = new IterList({50, 100, 0, 0}, board_);
    
    scrollPanel.append_child(new Gradient({0, 0, 2000, 2000}, BLACK, WHITE));
    scrollPanel.append_child(iterList);

    ScrollPanel* scrollWrapper = &scrollPanel;
    fixedButton = Button({0, 0, 200, 50}, "Adicionar",
        [board_, iter3, iterList, scrollWrapper]{
            board_->adicionar(iter3);
            iterList->updateBoard();
            scrollWrapper->update_content_rec();
        }
    );

    for(float i = 1; i <= 20; i++){ // Teste de inputs
        scrollPanel.append_child(new NumberEntry({50, 50*i}));

        scrollPanel.append_child(new Button({300, 50*i, 75, 20}, "Botao", 
            []{
                std::cout << "Clicou" << std::endl;
            }
        ));

        Label* label = new Label({400, 50*i, 100, 32});
        label->text = "Label";
        label->text.append(std::to_string((int)i));
        scrollPanel.append_child(label);

        string checkLabel = "Check";
        checkLabel.append(std::to_string((int)i));
        scrollPanel.append_child(new CheckBox({500, 50*i, 32, 32}, checkLabel));
    }*/ 
}

void MainFrame::render(){
    //Page::render(); // Not needed here because we dont add anything to MainFrame's scrollPanel;
    if(get_cur_frame() == INPUTFRAME) in_frame.render();
    else out_frame.render();
}