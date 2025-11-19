#ifndef UI_APP_H
#define UI_APP_H

#include <raylib.h>

#include "./Window/Window.h"
#include "./MainFrame/MainFrame.h"

// Classe Principal da UI(A main da UI basicamente)
class App{
    public:
        void start();

        App(int width_, int height_);

    private:
        Window window;
        MainFrame main_frame;
};

#endif // UI_APP_H