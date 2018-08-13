//
// Created by maciej on 21.06.18.
//

#include <iostream>
#include "Button.h"
#include "Exceptions.h"

//------------------   Constructors and destructors ---------------------

/// Constructs Button.
/// \param _height[in]
/// \param _width[in]
/// \param _left[in]
/// \param _top[in]
/// \param _text[in]
Button::Button(unsigned int _height, unsigned int _centerX, unsigned int _centerY, const std::string &_text,
               std::function Callback) :
        _height(_height),
        _centerX(_centerX),
        _centerY(_centerY),
        _text(_text),
        _functionality(functionaluty),
        _Object(_Object), Callback(Callback) {
    sf::Vector2f tmp(_centerX,_centerY);
    this->_colorNormal = sf::Color::Black;
    this->_colorFocused = sf::Color::Red;
    this->_colorClicked = sf::Color::Blue;
    this->_focused = false;
    //----------------------Text---------------------
    if (!this->_font.loadFromFile("Pacific_Again.ttf")){
        throw ButtonExcept; // NOLINT
    }
    this->_buttonText.setFont(this->_font);
    this->_buttonText.setString(this->_text);
    this->_buttonText.setCharacterSize(this->_height);
    tmp.x -= this->_buttonText.getGlobalBounds().width/2;

    this->_buttonText.setPosition(tmp);
    this->_buttonText.setFillColor(this->_colorNormal);

}


//------------------------  Public methods  ----------------------------------

/// Changes color of Button when clicked.
void Button::click() {
    this->_buttonText.setFillColor(this->_colorClicked);
}

/// Changes color of Button when focused.
void Button::focus() {
    this->_focused = true;
    this->_buttonText.setFillColor(this->_colorFocused);
}

/// Method returning position of button.
/// \return Position of Button(left-top corner).
sf::Vector2i Button::getLocalPosition() const{
    return {static_cast<int>(this->_buttonText.getGlobalBounds().left),
            static_cast<int>(this->_buttonText.getGlobalBounds().top)};
}

/// Method returning size of Button.
/// \return Size of Button(x,y).
sf::Vector2f Button::getSize() const{
    return {this->_buttonText.getGlobalBounds().width,this->_buttonText.getGlobalBounds().height};
}

/// Checking method to get know if Button is focused.
/// \return Returns true if focused, false otherwise.
bool Button::isFocused() const {
    return this->_focused;
}

/// Changes color of Button when unclicked.
void Button::unclick() {
    this->_buttonText.setFillColor(this->_colorNormal);
    if(this->_functionality != nullptr){
        this->_functionality(this->_Object);
    }
}

/// Changes color of Button when unfocused.
void Button::unfocus() {
    this->_focused = false;
    this->_buttonText.setFillColor(this->_colorNormal);
}

//----------------------    Private methods ------------------------------------

///Overriden function used when Button is drawn.
/// \param[out] target - RenderTarget where button will be drawn.
/// \param[in] states - RenderStates used when object is drawn.
void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(this->_buttonText,states);
}

/// Sets a function used by Button.
/// \param func[in] - Pointer to function called by Button.
void Button::setFunctionality(void (*func)( Callable*)) {
    this->_functionality=func;
}


