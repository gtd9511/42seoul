/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:23:45 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/24 14:40:49 by sanghan          ###   ########.fr       */
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
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif
