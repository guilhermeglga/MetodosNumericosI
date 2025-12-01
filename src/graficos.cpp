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
    double xi, xf, yMaximo = DBL_MIN, yMinimo = DBL_MAX;
    float passoX;
    float numTracos = 15.0f;
    std::vector<double> graus;

    std::cout << "CALCULADORA DE RAÍZES DE POLINÔMIOS\n\n";
    std::cout << "Informe o grau do polinômio: ";
    std::cin >> n;

    graus.resize(n+1);
    for (int i = 0; i <= n; i++) {
        std::cout << "Informe o coeficiente x" << i << ": ";
        std::cin >> graus[i];
    }

    Polinomio polinomio(graus);

    //std::cout << "Informe o começo (inclusivo) do intervalo em que "
    //<< "você deseja aplicar a função que você construiu: ";
    //std::cin >> xi;

    //std::cout << "Informe o final (inclusivo) do intervalo em que "
    //<< "você deseja aplicar a função que você construiu: ";
    //std::cin >> xf;

    std::cout << "Informe o raio, partindo do zero, do intervalo em que "
    << "você deseja aplicar a função que você construiu: ";
    std::cin >> xi;
    xf = -xi;

    if (xi > xf) std::swap(xi, xf);

    passoX = (xf - xi) / (numTracos - 1.0f);

    for (float x = xi; x <= xf; x += passoX) {
        yMaximo = fmax(yMaximo, polinomio.valor_funcao(x));
        yMinimo = fmin(yMinimo, polinomio.valor_funcao(x));
    }

    std::cout << "Máximo: " << yMaximo << "\n";
    std::cout << "Mínimo: " << yMinimo << "\n";

    const int px0 = 0;
    const int py0 = 0;
    const int frameWidth = 700;
    const int frameHeight = 700;
    const int screenWidth = 700;
    const int screenHeight = 700;
    const float axisThickness = 5.0;
    Vector2 vxi = (Vector2){screenWidth * 0.1, 0};
    Vector2 vxf = (Vector2){screenWidth * 0.9, 0};
    Vector2 vyi = (Vector2){0, screenHeight * 0.1};
    Vector2 vyf = (Vector2){0, screenHeight * 0.9};
    PosicaoEixo posicaoEixoX, posicaoEixoY;
    float fatorPosicional[] = {0.2, 0.5, 0.8};
    float axisWidth, axisHeight, distTracosX, distTracosY;

    // Determina posição dos eixos x e y na tela
    if (yMaximo * yMinimo > 0 && yMaximo < 0) {
        posicaoEixoX = COMPRESSAO;
    } else if (yMaximo * yMinimo > 0 && yMaximo > 0) {
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

    axisWidth = vxf.x - vxi.x;
    axisHeight = vyf.y - vyi.y;
    distTracosX = axisWidth / (numTracos + 1.0f);
    distTracosY = axisHeight / (numTracos + 1.0f);

    InitWindow(screenWidth, screenHeight, "Calculadora de Raízes de Polinômios");

    SetTargetFPS(10);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Desenho dos eixos
        /// Retas
        DrawLineEx(vxi, vxf, axisThickness, BLACK);
        DrawLineEx(vyi, vyf, axisThickness, BLACK);

        /// Pontas das setas
        DrawLineEx(vxi + (Vector2){0, 1.0}, vxi + (Vector2){20.0, -20.0}, 5.0, BLACK);
        DrawLineEx(vxi + (Vector2){0, -1.0}, vxi + (Vector2){20.0, 20.0}, 5.0, BLACK);

        DrawLineEx(vxf + (Vector2){0, 1.0}, vxf + (Vector2){-20.0, -20.0}, 5.0, BLACK);
        DrawLineEx(vxf + (Vector2){0, -1.0}, vxf + (Vector2){-20.0, 20.0}, 5.0, BLACK);

        DrawLineEx(vyi + (Vector2){1.0, 0}, vyi + (Vector2){-20.0, 20.0}, 5.0, BLACK);
        DrawLineEx(vyi + (Vector2){-1.0, 0}, vyi + (Vector2){20.0, 20.0}, 5.0, BLACK);

        DrawLineEx(vyf + (Vector2){1.0, 0}, vyf + (Vector2){-20.0, -20.0}, 5.0, BLACK);
        DrawLineEx(vyf + (Vector2){-1.0, 0}, vyf + (Vector2){20.0, -20.0}, 5.0, BLACK);


        /// Traços com os valores de X
        for (float i = 1; i <= numTracos; i++) {
            if (posicaoEixoY == COMPRESSAO && i == 1) continue;
            if (posicaoEixoY == EXTENSAO && i == numTracos) continue;
            DrawLineEx(vxi + (Vector2){distTracosX * i, -10.f}, vxi + (Vector2){distTracosX * i, 10.0f},
                2.0, BLACK);

        }

        float deslocX, deslocY;
        if (posicaoEixoX == COMPRESSAO) {
            deslocX = -20.0f;
        } else deslocX = 20.0f;
        if (posicaoEixoX == COMPRESSAO) {
            deslocY = -20.0f;
        } else deslocY = 20.0f;

        std::string valX = std::to_string(xi);
        DrawTextPro(GetFontDefault(),
            valX.c_str(),
            (Vector2){vxi.x + distTracosX, vxi.y + deslocX},
            (Vector2){0, 0},
            90.0f,
            10.0f,
            1.0f,
            BLACK);

        valX = std::to_string(xi + passoX * (numTracos - 1.0f));
        DrawTextPro(GetFontDefault(),
            valX.c_str(),
            (Vector2){vxi.x + distTracosX * numTracos, vxi.y + deslocX},
            (Vector2){0, 0},
            90.0f,
            10.0f,
            1.0f,
            BLACK);

        /// Traços com os valores de Y
        for (float i = 1; i <= numTracos; i++) {
            if (posicaoEixoX == COMPRESSAO && i == 1) continue;
            if (posicaoEixoX == EXTENSAO && i == numTracos) continue;
            DrawLineEx(vyi + (Vector2){-10.f, distTracosX * i}, vyi + (Vector2){10.0f,distTracosX * i},
                2.0, BLACK);
        }

        std::string valY = std::to_string(polinomio.valor_funcao(xi));
        DrawText(valY.c_str(), vyi.x + deslocY, vyi.y + distTracosY * numTracos, 5.0f, BLACK);

        valY = std::to_string(polinomio.valor_funcao(xi + passoX * (numTracos - 1.0f)));
        DrawText(valY.c_str(), vyi.x + deslocY, vyi.y + distTracosY, 5.0f, BLACK);

        // Desenho da função
        //for (float x = xi, xb)

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
