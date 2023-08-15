#pragma once
#ifndef C_HPP
# define C_HPP
#include "Base.hpp"
class C : public Base
{
    virtual ~C(){
        std::cout << "C destructor called.\n";
    };
};

#endif // C_HPP