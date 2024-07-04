/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <jmanuelmigoya@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:59:23 by migmanu           #+#    #+#             */
/*   Updated: 2024/07/04 12:41:30 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <ios>
#include <iostream>
#include <map>
#include <string>
#include <utility>

class BitCoinExchange
{
  public:
	~BitCoinExchange(void);
	BitCoinExchange &operator=(const BitCoinExchange &rhs);

	static void run_exchange(const std::string input_file_name);

	class DataBaseException : public std::exception
	{
	  public:
		virtual const char *what() const throw();
	};

	class BadInputFile : public std::exception
	{
	  public:
		virtual const char *what() const throw();
	};

  private:
	BitCoinExchange(void);
	BitCoinExchange(const BitCoinExchange &src);

	// Private methods
	static void create_db();

	// Private attributes
	static std::fstream db_stream;
	static std::map<std::string, float> db;
};
