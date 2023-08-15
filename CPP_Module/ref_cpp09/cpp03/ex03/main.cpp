#include "DiamondTrap.hpp"

int main()
{
	{
		FragTrap ft1("seoyoo");
		ScavTrap st1("yejinam");
		DiamondTrap dt1("ebang");

		dt1.whoAmI();
		dt1.showInfo();
	}
}