#include <iostream>
#include <Logger.hpp>

int main()
{
//    sf::Window mywindow(sf::VideoMode(800,600),"MyWindow");
//
//
//    while (mywindow.isOpen())
//    {
//        sf::Event event{};
//        while (mywindow.pollEvent(event))
//        {
//            if(event.type == sf::Event::Closed){
//                mywindow.close();
//            }
//        }
//
//    }

    Logger log("mojlog");
    log << "Tutaj cos napisze" << "tutaj tez" << "I tutaj" << logging::logEnd;
    return 0;
}