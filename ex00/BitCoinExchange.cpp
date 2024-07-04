/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <jmanuelmigoya@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:06:30 by migmanu           #+#    #+#             */
/*   Updated: 2024/07/04 12:47:06 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitCoinExchange.hpp"

std::fstream BitCoinExchange::db_stream;
std::map<std::string, float> BitCoinExchange::db;

void BitCoinExchange::run_exchange(const std::string input_file_name)
{
	std::cout << "arg is: " << input_file_name << std::endl;
	create_db();
}

BitCoinExchange::~BitCoinExchange(void)
{
	return;
}

const char *BitCoinExchange::DataBaseException::what() const throw()
{
	return "Data base error. Check file is called 'data.csv'. Note: format "
		   "is not checked for this file, you must ensure it adheres to "
		   "requirements.";
}

const char *BitCoinExchange::BadInputFile::what() const throw()
{
	return "Input file is incorrect: file must follow this format: \"date | value\"";
}

void BitCoinExchange::create_db()
{
	BitCoinExchange::db_stream.exceptions(std::ifstream::failbit);
	try
	{
		db_stream.open("data.csv", std::ios::in);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: data base file error!:" << std::endl;
		throw BitCoinExchange::DataBaseException();
	}
	std::string line;
	std::getline(db_stream, line); // ignore first line
	while (getline(db_stream, line))
	{
		db.insert(
			std::make_pair(line.substr(0, 10), std::atof(line.substr(11).c_str())));
	}
	db_stream.close();
}
