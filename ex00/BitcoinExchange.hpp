/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:32:04 by amaligno          #+#    #+#             */
/*   Updated: 2025/06/27 16:02:34 by amaligno         ###   ########.fr       */
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
				badInputException(std::string input);
				~badInputException() throw();

				const char	*what() const throw();

			private:
				std::string	_what;
		};

		class dateNotFoundException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		
		class nullNumberException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class largeNumberException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class negativeNumberException : public std::exception
		{
			public:
				const char	*what() const throw();
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