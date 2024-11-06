#include "../include/window.hpp"

PrettyWindow::PrettyWindow(int row, int col, int height, int width)
    : _background(newwin(height, width, row, col), delete_window)
    , _overlay(derwin(_background.get(), row-4, col-2, 3, 1), delete_window)
    , _panel(new_panel(_background.get()), delete_panel) {

    box(_background.get(), 0, 0);

    update_panels();
    doupdate();
}

void PrettyWindow::delete_window(WINDOW *win) {
    if (win) {
        delwin(win);
    }
}

void PrettyWindow::delete_panel(PANEL *panel) {
    if (panel) {
        del_panel(panel);
    }
}
