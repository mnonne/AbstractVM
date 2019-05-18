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

struct Command
{
	enum instruction {
		push, pop, dump, assert, add, sub, mul, div, mod, print, exit
	};
	eOperandType type;
	std::string value;
};

class Lexer {
public:
	Lexer();
	~Lexer(); //TODO: copline form

	Command checkSyntax(const std::string& line) const;

};


#endif //ABSTRACTVM_LEXER_H
