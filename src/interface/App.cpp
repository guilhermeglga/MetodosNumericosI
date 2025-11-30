#include "App.h"

void App::start(){
    InitWindow(width, height, "MN");
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        BeginDrawing();

            ClearBackground(RAYWHITE);

            main_frame.render();

        EndDrawing();
    }

    CloseWindow();
}

App::App(int width_, int height_, QuadroComparativo* quadro)
    : main_frame({0, 0, (float)width_, (float)height_}, &flow, quadro)
{
    width = width_;
    height = height_;
}
