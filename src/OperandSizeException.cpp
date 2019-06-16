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
	std::out_of_range("Operand size overflow of underflow")
{

}

OperandSizeException::OperandSizeException(const OperandSizeException &rhs) :
	std::out_of_range(rhs.what())
{

}

OperandSizeException::~OperandSizeException()
{

}

OperandSizeException::OperandSizeException(const char *msg) :
	std::out_of_range(msg)
{

}
