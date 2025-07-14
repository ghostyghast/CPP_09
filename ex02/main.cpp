/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:25:37 by amaligno          #+#    #+#             */
/*   Updated: 2025/07/14 18:03:57 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

using std::cout;
using std::cerr;

int main(int argc, char **argv)
{
	argv[argc] = NULL;
    try
    {
        PmergeMe::sort(argv);
    }
    catch (std::exception   &e)
    {
        cerr << "Error: " << e.what() << '\n';
    }
	// for (int i = 1; i < 10; i++)
	// {
	// 	cout << i << " => " << PmergeMe::jacobsthalNumber(i) << '\n';
	// }
	// int arr[] = {0, 2, 3, 4, 10};
	// std::vector<int> v(arr, arr + 5);
	// PmergeMe::binaryInsertion(v, std::pair<int, int>(1, 10));
	// cout << "vector: ";
	// for (size_t i = 0; i + 1 < v.size(); i++)
	// 	cout << v[i] << ", ";
	// cout << v.back() << '\n';
}