#ifndef UI_WINDOW_H
#define UI_WINDOW_H

// Se essa classe não crescer mais que isso dá pra passar as informações dela pra classe App, só pra diminuir o tanto de classes
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