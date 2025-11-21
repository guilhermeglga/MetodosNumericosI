#include "Button.h"

void Button::render(Vector2 scrollOffset){
    ScrollableFrame::render(scrollOffset);

    Rectangle offsetBounds = get_offset_bounds();
    
    if(GuiButton(offsetBounds, title)){
        callback();
    }
}

Button::Button(Rectangle bounds_, char* title_, function<void()> callback_)
    :ScrollableFrame(bounds_) 
{
    title = title_;
    callback = callback_;
}
