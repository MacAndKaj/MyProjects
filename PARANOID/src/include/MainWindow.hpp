//
// Created by maciej on 16.08.18.
//

#ifndef PARANOID_WINDOW_HPP
#define PARANOID_WINDOW_HPP


#include <SFML/Window.hpp>

class MainWindow
{
public:
    MainWindow (unsigned int _windowHeight, unsigned int _windowWidth, const std::string &_windowTitle);
    virtual ~MainWindow ();

private:
    unsigned int _windowHeight,_windowWidth;
    std::string _windowTitle;
    std::unique_ptr<sf::Window> _handlerWindow;
    std::unique_ptr<sf::ContextSettings> _handlerSettinngsWindow;
    std::unique_ptr<sf::VideoMode> _handlerVideoModeWindow;
};


#endif //PARANOID_WINDOW_HPP
