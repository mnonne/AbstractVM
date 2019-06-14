/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandSizeException.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <aminadzh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 16:54:00 by aminadzh          #+#    #+#             */
/*   Updated: 2019/05/11 16:54:00 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "OperandSizeException.h"

OperandSizeException::OperandSizeException() :
	std::exception(),
	m_Info("Operand size overflow of underflow")
{

}

OperandSizeException::OperandSizeException(const OperandSizeException &rhs)
{
	m_Info = rhs.what();
}

OperandSizeException::~OperandSizeException()
{

}

const OperandSizeException& OperandSizeException::operator=(const OperandSizeException &rhs)
{
	m_Info = rhs.what();
	return *this;
}

OperandSizeException::OperandSizeException(const char *msg) :
	m_Info(msg),
	std::exception()
{

}

const char *OperandSizeException::what() const noexcept
{
	return m_Info;
}
