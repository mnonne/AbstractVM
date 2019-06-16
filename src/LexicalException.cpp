/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LexicalException.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <aminadzh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 18:07:00 by aminadzh          #+#    #+#             */
/*   Updated: 2019/05/19 18:07:00 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "LexicalException.h"

LexicalException::LexicalException() :
	std::invalid_argument("Lexical exception")
{
}

LexicalException::LexicalException(const LexicalException &rhs) :
	std::invalid_argument(rhs.what())
{
	
}

LexicalException::~LexicalException()
{

}

LexicalException::LexicalException(const char *msg) :
	std::invalid_argument(msg)
{

}
