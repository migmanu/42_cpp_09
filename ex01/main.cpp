/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:35:24 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/07/16 14:02:13 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cout << "Error: RPM takes one argument, as per subject's examples."
				  << std::endl;
		return EXIT_FAILURE;
	}
	if (!RPN::validate_arg(av[1]))
	{
		std::cout << "Error" << std::endl;
		return EXIT_FAILURE;
	}
	try
	{
		RPN::calculate_RPN(av[1]);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
