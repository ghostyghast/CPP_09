/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pringles <pringles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:45:34 by amaligno          #+#    #+#             */
/*   Updated: 2025/07/10 17:22:53 by pringles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_TPP
# define PmergeMe_TPP

# include "PmergeMe.hpp"
# include <ctime>
# include <cmath>
# include <algorithm>
# include <iostream>

using std::cout;
using std::pair;

template <typename T>
void	PmergeMe::parse(T &container, char **values)
{
	for (size_t	i  = 1; values[i]; i++)
	{
		char	*end;
		int		value;

		value = strtol(values[i], &end, 10);
		if (value < 0)
			throw (negativeValueException());
		if (*end)
			throw (invalidInputException());
		container.push_back(value);
	}
}

template <class C>
void	PmergeMe::runContainerSort(std::string container_name, char **values)
{	
	clock_t	start = 0;
	clock_t	end = 0;
	C	sequence;
	
	_comparisons = 0;
	parse(sequence, values);

	cout << "Before: " << sequence << "\n";
	
	start = std::clock();
	sequence = mergeInsertion(sequence);
	end = std::clock();

	cout << "After: " << sequence << "\n";

	cout << std::fixed;
	cout << container_name << " sorting time for range of [" << sequence.size() << "] elements : " << 1000.0 * (end - start) / CLOCKS_PER_SEC << "ms\n";
	cout << "Using " << _comparisons << " comparisons\n";
}

template <template <typename, typename > class C, typename alloc> 
C<int, alloc>	PmergeMe::mergeInsertion(C<int, alloc> &sequence)
{
	size_t						size = sequence.size();
	C<int, alloc>				a_list;
	C<pair<int, int>, alloc>	b_list;
	C<int, alloc>				main;
	
	if (size <= 1)
		return (sequence);
		
	for (size_t i = 0; i + 1 < size; i += 2)
	{
		int	a = sequence[i];
		int	b = sequence[i + 1];
		
		if (xBiggerThanY(b, a))
			std::swap(a, b);
		a_list.push_back(a);
		b_list.push_back(pair<int, int>(b, a));
	}

	if (size % 2 == 1)
		b_list.push_back(pair<int, int>(sequence.back(), -1));

	main = mergeInsertion(a_list);
	
	insertBToA(main, b_list);
	return (main);
}

template <class A, class B>
void	PmergeMe::insertBToA(A &main, B &b_list)
{
	A		j_list = jacobsthalList<A>(b_list.size());

	for (size_t i = 0; i < b_list.size(); i++)
	{
		if (main[0] == b_list[i].second)
		{
			main.insert(main.begin(), b_list[i].first);
			break ;
		}
	}
	if (j_list.size() == 0)
		return ;
	for (size_t i = 1; i < j_list.size(); i++)
	{
		for (int pos = j_list[i]; pos != j_list[i - 1]; pos--)
			binaryInsertion(main, b_list[pos]);
	}
	for (int i = b_list.size() - 1; i > j_list.back(); i--)
		binaryInsertion(main, b_list[i]);
}

template <class C>
void	PmergeMe::binaryInsertion(C &container, pair<int, int> &b_a)
{
	int		value = b_a.first;
	size_t	low = 0;
	size_t 	middle = 0;
	size_t	high;

	if (b_a.second == -1)
		high = container.size();
	else
		high = std::distance(container.begin(), std::find(container.begin(), container.end(), b_a.second));
	while (low != high)
	{
		middle = static_cast<size_t>(std::ceil((high - low) / 2) + low);
		if (xBiggerThanY(value, container[middle]))
			low = middle + 1;
		else
			high = middle;
	}
	// b_a.first = -1;
	container.insert(container.begin() + low, value);
}

template <class C>
C	PmergeMe::jacobsthalList(int size)
{
	C	list;

	for (int i = 1; i <= size; i++)
	{
		int	j_num = jacobsthalNumber(i) - 1;
		if (j_num >= size)
			break ;
		list.push_back(j_num);
	}
	return (list);
}

#endif