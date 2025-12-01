#include "MainFrame.h"

#include "../../Widgets/Tables/IterList.h"
#include "../../Widgets/grafico/grafico.h"

MainFrame::MainFrame(Rectangle bounds_, ControlFlow* flow_, vector<QuadroComparativo*>* quadros_, Font* font_)
    : Page(bounds_, flow_)
{
    /*float total_height = 0;
    for(size_t i = 0; i < quadros_->size(); i++){
        IterList* list = new IterList({0, total_height, 0, 0}, quadros_->at(i), font_, "Tabela" + to_string(i));
        total_height += list->get_bounds().height;
        append_child(list);
    }*/
    append_child(new Grafico({0, 0, 700, 700}, {{-1, 2, 3}}, 10));
}

void MainFrame::render(){
    Page::render();
}