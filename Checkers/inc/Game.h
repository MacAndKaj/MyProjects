//
// Created by maciej on 29.06.18.
//

#ifndef CHECKERS_GAME_H
#define CHECKERS_GAME_H

#include <thread>

#include "Player.h"

class Game {
private:
    std::unique_ptr<Player> _playerFirst;
    std::unique_ptr<Player> _playerSecond;
    bool _running;
    bool _windowOpen;
public:
    Game();
    virtual ~Game();

    int exec();
    bool isRunning() const;

    void set_windowOpen(bool _windowOpen);

};


#endif //CHECKERS_GAME_H
