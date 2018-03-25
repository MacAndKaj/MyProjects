#include <SFML/Graphics.hpp>
#include <iostream>

#include "inc/Button.h"

int main() {


    unsigned int x=1024;
    unsigned int y=680;
    unsigned int posx=x/2-50;
    unsigned int posy=y/2-30;

    unsigned int sizx=200;
    unsigned int sizy=100;

    Button ksztalt("dasasd",sf::Color::Magenta,posx,posy,sizx,sizy);

    sf::RenderWindow window(sf::VideoMode(x,y),"Moje okno");

    while(window.isOpen()){
        sf::Event wydarzenie{};
        while(window.pollEvent(wydarzenie)) {
            if (wydarzenie.type == sf::Event::Closed) {
                window.close();
            }
                if (wydarzenie.type == sf::Event::MouseButtonReleased && wydarzenie.mouseButton.button==sf::Mouse::Left) {
                    sf::Vector2i wek = sf::Mouse::getPosition(window);
                    if (wek.x >= posx && wek.x <= posx + sizx) {
                        if (wek.y >= posy && wek.y <= posy + sizy) {
                            std::cout << "klikam" << std::endl;
                            ksztalt.Click();
                        }
                    }
                }


        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            window.close();
        }

        window.clear(sf::Color::White);


        window.draw(ksztalt);


        window.display();
    }



    return 0;
}