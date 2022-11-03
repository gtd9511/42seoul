#!/bin/bash
echo -e "\033[32;1m"unit-test"\033[m"
read $a
git clone https://github.com/alelievr/libft-unit-test.git
cd libft-unit-test/
sed -i "" 's/LIBFTDIR	=	..\/libft/LIBFTDIR	=	..\//' Makefile
arch x86_64 make f
cd ..
echo -e "\033[32;1m"libftTester"\033[m"
read $a
git clone https://github.com/Tripouille/libftTester.git
cd libftTester/
arch x86_64 make a
cd ..
rm -rf Libftest/ libft-war-machine/ libft-unit-test/ libftTester/
echo -e "\033[32;1m"make fclean"\033[m"
read $a
arch x86_64 make
arch x86_64 make fclean
ls
echo -e "\033[32;1m"make clean"\033[m"
read $a
arch x86_64 make
make clean
ls
echo -e "\033[32;1m"make all"\033[m"
read $a
arch x86_64 make all
ls
echo -e "\033[32;1m"make bonus"\033[m"
read $a
arch x86_64 make bonus
ls
echo -e "\033[32;1m"relink"\033[m"
read $a
arch x86_64 make
echo -e "\033[32;1m"DONE"\033[m"
