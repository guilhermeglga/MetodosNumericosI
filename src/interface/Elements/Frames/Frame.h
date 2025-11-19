#ifndef UI_FRAME_H
#define UI_FRAME_H

#include <raygui.h>

// Não acho que precise dessa classe
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