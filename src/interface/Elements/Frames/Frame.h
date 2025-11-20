#ifndef UI_FRAME_H
#define UI_FRAME_H

// Idealmente esse é o único arquivo que inclui a raylib e a raygui

#include <raylib.h>
#include <raygui.h>

class Frame{
    public:
        virtual void render() = 0;
        
        Frame(Rectangle bounds_){ bounds = bounds_; };

        Rectangle get_bounds() { return bounds; };

        virtual ~Frame() {};
    private:

    protected:
        Rectangle bounds;
};

#endif // UI_FRAME_H