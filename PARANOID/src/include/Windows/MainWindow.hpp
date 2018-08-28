//
// Created by maciej on 16.08.18.
//

#ifndef PARANOID_WINDOW_HPP
#define PARANOID_WINDOW_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <Detectors/EventDetector.hpp>
#include <Detectors/CollisionDetector.hpp>
#include <Engine.hpp>

using namespace eng;

class MainWindow
{
public:
    explicit MainWindow(Engine &engine);
    virtual ~MainWindow ();

    int run();
    void addItemToDraw(sf::Drawable&);

private:
    void drawAllItems();

    unsigned int _windowHeight,_windowWidth;
    sf::Color _defaultWindowColor;
    std::unique_ptr<sf::RenderWindow> _handlerWindow;
    det::EventDetector& _eventDetector;
    det::CollisionDetector& _collisionDetector;
    std::string _windowTitle;
    std::vector<sf::Drawable> _allDrawableItems;
    Logger _log;
};


#endif //PARANOID_WINDOW_HPP
