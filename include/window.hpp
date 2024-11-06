#pragma once

#ifndef SAPHY_WINDOW_HPP
#define SAPHY_WINDOW_HPP

#include <memory>
#include <ncurses.h>
#include <panel.h>

class PrettyWindow {
private:
    std::unique_ptr<WINDOW, void(*)(WINDOW*)> _background;
    std::unique_ptr<WINDOW, void(*)(WINDOW*)> _overlay;
    std::unique_ptr<PANEL, void(*)(PANEL*)> _panel;

    std::string _label;

    static void delete_window(WINDOW *win);
    static void delete_panel(PANEL *panel);

public:
    PrettyWindow(int row, int col, int height, int width, std::string &label);


    void set_label(const std::string &label);
    const std::string &get_label() const;
};

#endif //SAPHY_WINDOW_HPP
