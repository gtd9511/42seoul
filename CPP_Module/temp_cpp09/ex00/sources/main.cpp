/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:48:40 by sanghan           #+#    #+#             */
/*   Updated: 2023/08/01 16:29:01 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

// void leaks()
// {
// 	system("leaks btc");
// }

int main(int argc, char* argv[])
{
	// atexit(leaks);
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (0);
	}

	BitcoinExchange bitcoinex;

	BitcoinExchange exchange("Bitstamp");

	// std::cout << exchange << std::endl;
	return 0;
}
