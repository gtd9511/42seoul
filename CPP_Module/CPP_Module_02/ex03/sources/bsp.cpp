/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:27:09 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/14 15:25:06 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"

Fixed Point::getArea(const Point &p1, const Point &p2, const Point &p3)
{
	Fixed	set1;
	Fixed	set2;
	Fixed	big;
	Fixed	small;

	set1 = p1.getX() * p2.getY() + p2.getX() * p3.getY() + p3.getX() * p1.getY();
	set2 = p1.getY() * p2.getX() + p2.getY() * p3.getX() + p3.getY() * p1.getX();
	big = Fixed::max(set1, set2);
	small = Fixed::min(set1, set2);

	return ((big - small) / 2);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	area;
	Fixed	area1;
	Fixed	area2;
	Fixed	area3;

	area = Point::getArea(a, b, c);
	area1 = Point::getArea(a, b, point);
	area2 = Point::getArea(b, c, point);
	area3 = Point::getArea(c, a, point);

	if (area == area1 + area2 + area3 && (area1 * area2 * area3 != 0))
		return (true);
	else
		return (false);
}
