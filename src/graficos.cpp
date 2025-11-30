#include "../deps/include/raylib.h"
#include "../deps/include/raygui.h"
#include "../deps/include/rlgl.h"
#include "../deps/include/raymath.h"
#include "./metodos/Newton/Polinomio.h"
#include <cfloat>
#include <iostream>
#include <vector>

// Analogia com as posições possíveis para uma mola
typedef enum PosicaoEixo {
    COMPRESSAO,
    EQUILIBRIO,
    EXTENSAO
} PosicaoEixo;

int main() {
    int n;
    float xi, xf, maximo = FLT_MIN, minimo = FLT_MAX;
    float passo;
    std::cout << "CALCULADORA DE RAÍZES DE POLINÔMIOS\n\n";
    std::cout << "Informe o grau do polinômio: ";
    std::cin >> n;
    std::vector<double> graus(n+1);
    for (int i = 0; i < n; i++) {
        std::cout << "Informe o coeficiente x" << i << ": ";
        std::cin >> graus[i];
    }
    Polinomio polinomio(graus);
    std::cout << "Informe o começo (inclusivo) do intervalo em que "
    << "você deseja aplicar a função que você construiu: ";
    std::cin >> xi;

    std::cout << "Informe o final (inclusivo) do intervalo em que "
    << "você deseja aplicar a função que você construiu: ";
    std::cin >> xf;

    std::cout << "Informe o tamanho do passo "
    << "(distância horizontal entre um ponto do gráfico e o próximo): ";
    std::cin >> passo;

    if (xi > xf) std::swap(xi, xf);

    for (float x = xi; x <= xf; x += passo) {
        maximo = fmax(maximo, polinomio.valor_funcao(x));
        minimo = fmin(minimo, polinomio.valor_funcao(x));
    }

    std::cout << "Máximo: " << maximo << "\n";
    std::cout << "Mínimo: " << minimo << "\n";

    const int screenWidth = 700;
    const int screenHeight = 700;
    const float axisThickness = 5.0;
    Vector2 vxi = (Vector2){screenWidth * 0.1, 0};
    Vector2 vxf = (Vector2){screenWidth * 0.9, 0};
    Vector2 vyi = (Vector2){0, screenHeight * 0.1};
    Vector2 vyf = (Vector2){0, screenHeight * 0.9};
    PosicaoEixo posicaoEixoX, posicaoEixoY;
    double fatorPosicional[] = {0.1, 0.5, 0.9};

    // Determina posição dos eixos x e y na tela
    if (maximo * minimo > 0 && maximo < 0) {
        posicaoEixoX = COMPRESSAO;
    } else if (maximo * minimo > 0 && maximo > 0) {
        posicaoEixoX = EXTENSAO;
    } else {
        posicaoEixoX = EQUILIBRIO;
    }
    vxi.y = screenHeight * fatorPosicional[posicaoEixoX];
    vxf.y = screenHeight * fatorPosicional[posicaoEixoX];

    if (xf * xi > 0 && xf < 0) {
        posicaoEixoY = COMPRESSAO;
    } else if (xf * xi > 0 && xf > 0) {
        posicaoEixoY = EXTENSAO;
    } else posicaoEixoY = EQUILIBRIO;
    vyi.x = screenWidth * fatorPosicional[posicaoEixoY];
    vyf.x = screenWidth * fatorPosicional[posicaoEixoY];

    InitWindow(screenWidth, screenHeight, "Calculadora de Raízes de Polinômios");

    SetTargetFPS(10);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Desenho dos eixos
        DrawLineEx(vxi, vxf, axisThickness, BLACK);
        DrawLineEx(vyi, vyf, axisThickness, BLACK);

        // Desenho da função
        //for (float x = xi, xb)

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
