#include"SpellBook.hpp"

SpellBook::SpellBook() {}
SpellBook::~SpellBook()
{
	std::map<std::string, ASpell *>::iterator itr_begin = arr_spell.begin();
	std::map<std::string, ASpell *>::iterator itr_end = arr_spell.end();
	while (itr_begin != itr_end)
	{
		delete itr_begin->second;
		++itr_begin;
	}
	this->arr_spell.clear();
}

void SpellBook::learnSpell(ASpell *aspell_ptr)
{
	if (aspell_ptr)
		arr_spell.insert(std::pair<std::string, ASpell *>(aspell_ptr->getName(), aspell_ptr->clone()));
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

