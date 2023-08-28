#pragma once

#include "ASpell.hpp"
#include <map>

class SpellBook
{
	private:
		std::map<std::string, ASpell *> arr_spell;

		SpellBook(SpellBook const *obj);
		SpellBook &operator=(SpellBook const *obj);

	public:
		SpellBook();
		~SpellBook();

		void learnSpell(ASpell *);
		void forgetSpell(std::string const &name);
		ASpell* createSpell(std::string const &name);
};
