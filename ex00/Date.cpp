/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:28:00 by amaligno          #+#    #+#             */
/*   Updated: 2025/06/27 16:13:07 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"
#include <cstdlib>
#include <cstring>
#include <sstream>

using std::string;

// Constructors / Destructor

Date::Date()
{
}

Date::Date(const std::string &date)
{
	this->_str = date;
	this->_value = strToTime(date);
	this->_tm = *localtime(&this->_value);
}

Date::Date(const Date &copy)
{
	*this = copy;
}

Date::~Date()
{
}

// Operator overloads

Date	&Date::operator=(const Date &copy)
{
	this->_str = copy.getStr();
	this->_value = copy.getTime();
	this->_tm = copy.getTm();	
	return (*this);
}

bool	Date::operator==(const Date &date) const
{
	return (this->_value == date.getTime());
}

bool	Date::operator<(const Date &date) const
{
	return (std::difftime(this->_value, date.getTime()) < 0);
}

bool	Date::operator>(const Date &date) const
{
	return (std::difftime(this->_value, date.getTime()) > 0);
}

std::ostream	&operator<<(std::ostream &stream, const Date &date)
{
	stream << date.getStr();
	return (stream);
}

// Setters / Getters

const string	&Date::getStr(void) const
{
	return (this->_str);
}

const time_t	&Date::getTime(void) const
{
	return (this->_value);
}

const std::tm	&Date::getTm(void) const
{
	return (this->_tm);
}

// Methods

time_t	Date::strToTime(const std::string str) const
{
	std::tm	time = {};
	std::tm	new_time = {};
	string *tokens = this->splitDate(str);
	
	if (!tokens)
		throw (invalidFormatException());
	time.tm_year = strtod(tokens[0].c_str(), NULL) - 1900; 
	time.tm_mon = strtod(tokens[1].c_str(), NULL) - 1;
	time.tm_mday = strtod(tokens[2].c_str(), NULL);
	delete[] tokens;

	new_time = time;
	mktime(&new_time);
	if (time.tm_mday != new_time.tm_mday
		|| time.tm_mon != new_time.tm_mon
		|| time.tm_year != new_time.tm_year)
		throw InvalidDateException();
	return (mktime(&time));
}

string	*Date::splitDate(string date) const
{
	int size = 0;
	
	for (size_t pos = 0; pos < date.size();)
	{
		size += 1;
		pos = date.find('-', pos);
		if (pos == string::npos)
			break;
		pos += 1;
	}
	if (size != 3)
		return (NULL);

	string *tokens = new string[size];

	for (int i = 0; i < size; i++)
	{
		size_t	pos = date.find('-');
		string	token = date.substr(0, pos);
		tokens[i] = token;
		if (pos != string::npos)
			pos += 1;
		date.erase(0, pos);
	}
	return tokens;
}

// Exceptions

const char	*Date::invalidFormatException::what() const throw()
{
	return("invalid format given");
}

const char	*Date::InvalidDateException::what() const throw()
{
	return("invalid date given");
}