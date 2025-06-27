/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:31:52 by amaligno          #+#    #+#             */
/*   Updated: 2025/06/25 22:11:55 by amaligno         ###   ########.fr       */
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
		string	value = line.substr(comma + 1);
		
		try
		{
			this->_db[date] = atof(value.c_str());
		}
		catch(std::exception &e) 
		{
			cout << "Error: " << e.what() << '\n';
		}
	}
	
	cout << "Database: \n";
	for (std::map<Date, float>::iterator it = this->_db.begin(); it != this->_db.end(); it++)
	{
		cout << "Date: " << it->first << '\n';
		cout << "Time_t: " << it->first.getTime() << '\n';
		// cout << "Value: " << it->second << '\n';
	}
}

void	BitcoinExchange::output()
{
	string line;
	while (getline(this->_input_file, line))
	{
		try
		{
			size_t	sep = line.find(" | ");
			if (sep == string::npos)
				throw (badInputException(line));
			Date	date(line.substr(0, sep));
			float	value = atof(line.substr(sep + 3).c_str());

			if (date.getTime() == -1)
				throw (badInputException(date.getStr()));
			if (value < 0)
				throw (negativeNumberException());
			if (value > 1000)
				throw (largeNumberException());

			float	new_value = value * this->find_date(date)->second;
			// cout << "given value: " << value << '\n';
			// cout << "lower bound value: " << this->_db.lower_bound(date)->second << '\n';
			// cout << "lower bound date: " << this->_db.lower_bound(date)->first << '\n';
			cout << date << " => " << value << " = " << new_value << "\n";
		}
		catch (std::exception &e)
		{
			cerr << "Error: " << e.what() << '\n';
		}
	}
}

std::map<Date, double>::iterator	BitcoinExchange::find_date(const Date &date)
{
	std::map<Date, double>::iterator it = this->_db.upper_bound(date);

	if (it == this->_db.end())
		throw(dateNotFoundException());

	return (it);
}