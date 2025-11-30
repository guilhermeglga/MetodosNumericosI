#include "App.h"

void App::start(){
    InitWindow(width, height, "MN");
    SetTargetFPS(60);

    //ToDo: padronizar caminhos de resources
    font = LoadFont("../deps/Roboto-Regular.ttf");

    while(!WindowShouldClose()){
        BeginDrawing();

            ClearBackground(RAYWHITE);

            main_frame.render();

        EndDrawing();
    }

    UnloadFont(font);

    CloseWindow();
}


#include <iostream>
App::App(int width_, int height_, vector<QuadroComparativo*>* quadro)
    : main_frame({0, 0, (float)width_, (float)height_}, &flow, quadro, &font)
{
    width = width_;
    height = height_;
}
