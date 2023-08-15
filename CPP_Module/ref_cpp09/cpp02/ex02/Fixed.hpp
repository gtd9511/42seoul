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

	static Fixed& max(Fixed &fixed1, Fixed &fixed2);
	static const Fixed& max(const Fixed &fixed1, const Fixed &fixed2);
	static Fixed& min(Fixed &fixed1, Fixed &fixed2);
	static const Fixed& min(const Fixed &fixed1, const Fixed &fixed2);
	
	float toFloat(void)const;
	int toInt(void)const;
	int getRawBits(void) const;
	void setRawBits(int const raw);
	void setFractionBits(int const fractions);

	bool operator > (const Fixed &fixed)const;
	bool operator < (const Fixed &fixed)const;
	bool operator >= (const Fixed &fixed)const;
	bool operator <= (const Fixed &fixed)const;
	bool operator == (const Fixed &fixed)const;
	bool operator != (const Fixed &fixed)const;


	Fixed operator + (const Fixed &fixed)const;
	Fixed operator - (const Fixed &fixed)const;
	Fixed operator * (const Fixed &fixed)const;
	Fixed operator / (const Fixed &fixed)const;

	Fixed &operator++ ();
	Fixed operator++ (int);
	Fixed &operator-- ();
	Fixed operator-- (int);

};
std::ostream& operator<<(std::ostream& out, const Fixed& f);
#endif