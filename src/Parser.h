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

#define PARSER Parser::getInstance()

class Parser {
public:
	Parser(const Parser&) = delete;
	Parser& operator=(Parser&) = delete;

private:
	Parser();

	static Parser* m_Instance;
};


#endif //ABSTRACTVM_PARSER_H
