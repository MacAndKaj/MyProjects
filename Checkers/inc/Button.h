//
// Created by maciej on 21.06.18.
//

#ifndef CHECKERS_BUTTON_H
#define CHECKERS_BUTTON_H

#include "Clickable.h"
#include "Callable.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include <functional>

class Button : public Clickable{
public:
        explicit Button(unsigned int _height, unsigned int _centerX, unsigned int _centerY, const std::string &_text,
                                std::function Callback);

            void click() override;
            void focus() override;
    sf::Vector2i getLocalPosition() const override;
    sf::Vector2f getSize() const override;
            bool isFocused() const override;
            void setFunctionality(void (*func)( Callable*)) override;
            void unclick() override;
            void unfocus() override;

private:
            void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    unsigned int _height;
    unsigned int _centerX;
    unsigned int _centerY;
            bool _focused;
     std::string _text;

        sf::Text _buttonText;
        sf::Font _font;
       sf::Color _colorNormal,
                 _colorFocused,
                 _colorClicked;

          void (*_functionality)( Callable*);
      Callable  *_Object;
      std::function Callback;
};


#endif //CHECKERS_BUTTON_H
