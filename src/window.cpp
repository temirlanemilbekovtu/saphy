#include "window.hpp"
#include "constants.hpp"

PrettyWindow::PrettyWindow(int row, int col, int height, int width)
    : _background(nullptr, delete_window)
    , _overlay(nullptr, delete_window)
    , _panel(nullptr, delete_panel) {

    if (height < MIN_WIN_HEIGHT || width < MIN_WIN_WIDTH) {
        throw std::invalid_argument(
                "Window dimensions cannot be less then "
                + std::to_string(MIN_WIN_HEIGHT) + " and "
                + std::to_string(MIN_WIN_WIDTH) + " for height and width, respectively.");
    }

    _background.reset(newwin(height, width, row, col));
    _overlay.reset(derwin(_background.get(),
                          height - OVERLAY_Y_DIFF, width - OVERLAY_X_DIFF, OVERLAY_Y_OFFSET, OVERLAY_X_OFFSET));
    _panel.reset(new_panel(_background.get()));

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
