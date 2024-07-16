/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:58:21 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/07/16 14:01:53 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::~RPN(void)
{
	return;
}

bool RPN::validate_arg(std::string arg)
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

void RPN::calculate_RPN(std::string arg)
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
