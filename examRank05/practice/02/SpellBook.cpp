#include "SpellBook.hpp"

SpellBook::SpellBook() {}
SpellBook::~SpellBook()
{
	std::map<std::string, ASpell *>::iterator it_begin = arr_spell.begin();
	std::map<std::string, ASpell *>::iterator it_end = arr_spell.end();
	while (it_begin != it_end)
	{
		delete it_begin->second;
		++it_begin;
	}
	this->arr_spell.clear();
}

void SpellBook::learnSpell(ASpell *spell_ptr)
{
	if (spell_ptr)
		arr_spell.insert(std::pair <std::string, ASpell *>(spell_ptr->getName(), spell_ptr->clone()));

}

void SpellBook::forgetSpell(std::string const &name)
{
	std::map<std::string, ASpell *>::iterator itr = arr_spell.find(name);
	if (itr != arr_spell.end())
		delete itr->second;
	arr_spell.erase(name);
}

ASpell* SpellBook::createSpell(std::string const &name)
{
	std::map<std::string, ASpell *>::iterator itr = arr_spell.find(name);
	if (itr != arr_spell.end())
		return arr_spell[name];
	return NULL;
}
