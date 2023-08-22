/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:12:51 by sanghan           #+#    #+#             */
/*   Updated: 2023/08/22 16:48:42 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	value;
		static const int	bits = 8;

	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed& obj);
		Fixed& operator=(const Fixed& obj);
		Fixed(const int num);
		Fixed(const float num);

		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
		int	toInt( void ) const;
		float	toFloat( void ) const;

		bool	operator>(Fixed const &ref) const;
		bool	operator<(Fixed const &ref) const;
		bool	operator>=(Fixed const &ref) const;
		bool	operator<=(Fixed const &ref) const;
		bool	operator==(Fixed const &ref) const;
		bool	operator!=(Fixed const &ref) const;

		Fixed	operator+(Fixed const &ref) const;
		Fixed	operator-(Fixed const &ref) const;
		Fixed	operator*(Fixed const &ref) const;
		Fixed	operator/(Fixed const &ref) const;

		Fixed	&operator++(void);
		const Fixed	operator++(int);
		Fixed	&operator--(void);
		const Fixed	operator--(int);

		static Fixed	&min(Fixed &ref1, Fixed &ref2);
		static const Fixed	&min(Fixed const &ref1, Fixed const &ref2);
		static Fixed	&max(Fixed &ref1, Fixed &ref2);
		static const Fixed	&max(Fixed const &ref1, Fixed const &ref2);
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif

