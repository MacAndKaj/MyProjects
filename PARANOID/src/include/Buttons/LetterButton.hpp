//
// Created by maciej on 12.08.18.
//

#ifndef PARANOID_LETTERBUTTON_HPP
#define PARANOID_LETTERBUTTON_HPP

#include <Interface/IClickable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include <functional>
#include <Logger.hpp>

class ICallable;

class LetterButton
        : public IClickable, public sf::Drawable
{
public:
    LetterButton ();
    LetterButton (int positionY_, int positionX_, unsigned int size, const std::string &txt);
    ~LetterButton () override;

    //IClickable
    void click () override;
    void unclick () override;
    bool isClicked () override;
    void focus () override;
    void unfocus () override;

    //sf::Drawable
    void draw (sf::RenderTarget &target, sf::RenderStates states) const override;

    void setFunctionality(std::function<void()> &func);
    void setBasicColor (const sf::Color &basicColor);
    void setOnFocusColor (const sf::Color &onFocusColor);
    void setOnClickColor (const sf::Color &onClickColor);
    void setButtonText (const std::string &buttonText);
private:
    Logger _log;
    bool _clicked;
    bool _focused;
    unsigned int _fontSize;
    int _positionCentralY;
    int _positionCentralX;

    sf::Font _font;
    sf::Text _buttonText;
    sf::Color _basicColor;
    sf::Color _onFocusColor;
    sf::Color _onClickColor;
    std::function<void ()> _callback;
};

#endif //PARANOID_LETTERBUTTON_HPP
