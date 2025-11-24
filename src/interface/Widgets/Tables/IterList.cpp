#include "IterList.h"

#include <iostream>

void IterList::render(Vector2 scrollOffset){
    ScrollableFrame::render(scrollOffset);

    Rectangle offsetBounds = get_offset_bounds();

//RAYGUIAPI int GuiGroupBox(Rectangle bounds, const char *text);                                         // Group Box control with text name
//RAYGUIAPI int GuiPanel(Rectangle bounds, const char *text);                                            // Panel control, useful to group controls
//RAYGUIAPI int GuiTabBar(Rectangle bounds, const char **text, int count, int *active);                  // Tab Bar control, returns TAB to be closed or -1

    if(GuiPanel(offsetBounds, "")){
        std::cout << "Test" << std::endl;
    }
}

IterList::IterList(Rectangle bounds_/*, QuadroResposta *board_*/)
    :ScrollableFrame(bounds_)
{
    //board = board_;

    QuadroResposta board_;
}
