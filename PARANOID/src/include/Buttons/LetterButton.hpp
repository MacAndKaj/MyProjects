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
    explicit LetterButton (int positionY_, int positionX_, int length_, int height_,const std::string& txt);
    ~LetterButton () override;

    //IClickable
    void click () override;
    void unclick () override;
    bool isClicked () override;

    //sf::Drawable
    void draw (sf::RenderTarget &target, sf::RenderStates states) const override;

    void setFunctionality (const std::function<void ()> &functionality);
    void setBasicColor (const sf::Color &_basicColor);
    void setOnFocusColor (const sf::Color &_onFocusColor);
    void setOnClickColor (const sf::Color &onClickColor);
private:
    bool _clicked;
    int _height;
    int _length;
    int _positionCentralY;
    int _positionCentralX;
    sf::Text _buttonText;
    sf::Font _font;
    sf::Color _basicColor, _onFocusColor, _onClickColor;
    std::function<void ()> _functionality;
};


#endif //PARANOID_LETTERBUTTON_HPP
