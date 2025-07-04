/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmMergeMe.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:49:28 by amaligno          #+#    #+#             */
/*   Updated: 2025/07/04 15:24:46 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmMergeMe.hpp"


// Constructors / Destructor

PmMergeMe::PmMergeMe() {}

PmMergeMe::PmMergeMe(const PmMergeMe &copy) {(void)copy;}

PmMergeMe::~PmMergeMe() {}

// Operator Overloads

PmMergeMe	&PmMergeMe::operator=(const PmMergeMe &copy)
{
	(void)copy;
	return (*this);
}

void	PmMergeMe::sort(char **values)
{
	std::vector<int>	_vector;
	std::deque<int>		_deque;

	_comparisons = 0;
	parse(_vector, values);
	mergeInsertion(_vector);

	_comparisons = 0;
	parse(_deque, values);
	mergeInsertion(_deque);
}

const char	*PmMergeMe::negativeValueException::what(void) const throw()
{
    return("values must be positive");
}

const char	*PmMergeMe::invalidInputException::what(void) const throw()
{
    return("invalid input");
}