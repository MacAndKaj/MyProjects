//
// Created by maciej on 12.08.18.
//

#include <Buttons/LetterButton.hpp>

LetterButton::LetterButton (int positionY_,
                            int positionX_,
                            int length_,
                            int height_,
                            const std::string& txt) :
        _positionCentralY(positionY_),
        _positionCentralX(positionX_),
        _length(length_),
        _height(height_)
{
    sf::Vector2f tmp(positionX_,positionY_);
    this->_basicColor = sf::Color::Black;
    this->_onClickColor = sf::Color::Blue;
    this->_onFocusColor = sf::Color::Red;
    this->_buttonText.setString(txt);

}

LetterButton::~LetterButton ()
{

}

void LetterButton::click ()
{

}

void LetterButton::unclick ()
{

}

bool LetterButton::isClicked ()
{
    return true;
}

void LetterButton::setFunctionality (const std::function<void ()> &functionality)
{
    this->_functionality = functionality;
}

void LetterButton::draw (sf::RenderTarget &target, sf::RenderStates states) const
{

}

void LetterButton::setBasicColor (const sf::Color &_basicColor)
{
    this->_basicColor = _basicColor;
}

void LetterButton::setOnFocusColor (const sf::Color &_onFocusColor)
{
    this->_onFocusColor = _onFocusColor;
}

void LetterButton::setOnClickColor (const sf::Color &onClickColor)
{
    this->_onClickColor = onClickColor;
}


