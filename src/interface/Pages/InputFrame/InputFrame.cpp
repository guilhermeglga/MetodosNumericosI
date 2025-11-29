#include "InputFrame.h"

#include "../../Widgets/Inputs/Button.h"

void InputFrame::render(){
    Page::render();
}

InputFrame::InputFrame(Rectangle bounds_, ControlFlow* flow_)
    :Page(bounds_, flow_)
{
    Button* back = new Button({0, 300, 100, 50}, "Prosseguir",
        [this]{
            set_cur_frame(OUTPUTFRAME);
        });
    append_child(back);
}
