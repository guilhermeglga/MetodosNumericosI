#include "MainFrame.h"

#include "../Widgets/Gradient.h"
#include "../Widgets/Inputs/NumberEntry.h"
#include "../Widgets/Inputs/Button.h"
#include "../Widgets/Label.h"
#include "../Widgets/Inputs/CheckBox.h"
#include "../Widgets/Tables/IterList.h"

#include <iostream>
#include <string>

MainFrame::MainFrame()
    : scrollPanel({0, 0, 1080, 720})
{
    scrollPanel.append_child(new Gradient({0, 0, 2000, 2000}, BLACK, WHITE));
    scrollPanel.append_child(new IterList({100, 100, 400, 400}));

    for(float i = 1; i <= 20; i++){
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
    }
}

void MainFrame::render(){
    scrollPanel.render();
}