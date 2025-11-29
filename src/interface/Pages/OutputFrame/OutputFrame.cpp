#include "OutputFrame.h"

#include "../../Widgets/Inputs/Button.h"

void OutputFrame::render(){
    Page::render();
}

OutputFrame::OutputFrame(Rectangle bounds_, ControlFlow* flow_)
    : Page(bounds_, flow_)
{
    Button* back = new Button({0, 0, 100, 50}, "Voltar",
        [this]{
            set_cur_frame(INPUTFRAME);
        });
    append_child(back);
}
