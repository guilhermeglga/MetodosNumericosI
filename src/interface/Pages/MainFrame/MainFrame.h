#ifndef UI_MAINFRAME_H
#define UI_MAINFRAME_H

#include "../InputFrame/InputFrame.h"
#include "../OutputFrame/OutputFrame.h"
#include "../Page/Page.h"

/*
    Onde o quadro comparativo vai ficar? 
    Depende se ele vai poder ser modificado ou tudo é decidido na instanciação
*/

class MainFrame : public Page{
    public:
        void render();

        MainFrame(Rectangle bounds_, ControlFlow* flow);

    private:
        InputFrame in_frame;
        OutputFrame out_frame;
};

#endif // UI_MAINFRAME_H