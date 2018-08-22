#include <iostream>
#include "MainWindow.h"
#include "Game.h"

int main(int argc, char **argv) {
    Game game;
    MainWindow mainWindow;
    std::thread Window(&MainWindow::exec,&mainWindow,&game);
    std::thread Game(&Game::exec,&game);

    Window.join();
    Game.join();

    return EXIT_SUCCESS;
}
