//
// Created by maciej on 22.06.18.
//

#ifndef CHECKERS_MAINWINDOW_H
#define CHECKERS_MAINWINDOW_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <algorithm>
#include <memory>
#include "Clickable.h"
#include "Callable.h"
#include "Game.h"

class MainWindow: public Callable {
public:
            MainWindow();
    virtual ~MainWindow();
       void addButton(const unsigned int height, const std::string &text,
                   void (*functionaluty)( Callable*) = nullptr);
       void callExit() override ;
       void callClose() override ;
       void callIntro() override;
       void callStart() override;
       void callPause() override;

       void resetScreen();


    static void closeWindow(Callable *arg);
    static void exitWindow(Callable *arg);
    static void introWindow(Callable *arg);
    static void startGame(Callable* arg);
    static void pauseGame(Callable* arg);

    void exec(Game*);

protected:
       void drawAll() const;
       void mouseFocus(Clickable& Elem);
       void handleEvents() ;

private:
    sf::RenderWindow* _window;
    Game* _game;
    std::vector<Clickable*> _toDrawClick;
    std::vector<sf::Drawable*> _toDrawElements;

    sf::ContextSettings _settings;

    friend class Game;

};



//--------------------------    Others  ---------------------------


#endif //CHECKERS_MAINWINDOW_H
