#include "MainFrame.h"

#include "../Elements/Gradient.h" // Esse include podia tá no .h mas eu só tou usando o gradient na definição

MainFrame::MainFrame()
    : scrollPanel({0, 0, 1080, 720}, "Teste", new Gradient({0, 0, 3000, 3000}, BLACK, PURPLE)){}

void MainFrame::render(){
    scrollPanel.render();
}