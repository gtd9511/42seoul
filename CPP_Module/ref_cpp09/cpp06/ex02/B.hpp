#pragma once
#ifndef B_HPP
# define B_HPP
#include "Base.hpp"
class B: public Base
{
    virtual ~B(){
        std::cout << "B destructor called.\n";
    };
};

#endif // B_HPP