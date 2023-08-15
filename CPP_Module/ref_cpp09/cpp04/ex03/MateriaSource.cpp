#include "MateriaSource.hpp"

MateriaSource::MateriaSource() 
{
    for (int i  = 0; i < MAX_SLOTSIZE; i++)
        this->slot[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
    for (int i  = 0; i < MAX_SLOTSIZE; i++)
    {
        if (copy.slot[i] != NULL)
            this->slot[i] = copy.slot[i]->clone();
        else
            this->slot[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& copy)
{
    if (this != &copy)
    {
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

MateriaSource::~MateriaSource()
{
    std::cout << "~MateriaSource()" << std::endl;
}

void MateriaSource::learnMateria(AMateria *p)
{
    for(int i = 0; i < MAX_SLOTSIZE; i++)
    {
        if(slot[i] == NULL)
        {
            std::cout << "MateriaSource learned : " << p->getType() << "(in slot [" << i << "])" << std::endl;
            slot[i] = p;
            break;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const & type)
{
    for(int i = 0; i < MAX_SLOTSIZE; i++)
    {
        if(slot[i] != NULL && slot[i]->getType() == type)
           {
                std::cout << "new Materia created : " << type << std::endl;
                return slot[i]->clone();
           }
    }
    std::cout << "MateriaSource error : no such type." << std::endl;
    return NULL;
}
