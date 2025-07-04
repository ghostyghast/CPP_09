/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmMergeMe.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:45:34 by amaligno          #+#    #+#             */
/*   Updated: 2025/07/04 18:47:44 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMMERGEME_TPP
# define PMMERGEME_TPP

# include "PmMergeMe.hpp"
# include <ctime>
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
	time_t	before = 0;
	time_t	after = 0;
	T		sequence;
	
	_comparisons = 0;
	parse(sequence, values);

	cout << "Before: " << sequence << "\n";
	
	before = time(NULL);
	mergeInsertion(sequence);
	after = time(NULL);

	cout << "After: " << sequence << "\n";

	cout << container_name << " sorting time for range of [" << sequence.size() << "] elements : " << difftime(after, before) << "s\n";
	cout << "Using " << _comparisons << " comparisons\n";
}

template <typename T>
T	PmMergeMe::mergeInsertion(T &sequence)
{
	T	a_list;
	T	b_list;
	T	main;

	for (size_t i = 0; i + 1 < sequence.size(); i += 2)
	{
		int	a = sequence[i];
		int	b = sequence[i + 1];
	
		if (xBiggerThanY(b, a))
			std::swap(a, b);
		a_list.push_back(a);
		b_list.push_back(b);
	}
	
	main = mergeInsertion(a_list);
	
	return (main);
}


#endif