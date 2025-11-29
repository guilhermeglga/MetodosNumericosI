#ifndef UI_MAINFRAME_H
#define UI_MAINFRAME_H

#include "../Widgets/ScrollPanel/ScrollPanel.h"

// Temp && Test
#include "../Widgets/Inputs/Button.h"

class MainFrame{
    public:
        void render();

        MainFrame();

    private:
        ScrollPanel scrollPanel;
        Button fixedButton;
};


#endif // UI_MAINFRAME_H