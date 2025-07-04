/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmMergeMe.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:45:34 by amaligno          #+#    #+#             */
/*   Updated: 2025/07/03 17:41:09 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMMERGEME_TPP
# define PMMERGEME_TPP

# include "PmMergeMe.hpp"

template <typename T>
void	PmMergeMe::parse(T &container, char **values)
{
	for (size_t	i  = 0; values[0]; i++)
	{
		char	*end;
		int		value;

		value = strtol(values[0], &end);
		if (value < 0)
			throw (negativeValueException());
		container[i] = value;
		if (*end)
			throw (invalidInputException());
	}
}

template <typename T>
void	PmMergeMe::mergeInsertion(T	&container)
{
	
}

#endif