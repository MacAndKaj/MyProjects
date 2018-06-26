//
// Created by mkajdak on 17.11.17.
//

#ifndef TESTOWNIK_BUTTON_H
#define TESTOWNIK_BUTTON_H

#include <SFML/Graphics.hpp>

class Button : public sf::Drawable {
public:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void SetText(std::string&&);
    void SetText(std::string&);

    void SetPosition(float& x, float& y);
    void SetPosition(float&& x, float&& y);
    void SetColor(sf::Color& );

    void Click();

    Button();
    Button(const std::string &p_Text, const sf::Color &p_Color,float p_X_pos, float p_Y_pos, float p_X_size, float p_Y_size);
    ~Button() override = default;

private:
    sf::RectangleShape p_Button;
    std::string p_Text;
    sf::Color p_Color;
    sf::Color p_Color_Clicked;
    sf::Vector2f p_pos;
    sf::Vector2f p_size;

    bool Clicked;
};


#endif //TESTOWNIK_BUTTON_H
