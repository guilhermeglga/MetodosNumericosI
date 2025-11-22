#include "CheckBox.h"

#include <iostream>

void CheckBox::render(Vector2 scrollOffset){
    ScrollableFrame::render(scrollOffset);

    Rectangle offsetBounds = get_offset_bounds();

    GuiCheckBox(offsetBounds, label.c_str(), &state);
}

CheckBox::CheckBox(Rectangle bounds_, string label_)
    :ScrollableFrame(bounds_) 
{
    label = label_;
    state = true;    
}

bool CheckBox::get_state()
{
    return state;
}
