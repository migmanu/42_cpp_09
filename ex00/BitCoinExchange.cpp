/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <jmanuelmigoya@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:06:30 by migmanu           #+#    #+#             */
/*   Updated: 2024/07/09 13:24:35 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitCoinExchange.hpp"
#include <iomanip>
#include <iterator>

std::fstream BitCoinExchange::db_stream;
std::fstream BitCoinExchange::input_stream;
std::map<std::string, float> BitCoinExchange::db;

void BitCoinExchange::run_exchange(const std::string file_name)
{
	create_db();
	open_input_file(file_name);
	print_values();
}

BitCoinExchange::~BitCoinExchange(void)
{
	if (db_stream.is_open())
	{
		db_stream.close();
	}
	if (input_stream.is_open())
	{
		input_stream.close();
	}
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
	while (1)
	{
		try
		{
			getline(db_stream, line);
			db.insert(std::make_pair(line.substr(0, 10),
									 std::atof(line.substr(11).c_str())));
		}
		catch (std::exception &e)
		{
			input_stream.clear(); // Clear error state flags
			break;
		}
	}
	db_stream.close();
}

void BitCoinExchange::open_input_file(std::string file_name)
{
	BitCoinExchange::input_stream.exceptions(std::ifstream::failbit);
	try
	{
		input_stream.open(file_name.c_str(), std::ios::in);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: could not open file." << std::endl;
		throw BitCoinExchange::BadInputFile();
	}
}

void BitCoinExchange::print_values(void)
{
	BitCoinExchange::input_stream.exceptions(std::ifstream::goodbit);
	std::string line;
	getline(input_stream, line);
	if (line != "date | value")
	{
		std::cout << "Error: input file must have header: \"date | value\""
				  << std::endl;
		return;
	}
	while (getline(input_stream, line))
	{
		if (is_valid_line(line))
		{
			std::string date = line.substr(0, 10);
			float qty = std::atof(line.substr(13).c_str());
			std::map<std::string, float>::iterator it = db.lower_bound(date);
			if (it != db.begin() && (it)->first != date)
				--it;
			std::cout << std::setprecision(7) << date << " => " << qty << " = "
					  << qty * it->second << std::endl;
		}
	}
	input_stream.close();
}
