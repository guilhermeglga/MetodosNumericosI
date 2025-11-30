#ifndef UI_NUMBERENTRY_H
#define UI_NUMBERENTRY_H

#include "../Frames/ScrollableFrame.h"
#include <cstdlib>
#include <functional>
#include <string>

/* ToDo:
    - Essa fonte não tá muito legal
    - O backspace tá apagando muito rápido
*/

#define UI_MAX_NUMBER_DIGITS 100

using namespace std;

// Entrada de decimal, com uma validação básica de input
class NumberEntry : public ScrollableFrame{
    public:
        void render(Vector2 scrollOffset) override;

        double get_cur_num();

        // Callback chamado quando o novo número é validado
        void set_callback(function<void()> callback_);

        NumberEntry(Vector2 pos_, string title_, function<void()> callback_);

    private:
        double cur_num;
        string title;

        std::function<void()> callback;

        // Usando vetor de char no lugar de uma string pq a raygui não aceita string
        char lastValidated[UI_MAX_NUMBER_DIGITS] = "0";
        char text[UI_MAX_NUMBER_DIGITS] = "0";

        bool editMode;

        function<void()> callback;

        bool validate_input();
};

#endif // UI_NUMBERENTRY_H