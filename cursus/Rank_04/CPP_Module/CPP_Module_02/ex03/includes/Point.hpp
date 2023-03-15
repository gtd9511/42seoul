/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:26:30 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/14 15:15:46 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	Fixed const	x_;
	Fixed const	y_;

public:
	Point(void);
	~Point(void);
	Point(float const x, float const y);
	Point(const Point &obj);
	Point& operator=(const Point& obj);
	Fixed	getX(void) const;
	Fixed	getY(void) const;
	static Fixed 	getArea(Point const &p1, Point const &p2, Point const &p3);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
