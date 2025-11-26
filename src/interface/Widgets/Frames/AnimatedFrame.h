#ifndef UI_ANIMATEDFRAME_H
#define UI_ANIMATEDFRAME_H

#include "./ScrollableFrame.h"

// Classe com um atributo animFrames que automaticamente é decrementado todo frame, até chegar em zero
// A ideia é usar esse atributo pra controlar o timing da animação, a logica da animação fica fora da classe
class AnimatedFrame : public ScrollableFrame{
    public:
        virtual void render(Vector2 scrollOffset);

        AnimatedFrame(Rectangle bounds_);

        int getAnimFrames();
        void startAnim(int timeFrames);

    private:
        int animFrames;
};

#endif // UI_ANIMATEDFRAME_H