/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <jmanuelmigoya@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:08:59 by migmanu           #+#    #+#             */
/*   Updated: 2024/07/09 12:17:52 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validators.hpp"
#include <cstdlib>

bool is_valid_characters(const std::string &line)
{
	for (std::string::const_iterator it = line.begin(); it != line.end(); ++it)
	{
		if (!isdigit(*it) && *it != '-' && *it != '|' && *it != '.' && *it != ' ' &&
			*it != ',')
			return false;
		if (line[10] != ' ' && line[11] != '|' && line[12] != '|')
			return false;
	}
	return true;
}

bool is_valid_date(const std::string &date)
{
	struct tm tm = {};
	char buf[11];

	if (strptime(date.c_str(), "%Y-%m-%d", &tm) == NULL)
		return false;

	mktime(&tm);

	strftime(buf, sizeof(buf), "%Y-%m-%d", &tm);

	return date == buf;
}

// RETURN CODE:
// 0: OK
// 1: too big
// 2: not positive number
int is_valid_nbr(const std::string &str)
{
	if (str.length() == 1 && str[0] == '0')
		return 0;
	if (str.find('.', 1) == std::string::npos) // for integers
	{
		if (str.length() > 4)
			return 1;
		long nbr = std::atol(str.c_str());
		if (nbr > 1000)
			return 1;
		if (nbr < 1)
			return 2;
	}
	else // for floats
	{
		if (str.length() > 8)
			return 1;
		float nbr = std::atof(str.c_str());
		if (nbr > 1000)
			return 1;
		if (nbr <= 0)
			return 2;
	}
	return 0;
}

bool is_valid_line(const std::string &line)
{
	if (line.length() < 14 || !is_valid_date(line.substr(0, 10)) || !is_valid_characters(line))
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return false;
	}
	switch (is_valid_nbr(line.substr(13)))
	{
	case 0: {
		break;
	}
	case 1: {
			std::cout << "Error: too large a number." << std::endl;
			return false;
		}
	case 2: {
			std::cout << "Error: not a positive number" << std::endl;
			return false;
		}
	}
	return true;
}
