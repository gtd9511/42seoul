#pragma once
#ifndef FragTrap_HPP
# define FragTrap_HPP

#include "ClapTrap.hpp"
class FragTrap : public ClapTrap
{
private:
enum{
	INIT_HP = 100,
    INIT_EP = 100,
	INIT_AD = 30
};
        
public:
        FragTrap(std::string name);
        FragTrap(const FragTrap& copy);
        FragTrap& operator=(const FragTrap& copy);
        ~FragTrap();

        void attack(const std::string &target);//오버라이딩
        void highFiveGuys();
        void showInfo() const ; //오버라이딩

};

#endif // FragTrap_HPP