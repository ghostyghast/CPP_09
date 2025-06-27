/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:21:10 by amaligno          #+#    #+#             */
/*   Updated: 2025/06/27 16:13:19 by amaligno         ###   ########.fr       */
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
		~Date();
		Date(const Date &copy);
		Date &operator=(const Date &copy);

		const std::tm		&getTm(void) const;
		const std::string	&getStr(void) const;
		const time_t		&getTime(void) const;

		bool	operator==(const Date &date) const;
		bool	operator>(const Date &date) const;
		bool	operator<(const Date &date) const;

		class InvalidDateException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class invalidFormatException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

	private:
		time_t		_value;
		std::tm		_tm;
		std::string	_str;

		time_t		strToTime(const std::string str) const;
		std::string	timeToStr(const time_t time) const;
		std::string	*splitDate(std::string date) const;
};

std::ostream	&operator<<(std::ostream &stream, const Date &date);

#endif