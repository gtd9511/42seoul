/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghan <sanghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:41:41 by sanghan           #+#    #+#             */
/*   Updated: 2023/03/27 14:23:58 by sanghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("shrubberycreation", 145, 137), _target("no target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("shrubberycreation", 145, 137), _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj): AForm(obj), _target(obj._target)
{
	if (this == &obj)
		return ;
	*this = obj;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	if (this != &obj)
	{
		this->setSigned(obj.getSigned());
		this->_target = obj._target;
	}
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::string	tree;
	std::ofstream	file;

	tree =  "                            ,=!:\n"
			"                            ;!!;\n"
			"                            !*;:!\n"
			"                       :;;; !;;!!;\n"
			"                       !;!=-;;!!!;;\n"
			"                       !!;=;!;;!;;!=;!*   !\n"
			"                     !:;;***!;:;=:~*;;!; ;*\n"
			"                    **=*!;*!;:;;!;:!;;;!*!!\n"
			"                 :~ *!**;!=;!*;;;!;;:-;==!=\n"
			"                 -;:!!!;!;*:~:;;;;:;::;:;:*\n"
			"                  ;*!!!;!;::;:;:;:;::;:!;:!\n"
			"                  *;;;;;!;*::::~:~::;;:;*;*\n"
			"                  !!;;;;;:;;::~:::::::::;;\n"
			"                  *!;::::;:;:;:;~::::~;;;;\n"
			"                  ~;!:~-:~;!;!:~:::::~;!;;\n"
			"                   !;:!!!=~:;;:;::*;;:-;!;\n"
			"                   !!!!***;;;:::;;***!!:;!\n"
			"                   !***;:!=;;:;;!==*****;-\n"
			"                   !!*$##$*!!:;;==@#@!*;;\n"
			"                   .!!@@@=#$;;;;!#*!@@!!;\n"
			"                    !!@@@@##;:::=#@#@@;;;\n"
			"                    ;!*@@@**~~~-!@@@@#::.\n"
			"                    ;;;==*;;~~:,:!@##:::\n"
			"                    ;;::;;~~-~~~:;;~~~:;\n"
			"                    !;:~:-~~~~:~~-,~~~:;\n"
			"                     *!::;:;~-!!;;~::~:;\n"
			"                     :;!!;!!*:!=;::;::;\n"
			"                      ~!;!;;*$$$*:;!;;.\n"
			"                        ;!!!!;;;!!;!!\n"
			"                        *=*!;!;!!!!**\n"
			"                        =$*=$!;!*#*=!\n"
			"                       ~=$=*==#$=!!*!\n"
			"                       ;*$!*=*$*==$*=\n"
			"                       =;=#!*!**=*#=;\n"
			"                        ==#$#!-$=*=!!\n"
			"                        !*$#@#-$##**!\n"
			"                       *=!~$@:--=#!!!:\n"
			"                      ;*=;$#@-;,,$;;*!!\n"
			"                      ;!$:*##@~-$==;*:!\n"
			"                     ;-;;!~==$$$*$;!;!:*\n"
			"                    :~~~*=:@##@#$!!@=!*;!\n"
			"                   :!::;:##@@##@@#@$*;:!;;~\n"
			"                  !*!!*:;!        @=*:~;:!;\n"
			"                  ;**!;!*;         #$;;;;;!\n"
			"                  !=*!**!          =*;;;;=;\n"
			"                   ~**=**          ;!;*:!;\n"
			"                    ==*=!           =**;\n";

	if (!this->getSigned())
		throw (AForm::SignedException());
	else if (executor.getGrade() > this->getExecuteGrade())
		throw (AForm::GradeTooLowException());
	else
	{
		file.open(this->_target + "_shrubbery");
		if (!file)
			std::cout << "Failed to open" << std::endl;
		file << tree;
		file.close();
	}
}
