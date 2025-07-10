/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:49:28 by amaligno          #+#    #+#             */
/*   Updated: 2025/07/09 20:17:59 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cmath>

int	PmergeMe::_comparisons = 0;

// Constructors / Destructor

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy) {(void)copy;}

PmergeMe::~PmergeMe() {}

// Operator Overloads

PmergeMe	&PmergeMe::operator=(const PmergeMe &copy)
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

void	PmergeMe::sort(char **values)
{
	runContainerSort<std::vector<int> >("std::vector", values);
	runContainerSort<std::deque<int> >("std::deque", values);
}

const char	*PmergeMe::negativeValueException::what(void) const throw()
{
    return("values must be positive");
}

const char	*PmergeMe::invalidInputException::what(void) const throw()
{
    return("invalid input");
}

// return x > y, and increment _comparisons
bool	PmergeMe::xBiggerThanY(int x, int y)
{
	_comparisons += 1;
	return (x > y);
}

int	PmergeMe::jacobsthalNumber(int n)
{
	return round((pow(2, n+1) + pow(-1, n)) / 3);
}
