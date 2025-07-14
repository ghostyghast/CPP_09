/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:25:37 by amaligno          #+#    #+#             */
/*   Updated: 2025/07/14 21:59:25 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

using std::cout;
using std::cerr;

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		cerr << "Error: not enough arguments\n";
		return (1);
	}
	argv[argc] = NULL;
    try
    {
        PmergeMe::sort(argv);
    }
    catch (std::exception   &e)
    {
        cerr << "Error: " << e.what() << '\n';
		return (1);
    }
}