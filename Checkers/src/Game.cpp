//
// Created by maciej on 29.06.18.
//

#include "Game.h"


Game::Game() {

}


Game::~Game() {
}

int Game::exec() {
    while(this->_windowOpen){

    }
}

bool Game::isRunning() const {
    return this->_running;
}

void Game::set_windowOpen(bool _windowOpen) {
    this->_windowOpen = _windowOpen;
}

