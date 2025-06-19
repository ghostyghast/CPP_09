/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:28:00 by amaligno          #+#    #+#             */
/*   Updated: 2025/06/19 20:44:54 by amaligno         ###   ########.fr       */
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
	size_t	start = 0;
	size_t	end = 0;
	int		date_pos = 0;

	while (true)
	{
		if ((end = str.find('-', start) == string::npos))
			end = str.size();
		string	sub = str.substr(start, end);
		int		val = atol(sub.c_str());
		switch (date_pos)
		{
			case 0:
				time.tm_year = val - 1900; 
				break;
			case 1:
				time.tm_mon = val;
				break;
			case 2:
				time.tm_mday = val;
				return (std::mktime(&time));
		}
		date_pos += 1;
		start = end;
	}
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