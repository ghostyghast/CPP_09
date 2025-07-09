/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmMergeMe.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:25:58 by amaligno          #+#    #+#             */
/*   Updated: 2025/07/09 20:28:19 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMMERGEME_HPP
# define PMMERGEME_HPP

# include <cstdlib>
# include <vector>
# include <deque>
# include <utility>
# include <string>

class PmMergeMe{
	public:
		static	void	sort(char **values);
		static	int		jacobsthalNumber(int n);
		template <class C> static void				binaryInsertion(C &container, std::pair<int, int>);

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
		
		template <class C> static void								runContainerSort(std::string container_name, char **values);
		template <class C> static void								parse(C &container, char **values);
		template <template <typename, typename >class C, typename alloc> static C<int, alloc>
											mergeInsertion(C<int , alloc> &sequence);
	
		template <class A, class B> static void		insertBToA(A &main, B &b_list);
		template <class C> static C					jacobsthalList(int size);
		static bool									xBiggerThanY(int x, int y);

		PmMergeMe();
		PmMergeMe(const PmMergeMe &copy);
		~PmMergeMe();
		PmMergeMe &operator=(const PmMergeMe &copy);
};

std::ostream	&operator<<(std::ostream &os, const std::vector<int> &v);
std::ostream	&operator<<(std::ostream &os, const std::deque<int> &v);

# include "PmMergeMe.tpp"

#endif