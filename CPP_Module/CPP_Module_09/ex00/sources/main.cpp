/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:48:40 by sanghan           #+#    #+#             */
/*   Updated: 2023/08/02 20:57:32 by sanghan          ###   ########.fr       */
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
	BitcoinExchange bitcoinex;

	if (argc != 2)
	{
		std::cerr << "Error: could not open input file." << std::endl;
		return (0);
	}
	if(bitcoinex.getData())
		return (0);
	if(bitcoinex.checkInputFile(argv[1]))
		return (0);
	bitcoinex.setData(argv[1]);
	return (0);
}
