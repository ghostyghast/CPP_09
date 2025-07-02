/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmMergeMe.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:49:28 by amaligno          #+#    #+#             */
/*   Updated: 2025/07/02 21:37:42 by amaligno         ###   ########.fr       */
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