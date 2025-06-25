/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:28:00 by amaligno          #+#    #+#             */
/*   Updated: 2025/06/20 19:45:07 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"
#include <cstdlib>
#include <sstream>

using std::string;

Date::Date()
{
}

Date::Date(const std::string &date)
{
	this->_str = date;
	this->_value = strToTime(date);
}

Date::Date(const time_t &date)
{
	this->_value = date;
	this->_str = timeToStr(date);
}

Date::~Date()
{
}

Date::Date(const Date &copy)
{
	this->_str = copy.getStr();
	this->_value = copy.getTime();
}

string	Date::getStr(void) const
{
	return (this->_str);
}

time_t	Date::getTime(void) const
{
	return (this->_value);
}

// Date	&Date::operator=(const time_t &date)
// {
// 	this->_value = date;
// 	this->_str = this->timeToStr(date);
// }

// Date	&Date::operator=(const string &date)
// {
// 	this->_str = date;
// 	this->_value = strToTime(date);
// }

bool	Date::operator==(const Date &date) const
{
	return (this->_value == date._value);
}

bool	Date::operator<(const Date &date) const
{
	return (this->_value < date._value);
}

bool	Date::operator>(const Date &copy) const
{
	return (this->_value > copy._value);
}

std::ostream	&operator<<(std::ostream &stream, const Date &date)
{
	stream << date.getStr();
	return (stream);
}

time_t	Date::strToTime(const std::string str) const
{
	std::tm	time;
	std::tm	new_time;
	string *tokens = this->splitDate(str);

	memset(&time, 0, sizeof(std::tm));

	if (!tokens)
		return (-1);

	std::cout << "Tokens: ";
	for (int i = 0; i < 3; i++)
		std::cout << tokens[i] << ", ";
	std::cout << '\n';
	time.tm_year = strtod(tokens[0].c_str(), NULL) - 1900; 
	time.tm_mon = strtod(tokens[1].c_str(), NULL);
	time.tm_mday = strtod(tokens[2].c_str(), NULL);
	delete[] tokens;

	new_time = time;
	mktime(&new_time);
	if (time != new_time)
		return (-1);
	return (mktime(&time));
}

string	Date::timeToStr(const time_t time) const
{
	std::stringstream ss;
	std::tm *tm = localtime(&time);

	if (!tm)
		return (ss.str());
	
	ss << tm->tm_year << '-' << tm->tm_mon << '-' << tm->tm_mday;
	
	return (ss.str());
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
		date.erase(0, pos + token.size());
	}
	return tokens;
}

bool	operator!=(const std::tm &tm1, const std::tm &tm2)
{
	return (
		tm1.tm_mday == tm2.tm_mday		&&
		tm1.tm_mon == tm2.tm_mon		&&
		tm1.tm_year == tm2.tm_year
	);
}