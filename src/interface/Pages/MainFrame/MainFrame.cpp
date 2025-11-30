#include "MainFrame.h"

/*#include "../Widgets/Gradient.h"
#include "../Widgets/Inputs/NumberEntry.h"
#include "../Widgets/Inputs/Button.h"
#include "../Widgets/Label.h"
#include "../Widgets/Inputs/CheckBox.h"
#include "../Widgets/Tables/IterList.h"

#include <string>*/

#include "../../Widgets/Tables/IterList.h"

MainFrame::MainFrame(Rectangle bounds_, ControlFlow* flow_, vector<QuadroComparativo*>* quadros_, Font* font_)
    : Page(bounds_, flow_)
{
    float total_height = 0;
    for(size_t i = 0; i < quadros_->size(); i++){
        IterList* list = new IterList({0, total_height, 0, 0}, quadros_->at(i), font_, "Tabela" + to_string(i));
        total_height += list->get_bounds().height;
        append_child(list);
    }
}

void MainFrame::render(){
    Page::render();
}