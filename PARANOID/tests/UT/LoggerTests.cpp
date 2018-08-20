//
// Created by maciej on 20.08.18.
//

#ifndef LOGGERTESTS_CPP_
#define LOGGERTESTS_CPP_

#include <gtest/gtest.h>
#include <Logger.hpp>


class LoggerTests : public ::testing::Test
{


protected:
    void SetUp () override
    {
        _sut = std::make_unique<Logger>("TEST");
    }

    std::unique_ptr<Logger> _sut;
};

#endif