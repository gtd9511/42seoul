/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:29:22 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/14 15:47:42 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed(void): value(0)
{
}

Fixed::~Fixed(void)
{
}

Fixed::Fixed(const Fixed& obj)
{
	*this = obj;
}

Fixed&	Fixed::operator=(const Fixed& obj)
{
	setRawBits(obj.getRawBits());
	return (*this);
}

Fixed::Fixed(const int num)
{
	setRawBits(num << this->bits);
}

Fixed::Fixed(const float num)
{
	setRawBits(roundf(num * (1 << this->bits)));

}

int	Fixed::getRawBits( void ) const
{
	return (this->value);
}

void	Fixed::setRawBits( const int raw )
{
	this->value = raw;
}

int	Fixed::toInt( void ) const
{
	return (getRawBits() >> this->bits);
}

float	Fixed::toFloat( void ) const
{
	return ((float)getRawBits() /(1 << this->bits));
}

bool	Fixed::operator>(Fixed const &ref) const
{
	return (this->getRawBits() > ref.getRawBits());
}

bool	Fixed::operator<(Fixed const &ref) const
{
	return (this->getRawBits() < ref.getRawBits());
}

bool	Fixed::operator>=(Fixed const &ref) const
{
	return (this->getRawBits() >= ref.getRawBits());
}

bool	Fixed::operator<=(Fixed const &ref) const
{
	return (this->getRawBits() <= ref.getRawBits());
}

bool	Fixed::operator==(Fixed const &ref) const
{
	return (this->getRawBits() == ref.getRawBits());
}

bool	Fixed::operator!=(Fixed const &ref) const
{
	return (this->getRawBits() != ref.getRawBits());
}

Fixed	Fixed::operator+(Fixed const &ref) const
{
	Fixed ret (this->toFloat() + ref.toFloat());
	return (ret);
}

Fixed	Fixed::operator-(Fixed const &ref) const
{
	Fixed ret (this->toFloat() - ref.toFloat());
	return (ret);
}

Fixed	Fixed::operator*(Fixed const &ref) const
{
	Fixed ret (this->toFloat() * ref.toFloat());
	return (ret);
}

Fixed	Fixed::operator/(Fixed const &ref) const
{
	if (ref.getRawBits() == 0)
	{
		std::cout << "Can't be divided by zero" << std::endl;
		return (Fixed());
	}
	else
	{
		Fixed ret (this->toFloat() / ref.toFloat());
		return (ret);
	}
}

Fixed&	Fixed::operator++(void)
{
	this->value++;
	return (*this);
}

const Fixed	Fixed::operator++(int)
{
	const Fixed	old = *this;

	this->value++;
	return (old);
}

Fixed&	Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

const Fixed	Fixed::operator--(int)
{
	const Fixed	old = *this;

	this->value--;
	return (old);
}

Fixed&	Fixed::min(Fixed &ref1, Fixed &ref2)
{
	if (ref1 <= ref2)
		return (ref1);
	else
	 	return (ref2);
}

const Fixed&	Fixed::min(Fixed const &ref1, Fixed const &ref2)
{
	if (ref1 <= ref2)
		return (ref1);
	else
	 	return (ref2);
}

Fixed&	Fixed::max(Fixed &ref1, Fixed &ref2)
{
	if (ref1 >= ref2)
		return (ref1);
	else
	 	return (ref2);
}

const Fixed&	Fixed::max(Fixed const &ref1, Fixed const &ref2)
{
	if (ref1 >= ref2)
		return (ref1);
	else
	 	return (ref2);
}

std::ostream& operator << (std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

