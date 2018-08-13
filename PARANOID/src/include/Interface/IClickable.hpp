//
// Created by maciej on 30.07.18.
//

#ifndef PARANOID_ICLICKABLE_HPP
#define PARANOID_ICLICKABLE_HPP
#include <SFML/Graphics/Drawable.hpp>

class IClickable {
public:
    virtual void click() = 0;
    virtual void focus() = 0;
    virtual bool isFocused()const = 0 ;
    virtual void unclick() = 0;
    virtual void unfocus() = 0;
    virtual sf::Vector2i getLocalPosition() const = 0;
    virtual sf::Vector2f getSize() const = 0;
};


#endif //PARANOID_ICLICKABLE_HPP
