#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int  main()
{
	{
		Weapon MachineGun = Weapon("MachineGun");		
		HumanA ebang("A_ebang", MachineGun);	
		ebang.attack();
		MachineGun.setType("knife");
		ebang.attack();
	}
	{
		Weapon MachineGun = Weapon("MachineGun");
		HumanB seongmik("B_seongmik");
		seongmik.attack();
		seongmik.setWeapon(MachineGun);
		seongmik.attack();
		MachineGun.setType("revolver");
		seongmik.attack();
	}

std::cout << "\n\n";
{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
}
{	
	Weapon club = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();
}
	return 0;
}