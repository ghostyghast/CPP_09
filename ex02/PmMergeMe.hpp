/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmMergeMe.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:25:58 by amaligno          #+#    #+#             */
/*   Updated: 2025/07/07 21:51:25 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMMERGEME_HPP
# define PMMERGEME_HPP

# include <cstdlib>
# include <vector>
# include <string>
# include <deque>

class PmMergeMe{
	public:
		static	void	sort(char **values);
		static	int							jacobsthalNumber(int n);

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

		static	int	_comparisons;
		
		template <typename T> static void	runContainerSort(std::string container_name, char **argv);
		template <typename T> static void	parse(T &container, char **values);
		template <typename T> static T		mergeInsertion(T &sequence);
		template <typename T> static void	binaryInsertion(T &container, int value);
		
		static bool							xBiggerThanY(int x, int y);

		PmMergeMe();
		PmMergeMe(const PmMergeMe &copy);
		~PmMergeMe();
		PmMergeMe &operator=(const PmMergeMe &copy);
};

std::ostream	&operator<<(std::ostream &os, const std::vector<int> &v);
std::ostream	&operator<<(std::ostream &os, const std::deque<int> &v);

# include "PmMergeMe.tpp"

#endif