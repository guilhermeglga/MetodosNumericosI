#include "InputFrame.h"

#include "../../Widgets/Inputs/Button.h"
#include "../../Widgets/Inputs/NumberEntry.h"

void InputFrame::render(){
    Page::render();

    // Botão selecionar iter ou auto
    // Renderizar página certa de acordo com o flow
    // Botão Submit

    iter_input.render();
}

InputFrame::InputFrame(Rectangle bounds_, ControlFlow* flow_)
    :Page(bounds_, flow_),
    auto_input(bounds_, &input_flow),
    iter_input(bounds_, &input_flow) {}
