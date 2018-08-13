//
// Created by maciej on 22.06.18.
//

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "MainWindow.h"
#include "Button.h"
#include "Game.h"


//-------------------  Constructors and destructors    ------------
/// Constructs MainWindow.
MainWindow::MainWindow() {
    this->_window = new sf::RenderWindow(sf::VideoMode(720, 576),
                                         "Checkers",
                                         sf::Style::Titlebar | sf::Style::Close,
                                         sf::ContextSettings());

    sf::Image icon;
    if (icon.loadFromFile("icon.png")) {
        this->_window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    }

}

/// Destructs the window.
MainWindow::~MainWindow() {
    std::for_each(this->_toDrawClick.begin(), this->_toDrawClick.end(),
                  [](Clickable *arg) { delete arg; });
    std::for_each(this->_toDrawElements.begin(), this->_toDrawElements.end(),
                  [](sf::Drawable *arg) { delete arg; });
    this->_toDrawClick.clear();
    this->_toDrawElements.clear();

}

//----------------------    Public methods  ---------------------

/// Adds a Button with text to specified as height place.x
/// \param height[in] - Height in window where Button has to be placed.
/// \param text[in] - Text which has to be inside the Button.
void MainWindow::addButton(const unsigned int height, const std::string &text,
                           void (*functionality)(Callable *)) {
    if (height > this->_window->getSize().y || text.empty())
        return;
    this->_toDrawClick.push_back(new Button(40, 360, height, text, std::function()));
}


/// Exec method with a main loop of application.
/// \return Returns EXIT_SUCCESS when normally closed.
void MainWindow::exec(Game* game) {
    this->_game = game;
    this->_game->set_windowOpen(true);
    this->callIntro();

    while (this->_window->isOpen()) {
        // Process events
        this->handleEvents();
        for (auto &i : this->_toDrawClick) {
            this->mouseFocus(*i);
        }
        this->drawAll();
        this->_window->display();
    }
    this->_game->set_windowOpen(false);

}

/// Closes a window and exits.
/// \return EXIT_SUCCESS when succesfully, EXIT_FAILURE otherwise.
void MainWindow::callExit() {
    this->resetScreen();
    this->addButton(100, "Yes", MainWindow::closeWindow);
    this->addButton(160, "No", MainWindow::introWindow);
}

void MainWindow::callClose() {
    this->_window->close();
}


void MainWindow::callIntro() {
    this->resetScreen();
    this->addButton(100, "Start", MainWindow::startGame);
    this->addButton(180, "Options");
    this->addButton(260, "Exit", MainWindow::exitWindow);
}

void MainWindow::callPause() {
    this->resetScreen();
    this->addButton(100,"Back",MainWindow::startGame);
    this->addButton(180,"Options");
    this->addButton(260,"Exit",MainWindow::exitWindow);
}

void MainWindow::callStart() {
    this->resetScreen();

    auto windowSize = this->_window->getSize();
    sf::RectangleShape *board1 = new sf::RectangleShape(sf::Vector2f(
            static_cast<float>(windowSize.x * 0.75),
            static_cast<float>(windowSize.x * 0.75)));
    sf::RectangleShape *board2 = new sf::RectangleShape(sf::Vector2f(
            static_cast<float>(windowSize.x * 0.7),
            static_cast<float>(windowSize.x * 0.7)));
    board1->setPosition(windowSize.x / 2 - (board1->getSize().x / 2), windowSize.y / 2 - (board1->getSize().y / 2));
    board1->setFillColor(sf::Color::Black);

    board2->setPosition(windowSize.x / 2 - (board2->getSize().x / 2), windowSize.y / 2 - (board2->getSize().y / 2));
    board2->setFillColor(sf::Color(153, 102, 0));

    this->_toDrawElements.push_back(board1);
    this->_toDrawElements.push_back(board2);
}

/// Deletes all the Buttons from window.
void MainWindow::resetScreen() {
    std::for_each(this->_toDrawClick.begin(), this->_toDrawClick.end(),
                  [](Clickable *arg) { delete arg; });
    std::for_each(this->_toDrawElements.begin(), this->_toDrawElements.end(),
                  [](sf::Drawable *arg) { delete arg; });

    this->_toDrawClick.clear();
    this->_toDrawElements.clear();
}


//------------------    Protected methods   ---------------------

/// Method used to draw all the elements.
void MainWindow::drawAll() const {
    this->_window->clear(sf::Color::White);
    for (auto &i: this->_toDrawClick) {
        this->_window->draw(*i);
    }
    for (auto &i: this->_toDrawElements) {
        this->_window->draw(*i);
    }

}


/// Method used to handle all the events.
void MainWindow::handleEvents() {
    sf::Event event{};
    while (this->_window->pollEvent(event)) {
        // Close _window: callExit
        if (event.type == sf::Event::Closed)
            this->callExit();
        if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::Escape:
                    if(this->_game->isRunning())this->callPause();
                    break;
                default:
                    break;
            }
        }
        else if (event.type == sf::Event::MouseButtonReleased) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                auto i = this->_toDrawClick.begin();
                bool found = false;
                while (i != this->_toDrawClick.end() && !found) {
                    if ((*i)->isFocused()) {
                        (*i)->unclick();
                        found = true;
                    }
                    ++i;
                }
            }
        }
    }
}



//--------------------- Private methods -------------------------

/// Method to checking if coursor is on the element. Changes colours of buttons.
/// \param Elem[out] - Element to check if is focused.
void MainWindow::mouseFocus(Clickable &Elem) {
    sf::Vector2i MousePos = sf::Mouse::getPosition(*this->_window);
    sf::Vector2i ElemPos = Elem.getLocalPosition();
    sf::Vector2f ElemSize = Elem.getSize();
    if (ElemPos.x <= MousePos.x && ElemPos.y <= MousePos.y) {
        if (MousePos.x <= ElemPos.x + ElemSize.x && MousePos.y <= ElemPos.y + ElemSize.y) {
            Elem.focus();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                Elem.click();
            }

        }
        else Elem.unfocus();
    }
    else Elem.unfocus();
}


//--------------     Static     ------------------------

void MainWindow::exitWindow(Callable *arg) {
    arg->callExit();
}

void MainWindow::closeWindow(Callable *arg) {
    arg->callClose();
}

void MainWindow::introWindow(Callable *arg) {
    arg->callIntro();
}


void MainWindow::startGame(Callable *arg) {
    arg->callStart();
}

void MainWindow::pauseGame(Callable *arg) {
    arg->callPause();
}



//------------------------------------------------------