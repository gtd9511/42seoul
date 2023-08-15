#ifndef FIXED_POINT_HPP
#define FIXED_POINT_HPP

#include <iostream>

class Fixed{
private:
	int fixed_point_value;
	static const int fractional_bits;

public:
	Fixed();
	Fixed(Fixed &copy);
	Fixed &operator=(const Fixed &t);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif