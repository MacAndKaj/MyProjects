//
// Created by mkajdak on 17.08.18.
//
#include <gtest/gtest.h>
#include <cmath>
#include <Buttons/LetterButton.hpp>
#include <SFML/Window/Mouse.hpp>
#include <Interface/ICallable.hpp>


class LetterButtonTests : public ::testing::Test
{

public:
    void startService()
    {
        this->_sut = std::make_unique<LetterButton>();
    }

    void callback()
    {
        _change = true;
    }

    bool _change;
    std::unique_ptr<LetterButton> _sut;
};


TEST_F(LetterButtonTests, LetterButtonTests_ShouldChangeState_Test)
{
    startService();
    _sut->focus();
    _sut->click();
    ASSERT_TRUE(_sut->isClicked());
    _sut->unclick();
    ASSERT_FALSE(_sut->isClicked());
    _sut->unfocus();
    _sut->click();
    ASSERT_FALSE(_sut->isClicked());
    _sut->unclick();
    ASSERT_FALSE(_sut->isClicked());

}

TEST_F(LetterButtonTests, LetterButtonTests_ShouldHandleFunctionality_Test)
{
    startService();
    _change = false;
    std::function<void(void)> func = std::bind(&LetterButtonTests::callback, this);
    _sut->setFunctionality(func);
    _sut->focus();
    _sut->click();
    _sut->unclick();
    ASSERT_TRUE(_change);
}

TEST_F(LetterButtonTests, LetterButtonTests_ShouldNotHandleFunctionality_Test)
{
    startService();
    _change = false;
    std::function<void(void)> func = std::bind(&LetterButtonTests::callback, this);
    _sut->setFunctionality(func);
    _sut->click();
    ASSERT_FALSE(_change);
    _sut->unclick();
    ASSERT_FALSE(_change);
}
