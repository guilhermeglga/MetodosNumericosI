#include "AutoInput.h"

void AutoInput::render(){
    Page::render();
}

AutoInput::AutoInput(Rectangle bounds_, ControlFlow *flow_)
    :Page(bounds_, flow_){}