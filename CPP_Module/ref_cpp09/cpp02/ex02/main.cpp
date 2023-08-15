#include "Fixed.hpp"

int main( void ) {
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	Fixed c;
	std::cout << "a == c? " << (a == c) << "\n";
	std::cout << "a != c? "<< (a != c) << "\n";
}
{
	std::cout << "\n\ntest 2 \n\n";
	Fixed f1(3);
	Fixed f2(4.1f);

	std::cout<< "(f1++ + f2) = "<<  (f1++ + f2) << "\n";
	std::cout << "(f1 + f2) = " << (f1 + f2) << "\n";
	f1 = 3;
	std::cout<< "(++f1 + f2) = " << (++f1 + f2) << "\n";



	std::cout<< f1 * f2 << "\n";
	std::cout<< f1 + f2 << "\n";
	std::cout<< f1 - f2 << "\n";
	std::cout<< f1 / f2 << "\n";

	std::cout<<  (f1 > f2) << "\n";
	std::cout<< (f1 < f2) << "\n";
	std::cout<< (f1 >= f2) << "\n";
	std::cout<< (f1 <= f2) << "\n";

	std::cout<< (f1 == f2) << "\n";
	std::cout<< (f1 != f2) << "\n";

	

}
	return 0;
}