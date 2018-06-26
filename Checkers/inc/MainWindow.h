//
// Created by maciej on 22.06.18.
//

#ifndef CHECKERS_MAINWINDOW_H
#define CHECKERS_MAINWINDOW_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <algorithm>
#include <memory>
#include "Clickable.h"

class MainWindow {
private:
    std::unique_ptr<sf::RenderWindow> window;
    std::vector<Clickable*> toDrawClick;

    sf::ContextSettings settings;
    void mouseFocus(Clickable& Elem);
    void mouseClick(Clickable& Elem);
    void mouseUnclick(Clickable& Elem);
protected:
    void drawAll();
    void handleEvents();

public:
    MainWindow();
    int exec();
};


#endif //CHECKERS_MAINWINDOW_H
