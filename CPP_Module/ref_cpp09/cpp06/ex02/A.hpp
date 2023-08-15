#pragma once
#ifndef A_HPP
# define A_HPP
#include "Base.hpp"
class A : public Base
{
    virtual ~A(){
        std::cout << "A destructor called.\n";
    };

};

#endif // A_HPP