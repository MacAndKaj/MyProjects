//
// Created by maciej on 16.08.18.
//

#include <SFML/Window/Event.hpp>
#include <Windows/MainWindow.hpp>

MainWindow::MainWindow(eng::Engine &engine)
        : _log("MainWindow")
        , _defaultWindowColor (sf::Color::Black)
        , _eventDetector(engine.getDetectorsFactory().getEventDetector())
        , _collisionDetector(engine.getDetectorsFactory().getCollisionDetector())
{


}

MainWindow::~MainWindow ()
{

}

int MainWindow::run ()
{

    return EXIT_SUCCESS;
}

void MainWindow::addItemToDraw (sf::Drawable& item)
{

}

void MainWindow::drawAllItems ()
{
}
