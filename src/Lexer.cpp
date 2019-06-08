/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <aminadzh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 19:04:00 by aminadzh          #+#    #+#             */
/*   Updated: 2019/05/18 19:04:00 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Lexer.h"
#include "LexicalException.h"
#include <iostream>

Lexer::Lexer() :
m_Push("^[ \\t\\n]*(push)[\\s\\S]+"),
m_Pop("^[ \\t\\n]*(pop)[ \\t\\n]*"),
m_Dump("^[ \\t\\n]*(dump)[ \\t\\n]*"),
m_Assert("^[ \\t\\n]*(assert)[\\s\\S]+"),
m_Add("^[ \\t\\n]*(add)[ \\t\\n]*"),
m_Sub("^[ \\t\\n]*(sub)[ \\t\\n]*"),
m_Mul("^[ \\t\\n]*(mul)[ \\t\\n]*"),
m_Div("^[ \\t\\n]*(div)[ \\t\\n]*"),
m_Mod("^[ \\t\\n]*(mod)[ \\t\\n]*"),
m_Print("^[ \\t\\n]*(print)[ \\t\\n]*"),
m_Exit("^[ \\t\\n]*(exit)[ \\t\\n]*"),
m_Int8("^[ \\t\\n]*(int8\\([-]?[0-9]+\\))[ \\t\\n]*"),
m_Int16("^[ \\t\\n]*(int16\\([-]?[0-9]+\\))[ \\t\\n]*"),
m_Int32("^[ \\t\\n]*(int32\\([-]?[0-9]+\\))[ \\t\\n]*"),
m_Float("^[ \\t\\n]*(float\\([-]?[0-9]+.[0-9]+\\))[ \\t\\n]*"),
m_Double("^[ \\t\\n]*(double\\([-]?[0-9]+.[0-9]+\\))[ \\t\\n]*"),
m_Comment("^[;][\\s\\S]+")
{}

Lexer::~Lexer()
{}

Command Lexer::checkSyntax(const std::string &line) const
{
	std::cmatch m;
	Command command;
	if (std::regex_match(line.c_str(), m, m_Push))
	{
		command.type = findType(line.substr(line.find("push") + 4));
		command.instr = push;
		command.value = findValue(line);
	}
	else if (std::regex_match(line.c_str(), m, m_Pop))
		command.instr = pop;
	else if (std::regex_match(line.c_str(), m, m_Dump))
		command.instr = dump;
	else if (std::regex_match(line.c_str(), m, m_Assert))
	{
		command.instr = assert;
		command.type = findType(line.substr(line.find("assert") + 6));
		command.value = findValue(line);
	}
	else if (std::regex_match(line.c_str(), m, m_Add))
		command.instr = add;
	else if (std::regex_match(line.c_str(), m, m_Sub))
		command.instr = subtract;
	else if (std::regex_match(line.c_str(), m, m_Mul))
		command.instr = multiply;
	else if (std::regex_match(line.c_str(), m, m_Div))
		command.instr = divide;
	else if (std::regex_match(line.c_str(), m, m_Mod))
		command.instr = modulo;
	else if (std::regex_match(line.c_str(), m, m_Print))
		command.instr = print;
	else if (std::regex_match(line.c_str(), m, m_Exit))
		command.instr = finish;
	else if (std::regex_match(line.c_str(), m, m_Comment))
		command.instr = comment;
	else
	{
		std::string info("Unknown command: ");
		info = info + line;
		throw LexicalException(info.c_str());
	}
	return command;
}

eOperandType Lexer::findType(const std::string &line) const
{
	std::cmatch m;
	if (std::regex_match(line.c_str(), m, m_Int8))
		return Int8;
	else if (std::regex_match(line.c_str(), m, m_Int16))
		return Int16;
	else if (std::regex_match(line.c_str(), m, m_Int32))
		return Int32;
	else if (std::regex_match(line.c_str(), m, m_Float))
		return Float;
	else if (std::regex_match(line.c_str(), m, m_Double))
		return Double;
	else
	{
		std::string msg("Unknown type: ");
		msg = msg + line;
		throw LexicalException(msg.c_str());
	}
}

std::string Lexer::findValue(const std::string &line) const
{
	std::size_t start = line.find_first_of("(");
	std::size_t end = line.find_last_not_of(")");
	end = end - start;
	std::string val = line.substr(start + 1, end);
	return val;
}
