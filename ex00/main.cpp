/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:32:21 by amaligno          #+#    #+#             */
/*   Updated: 2025/06/19 15:40:40 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"
# include <iostream>

using std::cout;
using std::cerr;

int	main(int argc, char **argv)
{
	try
	{
		if (argc < 2)
			throw std::ifstream::failure("");
		BitcoinExchange	exchange(argv[1]);
		exchange.output();
	}
	catch (std::ifstream::failure& e)
	{
		cerr << "Error: could not open file.\n";
	}
	catch (std::exception& e)
	{
		cerr << "Error: " << e.what() << '\n';
	}
}