//
// Created by maciej on 16.08.18.
//

#ifndef PARANOID_WINDOW_HPP
#define PARANOID_WINDOW_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <Detectors/EventDetector.hpp>
#include "Workers/CollisionDetector.hpp"

class MainWindow
{
public:
    MainWindow() = delete;
    MainWindow (unsigned int _windowHeight, unsigned int _windowWidth, const std::string &_windowTitle);
    virtual ~MainWindow ();

    int run();
    void addItemToDraw(sf::Drawable&);

private:
    void drawAllItems();

    unsigned int _windowHeight,_windowWidth;
    sf::Color _defaultWindowColor;
    sf::RenderWindow _handlerWindow;
    EventDetector _eventDetector;
    CollisionDetector _collisionDetector;
    std::string _windowTitle;
    std::vector<sf::Drawable> _allDrawableItems;
};


#endif //PARANOID_WINDOW_HPP
