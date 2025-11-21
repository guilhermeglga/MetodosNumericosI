#ifndef UI_BUTTON_H
#define UI_BUTTON_H

#include "../Frames/ScrollableFrame.h"

#include <functional>

using namespace std;

class Button : public ScrollableFrame{
    public:
        void render(Vector2 scrollOffset);

        Button(Rectangle bounds_, char* title_, function<void()> callback_);

    private:
        char* title;
        function<void()> callback;
};

#endif // UI_BUTTON_H