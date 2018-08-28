//
// Created by maciej on 16.08.18.
//

#include <SFML/Window/Event.hpp>
#include <Windows/MainWindow.hpp>

MainWindow::MainWindow ()
        : _log("MainWindow")
        , _defaultWindowColor (sf::Color::Black)
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
