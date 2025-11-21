#include "MainFrame.h"

#include "../Widgets/Gradient.h"
#include "../Widgets/Inputs/NumberEntry.h"
#include "../Widgets/Inputs/Button.h"

#include <iostream>

MainFrame::MainFrame()
    : scrollPanel({0, 0, 1080, 720})
{
    scrollPanel.append_child(new Gradient({0, 0, 2000, 2000}, PURPLE, PINK));
    for(float i = 1; i < 5; i++){
        scrollPanel.append_child(new NumberEntry({50, 50*i}));
        scrollPanel.append_child(new Button({300, 50*i, 75, 20}, "Botao", 
            []{
                std::cout << "Clicou" << std::endl;
            }
        ));
    }
}

void MainFrame::render(){
    scrollPanel.render();
}