#include "Fixed.hpp"

int power(int base, int e)
{
	if(e == 0)
		return 1;
	return power(base, e - 1) * base;
}

const int Fixed::fractional_bits = 8;
Fixed::Fixed()
:fixed_point_value(0) {  std::cout << "Default constructor called\n";}

Fixed::Fixed(const int value)
:fixed_point_value(value << 8) {std::cout << "Int constructor called : " << std::cout << fixed_point_value << "\n";};

Fixed::Fixed(const float value)
:fixed_point_value(roundf(value * power(2, this->fractional_bits))){std::cout << "Float constructor called : " << std::cout << fixed_point_value<< std::endl;}

Fixed::Fixed(const Fixed &copy)
:fixed_point_value(copy.fixed_point_value) { std::cout << "Copy constructor called\n"; }

Fixed& Fixed::operator=(const Fixed& ref)
{
	// if (this != &ref)
	// {
		std::cout << "Copy assignment operator called\n";
		fixed_point_value = ref.fixed_point_value; 
	// }
	return *this;
}

Fixed::~Fixed()
{ 
	std::cout << "Destructor called\n";
}

float Fixed::toFloat(void)const
{
	return (float)this->fixed_point_value / (float)(1 << fractional_bits);
}

int Fixed::toInt(void)const
{
	return this->fixed_point_value >> (this->fractional_bits);
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

std::ostream& operator<<(std::ostream& out, const Fixed& f)
{
	out << f.toFloat();
	return out;
}