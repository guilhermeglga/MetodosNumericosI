#ifndef UI_FRAME_H
#define UI_FRAME_H

#include "../../../../deps/include/raylib.h"
#include "../../../../deps/include/raygui.h"

// Widget base
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
