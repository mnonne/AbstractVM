/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <aminadzh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:14:00 by aminadzh          #+#    #+#             */
/*   Updated: 2019/04/14 15:14:00 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdio>
#include "gtest/gtest.h"
#include "Parser.h"
#include "OperandStack.h"
#include "StackException.h"

int	main(int ac, char **av)
{
	OperandStack stack;
	PARSER->readConsole();
	try {
		PARSER->parseCommands(stack);
	}
	catch(StackException& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
