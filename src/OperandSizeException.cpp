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
m_info("Operand size overflow of underflow")
{

}

OperandSizeException::OperandSizeException(const OperandSizeException &rhs)
{
	//TODO: implement this
}

OperandSizeException::~OperandSizeException()
{

}

const OperandSizeException& OperandSizeException::operator=(const OperandSizeException &rhs)
{
	return OperandSizeException();
//TODO: implement this
}

OperandSizeException::OperandSizeException(const char *msg) :
m_info(msg)
{

}

const char* OperandSizeException::getInfo() const
{
	return m_info;
}

