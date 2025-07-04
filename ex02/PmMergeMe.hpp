/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmMergeMe.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:25:58 by amaligno          #+#    #+#             */
/*   Updated: 2025/07/04 15:22:37 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMMERGEME_HPP
# define PMMERGEME_HPP

# include <cstdlib>
# include <vector>
# include <deque>

class PmMergeMe{
	public:
		static	void	sort(char **values);

		class negativeValueException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class invalidInputException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

	private:

		static	int					_comparisons;

		template <typename T> static void	parse(T &container, char **values);
		template <typename T> static void	mergeInsertion(T &container);
		
		PmMergeMe();
		PmMergeMe(const PmMergeMe &copy);
		~PmMergeMe();
		PmMergeMe &operator=(const PmMergeMe &copy);
};

# include "PmMergeMe.tpp"

#endif