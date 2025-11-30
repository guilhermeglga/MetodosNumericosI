#ifndef UI_MAINFRAME_H
#define UI_MAINFRAME_H

#include "../Page/Page.h"
#include "../../Widgets/Tables/IterList.h"

/*
    Onde o quadro comparativo vai ficar? 
    Depende se ele vai poder ser modificado ou tudo é decidido na instanciação
*/

class MainFrame : public Page{
    public:
        void render();

        MainFrame(Rectangle bounds_, ControlFlow* flow, QuadroComparativo* quadro);

    private:
};

#endif // UI_MAINFRAME_H