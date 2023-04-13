/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:38:09 by sanghan           #+#    #+#             */
/*   Updated: 2023/04/13 22:31:17 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main() {
  std::string s[6] = { "42", "Seoul", "cpp", "module", "07", "sanghan" };
  int i[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  double d[10] = { 0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
  char c[12] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l' };

  std::cout << "String Iteration : ";
  ::iter(s, 6, ::print);
  std::cout << std::endl;
  std::cout << "Int Iteration : ";
  ::iter(i, 10, ::print);
  std::cout << std::endl;
  std::cout << "Double Iteration : ";
  ::iter(d, 10, ::print);
  std::cout << std::endl;
  std::cout << "Char Iteration : ";
  ::iter(c, 12, ::print);
  std::cout << std::endl;
  return 0;
}
