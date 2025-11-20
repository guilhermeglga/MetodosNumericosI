#ifndef UI_SCROLLABLEFRAME_H
#define UI_SCROLLABLEFRAME_H

#include "Frame.h"

class ScrollableFrame : public Frame{
    public:
        virtual void render(Vector2 scrollOffset) {
            offsetBounds = {
                bounds.x + scrollOffset.x,
                bounds.y + scrollOffset.y,
                bounds.width,
                bounds.height
            };
        }

        ScrollableFrame(Rectangle bounds_)
        : Frame(bounds_)
        {
            offsetBounds = { bounds_.x, bounds.y, bounds.width, bounds.height };
        }

        Rectangle get_offset_bounds(){ return offsetBounds; }
    
    private:
        void render() override {}; // Deixando esse render inacessivel(não funcionou eu acho)

        Rectangle offsetBounds; // Parte da visualização que fica variando
};

#endif // UI_SCROLLABLEFRAME_H