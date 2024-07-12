/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:35:24 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/07/12 17:00:25 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>

bool validate_args(std::string arg)
{
	std::string operators = "+-*/";
	int n_digits = 0;
	int n_operators = 0;
	for (std::string::iterator it = arg.begin(); it != arg.end(); it++)
	{
		if (std::isspace(*it))
			continue;
		else if (std::isdigit(*it))
			n_digits++;
		else if (operators.find(*it) != std::string::npos)
			n_operators++;
		else
			return false;
	}
	if (n_operators + 1 != n_digits)
		return false;
	return true;
}

void resolve(std::string arg)
{
	std::stack<int> stk;
	for (std::string::iterator it = arg.begin(); it != arg.end(); it++)
	{
		if (std::isspace(*it))
		{
			continue;
		}
		if (std::isdigit(*it))
		{
			stk.push(*it - '0');
		}
		else
		{
			int a = stk.top();
			stk.pop();
			int b = stk.top();
			stk.pop();
			switch (std::string("+-*/").find(*it))
			{
			case 0: {
				stk.push(b + a);
				break;
			}
			case 1: {
				stk.push(b - a);
				break;
			}
			case 2: {
				stk.push(b * a);
				break;
			}
			case 3: {
				if (a == 0 && b == 0)
					throw std::invalid_argument("Error: division by zero!");
				stk.push(b / a);
				break;
			}
			}
		}
	}
	std::cout << "result is: " << stk.top() << std::endl;
}

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cout << "Error: RPM takes one argument, as per subject's examples."
				  << std::endl;
		return EXIT_FAILURE;
	}
	if (!validate_args(av[1]))
	{
		std::cout << "Error" << std::endl;
		return EXIT_FAILURE;
	}
	try {
		resolve(av[1]);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
