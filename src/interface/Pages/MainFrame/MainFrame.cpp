#include "MainFrame.h"

/*#include "../Widgets/Gradient.h"
#include "../Widgets/Inputs/NumberEntry.h"
#include "../Widgets/Inputs/Button.h"
#include "../Widgets/Label.h"
#include "../Widgets/Inputs/CheckBox.h"
#include "../Widgets/Tables/IterList.h"

#include <string>*/

#include "../../Widgets/Tables/IterList.h"

MainFrame::MainFrame(Rectangle bounds_, ControlFlow* flow_, QuadroComparativo* quadro)
    : Page(bounds_, flow_)
{
    append_child(new IterList({0, 0, 0, 0}, quadro));
}

void MainFrame::render(){
    Page::render();
}