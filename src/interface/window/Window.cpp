#include "Window.h"

Window::Window(int width_, int height_){
    width = width_;
    height = height_;
}

int Window::get_width(){
    return width;
}

int Window::get_height(){
    return height;
}
