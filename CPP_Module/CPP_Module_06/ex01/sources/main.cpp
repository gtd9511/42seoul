/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:05:09 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/30 21:19:06 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

int	main(void)
{
	Data	data;
	Data*	data_ptr;

	uintptr_t	raw_data;
	uintptr_t	raw_ptr_data;

	Data*	ret_data;
	Data*	ret_ptr_data;

	data.name = "original data";
	data_ptr = new Data();

	std::cout << "Data			: " << &data << std::endl;
	std::cout << "Data_ptr		: " << data_ptr << std::endl;

	raw_data = Serializer::serialize(&data);
	raw_ptr_data = Serializer::serialize(data_ptr);

	std::cout << "Raw data		: " << raw_data << std::endl;
	std::cout << "Raw_ptr data		: " << raw_ptr_data << std::endl;

	ret_data = Serializer::deserialize(raw_data);
	ret_ptr_data = Serializer::deserialize(raw_ptr_data);

	std::cout << "Desiralized Data	: " << ret_data << std::endl;
	std::cout << "Desiralized Data	: " << ret_ptr_data << std::endl;

	std::cout << data.name << std::endl;
	std::cout << ret_data->name << std::endl;

	delete data_ptr;
	return (0);
}
