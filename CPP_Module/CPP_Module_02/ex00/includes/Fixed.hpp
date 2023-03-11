/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:55:58 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/11 14:39:53 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					value;
		static const int	bits;

	public:
		Fixed(void);
		Fixed(int);
		~Fixed(void);
		Fixed(const Fixed& mc) // 디폴트 복사 생성자의 형태
		{
			value = mc.value;
		}
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif
