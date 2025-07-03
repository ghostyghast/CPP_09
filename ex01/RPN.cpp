/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:34:46 by amaligno          #+#    #+#             */
/*   Updated: 2025/07/03 15:30:25 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"
#include <cstring>
#include <cstdlib>

using std::string;

// Constructors / Destructor

RPN::RPN()
{
}

RPN::RPN(const RPN &copy)
{
	(void)copy;
}

RPN::~RPN()
{
}

// Operator Overloads

RPN	&RPN::operator=(const RPN &copy)
{
	(void)copy;
	return (*this);
}

// Methods

int	RPN::calculate(string input)
{
	size_t	pos = 0;
	while (!input.empty())
	{
		pos = input.find(' ');
		string	token = input.substr(0, pos);
		input.erase(0, token.size() + 1);
		if (isdigit(token[0]))
			strToInt(token);
		else if (token.size() == 1)
			operation(token[0]);
		else
			throw (invalidinputException());
	}
	if (this->_stack.empty())
		throw (invalidinputException());
	return (this->getBottom());
}

void	RPN::operation(char c)
{
	int value2 = this->getPop();
	int value1 = this->getPop();

	switch (c)
	{
		case '*':
			this->_stack.push(value1 * value2);
			break;
		case '+':
			this->_stack.push(value1 + value2);
			break;
		case '/':
			if (value2 == 0)
				throw(divisionByZeroException());
			this->_stack.push(value1 / value2);
			break;
		case '-':
			this->_stack.push(value1 - value2);
			break;
		default:
			throw(invalidOperatorException());
	}
}

int	RPN::getPop()
{
	if (this->_stack.empty())
		throw (invalidinputException());

	int	value = this->_stack.top();
	this->_stack.pop();

	return(value);
}

int	RPN::getBottom()
{
	std::stack<int>	copy = this->_stack;

	while (copy.size() > 1)
	{
		copy.pop();	
	}
	return (copy.top());
}

void	RPN::strToInt(string s)
{
	char	*end;
	int		value = strtol(s.c_str(), &end, 10);
	if (*end)
		throw (invalidinputException());
	if (value > 10)
		throw (invalidValueException());
	this->_stack.push(value);
}

// Exceptions

const char	*RPN::divisionByZeroException::what() const throw()
{
	return("cannot divide by zero");
}

const char	*RPN::invalidValueException::what() const throw()
{
	return("value more than 10");
}

const char	*RPN::invalidOperatorException::what() const throw()
{
	return("invalid operator");
}

const char	*RPN::invalidinputException::what() const throw()
{
	return("invalid input");
}

