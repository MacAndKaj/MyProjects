//
// Created by maciej on 21.06.18.
//

#ifndef CHECKERS_CLICKABLE_H
#define CHECKERS_CLICKABLE_H

#include <SFML/Graphics/Drawable.hpp>

class Clickable : public sf::Drawable{
public:
    virtual void click() = 0;
    virtual void focus() = 0;
    virtual bool isFocused()const = 0 ;
    virtual void unclick() = 0;
    virtual void unfocus() = 0;
    virtual sf::Vector2i getLocalPosition() const = 0;
    virtual sf::Vector2f getSize() const = 0;
};


#endif //CHECKERS_CLICKABLE_H
