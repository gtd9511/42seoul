/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:48:40 by sanghan           #+#    #+#             */
/*   Updated: 2023/08/01 20:46:43 by sanghan          ###   ########.fr       */
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
	int error_flag = 0;

	if (argc != 2)
	{
		std::cerr << "Error: could not open input file." << std::endl;
		return (0);
	}
	// (void) argv;
	error_flag = bitcoinex.getData();
	if (error_flag == 1)
		return (0);
	error_flag = bitcoinex.checkInputFile(argv[1]);
	if (error_flag == 1)
		return (0);
	bitcoinex.setData(argv[1]);

	return (0);
}
