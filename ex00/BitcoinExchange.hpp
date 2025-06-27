/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:32:04 by amaligno          #+#    #+#             */
/*   Updated: 2025/06/27 13:55:24 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <map>
# include <string>
# include <fstream>
# include <iostream>
# include "Date.hpp"

class BitcoinExchange{
	public:
		BitcoinExchange(const char *input);
		~BitcoinExchange();

		class badInputException : public std::exception
		{
			public:
				badInputException(std::string input) : _what("bad input => " + input) {}
				~badInputException() throw() {}

				const char	*what() const throw() {return this->_what.c_str();}

			private:
				std::string	_what;
		};

		class dateNotFoundException : public std::exception
		{
			public:
				const char	*what() const throw() {
					return("date not in database");
				}
		};

		class largeNumberException : public std::exception
		{
			public:
				const char	*what() const throw() {return "too large a number";}
		};

		class negativeNumberException : public std::exception
		{
			public:
				const char	*what() const throw() {return "number is negative";}
		};

		void	output();

	private:
		std::ifstream			_input_file;
		std::map<Date, double>	_db;

		void								csvToMap();
		std::map<Date, double>::iterator	find_date(const Date &date);

		BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		BitcoinExchange(const BitcoinExchange &copy);
		
};

#endif