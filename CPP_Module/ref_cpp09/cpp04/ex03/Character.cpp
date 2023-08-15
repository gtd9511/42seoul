#include "Character.hpp"

Floor Character::floor = Floor();
Character::Character(const std::string name) : name(name)
{
    for(int i = 0 ; i < MAX_SLOTSIZE; i++)
        this->slot[i] = NULL;
}

Character::Character(const Character& copy)
{
    //깊은 복사 해야함
    for (int i = 0; i < MAX_SLOTSIZE; i++)
    {
        if(copy.slot[i] != NULL)
            this->slot[i] = copy.slot[i]->clone();
        else
            this->slot[i] = NULL;
    }
}

Character& Character::operator=(const Character& copy)
{
   //깊은 복사해야함
   std::cout << "Character::operator=(const Character &copy)" << std::endl;
    if (this != &copy)
    {
        this->name = copy.name;
        for (int i = 0; i < MAX_SLOTSIZE; i++)
        {
            if (this->slot[i] != NULL)
            {
                delete this->slot[i];
                this->slot[i] = NULL;
            }
        }
        for (int i =0; i < MAX_SLOTSIZE; i++)
        {
            if(copy.slot[i] != NULL)
                this->slot[i] = copy.slot[i]->clone();
        }
    }
    return *this;
}

Character::~Character()
{
    std::cout << "~Character()" << std::endl;
    for(int i = 0; i < MAX_SLOTSIZE; i++)    {
        
        if (this->slot[i] != NULL)
        {
            delete this->slot[i];
            this->slot[i] = NULL;
        }
    }
}

std::string const &Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria *p)
{
    for(int i = 0 ; i < MAX_SLOTSIZE; i++)
    {
        if(this->slot[i] == NULL)
        {
            std::cout << "Character " << this->getName() << " has equipped " <<  p->getType() << " in slot [" << i << "]" << std::endl;
            this->slot[i] = p;
            return;
        }
    }
    std::cout << "character " << this->getName() << " could not equip: full slot." << std::endl;
}

void Character::unequip(int idx)
{
    if(idx < 0 || idx >= MAX_SLOTSIZE)
        return;
    if (this->slot[idx] != NULL)
    {
        std::cout << "unequip ["  << idx <<']' << std::endl;
        floor.dropItem(this->slot[idx]);
        this->slot[idx] = NULL;
        return;
    }
    std::cout << "error: slot is emtpy." << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
    if(idx < 0 || MAX_SLOTSIZE <= idx)
        return;
    if(slot[idx] == NULL)
    {
        std::cout << "error: slot is emtpy." << std::endl;
    }
    this->slot[idx]->use(target);
}
