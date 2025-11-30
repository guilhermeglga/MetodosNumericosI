#include "NumberEntry.h"

void NumberEntry::render(Vector2 scrollOffset){
    ScrollableFrame::render(scrollOffset);

    Rectangle offsetBounds = get_offset_bounds();

    // Descobrir como isso funciona
    // GuiSetStyle(TEXTBOX, BACKGROUND_COLOR, ColorToInt(RAYWHITE));

    if(GuiTextBox(offsetBounds, text, 99, editMode)){
        editMode = !editMode;

        if(strcmp(text, "") && validate_input()){
            strcpy(lastValidated, text);
            cur_num = atof(lastValidated);
        }else{
            strcpy(text, lastValidated);
        }
    }
}

double NumberEntry::get_cur_num(){
    return cur_num;
}

void NumberEntry::set_callback(std::function<void()> callback_){
    callback = callback_;
}

NumberEntry::NumberEntry(Vector2 pos_, string title_, function<void()> callback_)
    : ScrollableFrame({pos_.x, pos_.y, 200, 32})
{
    cur_num = 0;
    editMode = false;

    title = title_;
    callback = callback_;
}

bool NumberEntry::validate_input()
{
    int dot_num = 0;
    for(char c : text){
        if(c == 46 || c == 44) dot_num++;

        // Tem que desenhar a tabela verdade pra entender essa aqui
        if(dot_num > 1 || (c != 0 && c!=46 && c!=44 && (c < 48 || c > 57))) return false;
    }

    callback();
    return true;
}
