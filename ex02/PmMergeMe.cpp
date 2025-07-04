/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmMergeMe.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:49:28 by amaligno          #+#    #+#             */
/*   Updated: 2025/07/04 18:45:11 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmMergeMe.hpp"

int	PmMergeMe::_comparisons = 0;

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

std::ostream	&operator<<(std::ostream &os, const std::vector<int> &v)
{
	std::vector<int>::const_iterator start = v.begin();
	std::vector<int>::const_iterator end = v.end();
	while (start + 1 != end)
	{
		os << *start << ", ";
		start++;
	}
	os << *start;
	return (os);
}

std::ostream	&operator<<(std::ostream &os, const std::deque<int> &d)
{
	std::deque<int>::const_iterator start = d.begin();
	std::deque<int>::const_iterator end = d.end();
	while (start + 1 != end)
	{
		os << *start << ", ";
		start++;
	}
	os << *start;
	return (os);
}

// Methods

void	PmMergeMe::sort(char **values)
{
	runContainerSort<std::vector<int> >("std::vector", values);
	runContainerSort<std::deque<int> >("std::deque", values);
}

const char	*PmMergeMe::negativeValueException::what(void) const throw()
{
    return("values must be positive");
}

const char	*PmMergeMe::invalidInputException::what(void) const throw()
{
    return("invalid input");
}

// return x > y, and increment _comparisons
bool	PmMergeMe::xBiggerThanY(int x, int y)
{
	_comparisons += 1;
	return (x > y);
}
