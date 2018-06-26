//
// Created by mkajdak on 17.11.17.
//

#include "../inc/Button.h"


void Button::SetText(std::string &&text) {
    this->p_Text = text;
}

void Button::SetText(std::string &text) {
    this->p_Text = text;
}

void Button::SetPosition(float &x, float &y) {
    this->p_pos.x = x;
    this->p_pos.y = y;
}

void Button::SetPosition(float &&x, float &&y) {
    this->p_pos.x = x;
    this->p_pos.y = y;
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    target.draw(this->p_Button, states);

}

void Button::SetColor(sf::Color &color) {
    this->p_Color = color;

}

Button::Button() {
    this->p_Text = "";
    this->p_pos = sf::Vector2f();
    this->p_size = sf::Vector2f();
    this->p_Color = sf::Color{0, 0, 0};
    /*******Creating button************/
    this->p_Button = sf::RectangleShape(this->p_size);
    this->p_Button.setPosition(this->p_pos);
    this->p_Button.setFillColor(this->p_Color);
    this->p_Color_Clicked = sf::Color::Yellow;
    this->Clicked = false;
}

Button::Button(const std::string &p_Text, const sf::Color &p_Color, float p_X_pos, float p_Y_pos, float p_X_size,
               float p_Y_size) : p_Text(p_Text), p_Color(p_Color) {

    this->p_pos = sf::Vector2f(p_X_pos, p_Y_pos);
    this->p_size = sf::Vector2f(p_X_size, p_Y_size);
    /*******Creating button************/
    this->p_Button = sf::RectangleShape(this->p_size);
    this->p_Button.setPosition(this->p_pos);
    this->p_Button.setFillColor(this->p_Color);
    this->p_Color_Clicked = sf::Color::Yellow;
    this->Clicked = false;
}


void Button::Click() {
    if (Clicked) {
        this->p_Button.setFillColor(this->p_Color);
        this->Clicked = false;
        return;
    }
    this->p_Button.setFillColor(this->p_Color_Clicked);
    this->Clicked = true;
}


