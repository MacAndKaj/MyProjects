#include <SFML/Graphics.hpp>
#include <Buttons/LetterButton.hpp>

sf::Color cleanColor = sf::Color::White;

void changeColor()
{
    if (cleanColor == sf::Color::White)
    {
        cleanColor = sf::Color::Magenta;
    }
    else
    {
        cleanColor = sf::Color::White;
    }
}

int main()
{
    sf::RenderWindow mywindow(sf::VideoMode(800,600),"MyWindow");
    LetterButton myButoon(500,500,30,"guzik");
    std::function<void()> fun = changeColor;
    myButoon.setFunctionality(fun);
    while (mywindow.isOpen())
    {
        sf::Event event{};
        while (mywindow.pollEvent(event))
        {

        }
        mywindow.clear(cleanColor);
        mywindow.draw(myButoon);
        mywindow.display();

    }
    return 0;
}