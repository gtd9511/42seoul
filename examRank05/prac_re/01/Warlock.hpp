#pragma once

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

class Warlock
{
	private:
		std::string name;
		std::string title;
		Warlock();
		Warlock(Warlock const &obj);
		Warlock &operator=(Warlock const &boj);

		std::map<std::string, ASpell *> arr;

	public:
		Warlock(std::string const &name, std::string const &title);
		~Warlock();
		std::string const &getName() const;
		std::string const &getTitle() const;

		void setTitle(std::string const &title);

		void introduce() const;

		void learnSpell(ASpell *aspell_ptr);
		void forgetSpell(std::string const &name);
		void launchSpell(std::string const &name, ATarget const &atarget_ref);

};
