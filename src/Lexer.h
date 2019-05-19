/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <aminadzh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 19:04:00 by aminadzh          #+#    #+#             */
/*   Updated: 2019/05/18 19:04:00 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ABSTRACTVM_LEXER_H
#define ABSTRACTVM_LEXER_H

#include "IOperand.h"
#include <string>
#include <regex>

enum instruction {
	push, pop, dump, assert, add, subtract, multiply, divide, modulo, print, finish, comment
};

struct Command
{
	instruction instr;
	eOperandType type;
	std::string value;
	int lNumber;
};

class Lexer {
public:
	Lexer();
	~Lexer(); //TODO: copline form

	Command checkSyntax(const std::string& line) const;

private:
	eOperandType findType(const std::string& line) const;
	std::string findValue(const std::string& line) const;

	const std::regex m_Push;
	const std::regex m_Pop;
	const std::regex m_Dump;
	const std::regex m_Assert;
	const std::regex m_Add;
	const std::regex m_Sub;
	const std::regex m_Mul;
	const std::regex m_Div;
	const std::regex m_Mod;
	const std::regex m_Print;
	const std::regex m_Exit;

	const std::regex m_Int8;
	const std::regex m_Int16;
	const std::regex m_Int32;
	const std::regex m_Float;
	const std::regex m_Double;

	const std::regex m_Comment;
};

#endif //ABSTRACTVM_LEXER_H
