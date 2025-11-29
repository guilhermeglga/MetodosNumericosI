#include "IterList.h"

void IterList::render(Vector2 scrollOffset){
    AnimatedFrame::render(scrollOffset);

    Rectangle offsetBounds = get_offset_bounds();
    int animFrames = getAnimFrames();

    drawHeaders(offsetBounds);

    int tamanhoQuadro = board->tamanhoQuadro();
    for(int i = 0; i < tamanhoQuadro; i++){
        iteracao iter = board->retornarInteracao(i);
        float x = (i+1)*UI_TABLE_CELL_WIDTH;
        float y = UI_TABLE_CELL_HEIGHT;

        if(i == tamanhoQuadro-1 && animFrames > 0){
            y = y - animFrames*2;
        }

        drawCell({offsetBounds.x + x, offsetBounds.y + y*1}, to_string(iter.raiz));
        drawCell({offsetBounds.x + x, offsetBounds.y + y*2}, to_string(iter.funcaoNaRaiz));
        drawCell({offsetBounds.x + x, offsetBounds.y + y*3}, to_string(iter.erroEmX));
        drawCell({offsetBounds.x + x, offsetBounds.y + y*4}, to_string(iter.erroEmFX));
        drawCell({offsetBounds.x + x, offsetBounds.y + y*5}, to_string(iter.parada));
    }
}

IterList::IterList(Rectangle bounds_, QuadroResposta *board_)
    :AnimatedFrame(bounds_)
{
    board = board_;

    bounds.height = 6*UI_TABLE_CELL_HEIGHT; // 5 propriedades + 1 celula vazia
    bounds.width = (board->tamanhoQuadro() + 1)*UI_TABLE_CELL_WIDTH; // tamanho do quadro + 1 celula vazia
}

void IterList::updateBoard(){
    //float newHeight = 6*UI_TABLE_CELL_HEIGHT; // Não dá pra adicionar propriedades
    float newWidth = (board->tamanhoQuadro() + 1)*UI_TABLE_CELL_WIDTH; // tamanho do quadro + 1 celula vazia
    if(newWidth <= bounds.width) return;

    bounds.width = newWidth;
    startAnim(15);
}

void IterList::drawCell(Vector2 pos, string text){
    DrawRectangleRec({pos.x, pos.y, UI_TABLE_CELL_WIDTH, UI_TABLE_CELL_HEIGHT}, RAYWHITE);
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
                drawCell(cellPos, iter);
            }else if(x == 0 && y != 0){ 
                // ToDo: Botar o nome certo das propriedades, pensei num vetor com o nome das propriedades
                // Mas esse vetor não faz sentido ficar nessa classe, talvez no próprio quadro
                string prop = "Propriedade ";
                prop.append(to_string((int)(y/(UI_TABLE_CELL_HEIGHT)))); // Que coisa feia2
                drawCell(cellPos, prop);
            }else{
                continue; // Desnecessário, mas deixei aqui pra ficar claro que esse for não cuida de desenhar o resto das celulas
            }
        }
    }
}