#ifndef UI_CHECKBOX_H
#define UI_CHECKBOX_H

#include "../Frames/ScrollableFrame.h"
#include <string>

using namespace std;

class CheckBox : public ScrollableFrame{
    public:
        void render(Vector2 scrollOffset) override;

        CheckBox(Rectangle bounds_, string label_);

        bool get_state();
    private:
        string label;
        bool state;
};

#endif // UI_CHECKBOX_H