#include "IterList.h"

#define UI_PRECISION_NUMBERS 12

void IterList::render(Vector2 scrollOffset){
    AnimatedFrame::render(scrollOffset);

    Rectangle offsetBounds = get_offset_bounds();
    //int animFrames = getAnimFrames();

    drawHeaders(offsetBounds);

    for(int q = 0; q < 4; q++){
        int tamanhoQuadro = resps[q]->getTamanho();
        for(int i = 0; i < tamanhoQuadro; i++){
            iteracao iter = resps[q]->getIteracao(i);
            float x = (i+1)*UI_TABLE_CELL_WIDTH;
            float y = q*6*UI_TABLE_CELL_HEIGHT;

            /*if(i == tamanhoQuadro-1 && animFrames > 0){
                y = y - animFrames*2;
            }*/
            unsigned char val = (unsigned char)(100 + q*(155/4));
            Color cellColor = {val, val, val, 255};

            string s;

            ostringstream raizStream;
            raizStream << fixed << setprecision(UI_PRECISION_NUMBERS) << iter.raiz;
            s = raizStream.str();
            drawCell({offsetBounds.x + x, offsetBounds.y + y + 1*UI_TABLE_CELL_HEIGHT}, s, cellColor);

            ostringstream fxStream;
            fxStream << fixed << setprecision(UI_PRECISION_NUMBERS) << iter.funcaoNaRaiz;
            s = fxStream.str();
            drawCell({offsetBounds.x + x, offsetBounds.y + y + 2*UI_TABLE_CELL_HEIGHT}, s, cellColor);

            ostringstream errxStream;
            errxStream << fixed << setprecision(UI_PRECISION_NUMBERS) << iter.erroEmX;
            s = errxStream.str();
            drawCell({offsetBounds.x + x, offsetBounds.y + y + 3*UI_TABLE_CELL_HEIGHT}, s, cellColor);

            ostringstream errfxStream;
            errfxStream << fixed << setprecision(UI_PRECISION_NUMBERS) << iter.erroEmFX;
            s = errfxStream.str();
            drawCell({offsetBounds.x + x, offsetBounds.y + y + 4*UI_TABLE_CELL_HEIGHT}, s, cellColor);
            
            s = iter.parada?"SIM":"NÃO";
            drawCell({offsetBounds.x + x, offsetBounds.y + y + 5*UI_TABLE_CELL_HEIGHT}, s, cellColor);

            s = iter.possivelRompimento?"SIM":"NÃO";
            drawCell({offsetBounds.x + x, offsetBounds.y + y + 6*UI_TABLE_CELL_HEIGHT}, s, cellColor);
        }
    }
}

IterList::IterList(Rectangle bounds_, QuadroComparativo* board_)
    :AnimatedFrame(bounds_)
{
    board = board_;
    resps[0] = &board_->QPadrao_M;
    resps[1] = &board_->QFL_M;
    resps[2] = &board_->QPadrao_H;
    resps[3] = &board_->QFL_H;

    bounds.height = 25*UI_TABLE_CELL_HEIGHT; // (5 propriedades)*4 tabelas + 1 celula vazia
    bounds.width = (board_->tam_max() + 1)*UI_TABLE_CELL_WIDTH; // tamanho do quadro + 1 celula vazia
}

void IterList::updateBoard(){
    //float newHeight = 6*UI_TABLE_CELL_HEIGHT; // Não dá pra adicionar propriedades
    //float newWidth = (board->tamanhoQuadro() + 1)*UI_TABLE_CELL_WIDTH; // tamanho do quadro + 1 celula vazia
    //if(newWidth <= bounds.width) return;

    //bounds.width = newWidth;
    //startAnim(15);
}

void IterList::drawCell(Vector2 pos, string text, Color color){
    DrawRectangleRec({pos.x, pos.y, UI_TABLE_CELL_WIDTH, UI_TABLE_CELL_HEIGHT}, color);
    DrawRectangleLinesEx({pos.x, pos.y, UI_TABLE_CELL_WIDTH, UI_TABLE_CELL_HEIGHT}, 2, BLACK);  

    DrawText(text.c_str(), pos.x + 4, pos.y+UI_TABLE_CELL_HEIGHT/2, 12, BLACK);
}

void IterList::drawHeaders(Rectangle offsetBounds){
    for(float x = 0; x < offsetBounds.width; x+=UI_TABLE_CELL_WIDTH){
        for(float y = 0; y < offsetBounds.height; y+=UI_TABLE_CELL_HEIGHT){
            Vector2 cellPos = {offsetBounds.x + x, offsetBounds.y + y};
            if(y == 0 && x != 0){
                string iter = "Iteracao ";
                iter.append(to_string((int)(x/(UI_TABLE_CELL_WIDTH)))); // Que coisa feia
                drawCell(cellPos, iter, RAYWHITE);
            }else if(x == 0 && y != 0){
                string prop = board->get_nome_prop((int)(y/UI_TABLE_CELL_HEIGHT) - 1);
                drawCell(cellPos, prop, RAYWHITE);
            }else{
                continue; // Desnecessário, mas deixei aqui pra ficar claro que esse for não cuida de desenhar o resto das celulas
            }
        }
    }
}