#ifndef UI_FRAME_H
#define UI_FRAME_H

#include <raylib.h>
#include <raygui.h>

class Frame{
    public:
        virtual void render() = 0;
        
        Frame(Rectangle bounds_);

        Rectangle get_bounds();

        virtual ~Frame() {};

    protected:
        Rectangle bounds;
};

#endif // UI_FRAME_H