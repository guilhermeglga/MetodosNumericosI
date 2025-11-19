#ifndef UI_SCROLLABLEFRAME_H
#define UI_SCROLLABLEFRAME_H

#include "Frame.h"

class ScrollableFrame : public Frame{
    public:
        virtual void render(Rectangle scrollOffset) = 0;

        ScrollableFrame(Rectangle bounds_)
        : Frame(bounds_) {}
    
    private:
        void render() override {}; // Deixando esse render inacessivel(não funcionou eu acho)
};

#endif // UI_SCROLLABLEFRAME_H