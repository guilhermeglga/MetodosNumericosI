#include "Gradient.h"

void Gradient::render(Rectangle scrollOffset){
    DrawRectangleGradientEx(
        {
            bounds.x + scrollOffset.x, 
            bounds.y + scrollOffset.y, 
            bounds.width + scrollOffset.width, 
            bounds.height + scrollOffset.height
        }, 
        
        color1, color1, color2, color2
    );
}

Gradient::Gradient(Rectangle bounds_, Color color1_, Color color2_)
    : ScrollableFrame(bounds_)
{
    color1 = color1_;
    color2 = color2_;
}
