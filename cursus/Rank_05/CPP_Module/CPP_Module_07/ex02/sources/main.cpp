/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:38:19 by sanghan           #+#    #+#             */
/*   Updated: 2023/04/27 22:36:16 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"

// void leaks()
// {
//     system("leaks Array");
// }

int main() {
	// atexit (leaks);

	std::cout << "------  test string 1 ------" << std::endl;
	Array<std::string> b(3);

	b[0] = "42seoul";
	b[1] = "cpp";
	b[2] = "hi";

	std::cout << "test 1 b[0] : " << b[0] << std::endl;
	std::cout << "test 1 b size : " << b.size() << std::endl;

	std::cout << "------  test string 2 ------" << std::endl;
	Array<std::string> arr(5);
	arr[0] = "42";
	arr[1] = "Seoul";
	arr[2] = "cpp";
	arr[3] = "module";
	arr[4] = "07";
	std::cout << "test 2 arr size : " << arr.size() << std::endl;
	std::cout << "test 2 arr stringArray : ";
	for (int i = 0; i < 5; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	std::cout << "------  test int  ------" << std::endl;

	Array<int> intArray(10);
	for (int i = 0; i < 10; ++i)
		intArray[i] = i;
	std::cout << "size : " << intArray.size() << std::endl;
	std::cout << "array : ";
	for (int i = 0; i < 10; ++i)
		std::cout << intArray[i] << " ";
	std::cout << std::endl;
	std::cout << "------  test char  ------" << std::endl;
	Array<char> charArray(10);
	for (int i = 0; i < 10; ++i)
		charArray[i] = 'A' + i;

	std::cout << "size : " << charArray.size() << std::endl;
	std::cout << "array : ";
	for (int i = 0; i < 10; ++i)
		std::cout << charArray[i] << " ";
	std::cout << std::endl;

	std::cout << "----- exception test ------" << std::endl;
	try {
		std::cout << "intArray[10] = 10 -> ";
		intArray[10] = 10;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "intArray[-1] = 10 -> ";
		intArray[-1] = 10;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
