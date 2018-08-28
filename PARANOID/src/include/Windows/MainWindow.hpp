//
// Created by maciej on 16.08.18.
//

#ifndef PARANOID_WINDOW_HPP
#define PARANOID_WINDOW_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <Detectors/EventDetector.hpp>
#include <Detectors/CollisionDetector.hpp>

class MainWindow
{
public:
    MainWindow ();
    virtual ~MainWindow ();

    int run();
    void addItemToDraw(sf::Drawable&);

private:
    void drawAllItems();

    unsigned int _windowHeight,_windowWidth;
    sf::Color _defaultWindowColor;
    std::unique_ptr<sf::RenderWindow> _handlerWindow;
    //EventDetector& _eventDetector;
    //CollisionDetector& _collisionDetector;
    std::string _windowTitle;
    std::vector<sf::Drawable> _allDrawableItems;
    Logger _log;
};


#endif //PARANOID_WINDOW_HPP
