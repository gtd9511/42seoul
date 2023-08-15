#include "AMateria.hpp"
#include "Floor.hpp"

Floor::Floor() : idx(0), max_len(2)
{
   this->floor = new AMateria*[max_len];
   for(int i = 0; i < max_len; i++)
        this->floor[i] = NULL;
}

Floor::~Floor()
{
    std::cout << "~Floor()" << std::endl;
    for(int i = 0; i < idx; i++)
        delete floor[i];
    delete floor;
}

void Floor::dropItem(AMateria * p)
{
    if(idx == max_len)//저장 슬롯 늘리기.
    {
        max_len += 10;
        AMateria **ptr = new AMateria*[max_len];
        for(int i = 0; i < idx; i++)
            ptr[i] = this->floor[i];
        delete this->floor;
        this->floor = ptr;
    }
        this->floor[idx++] = p;
}

void Floor::checkItem()
{
    for(int i = 0; i < max_len; i++)
    {
        if (this->floor[i] != NULL)
            std::cout << "item " << i << " " << floor[i]->getType() << std::endl;
    }
}