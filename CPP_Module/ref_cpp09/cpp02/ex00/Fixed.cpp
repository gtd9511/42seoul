#include "Fixed.hpp"

const int Fixed::fractional_bits = 8;
Fixed::Fixed()
:fixed_point_value(0)
{
	 std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed &copy)
:fixed_point_value(copy.fixed_point_value)
{
	 std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& ref)
{
	if (this != &ref)
	{
		std::cout << "Copy assignment operator called\n";
		fixed_point_value = ref.fixed_point_value; 
	}
	return *this;
}

Fixed::~Fixed()
{ 
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return this->fixed_point_value;
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_point_value = raw;
}