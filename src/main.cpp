#define RAYGUI_IMPLEMENTATION
#include "./interface/App.h"

int main(){
    //Quadro temporario, só pra testar
    QuadroComparativo* board = new QuadroComparativo({1.0, 0, -9.0, 3.0}, 0.001, 0.05, 10);

    App app(1080, 720, board);

    app.start();

    return 0;
}