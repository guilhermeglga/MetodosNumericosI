#include "grafico.h"

void Grafico::render(Vector2 scrollOffset){
    ScrollableFrame::render(scrollOffset);

    Rectangle offsetBounds = get_offset_bounds();

    vxi = {vxi.x + offsetBounds.x, vxi.y + offsetBounds.y};
    vyi = {vyi.x + offsetBounds.x, vyi.y + offsetBounds.y};
    vxf = {vxf.x + offsetBounds.x, vxf.y + offsetBounds.y};
    vyf = {vyf.x + offsetBounds.x, vyf.y + offsetBounds.y};

    // Desenho dos eixos
    /// Retas
    DrawLineEx(vxi, vxf, axisThickness, BLACK);
    DrawLineEx(vyi, vyf, axisThickness, BLACK);

    /// Pontas das setas
    DrawLineEx(vxi + Vector2{0, 1.0}, vxi + Vector2{20.0, -20.0}, 5.0, BLACK);
    DrawLineEx(vxi + Vector2{0, -1.0}, vxi + Vector2{20.0, 20.0}, 5.0, BLACK);

    DrawLineEx(vxf + Vector2{0, 1.0}, vxf + Vector2{-20.0, -20.0}, 5.0, BLACK);
    DrawLineEx(vxf + Vector2{0, -1.0}, vxf + Vector2{-20.0, 20.0}, 5.0, BLACK);

    DrawLineEx(vyi + Vector2{1.0, 0}, vyi + Vector2{-20.0, 20.0}, 5.0, BLACK);
    DrawLineEx(vyi + Vector2{-1.0, 0}, vyi + Vector2{20.0, 20.0}, 5.0, BLACK);

    DrawLineEx(vyf + Vector2{1.0, 0}, vyf + Vector2{-20.0, -20.0}, 5.0, BLACK);
    DrawLineEx(vyf + Vector2{-1.0, 0}, vyf + Vector2{20.0, -20.0}, 5.0, BLACK);


    /// Traços com os valores de X
    for (float i = 1; i <= numTracos; i++) {
        if (posicaoEixoY == COMPRESSAO && i == 1) continue;
        if (posicaoEixoY == EXTENSAO && i == numTracos) continue;
        DrawLineEx(vxi + Vector2{distTracosX * i, -10.f}, vxi + Vector2{distTracosX * i, 10.0f},
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
        Vector2{vxi.x + distTracosX, vxi.y + deslocX},
        Vector2{0, 0},
        90.0f,
        10.0f,
        1.0f,
        BLACK);

    valX = std::to_string(xi + passoX * (numTracos - 1.0f));
    DrawTextPro(GetFontDefault(),
        valX.c_str(),
        Vector2{vxi.x + distTracosX * numTracos, vxi.y + deslocX},
        Vector2{0, 0},
        90.0f,
        10.0f,
        1.0f,
        BLACK);

    /// Traços com os valores de Y
    for (float i = 1; i <= numTracos; i++) {
        if (posicaoEixoX == COMPRESSAO && i == 1) continue;
        if (posicaoEixoX == EXTENSAO && i == numTracos) continue;
        DrawLineEx(vyi + Vector2{-10.f, distTracosX * i}, vyi + Vector2{10.0f,distTracosX * i},
            2.0, BLACK);
    }

    std::string valY = std::to_string(polinomio->valor_funcao(xi));
    DrawText(valY.c_str(), vyi.x + deslocY, vyi.y + distTracosY * numTracos, 5.0f, BLACK);

    valY = std::to_string(polinomio->valor_funcao(xi + passoX * (numTracos - 1.0f)));
    DrawText(valY.c_str(), vyi.x + deslocY, vyi.y + distTracosY, 5.0f, BLACK);

    // Desenho da função
    //for (float x = xi, xb)
}

Grafico::Grafico(Rectangle bounds_, Polinomio pol_, double xi_)
    :ScrollableFrame({bounds_.x, bounds_.y, 700, 700})
{
    polinomio = &pol_;
    double yMaximo = DBL_MIN, yMinimo = DBL_MAX, xf;
    numTracos = 15.0f;

    xi = xi_;
    xf = -xi;

    if (xi > xf) std::swap(xi, xf);

    passoX = (xf - xi) / (numTracos - 1.0f);

    for (float x = xi; x <= xf; x += passoX) {
        yMaximo = fmax(yMaximo, polinomio->valor_funcao(x));
        yMinimo = fmin(yMinimo, polinomio->valor_funcao(x));
    }

    //int px0 = 0;
    //int py0 = 0;
    //int frameWidth = bounds.width;
    //int frameHeight = bounds.height;
    int screenWidth = bounds.width;
    int screenHeight = bounds.height;

    axisThickness = 5.0;

    vxi = Vector2{screenWidth * 0.1f, 0};
    vxf = Vector2{screenWidth * 0.9f, 0};
    vyi = Vector2{0, screenHeight * 0.1f};
    vyf = Vector2{0, screenHeight * 0.9f};
    
    float fatorPosicional[] = {0.2, 0.5, 0.8};
    float axisWidth, axisHeight;

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
}
