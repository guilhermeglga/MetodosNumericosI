#ifndef UI_APP_H
#define UI_APP_H

#include <raylib.h>

#include "./window/Window.h"
#include "./mainFrame/MainFrame.h"

class App{
    public:
        void start();

        App(int width_, int height_);

    private:
        Window window;
        MainFrame main_frame;
};

#endif // UI_APP_H