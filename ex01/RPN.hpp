/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:51:49 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/07/16 14:01:59 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <stack>
#include <string>

class RPN
{
  public:
	~RPN(void);
	static bool validate_arg(std::string arg);
	static void calculate_RPN(std::string arg);

  private:
	RPN(void);
	RPN(const RPN &src);
	RPN &operator=(const RPN &rhs);
};
