/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:21:10 by amaligno          #+#    #+#             */
/*   Updated: 2025/06/25 19:19:38 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
# define DATE_HPP

# include <string>
# include <ctime>
# include <iostream>

class Date{
	public:
	
		Date();
		Date(const std::string &date);
		Date(const time_t &date);
		~Date();
		Date(const Date &copy);
		// Date &operator=(const Date &copy);
		// Date &operator=(const time_t &date);
		// Date &operator=(const std::string &date);
	
		std::string	getStr(void) const;
		time_t		getTime(void) const;

		bool	operator==(const Date &date) const;
		bool	operator>(const Date &date) const;
		bool	operator<(const Date &date) const;

		class InvalidDateException : public std::exception
		{
			public:
				const char	*what() const throw() {
					return("invalid date given");
				}
		};

		class invalidFormatException : public std::exception
		{
			public:
				const char	*what() const throw() {
					return("invalid format given");
				}
		};

	private:
		time_t		_value;
		std::string	_str;

		time_t		strToTime(const std::string str) const;
		std::string	timeToStr(const time_t time) const;
		std::string	*splitDate(std::string date) const;
};

std::ostream	&operator<<(std::ostream &stream, const Date &date);

#endif