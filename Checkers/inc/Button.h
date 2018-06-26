//
// Created by maciej on 21.06.18.
//

#ifndef CHECKERS_BUTTON_H
#define CHECKERS_BUTTON_H

#include "Clickable.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>

class Button : public Clickable{
private:
    //std
    unsigned int _height;
    unsigned int _centerX;
    unsigned int _centerY;
    std::string _text;
    bool _focused;
    //sf
    sf::Text _buttonText;
    sf::Font _font;
    sf::Color _colorNormal,_colorFocused,_colorClicked;
public:
        explicit Button(unsigned int _height, unsigned int _centerX, unsigned int _centerY,const std::string& _text);

            void click() override;
            void focus() override;
    sf::Vector2i getLocalPosition() const override;
    sf::Vector2f getSize() const override;
            bool isFocused() const override;
            void unclick() override;
            void unfocus() override;

private:
            void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //CHECKERS_BUTTON_H
