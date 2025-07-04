/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmMergeMe.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pringles <pringles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:49:28 by amaligno          #+#    #+#             */
/*   Updated: 2025/07/04 15:02:49 by pringles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmMergeMe.hpp"

void	PmMergeMe::sort(char **values)
{
	_comparisons = 0;
	parse(_vector, values);
	vectorSort();

	_comparisons = 0;
	parse(_list, values);
	listSort();
}

const char	*PmMergeMe::negativeValueException::what(void) const throw()
{
    return("values must be positive");
}

const char	*PmMergeMe::invalidInputException::what(void) const throw()
{
    return("invalid input");
}