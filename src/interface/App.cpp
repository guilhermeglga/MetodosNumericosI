#include "app.h"

void App::start(){
    InitWindow(window.get_width(), window.get_height(), "MN");
    
    while(!WindowShouldClose()){
        BeginDrawing();
        
            ClearBackground(RAYWHITE);

            main_frame.render();

        EndDrawing();
    }

    CloseWindow();
}

App::App(int width_, int height_)
: window(width_, height_) {}
