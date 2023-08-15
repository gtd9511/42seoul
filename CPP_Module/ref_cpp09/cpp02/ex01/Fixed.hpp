#ifndef FIXED_POINT_HPP
#define FIXED_POINT_HPP

#include <iostream>
#include <cmath>

class Fixed{
private:

	int fixed_point_value;
	static const int fractional_bits;
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed &t);
	~Fixed();

	float toFloat(void)const;
	int toInt(void)const;
	int getRawBits(void) const;
	void setRawBits(int const raw);
	void setFractionBits(int const fractions);
};
std::ostream& operator<<(std::ostream& out, const Fixed& f);
#endif