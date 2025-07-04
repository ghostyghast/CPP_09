/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pringles <pringles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:25:37 by amaligno          #+#    #+#             */
/*   Updated: 2025/07/04 14:51:52 by pringles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmMergeMe.hpp"
#include <iostream>

using std::cout;
using std::cerr;

int main(int argc, char **argv)
{
    try
    {
        PmMergeMe::sort(argv);
    }
    catch (std::exception   &e)
    {
        cerr << "Error: " << e.what() << '\n';
    }
}