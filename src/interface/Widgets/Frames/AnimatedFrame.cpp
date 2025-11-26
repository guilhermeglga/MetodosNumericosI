#include "AnimatedFrame.h"

void AnimatedFrame::render(Vector2 scrollOffset){
    ScrollableFrame::render(scrollOffset);
    if(animFrames > 0) animFrames--;
}

AnimatedFrame::AnimatedFrame(Rectangle bounds_)
    :ScrollableFrame(bounds_){
    animFrames = 0;
}

int AnimatedFrame::getAnimFrames()
{
    return animFrames;
}

void AnimatedFrame::startAnim(int value){
    animFrames = value;
}
