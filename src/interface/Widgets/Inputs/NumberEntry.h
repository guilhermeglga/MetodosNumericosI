#ifndef UI_NUMBERENTRY_H
#define UI_NUMBERENTRY_H

#include "../Frames/ScrollableFrame.h"
#include <string.h>
#include <cstdlib>

/* ToDo:
    - Essa fonte não tá muito legal
*/

#define UI_MAX_NUMBER_DIGITS 100
class NumberEntry : public ScrollableFrame{
    public:
        void render(Vector2 scrollOffset) override;

        float get_cur_num();

        NumberEntry(Vector2 pos_);

    private:
        // Usando um float aqui mas talvez tenha que mudar
        float cur_num;

        // Usando vetor de char no lugar de uma string pq a raygui não aceita string
        char lastValidated[UI_MAX_NUMBER_DIGITS] = "0";
        char text[UI_MAX_NUMBER_DIGITS] = "0";

        bool editMode;

        bool validate_input();
};

#endif // UI_NUMBERENTRY_H