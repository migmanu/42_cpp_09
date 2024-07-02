/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <jmanuelmigoya@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:47:07 by migmanu           #+#    #+#             */
/*   Updated: 2024/07/02 20:38:04 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <string>
#include <utility>

std::map<std::string, float> create_map()
{
	std::map<std::string, float> map;
	std::fstream file;
	file.open("data.csv", std::ios::in);
	std::string line;
	std::getline(file, line); // ignore first line
	while (getline(file, line))
	{
		map.insert(
			std::make_pair(line.substr(0, 10), std::atof(line.substr(11).c_str())));
	}
	file.close();
	return map;
}

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return EXIT_FAILURE;
	}
	std::map<std::string, float> map = create_map();
	std::fstream input_file;
	input_file.exceptions(std::ifstream::failbit);
	try
	{
		input_file.open(av[1], std::ios::in);
		input_file.close();
	}
	catch (std::exception &e)
	{
		std::cout << "Error: could not open file: " << e.what() << std::endl;
	}
	return 0;
}
