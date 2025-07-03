/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:32:42 by amaligno          #+#    #+#             */
/*   Updated: 2025/07/03 15:26:37 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>

class RPN{
	public:
		RPN();
		~RPN();
		
		class divisionByZeroException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class invalidValueException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class invalidOperatorException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class invalidinputException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		int	calculate(std::string input);

	private:
		std::stack<int>	_stack;

		int		getPop();
		int		getBottom();
		void	operation(char c);
		void	strToInt(std::string s);

		RPN		&operator=(const RPN &copy);
		RPN(const RPN &copy);

};

#endif