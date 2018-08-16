//
// Created by maciej on 16.08.18.
//

#include "MainWindow.hpp"

MainWindow::MainWindow ():
{
    this->_handlerSettinngsWindow = std::make_unique<sf::ContextSettings>();
    this->_handlerVideoModeWindow = std::make_unique<sf::VideoMode>(sf::VideoMode::getDesktopMode());
    this->_handlerWindow = std::make_unique<sf::Window>(new());
}

MainWindow::~MainWindow ()
{

}

MainWindow::MainWindow (unsigned int _windowHeight, unsigned int _windowWidth,
                        const std::string &_windowTitle) : _windowHeight(_windowHeight), _windowWidth(_windowWidth),
                                                           _windowTitle(_windowTitle) { }
