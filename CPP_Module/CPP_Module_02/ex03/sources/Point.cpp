/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:27:15 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/14 14:39:12 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

Point::Point(void): x_(0), y_(0)
{
}

Point::~Point(void)
{
}

Point::Point(float const x, float const y): x_(x), y_(y)
{
}

Point::Point(const Point &obj): x_(obj.getX()), y_(obj.getY())
{
}

Point& Point::operator=(const Point& obj)
{
	if (this != &obj)
	{
		const_cast<Fixed&>(x_) = obj.getX();
		const_cast<Fixed&>(y_) = obj.getY();
	}
	return (*this);
}

Fixed	Point::getX(void) const
{
	return (this->x_);
}

Fixed	Point::getY(void) const
{
	return (this->y_);
}
