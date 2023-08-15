#pragma once
#ifndef Floor_HPP
# define Floor_HPP

#include "AMateria.hpp"

class Floor
{
private:
    int idx;
    int max_len;
    AMateria **floor;
public:
        Floor();
        Floor(const Floor& Floor);
        Floor& operator=(const Floor& Floor);
        ~Floor();

        void dropItem(AMateria * p);
        void checkItem();
};

#endif // Floor_HPP