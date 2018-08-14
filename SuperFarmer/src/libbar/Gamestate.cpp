#include "Gamestate.hpp"
#include "Dice.hpp"
#include <iostream>


Gamestate::Gamestate(int noPlayers) : 
    _vecPlayers(noPlayers),
    _turn(0)
{

}

bool Gamestate::isGameOver()
{
    return  requestForEnd() or hasSomebodyWon();
}

bool Gamestate::requestForEnd()
{
    
    return false;
}

bool Gamestate::hasSomebodyWon()
{
    return false;
}



void Gamestate::askTrade(){
    char choice;
    while(true)
    {
        std::cout << "Czy chcesz handlowac?[t/n]\n";
        std::cin >> choice;
        switch(choice)
        {
            case 't':
                trade();
                break;
            case 'n':
                return;
            default:
                std::cout << "Wybrano nieprawidlowa opcje!\n";
                break;
        }
    }
}

void Gamestate::handlePlayerTurn(Player& player)
{
    bool playerTraded=false;
    askTrade();
    auto diceThrow = _dice.rollDice();
}
void Gamestate::start()
{
    //wybrac graczaq
    //wypisac bank
    //rzuic
    Player& currPlayer = _vecPlayers[_turn%_vecPlayers.size()];
    do
    {
        handlePlayerTurn(currPlayer);
        ++_turn;
        currPlayer = _vecPlayers[_turn%_vecPlayers.size()];
        break;
    } while(isGameOver());


    //currPlayer.trade();
    _turn++;
}

