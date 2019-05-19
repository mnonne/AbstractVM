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
	std::exception(),
	m_Info("Lexical exception")
{
}

LexicalException::LexicalException(const LexicalException &rhs)
{
	m_Info = rhs.what();
}

LexicalException::~LexicalException()
{

}

LexicalException &LexicalException::operator=(const LexicalException &rhs)
{
	m_Info = rhs.what();
	return *this;
}

LexicalException::LexicalException(const char *msg) :
	m_Info(msg),
	std::exception()
{

}

const char *LexicalException::what() const _NOEXCEPT
{
	return m_Info;
}
