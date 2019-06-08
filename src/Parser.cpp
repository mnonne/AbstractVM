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
#include <fstream>
#include "OperandFactory.h"
#include "LexicalException.h"
#include "OperandSizeException.h"
#include "StackException.h"

Parser* Parser::m_Instance = 0;

Parser::Parser()
{}

Parser* Parser::getInstance()
{
	if (!m_Instance)
		m_Instance = new Parser();
	return m_Instance;
}

void Parser::readInput()
{
	std::string line;
	Command instr;
	int lNumber = 0;
	while (line != ";;")
	{
		size_t column = line.find(";");
		if (column != std::string::npos)
			line = line.substr(0, column);
		lNumber++;
		std::getline(std::cin, line);
		if (line.empty())
			continue;
		try {
			instr = m_Lexer.checkSyntax(line);
			instr.lNumber = lNumber;
		}
		catch (LexicalException& e)
		{
			std::cout << "Line " << lNumber << ": " << e.what() << std::endl;
			continue;
		}
		if (instr.instr != comment)
			m_Commands.push_back(instr);
	}
}

void Parser::readInput(const char *filePath)
{
	std::ifstream infile(filePath);
	std::string line;
	Command instr;
	int lNumber = 0;
	while (std::getline(infile, line))
	{
		size_t column = line.find(";");
		if (column != std::string::npos)
			line = line.substr(0, column);
		lNumber++;
		if (line.empty())
			continue;
		try {
			instr = m_Lexer.checkSyntax(line);
			instr.lNumber = lNumber;
		}
		catch (LexicalException& e)
		{
			std::cout << "Line " << lNumber << ": " << e.what() << std::endl;
			continue;
		}
		if (instr.instr != comment)
			m_Commands.push_back(instr);
	}
}

void Parser::parseCommands(OperandStack &stack) const
{
	bool isEndig = false;
	for (auto it = m_Commands.begin(); it != m_Commands.end(); ++it)
	{
		switch(it->instr)
		{
			case push:
				try {
					stack.push(FACTORY->createOperand(it->type, it->value));
				}
				catch (OperandSizeException& e)
				{
					std::cout << "Line " << it->lNumber << ": " << e.what() << std::endl;
				}
				break;
			case pop:
				try {
					stack.pop();
				}
				catch (StackException& e)
				{
					std::cout << "Line " << it->lNumber << ": " << e.what() << std::endl;
				}
				break;
			case dump:
				try {
					stack.dump();
				}
				catch (StackException& e)
				{
					std::cout << "Line " << it->lNumber << ": " << e.what() << std::endl;
				}
				break;
			case assert:
				try {
					stack.compare(FACTORY->createOperand(it->type, it->value));
				}
				catch (StackException& e)
				{
					std::cout << "Line " << it->lNumber << ": " << e.what() << std::endl;
				}
				break;
			case add:
				try {
					stack.add();
				}
				catch (StackException& e)
				{
					std::cout << "Line " << it->lNumber << ": " << e.what() << std::endl;
				}
				catch (OperandSizeException&e)
				{
					std::cout << "Line " << it->lNumber << ": " << e.what() << std::endl;
				}
				break;
			case subtract:
				try {
					stack.sub();
				}
				catch (StackException& e)
				{
					std::cout << "Line " << it->lNumber << ": " << e.what() << std::endl;
				}
				break;
			case multiply:
				try {
					stack.mul();
				}
				catch (StackException& e)
				{
					std::cout << "Line " << it->lNumber << ": " << e.what() << std::endl;
				}
				break;
			case divide:
				try {
					stack.div();
				}
				catch (StackException& e)
				{
					std::cout << "Line " << it->lNumber << ": " << e.what() << std::endl;
				}
				catch (OperandSizeException& e)
				{
					std::cout << "Line " << it->lNumber << ": " << e.what() << std::endl;
				}
				break;
			case modulo:
				try {
					stack.mod();
				}
				catch (StackException& e)
				{
					std::cout << "Line " << it->lNumber << ": " << e.what() << std::endl;
				}
				catch (OperandSizeException& e)
				{
					std::cout << "Line " << it->lNumber << ": " << e.what() << std::endl;
				}
				break;
			case print:
				try {
					stack.print();
				}
				catch (StackException& e)
				{
					std::cout << "Line " << it->lNumber << ": " << e.what() << std::endl;
				}
				break;
			case finish:
				isEndig = true;
				break;
			default:
				break;
		}
	}
	if (!isEndig)
		throw StackException("The program has no exit status");
}
