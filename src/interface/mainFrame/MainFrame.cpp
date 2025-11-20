#include "MainFrame.h"

#include "../Elements/Gradient.h" // Esse include podia tá no .h mas eu só tou usando o gradient na definição

MainFrame::MainFrame()
    : scrollPanel({0, 0, 1080, 720}, new Gradient({0, 0, 2000, 2000}, PURPLE, PINK)){}

void MainFrame::render(){
    scrollPanel.render();
}