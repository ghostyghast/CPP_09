/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:25:37 by amaligno          #+#    #+#             */
/*   Updated: 2025/07/07 22:13:16 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmMergeMe.hpp"
#include <iostream>

using std::cout;
using std::cerr;

int main(int argc, char **argv)
{
	argv[argc] = NULL;
    try
    {
        PmMergeMe::sort(argv);
    }
    catch (std::exception   &e)
    {
        cerr << "Error: " << e.what() << '\n';
    }
	// for (int i = 0; i < 10; i++)
	// {
	// 	cout << i << " => " << PmMergeMe::jacobsthalNumber(i) << '\n';
	// }
}