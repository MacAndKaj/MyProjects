//
// Created by maciej on 12.08.18.
//

#include <Buttons/LetterButton.hpp>

LetterButton::LetterButton()
{}

LetterButton::LetterButton(int positionY,
                           int positionX,
                           int length,
                           int height,
                           const std::string &txt) :
        _positionCentralY(positionY),
        _positionCentralX(positionX),
        _length(length),
        _height(height)
{
    sf::Vector2f tmp(positionX, positionY);
    _basicColor = sf::Color::Black;
    _onClickColor = sf::Color::Blue;
    _onFocusColor = sf::Color::Red;
    _buttonText.setString(txt);

}

LetterButton::~LetterButton()
{

}

void LetterButton::click()
{
    if (_focused)
    {
        _clicked = true;
    }

}

void LetterButton::unclick()
{
    if (_clicked)
    {
        if(_functionality)
            _functionality();
        _clicked = false;
    }
}

bool LetterButton::isClicked()
{
    return _clicked;
}

void LetterButton::setFunctionality(const std::function<void()> &functionality)
{
    _functionality = functionality;
}

void LetterButton::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

}

void LetterButton::setBasicColor(const sf::Color &basicColor)
{
    _basicColor = basicColor;
}

void LetterButton::setOnFocusColor(const sf::Color &onFocusColor)
{
    _onFocusColor = onFocusColor;
}

void LetterButton::setOnClickColor(const sf::Color &onClickColor)
{
    _onClickColor = onClickColor;
}

void LetterButton::focus()
{
    if (not _focused)
    {
        _focused = true;
    }
}

void LetterButton::unfocus()
{
    if (_focused)
    {
        _focused = false;
    }
}


