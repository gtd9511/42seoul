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
:fixed_point_value(value << fractional_bits) {std::cout << "Int constructor called : " << std::cout << fixed_point_value << "\n";};

Fixed::Fixed(const float value)
:fixed_point_value(roundf(value * power(2, fractional_bits))){std::cout << "Float constructor called : " << std::cout << fixed_point_value<< std::endl;}

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
	return this->fixed_point_value >> (fractional_bits);
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

bool Fixed::operator > (const Fixed &fixed)const
{
	return (this->getRawBits() > fixed.getRawBits());
}

bool	Fixed::operator < (const Fixed &fixed)const
{
	return (this->getRawBits() < fixed.getRawBits());
}

bool Fixed::operator >= (const Fixed &fixed)const
{
	return (this->getRawBits() >= fixed.getRawBits());
}

bool Fixed::operator <= (const Fixed &fixed)const
{
	return (this->getRawBits() <= fixed.getRawBits());
}

Fixed Fixed::operator + (const Fixed &fixed)const
{
	Fixed temp(this->toFloat() + fixed.toFloat());
	return temp;
}

Fixed Fixed::operator - (const Fixed &fixed)const
{
	Fixed temp(this->toFloat() - fixed.toFloat());
	return temp;
}

Fixed Fixed::operator * (const Fixed &fixed)const
{
	Fixed temp((this->toFloat() * fixed.toFloat()));
	return temp;
}

Fixed Fixed::operator / (const Fixed &fixed)const
{
	Fixed temp(this->toFloat() / fixed.toFloat());
	return temp;
}

Fixed &Fixed::operator++()
{
	fixed_point_value += (1);
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++(*this);
	return temp;
}

Fixed &Fixed::operator--()
{
	fixed_point_value -= (1);
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--(*this);
	return temp;
}

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if(fixed1 > fixed2)
		return fixed1;
	return fixed2;
}

Fixed const &Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	if(fixed1 > fixed2)
		return fixed1;
	return fixed2;
}

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1 < fixed2)
		return fixed1;
	return fixed2;
}

Fixed const &Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1 < fixed2)
		return fixed1;
	return fixed2;
}

bool Fixed::operator== (const Fixed &fixed)const
{
	return fixed.fixed_point_value == this->fixed_point_value;
}

bool Fixed::operator!= (const Fixed &fixed)const
{
	return !(fixed == *this);
}