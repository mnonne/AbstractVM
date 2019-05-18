/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <aminadzh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 18:33:00 by aminadzh          #+#    #+#             */
/*   Updated: 2019/05/18 18:33:00 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Parser.h"
#include <iostream>
#include <string>

Parser* Parser::m_Instance = 0;

Parser::Parser()
{}

Parser* Parser::getInstance()
{
	if (!m_Instance)
		m_Instance = new Parser();
	return m_Instance;
}

std::vector<Command> Parser::readConsole() const
{
	std::vector<Command> buf;
	std::string line;
	int lNumber;
	while (line != ";;")
	{
		std::getline(std::cin, line);
		try {
			Command instr = m_Lexer.checkSyntax(line);
		}
		catch (std::exception& e) //TODO: catch another type of exception
		{
			std::cout << "Line " << lNumber << std::endl;
		}
		lNumber++;
	}
	return buf;
}
