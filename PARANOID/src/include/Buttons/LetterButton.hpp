//
// Created by maciej on 12.08.18.
//

#ifndef PARANOID_LETTERBUTTON_HPP
#define PARANOID_LETTERBUTTON_HPP

#include <Interface/IClickable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include <functional>

class LetterButton : public IClickable,
                     public sf::Drawable
{
public:
    explicit LetterButton (int positionY_, int positionX_, int length_, int height_);
    ~LetterButton () override;

    //IClickable
    void click () override;
    void unclick () override;
    bool isClicked () override;

    //sf::Drawable
    void draw (RenderTarget &target, sf::RenderStates states) const override;

    void setFunctionality (const std::function<void ()> &functionality);
private:
    bool clicked_;
    int height_;
    int length_;
    int positionX_;
    int positionY_;
    sf::Text buttonText_;
    std::function<void ()> functionality_;
};


#endif //PARANOID_LETTERBUTTON_HPP
