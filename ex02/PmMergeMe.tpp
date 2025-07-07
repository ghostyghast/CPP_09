/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmMergeMe.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:45:34 by amaligno          #+#    #+#             */
/*   Updated: 2025/07/07 22:13:51 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMMERGEME_TPP
# define PMMERGEME_TPP

# include "PmMergeMe.hpp"
# include <ctime>
# include <cmath>
# include <iostream>

using std::cout;

template <typename T>
void	PmMergeMe::parse(T &container, char **values)
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

template <typename T>
void	PmMergeMe::runContainerSort(std::string container_name, char **values)
{	
	clock_t	start = 0;
	clock_t	end = 0;
	T		sequence;
	
	_comparisons = 0;
	parse(sequence, values);

	cout << "Before: " << sequence << "\n";
	
	start = std::clock();
	sequence = mergeInsertion(sequence);
	end = std::clock();

	cout << "After: " << sequence << "\n";

	cout << std::fixed;
	cout << container_name << " sorting time for range of [" << sequence.size() << "] elements : " << 1000.0 * (end - start) / CLOCKS_PER_SEC << "us\n";
	cout << "Using " << _comparisons << " comparisons\n";
}

template <typename T>
T	PmMergeMe::mergeInsertion(T &sequence)
{
	size_t	size = sequence.size();
	T		a_list;
	T		b_list;
	T		main;
	T		indexes;
	
	if (size <= 1)
		return (sequence);
		
	for (size_t i = 0; i + 1 < size; i += 2)
	{
		int	a = sequence[i];
		int	b = sequence[i + 1];
		
		if (xBiggerThanY(b, a))
			std::swap(a, b);
		a_list.push_back(a);
		b_list.push_back(b);
	}

	if (size % 2 == 1)
		b_list.push_back(sequence.back());

	main = mergeInsertion(a_list);

	main.insert(main.begin(), b_list[0]);
	// b_list.erase(main.begin());
	for (size_t i = 1; i <= b_list.size(); i++)
	{
		int	j_num = jacobsthalNumber(i) - 1;
		binaryInsertion(main, b_list[j_num]);
	}
	return (main);
}

template <typename T>
void	PmMergeMe::binaryInsertion(T &container, int value)
{
	size_t	low = 0;
	size_t 	middle = 0;
	size_t	high = container.size() - 1;

	while (low != high)
	{
		middle = static_cast<size_t>(std::ceil((high - low) / 2) + low);
		if (xBiggerThanY(value, container[middle]))
			low = middle + 1;
		else
			high = middle;
	}
	container.insert(container.begin() + low, value);
}

#endif