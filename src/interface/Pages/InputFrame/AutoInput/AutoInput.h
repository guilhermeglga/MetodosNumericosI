#ifndef UI_AUTOINPUT_H
#define UI_AUTOINPUT_H

#include "../../Page/Page.h"

class AutoInput : public Page{
    public:
        void render() override;
        AutoInput(Rectangle bounds_, ControlFlow* flow_);
};

#endif // UI_AUTOINPUT_H