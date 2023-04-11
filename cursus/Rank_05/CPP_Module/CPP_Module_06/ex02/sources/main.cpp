/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:05:12 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/30 20:02:41 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"

int	main(void)
{
	Base* randomBase = generate();

	identify(randomBase);
	identify(*randomBase);

	delete randomBase;
	return (0);
}
