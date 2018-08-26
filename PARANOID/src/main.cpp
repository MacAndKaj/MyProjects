#include <SFML/Graphics.hpp>
#include <Buttons/LetterButton.hpp>

int main()
{
    sf::RenderWindow mywindow(sf::VideoMode(800,600),"MyWindow");
    LetterButton myButoon(500,500,30,"guzik");

    while (mywindow.isOpen())
    {
        sf::Event event{};
        while (mywindow.pollEvent(event))
        {
            if(event.type == sf::Event::Closed){
                mywindow.close();
            }
        }
        mywindow.clear(sf::Color::White);
        mywindow.draw(myButoon);
        mywindow.display();

    }
    return 0;
}