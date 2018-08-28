//
// Created by maciej on 12.08.18.
//

#include <Buttons/LetterButton.hpp>
#include <iostream>

LetterButton::LetterButton ()
        : _log("LetterButton")
{
    if(!_font.loadFromFile("Pacific_Again.ttf")){
        _log << "Error while loading font!" << logging::logEnd;
    }
}

LetterButton::LetterButton(int positionY, int positionX, unsigned int size, const std::string &txt)
        : _positionCentralY(positionY)
        , _positionCentralX(positionX)
        , _fontSize(size)
        , _clicked(false)
        , _focused(false)
        , _log("LetterButton("+txt+')')
{
    sf::Vector2f tmp(positionX, positionY);
    _basicColor = sf::Color::Black;
    _onClickColor = sf::Color::Blue;
    _onFocusColor = sf::Color::Red;
    _buttonText.setString(txt);
    if(!_font.loadFromFile("Pacific_Again.ttf")){
        _log << "Error while loading font!" << logging::logEnd;
    }
    _buttonText.setFont(_font);
    _buttonText.setFillColor(_basicColor);
    _buttonText.setPosition(tmp);
    _buttonText.setCharacterSize(_fontSize);

}

LetterButton::~LetterButton()
{

}

void LetterButton::click()
{
    if (_focused)
    {
        _buttonText.setFillColor(_onClickColor);
        _clicked = true;
    }

}

void LetterButton::unclick()
{
    if (_clicked)
    {
        if(_callback)
        {
            _log << __FUNCTION__ << "callback applied." << logging::logEnd;
            _callback();
        }
        _buttonText.setFillColor(_onFocusColor);
        _clicked = false;
    }
}

bool LetterButton::isClicked()
{
    return _clicked;
}

void LetterButton::setFunctionality (std::function<void()> &functionality)
{
    _callback = functionality;
}

void LetterButton::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(_buttonText, states);
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
        _buttonText.setFillColor(_onFocusColor);
        _focused = true;
    }
}

void LetterButton::unfocus()
{
    if (_focused)
    {
        _buttonText.setFillColor(_basicColor);
        _focused = false;
    }
}

void LetterButton::setButtonText (const std::string &buttonText)
{
    _buttonText.setString(buttonText);
    _log.setNameOfLoggerOwner("LetterButton("+buttonText+')');
}


