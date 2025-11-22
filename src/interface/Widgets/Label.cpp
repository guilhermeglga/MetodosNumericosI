#include "Label.h"

void Label::render(Vector2 scrollOffset){
    ScrollableFrame::render(scrollOffset);

    Rectangle offsetBounds = get_offset_bounds();

    GuiLabel(offsetBounds, text.c_str());
}

Label::Label(Rectangle bounds_)
    :ScrollableFrame(bounds_)
{
}
