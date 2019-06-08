/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <aminadzh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 18:33:00 by aminadzh          #+#    #+#             */
/*   Updated: 2019/05/18 18:33:00 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ABSTRACTVM_PARSER_H
#define ABSTRACTVM_PARSER_H

#include <vector>
#include "Lexer.h"
#include "OperandStack.h"

#define PARSER Parser::getInstance()

class Parser {
public:
	Parser(const Parser&) = delete;
	Parser& operator=(Parser&) = delete;

	static Parser* getInstance();

	void readInput();
	void readInput(const char *filePath);
	void parseCommands(OperandStack& stack) const;

private:
	Parser();
	void checkExitStatus() const;

	static Parser* m_Instance;
	Lexer m_Lexer;
	std::vector<Command> m_Commands;
};

#endif //ABSTRACTVM_PARSER_H
