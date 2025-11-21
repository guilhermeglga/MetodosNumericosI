#ifndef UI_MAINFRAME_H
#define UI_MAINFRAME_H

#include "../Widgets/ScrollPanel/ScrollPanel.h"

class MainFrame{
    public:
        void render();

        MainFrame();

    private:
        ScrollPanel scrollPanel;
};


#endif // UI_MAINFRAME_H