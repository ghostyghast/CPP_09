/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:31:52 by amaligno          #+#    #+#             */
/*   Updated: 2025/06/19 20:53:17 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>

using std::string;
using std::ifstream;
using std::cout;
using std::cerr;

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const char *input)
{
	csvToMap();
	this->_input_file.exceptions(ifstream::badbit);
	this->_input_file.open(input);
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	(void)copy;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	(void)copy;
	return (*this);
}

void	BitcoinExchange::csvToMap()
{
	ifstream	db_file("data.csv");

	for (string line; db_file >> line;)
	{
		size_t	comma = line.find(',');
		string	date = line.substr(0, comma);
		string	value = line.substr(comma);
		
		this->_db[date] = atof(value.c_str());
	}
}

void	BitcoinExchange::output()
{
	for (string line; getline(this->_input_file, line);)
	{
		size_t	sep = line.find(" | ");
		if (sep == string::npos)
		{
			cerr << "Error: bad input => " << line << '\n';
			continue;
		}
		Date	date(line.substr(0, sep));
		float	value = atof(line.substr(sep + 3).c_str());

		if (date.getTime() == -1)
		{
			cerr << "Error: bad input => " << line << '\n';
			continue;
		}
		if (value < 0 || value > 1000)
		{
			if (value < 0)
				cerr << "Error: not positive number.\n";
			else
				cerr << "Error: too large a number.";
			continue;
		}
		cout << date << " => " << value << " = " << "\n";
	}
}