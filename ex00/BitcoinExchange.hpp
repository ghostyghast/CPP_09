/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:32:04 by amaligno          #+#    #+#             */
/*   Updated: 2025/06/19 19:23:55 by amaligno         ###   ########.fr       */
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

		void	output();

	private:
		std::ifstream			_input_file;
		std::map<Date, float>	_db;

		void	parseDate(const std::string date);
		void	inputToMap(const std::string filename);
		void	csvToMap();

		BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		BitcoinExchange(const BitcoinExchange &copy);
		
};

#endif