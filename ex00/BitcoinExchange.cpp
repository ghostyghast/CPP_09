/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:31:52 by amaligno          #+#    #+#             */
/*   Updated: 2025/06/27 16:04:54 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <limits>

using std::string;
using std::ifstream;
using std::cout;
using std::cerr;

// Constructors/Destructor

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const char *input)
{
	csvToMap();
	this->_input_file.exceptions(ifstream::badbit);
	this->_input_file.open(input);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	(void)copy;
}

BitcoinExchange::~BitcoinExchange()
{
}

// Operator Overloads

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	(void)copy;
	return (*this);
}

// Methods

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
			this->_db[date] = strtod(value.c_str(), NULL);
		}
		catch(std::exception &e) 
		{
			cout << "Error: " << e.what() << '\n';
		}
	}
	
	// for (std::map<Date, double>::iterator it = this->_db.begin(); it != this->_db.end(); it++)
	// {
	// 	cout << "Date: " << it->first << ", " << asctime(&it->first.getTm()) << " => " << it->second <<'\n';
	// }
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
			string	value_token = line.substr(sep + 3);	
			if (value_token.empty())
				throw(badInputException(line));

			char	*str;
			float	value = strtod(value_token.c_str(), &str);
			if (*str || value > std::numeric_limits<float>().max())
				throw (badInputException(value_token));
			if (!value)
				throw (nullNumberException());
			if (value < 0)
				throw (negativeNumberException());
			if (value >= 1000)
				throw (largeNumberException());

			// cout << "Date found: " << this->find_date(date)->first << '\n';
			float	new_value = value * this->find_date(date)->second;
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

	if (it == this->_db.end() || it == this->_db.begin())
		throw(dateNotFoundException());
	
	return (--it);
}

// Exceptions----------------------

BitcoinExchange::badInputException::badInputException(string input) : _what("bad input => " + input) {}

BitcoinExchange::badInputException::~badInputException() throw() {}

const char	*BitcoinExchange::badInputException::what() const throw()
{
	return(this->_what.c_str());
}

const char	*BitcoinExchange::nullNumberException::what() const throw()
{
	return("number is zero");
}

const char	*BitcoinExchange::largeNumberException::what() const throw()
{
	return("too large a number");
}

const char	*BitcoinExchange::negativeNumberException::what() const throw()
{
	return("number is negative");
}

const char	*BitcoinExchange::dateNotFoundException::what() const throw()
{	
	return("date not in database");
}