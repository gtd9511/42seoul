/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:08:47 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/10 18:17:48 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int	main(int argc, char *argv[])
{
	Harl h;

	if (argc != 2)
	{
		std::cout << "Invalid arguments" << std::endl;
		return (1);
	}
	h.complain(argv[1]);
	return (0);
}
