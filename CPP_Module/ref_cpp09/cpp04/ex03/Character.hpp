#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Floor.hpp"

class Floor;

class Character : public ICharacter
{
    private:
        std::string name;
        static const int MAX_SLOTSIZE = 4;
        AMateria *slot[MAX_SLOTSIZE];
        static Floor floor;
    public:
        Character(const std::string name);
        Character(const Character &copy);
        Character &operator=(const Character &copy);
        ~Character();
        
	    virtual std::string const &getName() const;
	    virtual void equip(AMateria *m);
	    virtual void unequip(int idx);
	    virtual void use(int idx, ICharacter &target);
};