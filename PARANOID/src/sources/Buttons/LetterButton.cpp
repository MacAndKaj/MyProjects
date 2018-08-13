//
// Created by maciej on 12.08.18.
//

#include <Buttons/LetterButton.hpp>

LetterButton::LetterButton (int positionY_,
                            int positionX_,
                            int length_,
                            int height_) :
        positionY_(positionY_),
        positionX_(positionX_),
        length_(length_),
        height_(height_)
{

}

LetterButton::~LetterButton ()
{

}

void LetterButton::click ()
{

}

void LetterButton::unclick ()
{

}

bool LetterButton::isClicked ()
{
    return this->clicked_;
}

void LetterButton::setFunctionality (const std::function<void ()> &functionality)
{
    functionality_ = functionality;
}

void LetterButton::draw (sf::RenderTarget &target, sf::RenderStates states) const
{

}


