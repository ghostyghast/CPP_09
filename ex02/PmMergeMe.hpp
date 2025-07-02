/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmMergeMe.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:25:58 by amaligno          #+#    #+#             */
/*   Updated: 2025/07/02 21:37:49 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMMERGEME_HPP
# define PMMERGEME_HPP

# include <cstdlib>
# include <vector>
# include <list>

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

		static	std::vector<int>	_vector;
		static	std::list<int>		_list;
		static	int					_comparisons;

		template<typename T> static void	parse(T &container, char **values){
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
	
		static void							vectorSort();
		static void							listSort();
		
		PmMergeMe();
		PmMergeMe(const PmMergeMe &copy);
		~PmMergeMe();
		PmMergeMe &operator=(const PmMergeMe &copy);
};

#endif