#ifndef UI_WINDOW_H
#define UI_WINDOW_H

class Window{
    public:
        Window(int width_, int height_);

        int get_width();
        int get_height();

    private:
        int width;
        int height;

};

#endif // UI_WINDOW_H