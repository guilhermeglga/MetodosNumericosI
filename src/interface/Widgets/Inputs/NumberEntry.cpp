#include "NumberEntry.h"

void NumberEntry::render(Vector2 scrollOffset){
    ScrollableFrame::render(scrollOffset);

    Rectangle offsetBounds = get_offset_bounds();

    // Descobrir como isso funciona
    // GuiSetStyle(TEXTBOX, BACKGROUND_COLOR, ColorToInt(RAYWHITE));

    if(GuiTextBox(offsetBounds, text, 99, editMode)){
        editMode = !editMode;

        if(validate_input()){
            strcpy(lastValidated, text);
            cur_num = atof(lastValidated);
        }else{
            strcpy(text, lastValidated);
        }
    }
    //DrawTextEx(GuiGetFont(), text.c_str(), {offsetBounds.x + 8, offsetBounds.y + 8}, 24, 2, BLACK);
}

float NumberEntry::get_cur_num(){
    return cur_num;
}

NumberEntry::NumberEntry(Vector2 pos_)
    : ScrollableFrame({pos_.x, pos_.y, 200, 32})
{
    cur_num = 0;
    editMode = false;
}

bool NumberEntry::validate_input()
{
    int dot_num = 0;
    for(char c : text){
        if(c == 46) dot_num++;

        if(dot_num > 1 || (c != 0 && c!=46 && (c < 48 || c > 57))) return false;
    }

    return true;
}
