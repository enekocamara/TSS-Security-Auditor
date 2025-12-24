#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

int main() {
    Fl_Window* win = new Fl_Window(300, 180, "Hello FLTK");
    Fl_Box* box = new Fl_Box(20, 40, 260, 100, "Hello World!");
    win->end();
    win->show();
    return Fl::run();
}