#ifndef UI_GRAFICO_H
#define UI_GRAFICO_H

#include "../../../metodos/Newton/Polinomio.h"
#include "../Frames/ScrollableFrame.h"
#include <string>
#include <cfloat>

typedef enum PosicaoEixo {
    COMPRESSAO,
    EQUILIBRIO,
    EXTENSAO
} PosicaoEixo;

class Grafico : public ScrollableFrame{
    public:
        void render(Vector2 scrollOffset) override;
        
        // width e height fixos
        Grafico(Rectangle bounds_, Polinomio pol_, double xi_);

    private:
        Polinomio* polinomio;

        Vector2 vxi, vyi, vxf, vyf;
        double xi;
        float passoX;
        float axisThickness;
        float numTracos;

        PosicaoEixo posicaoEixoY, posicaoEixoX;
        float distTracosX, distTracosY;
};

#endif // UI_GRAFICO_H