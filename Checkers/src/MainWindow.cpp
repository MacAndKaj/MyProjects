//
// Created by maciej on 22.06.18.
//

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "../inc/MainWindow.h"
#include "../inc/Button.h"


/// Constructs MainWindow.
MainWindow::MainWindow() {
    this->settings.antialiasingLevel = 8;

    this->window = std::unique_ptr<sf::RenderWindow>(
            new sf::RenderWindow(sf::VideoMode(720, 576),
                                 "Checkers",
                                 sf::Style::Titlebar | sf::Style::Close, settings));
    sf::Image icon;
    if(icon.loadFromFile("/home/maciej/Documents/MyProjects/Checkers/icon.png")) {
        this->window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    }
    this->toDrawClick.push_back(new Button(50, 360, 180, "Start"));
    this->toDrawClick.push_back(new Button(50, 360, 250, "Exit"));
}

/// Method used to draw all the elements.
void MainWindow::drawAll() {
    this->window->clear(sf::Color::White);
    for (auto &i: this->toDrawClick) {
        this->window->draw(*i);
    }
    this->window->display();
}

/// Exec method with a main loop of application.
/// \return Returns EXIT_SUCCESS when normally closed.
int MainWindow::exec() {
    while (this->window->isOpen()) {
        // Process events
        for(auto &i : this->toDrawClick){
            this->mouseFocus(*i);
        }
        this->handleEvents();
        this->drawAll();
    }
    return EXIT_SUCCESS;
}

/// Method used to handle all the events.
void MainWindow::handleEvents() {
    sf::Event event{};
    while (this->window->pollEvent(event)) {
        // Close window: exit
        if (event.type == sf::Event::Closed)
            this->window->close();
        if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::Escape:
                    this->window->close();
                    break;
                default:
                    break;
            }
        }
        if (event.type == sf::Event::MouseButtonPressed){
            auto clickable = std::find_if(this->toDrawClick.begin(),this->toDrawClick.end(),
                                          [](const Clickable* arg)->bool{ return arg->isFocused();});
            if(clickable != this->toDrawClick.end()) (*clickable)->click();
        }
        if (event.type == sf::Event::MouseButtonReleased){
            auto clickable = std::find_if(this->toDrawClick.begin(),this->toDrawClick.end(),
                                          [](const Clickable* arg)->bool{ return arg->isFocused();});
            if(clickable != this->toDrawClick.end()) (*clickable)->unclick();
        }
    }
}

/// Method to checking if coursor is on the element. Changes colours of buttons.
/// \param Elem[out] - Element to check if is focused.
void MainWindow::mouseFocus(Clickable &Elem)  {
    sf::Vector2i MousePos = sf::Mouse::getPosition(*this->window.get());
    sf::Vector2i ElemPos = Elem.getLocalPosition();
    sf::Vector2f ElemSize = Elem.getSize();
    if(ElemPos.x <= MousePos.x && ElemPos.y <= MousePos.y){
        if(MousePos.x <= ElemPos.x + ElemSize.x && MousePos.y <= ElemPos.y + ElemSize.y){
            Elem.focus();
        }
        else Elem.unfocus();
    }
    else Elem.unfocus();
}

void MainWindow::mouseClick(Clickable &Elem) {
    sf::Vector2i MousePos = sf::Mouse::getPosition(*this->window.get());
    sf::Vector2i ElemPos = Elem.getLocalPosition();
    sf::Vector2f ElemSize = Elem.getSize();
    if(ElemPos.x <= MousePos.x && ElemPos.y <= MousePos.y){
        if(MousePos.x <= ElemPos.x + ElemSize.x && MousePos.y <= ElemPos.y + ElemSize.y){
            Elem.click();
        }
    }
}

void MainWindow::mouseUnclick(Clickable &Elem) {
    sf::Vector2i MousePos = sf::Mouse::getPosition(*this->window.get());
    sf::Vector2i ElemPos = Elem.getLocalPosition();
    sf::Vector2f ElemSize = Elem.getSize();
    if(ElemPos.x <= MousePos.x && ElemPos.y <= MousePos.y){
        if(MousePos.x <= ElemPos.x + ElemSize.x && MousePos.y <= ElemPos.y + ElemSize.y){
            Elem.click();
        }
    }
}



