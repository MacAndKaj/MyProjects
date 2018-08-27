//
// Created by maciej on 16.08.18.
//

#include <SFML/Window/Event.hpp>
#include "MainWindow.hpp"

MainWindow::MainWindow (unsigned int _windowHeight, unsigned int _windowWidth
                        , const std::string &_windowTitle)
        : _windowHeight(_windowHeight)
        , _windowWidth(_windowWidth)
        , _windowTitle(_windowTitle)
        , _handlerWindow(sf::VideoMode(_windowWidth,_windowHeight),_windowTitle)
        , _defaultWindowColor(sf::Color::White)
{}

MainWindow::~MainWindow ()
{

}

int MainWindow::run ()
{
    while (_handlerWindow.isOpen())
    {

    }

    return EXIT_SUCCESS;
}

void MainWindow::addItemToDraw (sf::Drawable& item)
{

}

void MainWindow::drawAllItems ()
{
    _handlerWindow.clear();
    for (auto &&drawableItem : _allDrawableItems)
    {
        _handlerWindow.draw(drawableItem);
    }
}
